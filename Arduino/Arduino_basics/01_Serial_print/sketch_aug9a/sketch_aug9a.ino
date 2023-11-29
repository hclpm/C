void setup() {
  Serial.begin(115200);  //클래스 안에 begin이라는 함수가 있는 것. 구조체의 '.'과 유사
  Serial.println("\nHello PC. I'm Arduino.\n\n");
  Serial.println(78);
  Serial.println(78, DEC);  //10진수
  Serial.println(78, HEX); //16진수
  Serial.println(78, BIN);  //2진수
  Serial.println(1.23456);
  Serial.println(1.23456, 1); //소수 1번째 자리까지 출력
  Serial.println('N');
}


void loop() {
}
