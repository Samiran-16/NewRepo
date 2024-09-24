#include <ArduinoJson.h>
#include <String.h>
#include "Variables.h"
#include "Matrix_.h"
#include "communication.h"
#include "encoder_rpm.h"
#include "pid.h"

void setup() {
  Serial.begin(38400);
  Serial2.begin(38400);
  Serial1.begin(38400);
  Serial3.begin(38400);
  pinMode(DIR1_PIN, OUTPUT);
  pinMode(DIR2_PIN, OUTPUT);
  pinMode(DIR3_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoder1), countPulse1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder2), countPulse2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder3), countPulse3, CHANGE);
}

void loop() {
  json_rec();
  rpm_cal();
  bno_rec();

 float Matrix[3][3] = {
    // { 1, 0, 0.36 },
    // { -0.5, 0.8666, 0.36 },
    // { -0.5, -0.8666, 0.36 }


    { cos(bno_chassis * (3.142 / 180)), sin(bno_chassis * (3.142 / 180)), 0.36 },
    { cos((bno_chassis + 120) * (3.142 / 180)), sin((bno_chassis + 120) * (3.142 / 180)), 0.36 },
    { cos((bno_chassis + 240) * (3.142 / 180)), sin((bno_chassis + 240) * (3.142 / 180)), 0.36 }
  };
  // Serial.println(bno_chassis);
  // num=num/10;
  // num*=10;
  Vx = cos(num * M_PI / 180.0) * 6 * strength / 100;
  Vy = sin(num * M_PI / 180.0) * 6 * strength / 100;

  if (cmd == 'S') {
    W = 0;
    bno_chassis = 0;
  } else if (cmd == 'L') {
    W = 5;

  } else if (cmd == 'R') {
    W = -5;
    // bno_rec();
  }


  if (num == 400 && cmd == 'S') {
    change1 = 0;
    change2 = 0;
    change3 = 0;
    change1_f = 0;
    change2_f = 0;
    change3_f = 0;
    Vx = Vy = W = 0;
  } else if (cmd != 'S' && num == 400) {
    // Serial.println("hello");
    Vx = Vy = 0;
  }

  change1 = (Matrix[0][0] * Vx + Matrix[0][1] * Vy + Matrix[0][2] * W) / 0.076;
  change2 = (Matrix[1][0] * Vx + Matrix[1][1] * Vy + Matrix[1][2] * W) / 0.076;
  change3 = (Matrix[2][0] * Vx + Matrix[2][1] * Vy + Matrix[2][2] * W) / 0.076;

  // Serial.print("Cmd : ");
  // Serial.print(cmd);
  // Serial.print("YAW : ");
  // Serial.print(bno_chassis);
  // Serial.print("Angle : ");
  // Serial.print(num);
  // Serial.print(strength);


  Direction1 = (change1 < 0) ? false : true;
  Direction2 = (change2 < 0) ? false : true;
  Direction3 = (change3 < 0) ? true : false;
  // change1=abs(change1);
  // change2=abs(change2);
  // change3=abs(change3);
  // change1 = constrain(change1, 0, 255);
  // change2 = constrain(change2, 0, 255);
  // change3 = constrain(change3, 0, 255);
  pid_fn();
  digitalWrite(DIR1_PIN, Direction1);
  digitalWrite(DIR2_PIN, Direction2);
  digitalWrite(DIR3_PIN, Direction3);
    Serial.print(" : ");
  Serial.print(change1);
  Serial.print(" : ");
   
  Serial.print(change1_f);
  Serial.print(" : ");
  Serial.print(change2);
  Serial.print(" : ");
  Serial.print(change2_f);
  Serial.print(" : ");
  Serial.print(change3);
  Serial.print("     :    ");
  Serial.println(change3_f);
  // analogWrite(PWM1, abs(change1));
  // analogWrite(PWM2, abs(change2));
  // analogWrite(PWM3, abs(change3));
  analogWrite(PWM1, abs(change1_f));
  analogWrite(PWM2, abs(change2_f));
  analogWrite(PWM3, abs(change3_f));
  // Serial.println();
  delay(10);
}

