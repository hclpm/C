
const int SW1 = { 7 };
const int SW2 = { 8 };
const int SW3 = { 13 };
int Rtime[4] = { 0 };
int time_millis = 0;
int time = 0;
unsigned long long t_now = 0;


void setup() {
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(13, INPUT);
  Serial.begin(115200);
}

void loop() {
  time_millis = millis();
  time = time_millis / 1000;
  if (digitalRead(7) == HIGH) {
    t_now = time;
  }
}
