const int LED_0 = 12;
const int LED_1 = 11;

void setup() {
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);

}

void loop() {
  if (Serial.available()) {
    char input[30] = { 0 };
    Serial.readBytesUntil("\n", input, 30);
    Serial.print(input);

    if (strcmp("L0_ON", input) == 0) {
      digitalWrite(LED_0, HIGH);
    } else if (strcmp("L0_OFF", input) == 0) {
      digitalWrite(LED_0, LOW);
    } else if (strcmp("L1_ON", input) == 0) {
      digitalWrite(LED_1, HIGH);
    } else if (strcmp("L1_OFF", input) == 0) {
      digitalWrite(LED_1, LOW);
    }
  }
}
