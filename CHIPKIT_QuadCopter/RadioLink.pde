#define TIMEOUT  2000   //two second time out to start shuting down if valid signal is not recieved.

int RX_state, RX_count;
int flag, last;
int dummy;

union RX_data {
  char B[20];
  int I[5];
  float F[5]; 
}
RX_data;


void radio_init(void){
  //Pin 39RX and 40TX are serial2 pins
  Serial1.begin(2400);
  RX_state = 0;
  RX_count = 0;
}

inline void radio_check(void){
  if(Serial1.available()) {
    dummy = Serial1.read();
    switch (RX_state) {
    case 0:
      if (dummy == 0xB5) //button pressed recieved
        RX_state = 1;
      if(dummy == 0xC5)//Activat PID
        RX_state = 3;
      #ifdef TUNPID == 1
      if(dummy == 0xD5)
        RX_state = 4;
      break;
      #endif
    case 1: //recieving x y data from controller
      if (dummy == 0x5C) //button pressed recieved
        RX_state = 2;
      else
        RX_state = 0;
      break;
    case 2: //Roll Pitch Throttle Commands
      RX_data.B[RX_count++] =dummy;
      if (RX_count > 16) {
        flag = false;  //Reset flag that shuts down motors
        RX_count = 0;
        RX_state = 0;
        if(abs(RX_data.F[0])<1.5)
          D_roll = RX_data.F[0];
        if(abs(RX_data.F[1])<1.5)
          D_pitch = RX_data.F[1];
        if(abs(RX_data.I[2])<100000)
          throttle = RX_data.I[2];
        if(abs(RX_data.I[3])<4000);
        D_yaw = RX_data.I[3];
        // Serial.print("packet Received");
      } 
      break; 
    case 3:
      if(dummy == 0x5B){//PID Activation
        RollPID.SetMode(AUTOMATIC);
        PitchPID.SetMode(AUTOMATIC);
      }
      RX_state = 0;
      break;
      #ifdef TUNPID == 1
    case 4:
      if(dummy == 0x5D){//PID Tuning loop
        RX_state = 5;

      } 
      else
        RX_state = 0;
      break;
    case 5:
      RX_data.B[RX_count++] =dummy;
      if (RX_count > 1) {
        P_TERM=RX_data.B[0]*1.0+RX_data.B[1]*0.1;
        flag = false;  //Reset flag that shuts down motors
        RX_count = 0;
        RX_state = 0;
        //   RollPID..SetTunings(P_TERM,0.0,0.0);
        PitchPID.SetTunings(P_TERM,0.0,0.0);

        //                       Serial.print("PID RX ");
        //                       Serial.print(RX_data.B[0]);
        //                       Serial.print(" ");
        //                       Serial.println(RX_data.B[1]);
      } 
      break; 
      #endif
    }
  }
  else{
    if(flag){
      if(millis()-last > TIMEOUT){
        D_roll = 0.0;
        D_pitch = 0.0;
        throttle -= 200;
        last = millis();
        if(throttle<0)
            throttle = 0;
        // Serial.println("No Signal");
      }
    }
    else{
      flag = true;
      last = millis();
    }
  }
}

