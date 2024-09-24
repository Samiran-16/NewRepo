#ifndef VARIABLES_H
#define VARIABLES_H
#define encoder1 2
#define encoder2 20
#define encoder3 3

#define PWM1 7
#define PWM2 8
#define PWM3 9

#define DIR1_PIN 26
#define DIR2_PIN 28
#define DIR3_PIN 30

bool Direction1 = true;
bool Direction2 = true;
bool Direction3 = true;
int bno_chassis = 0;
DynamicJsonDocument doc(200);
DynamicJsonDocument enc(1024);
String json = "";
String strenc="";
char cmd = 'S';
DeserializationError Jsonerror;
int num = 400;
unsigned long currentTime = 0;
unsigned long lastTime = 0;

int W = 0;
float Vx = 0;
float Vy = 0;

volatile unsigned long rpm1;
volatile unsigned long rpm2;
volatile unsigned long rpm3;

unsigned long pulseCount1 = 0;
unsigned long pulseCount2 = 0;
unsigned long pulseCount3 = 0;

float change1 = 0;
float change2 = 0;
float change3 = 0;

float change1_f = 0;
float change2_f = 0;
float change3_f = 0;

float error1 = 0;
float error2 = 0;
float error3 = 0;

float prev_error1=0;
float prev_error2=0;
float prev_error3=0;

float setpoint1 = 0;
float setpoint2 = 0;
float setpoint3 = 0;

float pid_p1 = 0;
float pid_p2 = 0;
float pid_p3 = 0;

float pid_d1 = 0;
float pid_d2 = 0;
float pid_d3 = 0;

float kp1 = 0.1;
float kp2 = 0.1;
float kp3 = 0.1;

float kd1 = 0.005;
float kd2 = 0.005;
float kd3 = 0.005;

const unsigned long interval = 80;
unsigned long delay_millis = 0;
unsigned long nume = 60000;
unsigned long dino = 28800;
float elapsedtime=0,time=0,prevtime=0;

int strength = 0;

float Matrix[3][3];

#endif