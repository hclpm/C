const int analogPin = A0;
const int X = A0;
const int Y = A1;
const int KEY = 3;

void setup() {
  Serial.begin(115200);
  pinMode(KEY, INPUT_PULLUP);
}

void loop() {
  int xValue = analogRead(X);
  int yValue = analogRead(Y);
  int keyValue = digitalRead(KEY);

  Serial.print("X: "); Serial.print(xValue, DEC);
  Serial.print("   Y: "); Serial.print(yValue, DEC);
  Serial.print("   Key: "); Serial.println(keyValue, DEC); 
}
