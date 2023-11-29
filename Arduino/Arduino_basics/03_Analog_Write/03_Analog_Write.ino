const unsigned int led[6] = { 3, 5, 6, 9, 10, 11 };
// LED: 0, 1, 2, 3,  4,  5
int cnt = 0;
int bit_0;
int bit_1;
int bit_2;
int bit_3;
int bit_4;
int bit_5;


void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }
}

//1초마다  count 0~4까지 증가, 0이면 다 꺼짐, 1이면
void loop() {
  // cnt++;
  // for (int i = 0; i < 6; i++) {
  //   if ((cnt & j) == j) {
  //     analogWrite(led[i], 255);
  //   } else {
  //     analogWrite(led[i], 0);
  //   }
  //   j = j * 2;
  //   if (j == 64) {
  //     j = 1;
  //   }
  // }
  // if (cnt == 63) {
  //   cnt = 0;
  // }
  // delay(700);
  for (int i = 0; i < 6; i++) {
    digitalWrite(led[i], cnt & (0x01 << i) ? HIGH : LOW);
  }
  cnt ++;
    delay(700);
}
