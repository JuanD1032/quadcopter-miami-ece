#include <LSM303.h>
#include <Wire.h>
#include <math.h>

// Defines ////////////////////////////////////////////////////////////////

// The Arduino two-wire interface uses a 7-bit number for the address, 
// and sets the last bit correctly based on reads and writes
#define MAG_ADDRESS            (0x3C >> 1)
#define ACC_ADDRESS_SA0_A_LOW  (0x30 >> 1)
#define ACC_ADDRESS_SA0_A_HIGH (0x32 >> 1)

// Constructors ////////////////////////////////////////////////////////////////

LSM303::LSM303(void)
{
	// These are just some values for a particular unit; it is recommended that
	// a calibration be done for your particular unit.
//	m_max.x = +540; m_max.y = +500; m_max.z = 180;
//	m_min.x = -520; m_min.y = -570; m_min.z = -770;
 // m_min.x = -551; m_min.y =-543; 	m_min.z = -584;
 // m_max.x = +134; m_max.y =+78; 	m_max.z = +605;
  m_min.x = -38; m_min.y = -48; m_min.z = -38;
  m_max.x = +10; m_max.y = +9;  m_max.z = 39;

	_device = LSM303_DEVICE_AUTO;
	acc_address = ACC_ADDRESS_SA0_A_LOW;
}

// Public Methods //////////////////////////////////////////////////////////////

void LSM303::init(byte device, byte sa0_a)
{	
	_device = device;
	switch (_device)
	{
		case LSM303DLH_DEVICE:
		case LSM303DLM_DEVICE:
			if (sa0_a == LSM303_SA0_A_LOW)
				acc_address = ACC_ADDRESS_SA0_A_LOW;
			else if (sa0_a == LSM303_SA0_A_HIGH)
				acc_address = ACC_ADDRESS_SA0_A_HIGH;
			else
				acc_address = (detectSA0_A() == LSM303_SA0_A_HIGH) ? ACC_ADDRESS_SA0_A_HIGH : ACC_ADDRESS_SA0_A_LOW;
			break;	
		
		case LSM303DLHC_DEVICE:
			acc_address = ACC_ADDRESS_SA0_A_HIGH;
			break;
			
		default:
			// try to auto-detect device
			if (detectSA0_A() == LSM303_SA0_A_HIGH)
			{
				// if device responds on 0011001b (SA0_A is high), assume DLHC
				acc_address = ACC_ADDRESS_SA0_A_HIGH;
				_device = LSM303DLHC_DEVICE;
			}
			else
			{
				// otherwise, assume DLH or DLM (pulled low by default on Pololu boards); query magnetometer WHO_AM_I to differentiate these two
				acc_address = ACC_ADDRESS_SA0_A_LOW;
				_device = (readMagReg(LSM303_WHO_AM_I_M) == 0x3C) ? LSM303DLM_DEVICE : LSM303DLH_DEVICE;
			}
	}
}

// Turns on the LSM303's accelerometer and magnetometers and places them in normal
// mode.
void LSM303::enableDefault(void)
{
	// Enable Accelerometer
	// 0x27 = 0b00100111
	// Normal power mode, all axes enabled
	writeAccReg(LSM303_CTRL_REG1_A, 0x27);
  
	// Enable Magnetometer
	// 0x00 = 0b00000000
	// Continuous conversion mode
	writeMagReg(LSM303_MR_REG_M, 0x00);
}

// Writes an accelerometer register
void LSM303::writeAccReg(byte reg, byte value)
{
	Wire.beginTransmission(acc_address);
	Wire.send(reg);
	Wire.send(value);
	Wire.endTransmission();
}

// Reads an accelerometer register
byte LSM303::readAccReg(byte reg)
{
	byte value;
	
	Wire.beginTransmission(acc_address);
	Wire.send(reg);
	Wire.endTransmission();
	Wire.requestFrom(acc_address, (byte)1);
	value = Wire.receive();
	Wire.endTransmission();
	
	return value;
}

// Writes a magnetometer register
void LSM303::writeMagReg(byte reg, byte value)
{
	Wire.beginTransmission(MAG_ADDRESS);
	Wire.send(reg);
	Wire.send(value);
	Wire.endTransmission();
}

// Reads a magnetometer register
byte LSM303::readMagReg(byte reg)
{
	byte value;
	
	// if dummy register address (magnetometer Y/Z), use device type to determine actual address
	if (reg < 0)
	{
		switch (reg)
		{
			case LSM303_OUT_Y_H_M:
				reg = (_device == LSM303DLH_DEVICE) ? LSM303DLH_OUT_Y_H_M : LSM303DLM_OUT_Y_H_M;
				break;
			case LSM303_OUT_Y_L_M:
				reg = (_device == LSM303DLH_DEVICE) ? LSM303DLH_OUT_Y_L_M : LSM303DLM_OUT_Y_L_M;
				break;
			case LSM303_OUT_Z_H_M:
				reg = (_device == LSM303DLH_DEVICE) ? LSM303DLH_OUT_Z_H_M : LSM303DLM_OUT_Z_H_M;
				break;
			case LSM303_OUT_Z_L_M:
				reg = (_device == LSM303DLH_DEVICE) ? LSM303DLH_OUT_Z_L_M : LSM303DLM_OUT_Z_L_M;
				break;
		}
	}
	
	Wire.beginTransmission(MAG_ADDRESS);
	Wire.send(reg);
	Wire.endTransmission();
	Wire.requestFrom(MAG_ADDRESS, 1);
	value = Wire.receive();
	Wire.endTransmission();
	
	return value;
}

// Reads the 3 accelerometer channels and stores them in vector a
void LSM303::readAcc2(void)
{

	Wire.beginTransmission(acc_address);
	// assert the MSB of the address to get the accelerometer 
	// to do slave-transmit subaddress updating.
	Wire.send(LSM303_OUT_X_L_A | (1 << 7)); 
	Wire.endTransmission();
	Wire.requestFrom(acc_address, (byte)6);

	while (Wire.available() < 6);
	
	aI.buf[0] = Wire.receive();
	aI.buf[1] = Wire.receive();
	aI.buf[2] = Wire.receive();
	aI.buf[3] = Wire.receive();
	aI.buf[4] = Wire.receive();
	aI.buf[5]= Wire.receive();

	aI.I.x = aI.I.x  >> 4;
	aI.I.y = aI.I.x  >> 4;
	aI.I.z = aI.I.x  >> 4;
}
void LSM303::readAcc(void)
{
	Wire.beginTransmission(acc_address);
	// assert the MSB of the address to get the accelerometer 
	// to do slave-transmit subaddress updating.
	Wire.send(LSM303_OUT_X_L_A | (1 << 7)); 
	Wire.endTransmission();
	Wire.requestFrom(acc_address, (byte)6);

	while (Wire.available() < 6);
	
	byte xla = Wire.receive();
	byte xha = Wire.receive();
	byte yla = Wire.receive();
	byte yha = Wire.receive();
	byte zla = Wire.receive();
	byte zha = Wire.receive();

	a.x = ((int16_t)(xha << 8 | xla)) >> 4;
	a.y = ((int16_t)(yha << 8 | yla)) >> 4;
	a.z = ((int16_t)(zha << 8 | zla)) >> 4;
}

// Reads the 3 magnetometer channels and stores them in vector m
void LSM303::readMag(void)
{
	Wire.beginTransmission(MAG_ADDRESS);
	Wire.send(LSM303_OUT_X_H_M);
	Wire.endTransmission();
	Wire.requestFrom(MAG_ADDRESS, 6);

	while (Wire.available() < 6);

	byte xhm = Wire.receive();
	byte xlm = Wire.receive();
	
	byte yhm, ylm, zhm, zlm;
	
	if (_device == LSM303DLH_DEVICE)
	{
		// DLH: register address for Y comes before Z
		yhm = Wire.receive();
		ylm = Wire.receive();
		zhm = Wire.receive();
		zlm = Wire.receive();
	}
	else
	{
		// DLM, DLHC: register address for Z comes before Y
		zhm = Wire.receive();
		zlm = Wire.receive();
		yhm = Wire.receive();
		ylm = Wire.receive();

	}

	m.x = ((int16_t)(xhm << 8 | xlm))>>4;
	m.y = ((int16_t)(yhm << 8 | ylm))>>4;
	m.z = ((int16_t)(zhm << 8 | zlm))>>4;
}

// Reads all 6 channels of the LSM303 and stores them in the object variables
void LSM303::read(void)
{
	readAcc();
	readMag();
}

// Returns the number of degrees from the -Y axis that it
// is pointing.
float LSM303::heading(void)
{
	return heading((vector){0,-1,0});
}

// Returns the number of degrees from the From vector projected into
// the horizontal plane is away from north.
// 
// Description of heading algorithm: 
// Shift and scale the magnetic reading based on calibration data to
// to find the North vector. Use the acceleration readings to
// determine the Down vector. The cross product of North and Down
// vectors is East. The vectors East and North form a basis for the
// horizontal plane. The From vector is projected into the horizontal
// plane and the angle between the projected vector and north is
// returned.
float LSM303::heading(vector from)
{
    // shift and scale
    m.x = (m.x - m_min.x) / (m_max.x - m_min.x) * 2 - 1.0;
    m.y = (m.y - m_min.y) / (m_max.y - m_min.y) * 2 - 1.0;
    m.z = (m.z - m_min.z) / (m_max.z - m_min.z) * 2 - 1.0;

    vector temp_a = a;
    // normalize
    vector_normalize(&temp_a);
    //vector_normalize(&m);

    // compute E and N
    vector E;
    vector N;
    vector_cross(&m, &temp_a, &E);
    vector_normalize(&E);
    vector_cross(&temp_a, &E, &N);
	
    // compute heading
    float heading = round(atan2(vector_dot(&E, &from), vector_dot(&N, &from)) * 180.0 / M_PI);
    if (heading < 0) heading += 360.0;
	return heading;
}

void LSM303::vector_cross(const vector *a,const vector *b, vector *out)
{
  out->x = a->y*b->z - a->z*b->y;
  out->y = a->z*b->x - a->x*b->z;
  out->z = a->x*b->y - a->y*b->x;
}

float LSM303::vector_dot(const vector *a,const vector *b)
{
  return a->x*b->x+a->y*b->y+a->z*b->z;
}

void LSM303::vector_normalize(vector *a)
{
  float mag = sqrt(vector_dot(a,a));
  a->x /= mag;
  a->y /= mag;
  a->z /= mag;
}

// Private Methods //////////////////////////////////////////////////////////////

byte LSM303::detectSA0_A(void)
{
	Wire.beginTransmission(ACC_ADDRESS_SA0_A_LOW);
	Wire.send(LSM303_CTRL_REG1_A);
	Wire.endTransmission();
	Wire.requestFrom(ACC_ADDRESS_SA0_A_LOW, 1);
	if (Wire.available())
	{
		Wire.receive();
		return LSM303_SA0_A_LOW;
	}
	else
		return LSM303_SA0_A_HIGH;
}
