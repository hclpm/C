const int analogPin = A0;
const int LED0 = 10;


void setup() {
  Serial.begin(115200);
  pinMode(LED0, OUTPUT);
}

void loop() {
 int analogValue = analogRead(analogPin);
 float V = 5.0 * analogValue / 1024;
 Serial.print("A Value: ");Serial.print(analogValue);Serial.print("     ");Serial.print(V); Serial.println(" V");
 
 analogWrite(LED0, map(analogValue, 0, 1023, 0, 50));
}
