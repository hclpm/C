const uint8_t SW_0 = 2;
const uint8_t LED_0 = 13;

const uint8_t SW_1 = 3;
const uint8_t LED_1 = 12;

int LED1 = 0;
int LED2 = 0;


void SW0_Pressed(void) {
  if (LED1 == 0) {
    digitalWrite(LED_0, HIGH);
    LED1 = 1;
  } else {
    digitalWrite(LED_0, LOW);
    LED1 = 0;
  }
}

void SW1_Pressed(void) {
  if (LED2 == 0) {
    digitalWrite(LED_1, HIGH);
    LED2 = 1;
  } else {
    digitalWrite(LED_1, LOW);
    LED2 = 0;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(SW_0, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(SW_1, INPUT);
  pinMode(LED_1, OUTPUT);

  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);

  attachInterrupt(digitalPinToInterrupt(SW_0), SW0_Pressed, RISING);  //(현상발생위치, 실행함수, 조건)
  attachInterrupt(digitalPinToInterrupt(SW_1), SW1_Pressed, RISING);  //(현상발생위치, 실행함수, 조건)
}

void loop() {

}
