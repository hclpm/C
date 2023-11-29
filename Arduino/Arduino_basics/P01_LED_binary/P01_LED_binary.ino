const unsigned int led[6] = {3, 5, 6, 9,10, 11};
int cnt = 0;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(led[i], cnt & (0x01 << i) ? HIGH : LOW);
  }
  cnt++;
  delay(1000);
}
