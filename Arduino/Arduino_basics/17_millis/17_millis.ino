
unsigned long t_prev = 0;
const unsigned long t_delay = 1000;

unsigned long t2_prev = 0;
const unsigned long t2_delay = 500;


void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long t_now = millis();
  if (t_now - t_prev >= t_delay) {
    t_prev = t_now;
    Serial.print(t_now / 1000);
    Serial.println(" sec");
  }
  //////////t2
  unsigned long t2_now = millis();
  if (t2_now - t2_prev >= t2_delay) {
    t2_prev = t2_now;
    Serial.println(t2_now / 1000);
  }
}