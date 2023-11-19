// MS EDIT
#include <IRremote.h>
#include <Servo.h>

// buzzer
const int Buzzer = 8;  // 262, 294, 330, 393, 440, 494, 523(C D E F G A B)

// IRRecv
const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

int fspeed = 1;
// DC_MOTOR
const int moPin1 = 11;
const int moPin2 = 10;
int count = 0;  // 버튼 누른 횟수
int state = 0;

// power global rotate global
int power = 0;
int RotationVal = 0;

//buzzer
int cur_buzzer = 0;
int prev_buzzer = 0;

void fan(void) {
  if (power == 1) {
    switch (fspeed) {
      case 1:
        analogWrite(moPin1, 255);
        analogWrite(moPin2, 140);
        break;
      case 2:
        analogWrite(moPin1, 255);
        analogWrite(moPin2, 50);
        break;
      case 3:
        analogWrite(moPin1, 255);
        analogWrite(moPin2, 0);
        break;
    }
  } else if (power == 0) {
    analogWrite(moPin1, 0);
    analogWrite(moPin2, 0);
  }
  if (irrecv.decode(&results)) {
    fanSetting();
    irrecv.resume();
  }
}

void fanSetting(void) {
  Serial.print("rVAl: ");
  Serial.println(results.value);
  if (results.value == 0x00) {
    // Serial.print("파워상태: ");
    // Serial.println(power);
    if (power == 1) {
      Serial.println("Power -> 0");
      delay(1500);
      power = 0;
      // tone(Buzzer, 440, 1000);
    } else if (power == 0) {
      Serial.println("Power -> 1");
      delay(1500);
      power = 1;
      // tone(Buzzer, 225, 1000);
    }
  } else if (results.value == 0x01) {  //신호[1] 받으면 RotationVal 0, 1 변환
    if (RotationVal == 0) {
      Serial.println("rotationVal -> 1");
      RotationVal = 1;
    } else if (RotationVal == 1) {
      Serial.println("rotationVal -> 0");
      RotationVal = 0;
    }
  } else if (results.value == 0x02) {
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
  } else if (results.value == 0x03) {
    //setTimer();
  }
}

void ON_buzzer(void) {
  tone(Buzzer, 225, 1000);
  noTone(Buzzer);
}

void OFF_buzzer(void) {
  tone(Buzzer, 440, 1000);
  noTone(Buzzer);
}


void setup() {
  // BUZZER
  pinMode(8, OUTPUT);

  // IR 수신 시작
  irrecv.enableIRIn();

  // DC_MOTOR
  pinMode(moPin1, OUTPUT);
  pinMode(moPin2, OUTPUT);

  Serial.begin(9600);

  //"decode" 함수 내 광고 문구 실행
  if (irrecv.decode(&results)) {}
}

void loop() {
  fan();
}
