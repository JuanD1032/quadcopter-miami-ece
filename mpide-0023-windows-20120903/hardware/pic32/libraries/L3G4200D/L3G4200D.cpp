#include <L3G4200D.h>
#include <Wire.h>
#include <math.h>

// Defines ////////////////////////////////////////////////////////////////

// The Arduino two-wire interface uses a 7-bit number for the address, 
// and sets the last bit correctly based on reads and writes
#ifndef GYR_ADDRESS
#define GYR_ADDRESS (0xD2 >> 1)
//#define GYR_ADDRESS (0xD0 >> 1)
#endif
// Public Methods //////////////////////////////////////////////////////////////

// Turns on the L3G4200D's gyro and places it in normal mode.
void L3G4200D::enableDefault(void)
{
	// 0x0F = 0b00001111
	// Normal power mode, all axes enabled
	writeReg(L3G4200D_CTRL_REG1, 0x0F);
}

// Writes a gyro register
void L3G4200D::writeReg(byte reg, byte value)
{
	Wire.beginTransmission(GYR_ADDRESS);
	Wire.send(reg);
	Wire.send(value);
	Wire.endTransmission();
}
//check the depth of the FIFO to be followed by a FIFO read
byte L3G4200D::readFIFOdepth(void){
	byte value;
	Wire.beginTransmission(GYR_ADDRESS);
	Wire.send(L3G4200D_FIFO_SRC_REG);
	Wire.endTransmission();
	Wire.requestFrom(GYR_ADDRESS, 1);
	value = (Wire.receive()&0x1f);
	Wire.endTransmission();

	return value;


}

//Read the data register (assuming in FIFO mode) depth number of times
void L3G4200D::readFIFO(byte* buf, byte depth){
	Wire.beginTransmission(GYR_ADDRESS);
	Wire.send(L3G4200D_OUT_X_L| (1 << 7));
	Wire.endTransmission();
	Wire.requestFrom(GYR_ADDRESS, depth*6);
	while (Wire.available() < (depth*6));
	for(int i = 0; i<depth*6;i++)
		buf[i]=Wire.receive();
	Wire.endTransmission();

}
// Reads a gyro register
byte L3G4200D::readReg(byte reg)
{
	byte value;
	
	Wire.beginTransmission(GYR_ADDRESS);
	Wire.send(reg);
	Wire.endTransmission();
	Wire.requestFrom(GYR_ADDRESS, 1);
	value = Wire.receive();
	Wire.endTransmission();
	
	return value;
}

// Reads the 3 gyro channels and stores them in vector g
void L3G4200D::read()
{
	Wire.beginTransmission(GYR_ADDRESS);
	// assert the MSB of the address to get the gyro 
	// to do slave-transmit subaddress updating.
	Wire.send(L3G4200D_OUT_X_L | (1 << 7)); 
	Wire.endTransmission();
	Wire.requestFrom(GYR_ADDRESS, 6);

	while (Wire.available() < 6);
	
	uint8_t xla = Wire.receive();
	uint8_t xha = Wire.receive();
	uint8_t yla = Wire.receive();
	uint8_t yha = Wire.receive();
	uint8_t zla = Wire.receive();
	uint8_t zha = Wire.receive();

	g.x = ((int16_t)(xha << 8 | xla));
	g.y = ((int16_t)(yha << 8 | yla));
	g.z = ((int16_t)(zha << 8 | zla));
}

void L3G4200D::vector_cross(const vector *a,const vector *b, vector *out)
{
  out->x = a->y*b->z - a->z*b->y;
  out->y = a->z*b->x - a->x*b->z;
  out->z = a->x*b->y - a->y*b->x;
}

float L3G4200D::vector_dot(const vector *a,const vector *b)
{
  return a->x*b->x+a->y*b->y+a->z*b->z;
}

void L3G4200D::vector_normalize(vector *a)
{
  float mag = sqrt(vector_dot(a,a));
  a->x /= mag;
  a->y /= mag;
  a->z /= mag;
}