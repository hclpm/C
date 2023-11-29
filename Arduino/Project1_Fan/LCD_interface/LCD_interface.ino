#include "LiquidCrystal.h"  // Text LCD 라이브러리 함수

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //아두이노-LCD 선 연결
int FanSpeed = 1;                       //선풍기 속도
int Rtime[4] = { 0 };                   //예약 종료 시간까지 남은 시간 배열

//LCD 시작화면(전원 키고 바로)
void LCD_Start(int fs, int Rtime[]) {     //(선풍기속도, 예약종료남은시간)
  lcd.clear();
  lcd.print("FAN_01");                                //첫번째줄
  lcd.setCursor(0,2); lcd.print("by KM,HJ,KM,HC   "); //두번째줄
}
pi
void LCD_Main(int fs, int Rtime[]) {      //(선풍기속도, 예약종료남은시간)
  lcd.clear(); 
  lcd.print("Speed:");lcd.print(FanSpeed);          //첫번째줄
  lcd.setCursor(0, 2);lcd.print("Rtime: [");        //두번째줄
  for (int i = 3; i >= 0; i--) {       //시간 배열 출력 for문
    if (i == 2) {
      lcd.print(":");
    }
    lcd.print(Rtime[i]);
  }
  lcd.print("]");
}

void LCD_turnoff(void){
  lcd.clear();
}


void setup() {
  lcd.begin(16, 2);               //LCD 패널 활성화 (x, y)개
  LCD_Start(FanSpeed, Rtime);     //LCD 시작화면 함수 호출(선풍기 속도, 예약 종료까지 남은 시간)
  delay(3000);
  LCD_Main(FanSpeed, Rtime);      //LCD 메인화면 함수 호출
  delay(3000);
  LCD_turnoff();
}

void loop() {
}