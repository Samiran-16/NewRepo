#ifndef ENCODER_H
#define ENCODER_H
void countPulse1() {
  if (digitalRead(encoder1) == LOW) {
    pulseCount1++;
  }
}

void countPulse2() {
  if (digitalRead(encoder2) == LOW) {
    pulseCount2++;
  }
}

void countPulse3() {
  if (digitalRead(encoder3) == LOW) {
    pulseCount3++;
  }
}


void rpm_cal() {
  currentTime = millis();
  if (currentTime - lastTime >= interval) {  // PID Sampling
    rpm1 = ((pulseCount1 * nume) / dino);
    rpm2 = ((pulseCount2 * nume) / dino);
    rpm3 = ((pulseCount3 * nume) / dino);
    pulseCount1 = 0;
    pulseCount2 = 0;
    pulseCount3 = 0;

    lastTime = currentTime;
    enc["rpm1"]=rpm1;
    enc["rpm2"]=rpm2;
    enc["rpm3"]=rpm3;
    serializeJson(enc,strenc);
    Serial3.print(strenc);
    Serial3.print("*");

  }
}

#endif
