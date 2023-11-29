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

void setup() {
  // BUZZER
  pinMode(8, OUTPUT);


  // IR 수신 시작
  irrecv.enableIRIn();

  Serial.begin(9600);
  ON_buzzer();
  //"decode" 함수 내 광고 문구 실행
  // if (irrecv.decode(&results)) {}
}

void ON_buzzer(void) {
  tone(Buzzer, 225, 1000);
  results.value = 0;
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("results.value: ");
    Serial.println(results.value);
    irrecv.resume();
  }
}
