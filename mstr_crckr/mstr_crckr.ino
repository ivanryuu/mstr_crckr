#include <AFMotor.h>

int SPR = 200;       // steps per revolution
int SPD = SPR / 40; // steps per degree
int clockwise = BACKWARD;
int counterclockwise = FORWARD;
int stepType = SINGLE;
int current = 0;

int limitswitch = 31;
AF_Stepper motor(SPR, 1);

void setup() {
  Serial.begin(9600);
  Serial.println("Initialize stepper.");
  
  pinMode(limitswitch, INPUT);
  motor.setSpeed(10);
}

void loop() {
  
  //int switch1 = digitalRead(limitswitch);
  //if(switch1 == HIGH) {
    delay(2000);
    first_step(30, clockwise);
    //switch1 = digitalRead(limitswitch);
    
    Serial.println(current);
  //}
  
}

void solve(int n1, int n2, int n3) {
  first_step(n1, clockwise);
  second_step(n2, counterclockwise);
  third_step(n3, clockwise);
}

void first_step(int deg, int orientation) {
  motor.stepWithBreaks(SPR * 3, orientation, stepType,limitswitch);
  go_to_degree(deg, orientation);
}

void second_step(int deg, int orientation) {
  motor.step(SPR, orientation, stepType);
  go_to_degree(deg, orientation);
}

void third_step(int deg, int orientation) {
  go_to_degree(deg, orientation);
}

void go_to_degree(int deg, int orientation) {
  int dist = 0;
  if(orientation == clockwise) {
    if(deg > current) {
      dist = 40 - deg + current;
    } else {
      dist = current - deg;
    }
    current = (40 + current - dist) % 40;
  }
  else if(orientation == counterclockwise) {
    if(deg > current) {
      dist = deg - current;
    } else {
      dist = 40 - current + deg;
    }
    current = (current + dist) % 40;
  }
  
  
  motor.step(dist * SPD, orientation, stepType);
}
