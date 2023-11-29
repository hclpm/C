
int LED[] = { 0, 1, 2, 3, 4, 5, 6, 7 };


void setup() {

  for (int i = 0; i < (sizeof(LED) / sizeof(int)); i++) {
    LED[i] = i+6;
  }
  for (int i = 0; i < (sizeof(LED) / sizeof(int)); i++) {
    pinMode(LED[i], OUTPUT);
  }
  Serial.begin(115200);
  Serial.println(sizeof(LED));
  Serial.println(sizeof(int));
}

void loop() {
  for (int j = 0; j < sizeof(LED) / sizeof(int); j++) {
    digitalWrite(LED[j], HIGH);
    delay(1);
    digitalWrite(LED[j], LOW);
    delay(19);
  }
}
