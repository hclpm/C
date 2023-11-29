#define STOP 0
#define CW 1
#define CCW 2


const int MotorE = 3;
const int MotorP = 5;
const int MotorN = 4;

void Motor_cnt(int mode, double sec) {
  switch (mode) {
    case STOP:
      digitalWrite(MotorE, LOW);
      digitalWrite(MotorP, LOW);
      digitalWrite(MotorN, LOW);
      break;
    case CW:
      digitalWrite(MotorE, HIGH);
      digitalWrite(MotorP, HIGH);
      digitalWrite(MotorN, LOW);
      break;
    case CCW:
      digitalWrite(MotorE, HIGH);
      digitalWrite(MotorP, LOW);
      digitalWrite(MotorN, HIGH);
      break;
    default:
      digitalWrite(MotorE, LOW);
      digitalWrite(MotorP, LOW);
      digitalWrite(MotorN, LOW);
  }
  delay(sec * 1000);
}


void setup() {
  pinMode(MotorE, OUTPUT);
  pinMode(MotorP, OUTPUT);
  pinMode(MotorN, OUTPUT);
}

void loop() {
  Motor_cnt(CW, 0.5);
  Motor_cnt(CCW, 0.1);
  Motor_cnt(CW, 0.5);
  Motor_cnt(CCW, 0.1);
  Motor_cnt(STOP, 0.1);
  delay(200);
}
