#include "PinChangeInterrupt.h"
const unsigned int led[6] = { 3, 5, 6, 9, 10, 11 };
const int SW_0 = 13;
int cnt = 0;

void SW0_Pressed(void) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(led[i], cnt & (0x01 << i) ? HIGH : LOW);
  }
  cnt++;
}

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }
  attachPCINT(digitalPinToPCINT(SW_0), SW0_Pressed, RISING);
}

void loop() {
}
