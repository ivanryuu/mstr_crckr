#include <AFMotor.h>

int SPR = 200;       // steps per revolution
int SPD = SPR / 40;  // steps per degree
int clockwise = BACKWARD;
int counterclockwise = FORWARD;
int stepType = SINGLE;
int current = 0;


int n1[10];
int n2[10];
int n3 = 7;

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
    
    Serial.println(current)
  //}
  
}

void 

void stepThroughSolutions() {
  
  for(int i = 0; i < 10; i++) {
    setupMove(n1[i]);
    for(int j = 0; j < 10; j++) {
      last_two_steps(n2[j], n3);
      
      // someway to tell if its done or not
      if(done()) {
        return;
      }
    }
  }
}

void setupMove(int n_1) {
  first_step(n1, clockwise);
  motor.step(SPR, COUNTERCLOCKWISE, SINGLE);  
}

void solve(int n_1, int n_2, int n_3) {
  first_step(n_1, clockwise);
  second_step(n_2, counterclockwise);
  third_step(n_3, clockwise);
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

void last_two_steps(int n_2, int n_3) {
  go_to_degree(n_2, COUNTERCLOCKWISE);
  go_to_degree(n_3, CLOCKWISE);
}

void go_to_degree(int deg, int orientation) {
  int dist = 0;
  if(orientation == clockwise) {
    if(deg > current) {
      dist = 40 - deg + current;
    }
    else {
      dist = current - deg;
    }
    current = (40 + current - dist) % 40;
  }
  else {
    if(deg > current) {
      dist = deg - current;
    }
    else {
      dist = 40 - current + deg;
    }
    current = (current + dist) % 40;
  }
  
  
  motor.step(dist * SPD, orientation, stepType);
}

boolean done() {
  return false;
}

void get_n1() {
    for (int i = 0; i < 10; ++i) {
        n1[i] = (4 * i) + (n3 % 4);
    }
}

void get_n2() {
    for (int i = 0; i < 10; ++i) {
        n2[i] = (n1[i] + 2) % 40;
    }
}
