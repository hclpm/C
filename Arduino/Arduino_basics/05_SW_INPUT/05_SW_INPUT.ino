const uint8_t SW_0 = 2;
const uint8_t LED_0 = 13;

const uint8_t SW_1 = 3;
const uint8_t LED_1 = 12;


int sw = 0;
int pre_sw = 0;
int cur_sw = 0;
int sw1 = 0;
int pre_sw1 = 0;
int cur_sw1 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(SW_0, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(SW_1, INPUT);
  pinMode(LED_1, OUTPUT);

  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);

}

void loop() {
  cur_sw = digitalRead(SW_0);
  if ((pre_sw == LOW) && (cur_sw == HIGH)) {
    if (sw == 0) {
      digitalWrite(LED_0, HIGH);

      sw = 1;
    } else {
      digitalWrite(LED_0, LOW);
      sw = 0;
    }
  }
  pre_sw = cur_sw;
  ///////////////////////////////////////////
  cur_sw1 = digitalRead(SW_1);
  if ((pre_sw1 == LOW) && (cur_sw1 == HIGH)) {
    if (sw1 == 0) {
      digitalWrite(LED_1, HIGH);
      sw1 = 1;
    } else {
      digitalWrite(LED_1, LOW);
      sw1 = 0;
    }
  }
  pre_sw1 = cur_sw1;
}
