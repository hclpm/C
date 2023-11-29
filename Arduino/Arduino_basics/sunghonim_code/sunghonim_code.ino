#include <Servo.h>

Servo myservo;

#define ir_enter 7
#define ir_back  6
#define ir_car1 5
#define ir_car2 4
#define ir_car3 3
#define ir_car4 2

#define redPin1 A0
#define greenPin1 A1
#define bluePin1 12

#define redPin2 A2
#define greenPin2 A3
#define bluePin2 12

#define redPin3 A4
#define greenPin3 A5
#define bluePin3 12

#define redPin4 13
#define greenPin4 11
#define bluePin4 12

#define redPin5 10
#define greenPin5 8
#define bluePin5 12


int flag1 = 0, flag2 = 0;

int tmp1 = 2000;
int tmp2 = 2000;
int tmp3, tmp4, tmp5, tmp6;
int pos = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);
  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  digitalWrite(greenPin1, 255);
  
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  digitalWrite(greenPin2, 255);

  pinMode(redPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(bluePin3, OUTPUT);
  digitalWrite(greenPin3, 255);

  pinMode(redPin4, OUTPUT);
  pinMode(greenPin4, OUTPUT);
  pinMode(bluePin4, OUTPUT);
  digitalWrite(greenPin4, 255);
    
  pinMode(redPin5, OUTPUT);
  pinMode(greenPin5, OUTPUT);
  pinMode(bluePin5, OUTPUT);


  myservo.attach(9); 
  myservo.write(0);
 
  
}

void loop() {

  

  if (Serial.available() >= 2) {
    tmp1 = Serial.parseInt();
    tmp2 = Serial.parseInt();

    Serial.print("tmp1: ");
    Serial.println(tmp1);
    Serial.print("tmp2: ");
    Serial.println(tmp2);
    
    if (tmp1 == 0 || tmp2 == 0) {
      for(pos = 0; pos <= 90; pos += 1) {
        myservo.write(pos);
        flag1 = 1;
        flag2 = 1;
        delay(15);
      }
    } 
    else if (flag1 == 1 && flag2 == 1) {
         for(pos = 90; pos >= 0; pos -= 1) {
              myservo.write(pos);
              flag1 = 0;
           flag2 = 0; 
             delay(15);
         }
    }
  }
  
  if (Serial.available() >= 4) {
    tmp3 = Serial.parseInt();
    tmp4 = Serial.parseInt();
    tmp5 = Serial.parseInt();
    tmp6 = Serial.parseInt();

    Serial.print("tmp3: ");
    Serial.println(tmp3);
    Serial.print("tmp4: ");
    Serial.println(tmp4);
    Serial.print("tmp5: ");
    Serial.println(tmp5);
    Serial.print("tmp6: ");
    Serial.println(tmp6);
    
      if (tmp3 == 0) {
        digitalWrite(redPin1, HIGH);
        digitalWrite(greenPin1, LOW);
        digitalWrite(bluePin1, LOW);
      } else if(tmp3 == 1) {
        digitalWrite(redPin1, LOW);
        digitalWrite(greenPin1, HIGH);
        digitalWrite(bluePin1, LOW);
      }
    

      if (tmp4 == 0) {
        digitalWrite(redPin2, HIGH);
        digitalWrite(greenPin2, LOW);
        digitalWrite(bluePin2, LOW);
      } else if(tmp4 == 1) {
        digitalWrite(redPin2, LOW);
        digitalWrite(greenPin2, HIGH);
        digitalWrite(bluePin2, LOW);
      }

      if (tmp5 == 0) {
        digitalWrite(redPin3, HIGH);
        digitalWrite(greenPin3, LOW);
        digitalWrite(bluePin3, LOW);
      } else if(tmp5 == 1) {
        digitalWrite(redPin3, LOW);
        digitalWrite(greenPin3, HIGH);
        digitalWrite(bluePin3, LOW);
      }

      if (tmp6 == 0) {
        digitalWrite(redPin4, HIGH);
        digitalWrite(greenPin4, LOW);
        digitalWrite(bluePin4, LOW);
      } else if(tmp6 == 1) {
        digitalWrite(redPin4, LOW);
        digitalWrite(greenPin4, HIGH);
        digitalWrite(bluePin4, LOW);
      }
    }
  
  delay(100);
}