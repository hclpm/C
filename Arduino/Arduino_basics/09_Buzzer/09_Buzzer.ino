const int buzzer = 10;

void setup() {
  for (int i = 0; i <= 2; i++) {
    tone(buzzer, 330);
    delay(300);
    tone(buzzer, 294);
    delay(300);
    tone(buzzer, 262);
    delay(300);
    tone(buzzer, 294);
    delay(300);
    tone(buzzer, 330);
    noTone(buzzer);
    delay(300);
    tone(buzzer, 330);
    noTone(buzzer);
    delay(300);
    tone(buzzer, 330);
    noTone(buzzer);
    delay(300);
  }
  noTone(buzzer);
}

void loop() {
}
