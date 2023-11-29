int led[9] = { 0 };  // 2~8, a~g

void display_init(int *pin) {
  for (int i = 2; i <= 9; i++) {
    pinMode(*(pin + i - 1), OUTPUT);
  }
}
void clear(void) {
  for (int i = 2; i <= 8; i++) {
    digitalWrite(led[i], LOW);
  }
}
const int num[10][7] = { { 1, 1, 1, 1, 1, 1, 0 }, { 0, 1, 1, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1, 0, 1 }, { 1, 1, 1, 1, 0, 0, 1 }, { 0, 1, 1, 0, 0, 1, 1 }, { 1, 0, 1, 1, 0, 1, 1 }, { 1, 0, 1, 1, 1, 1, 1 }, { 1, 1, 1, 0, 0, 1, 0 }, { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 0, 0, 1, 1 } };
void display_number(int number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(led[i + 2], num[number][i]);
  }
  delay(1000);
  clear();
}

void setup() {
  for (int i = 2; i <= 8; i++) {
    led[i] = i;
  }
  display_init(led);
  Serial.begin(115200);
}

void loop() {

  if (Serial.available()) {
    char input_number = Serial.read();
    if ((input_number >= '0') && (input_number <= '9')) {
      int int_number = input_number - '0';
      display_number(int_number);
    }
  }
}
