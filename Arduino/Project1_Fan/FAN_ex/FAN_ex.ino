#include "LiquidCrystal.h"  // Text LCD 라이브러리 함수
#include <IRremote.h>
#include <Servo.h>

// servo
Servo servo;
int RotationVal = 0;
int RotationAngle = 0;
int rotationStartTime = 0;


// buzzer
const int Buzzer = 8;  // 262, 294, 330, 393, 440, 494, 523(C D E F G A B)
// DC_MOTOR
const int moPin1 = 11;
const int moPin2 = 10;
int count = 0;  // 버튼 누른 횟수
int state = 0;
//motor millis

unsigned long cntmillis = 0;

const long interval1 = 300;
const long interval2 = 500;


// IRRecv
const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;


//LCD 전역변수
LiquidCrystal lcd(0, 1, 4, 5, 6, 7);  //아두이노-LCD 선 연결
int FanSpeed = 1;                     //선풍기 속도

int signal = -1;

// Start // Increase // Decrease // Enter //

int EnterValue = 0;    //Enter가 몇번 눌러졌는지. 1이면 시간, 2이면 분 설정으로도 사용할 것
int Rtime[4] = { 0 };  //time array
//Rtime[0][1] : [2][3];

//Main화면 Timer 감소 전역변수
unsigned long timerStartTime = 0;  //타이머가 시작한 시간

// 전역 스피드
int fspeed = 1;

int signalVal(void) {
  if (irrecv.decode(&results)) {
    signal = results.value;
    irrecv.resume();
  }
  return signal;
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
    if (signalVal() == 4) {
      if (Rtime[1] == 9) {
        Rtime[1] = 0;
        Rtime[0]++;
      } else {
        Rtime[1]++;
      }
      delay(300);
    }
    if (signalVal() == 5) {
      if (Rtime[1] == 0 && Rtime[0] > 0) {
        Rtime[1] = 9;
        Rtime[0]--;
      } else {
        Rtime[1]--;
      }
      delay(300);
    }
    //EnterSW 눌리면 EnterValue 1로 변경하고 탈출
    if (signalVal() == 6) {
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
    if (signalVal() == 4) {
      if (Rtime[2] == 5) {
        Rtime[2] = 0;
      } else {
        Rtime[2]++;
      }
      delay(300);
    }
    if (signalVal() == 5) {
      if (Rtime[2] == 0) {
        Rtime[2] = 5;
      } else {
        Rtime[2]--;
      }
      delay(300);
    }
    //EnterSW 눌리면 EnterValue 1로 변경하고 탈출
    if (signalVal() == 6) {
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
      // LCD_Main(FanSpeed, Rtime);
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
  timerStartTime = millis();
  if ((Rtime[0] > 0) || (Rtime[1] > 0) || (Rtime[2] > 0) || (Rtime[3] > 0)) {
    if (millis() - timerStartTime == 1000) {
      arrTimer();
      timerStartTime = millis();
      for (int i = 0; i < 4; i++) {
        Serial.print(Rtime[i]);
        if (i == 3) {
          Serial.println();
        }
      }
      fanMain();
    }
  }
  delay(300);
}

void fanRotation(void) {
  if (RotationVal == 1) {
    rotationStartTime = millis();
    if (millis() - rotationStartTime == 100) {
      if (RotationAngle < 180) {
        RotationAngle++;
        servo.write(RotationAngle);
      } else if (RotationAngle >= 180) {
        if (RotationAngle == 360) {
          RotationAngle = 0;
        } else {
          RotationAngle--;
        }
        servo.write(360 - RotationAngle);
      }
    }
  }
}

void ON_buzzer(void) {
  tone(Buzzer, 440);
  delay(500);
  noTone(Buzzer);
}

int power = 0;

void fanSetting(void) {
  if (irrecv.decode(&results)) {
    if (results.value == 0) {
      if (power == 1) {
        Serial.println("Power -> 0");
        power = 0;
      } else if (power == 0) {
        Serial.println("Power -> 1");
        power = 1;
      }
    } else if (results.value == 1) {  //신호[1] 받으면 RotationVal 0, 1 변환
      if (RotationVal == 0) {
        Serial.println("rotationVal -> 1");
        RotationVal = 1;
      } else if (RotationVal == 1) {
        Serial.println("rotationVal -> 0");
        RotationVal = 0;
      }
    } else if (results.value == 2) {
      if (fspeed == 1) {
        Serial.println("speed -> 2");
        fspeed = 2;
      } else if (fspeed == 2) {
        Serial.println("speed -> 3");
        fspeed = 3;
      } else if (fspeed == 3) {
        Serial.println("speed -> 1");
        fspeed = 1;
      }
      //신호[2] 받으면 fspeed 1 -> 2 -> 3 -> 1 변환
    } else if (results.value == 3) {
      setTimer();
    }
    irrecv.resume();
  }
}

void fan(void) {
  Serial.print("fspeed : " );
  Serial.println(fspeed);
  if(fspeed == 1){
      Serial.println("1");
      analogWrite(moPin1, 255);
      analogWrite(moPin2, 140);
      Serial.println("1 finish");
  }
  else if(fspeed == 2){
      Serial.println("1");
      analogWrite(moPin1, 255);
      analogWrite(moPin2, 50);
      Serial.println("1 finish");
  }
  // switch (fspeed) {
  //   case 1:
  //     Serial.println("1");
  //     analogWrite(moPin1, 255);
  //     analogWrite(moPin2, 140);
  //     Serial.println("1 finish");
  //     aa();
  //     break;
  //   case 2:
  //     Serial.println("2");
  //     analogWrite(moPin1, 255);
  //     analogWrite(moPin2, 50);
  //     break;
  //   case 3:
  //     Serial.println("3");
  //     analogWrite(moPin1, 255);
  //     analogWrite(moPin2, 0);
  //     break;
  // }
}

void aa(){
  Serial.println("aa");
}

void fanMain(void) {
  while (power == 1) {
    fan();
    for (int i = 0; i < 4; i++) {
      Serial.print(Rtime[i]);
      if (i == 3) {
        Serial.println();
      } else if (i == 1) {
        Serial.print(":");
      }
    }
    if ((Rtime[0] > 0) || (Rtime[1] > 0) || (Rtime[2] > 0) || (Rtime[3] > 0)) {
      timerCntDwn();
    }
  }
}

void setup() {
  // IR 수신 시작
  irrecv.enableIRIn();
  // BUZZER
  pinMode(8, OUTPUT);
  // servo
  servo.attach(9);  // 9번 핀에 PWM 선 연결
  // DC_MOTOR
  pinMode(moPin1, OUTPUT);
  pinMode(moPin2, OUTPUT);
  Serial.begin(9600);
  //receiver interrupt
  attachInterrupt(digitalPinToInterrupt(RECV_PIN), fanSetting, FALLING);
  //만약에 millis 잘 안풀리면 delay로 하고 fan Rotation, fanSpeedSet 인터럽트로 하기
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 0 && power == 0) {
      power = 1;
      //fanMain();
      if (power == 1) {
        fan();
        // for (int i = 0; i < 4; i++) {
        //   Serial.print(Rtime[i]);
        //   if (i == 3) {
        //     Serial.println();
        //   } else if (i == 1) {
        //     Serial.print(":");
        //   }
        // }
        // if ((Rtime[0] > 0) || (Rtime[1] > 0) || (Rtime[2] > 0) || (Rtime[3] > 0)) {
        //   timerCntDwn();
        // }
      }
    }
    irrecv.resume();
  }
}