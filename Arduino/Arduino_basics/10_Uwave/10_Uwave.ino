#include "TimerOne.h"

const int tpin = 10;
const int epin = 12;

void setup() {

  pinMode(tpin, OUTPUT);
  pinMode(epin, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(tpin, LOW);
  delayMicroseconds(2);
  digitalWrite(tpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tpin, LOW);

  unsigned long duration = pulseIn(epin, HIGH);
  unsigned long distance = (duration/2) / 29.1;

  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
