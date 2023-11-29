#include "TimerOne.h"
const int LED0 = 10;
const int LED1 = 5;
int flag = 0;
int flag1 = 0;

void timerIsr(void) {
  if (flag == 0) {
    digitalWrite(LED0, HIGH);
    flag = 1;
  } else {
    digitalWrite(LED0, LOW);
    flag = 0;
  }
  if (flag == 0) {
    digitalWrite(LED1, HIGH);
    flag1 = 1;
  } else {
    digitalWrite(LED1, LOW);
    flag1 = 0;
  }
}
void setup() {
  Timer1.initialize(1000000 / 10);
  pinMode(LED1, OUTPUT);
  pinMode(LED0, OUTPUT);
  Timer1.pwm(LED0, 100);
  Timer1.attachInterrupt(timerIsr);  //정해진 주기의 시간에 timerIsr이라는 함수 호출
}

void loop() {
}
