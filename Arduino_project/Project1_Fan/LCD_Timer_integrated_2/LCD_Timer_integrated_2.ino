#include "LiquidCrystal.h"  // Text LCD 라이브러리 함수

//LCD 전역변수
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //아두이노-LCD 선 연결
int FanSpeed = 1;                       //선풍기 속도

//Timer 전역변수
const int StartSW = { 7 };  //이 신호만 적외선 입력 신호로 변경하면 됨
const int IncreSW = { 8 };
const int DecreSW = { 13 };
const int EnterSW = { 9 };
// Start // Increase // Decrease // Enter //
int EnterValue = 0;    //Enter가 몇번 눌러졌는지. 1이면 시간, 2이면 분 설정으로도 사용할 것
int Rtime[4] = { 0 };  //time array
//Rtime[0][1] : [2][3]

//Main화면 Timer 감소 전역변수
unsigned long timerStartTime = 0;  //타이머가 시작한 시간


//LCD 시작화면(전원 키고 바로)
void LCD_Start(int fs, int Rtime[]) {  //(선풍기속도, 예약종료남은시간)
  lcd.clear();
  lcd.print("FAN_01");  //첫번째줄
  lcd.setCursor(0, 2);
  lcd.print("by KM,HJ,KM,HC   ");  //두번째줄
  delay(2500);
  lcd.clear();
}


//LCD 메인화면
void LCD_Main(int fs, int Rtime[]) {  //(선풍기속도, 예약종료남은시간)
  while (1) {
    if (digitalRead(StartSW) == 1) {
      setTimer();
    }
    lcd.print("Speed:");
    lcd.print(FanSpeed);  //첫번째줄
    lcd.setCursor(0, 2);
    lcd.print("Rtime: [");         //두번째줄
    for (int i = 0; i < 4; i++) {  //시간 배열 출력 for문
      if (i == 2) {
        lcd.print(":");
      }
      lcd.print(Rtime[i]);
    }
    lcd.print("]  ");
    while ((Rtime[0] > 0) || (Rtime[1] > 0) || (Rtime[2] > 0) || (Rtime[3] > 0)) {
      timerCntDwn();
    }
  }
}

//Timer 설정 함수
void setTimer(void) {
  lcd.clear();
  lcd.print("Loading...");
  delay(1500);
  lcd.clear();
  delay(500);

  EnterValue = 1;
  //분 설정
  while (EnterValue == 1) {
    if (digitalRead(IncreSW) == 1) {
      if (Rtime[1] == 9) {
        Rtime[1] = 0;
        Rtime[0]++;
      } else {
        Rtime[1]++;
      }
      delay(300);
    }
    if (digitalRead(DecreSW) == 1) {
      if (Rtime[1] == 0 && Rtime[0] > 0) {
        Rtime[1] = 9;
        Rtime[0]--;
      } else {
        Rtime[1]--;
      }
      delay(300);
    }
    //EnterSW 눌리면 EnterValue 1로 변경하고 탈출
    if (digitalRead(EnterSW) == 1) {
      EnterValue = 2;
      delay(500);
      lcd.clear();
    }
    //출력 상태 확인//
    for (int i = 0; i < 4; i++) {
      if (i == 0) {
        lcd.setCursor(0, 2);
        lcd.print("[Min]");
      }
      lcd.print(Rtime[i]);
      if (i == 1) {
        lcd.print(":");
      }
    }
  }
  //초 설정
  while (EnterValue == 2) {
    if (digitalRead(IncreSW) == 1) {
      if (Rtime[2] == 5) {
        Rtime[2] = 0;
      } else {
        Rtime[2]++;
      }
      delay(300);
    }
    if (digitalRead(DecreSW) == 1) {
      if (Rtime[2] == 0) {
        Rtime[2] = 5;
      } else {
        Rtime[2]--;
      }
      delay(300);
    }
    //EnterSW 눌리면 EnterValue 1로 변경하고 탈출
    if (digitalRead(EnterSW) == 1) {
      delay(500);
      for (int i = 0; i < 4; i++) {
        if (i == 0) {
          lcd.setCursor(0, 2);
          lcd.print("[Confirm]");
        }
        lcd.print(Rtime[i]);
        if (i == 1) {
          lcd.print(":");
        }
      }
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Loading...");
      delay(3000);
      lcd.setCursor(0, 0);
      lcd.clear();
      LCD_Main(FanSpeed, Rtime);
    }
    //출력 상태 확인//
    for (int i = 0; i < 4; i++) {
      if (i == 0) {
        lcd.setCursor(0, 2);
        lcd.print("[Sec]");
      }
      lcd.print(Rtime[i]);
      if (i == 1) {
        lcd.print(":");
      }
      if (i == 3) {
        lcd.print(" ");
      }
    }
  }
}



//시간값 배열 감소 함수
void arrTimer(void) {
  if (Rtime[3] > 0) {
    Rtime[3]--;
  } else {
    Rtime[3] = 9;
    if (Rtime[2] > 0) {
      Rtime[2]--;
    } else {
      Rtime[2] = 5;
      if (Rtime[1] > 0) {
        Rtime[1]--;
      } else {
        Rtime[1] = 9;
        if (Rtime[0] > 0) {
          Rtime[0]--;
        }
      }
    }
  }
}


//Timer 시간 감소 함수
void timerCntDwn(void) {
  Serial.println("CNT START");
  timerStartTime = millis();
  while ((Rtime[0] > 0) || (Rtime[1] > 0) || (Rtime[2] > 0) || (Rtime[3] > 0)) {
    if (millis() - timerStartTime == 1000) {
      arrTimer();
      timerStartTime = millis();
      for (int i = 0; i < 4; i++) {
        Serial.print(Rtime[i]);
        if (i == 3) {
          Serial.println();
        }
      }
      LCD_Main(FanSpeed, Rtime);
    }
  }
  lcd.clear();
  delay(300);
  LCD_Main(FanSpeed, Rtime);
}


void setup() {
  //LCD 셋
  lcd.begin(16, 2);  //LCD 패널 활성화 (x, y)개
  LCD_Start(FanSpeed, Rtime);  //LCD 시작화면 함수 호출(선풍기 속도, 예약 종료까지 남은 시간)
  LCD_Main(FanSpeed, Rtime);   //LCD 메인화면 함수 호출
  //Timer 셋업
  pinMode(7, INPUT);   //Enter
  pinMode(8, INPUT);   //num increase
  pinMode(13, INPUT);  //num decrease
  pinMode(9, INPUT);   //start time setting
  Serial.begin(115200);
  LCD_Main(FanSpeed, Rtime);
}

void loop() {
}
