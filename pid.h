#ifndef PID_H
#define PID_H
#include "Variables.h"

void pid_fn() {

  time = millis();
  elapsedtime = (time - prevtime) / 1000;
  setpoint1 = abs(change1) * 3.65;
  setpoint2 = abs(change2) * 3.65;
  setpoint3 = abs(change3) * 3.65;
  error1 = setpoint1 - rpm1;
  error2 = setpoint2 - rpm2;
  error3 = setpoint3 - rpm3;
  pid_p1 = error1 * kp1;
  pid_p2 = error2 * kp2;
  pid_p3 = error3 * kp3;

  pid_d1 = kd1 * ((error1 - prev_error1) / elapsedtime);
  pid_d2 = kd2 * ((error2 - prev_error2) / elapsedtime);
  pid_d3 = kd3 * ((error3 - prev_error3) / elapsedtime);




  change1_f = abs(change1) + pid_p1 + pid_d1; 
  change2_f = abs(change2) + pid_p2 + pid_d2;
  change3_f = abs(change3) + pid_p3 + pid_d3;
  
  // Remove abs from above equations, after this add directions
  // Direction1 = (change1_f < 0) ? false : true;
  // Direction2 = (change2_f < 0) ? false : true;
  // Direction3 = (change3_f < 0) ? true : false;

  change1_f = constrain(change1_f, 0, 180);
  change2_f = constrain(change2_f, 0, 180);
  change3_f = constrain(change3_f, 0, 180);

  prev_error1 = error1;
  prev_error2 = error2;
  prev_error3 = error3;
  prevtime = time;
}


#endif