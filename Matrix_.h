#ifndef MATRIX_H
#define MATRIX_H

float matrix_cal(){
   // if(cmd == 'S')bno_chassis = 0;

  // Serial.println(bno_chassis);
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


}
#endif