const int row[4] = { 13, 12, 11, 10 };  // output
const int col[4] = { 9, 8, 7, 6 };      //input

const int switchArr[4][4] = { 0 };

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(row[i], OUTPUT);
    pinMode(col[i], INPUT);
    digitalWrite(row[i], LOW);
    digitalWrite(col[i], LOW);
  }
}

int colVal[4] = { 0 };  //LOW로 설정한 것임(LOW = 0)

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(row[i], HIGH);
    for (int j = 0; j < 4; j++) {
      colVal[j] = digitalRead(col[j]);
      if (colVal[j] == HIGH) {
        Serial.print((i * 4) + j, HEX);
        Serial.println();
      }
      colVal[j] = 0;
      digitalWrite(col[j], LOW);
    }
    digitalWrite(row[i], LOW);
  }
}
