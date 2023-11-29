#include <TimerOne.h>

int fnd_data[9] = { 2, 3, 4, 5, 6, 7, 8 };  // 2~8, a~g
const int fnd_digit[6] = { A0, A1, A2, A3, A4, A5 };
const int num[10][7] = { { 1, 1, 1, 1, 1, 1, 0 }, { 0, 1, 1, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1, 0, 1 }, { 1, 1, 1, 1, 0, 0, 1 }, { 0, 1, 1, 0, 0, 1, 1 }, { 1, 0, 1, 1, 0, 1, 1 }, { 1, 0, 1, 1, 1, 1, 1 }, { 1, 1, 1, 0, 0, 1, 0 }, { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 0, 0, 1, 1 } };

int num1 = 0;

void display_init(void) {
  for (int i = 2; i <= 8; i++) {
    pinMode(fnd_data[i], OUTPUT);
    digitalWrite(fnd_data[i], LOW);
  }
  for (int j = 0; j < 6; j++) {
    pinMode(fnd_digit[j], OUTPUT);
    digitalWrite(fnd_digit[j], LOW);
  }
}

void clear(void) {
  for (int i = 2; i <= 8; i++) {
    digitalWrite(fnd_data[i], LOW);
  }
}

void display_number(int number, int digit) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(fnd_digit[i], HIGH);
  }
  digitalWrite(fnd_digit[digit - 1], LOW);
  for (int i = 0; i < 7; i++) {
    digitalWrite(fnd_data[i + 2], num[number][i]);
  }
  delay(3);
  clear();
}

void display_numbers(unsigned long number) {
  unsigned long num_100000 = number / 100000;
  unsigned long num_10000 = number % 100000 / 10000;
  unsigned long num_1000 = number % 10000 / 1000;
  unsigned long num_100 = number % 1000 / 100;
  unsigned long num_10 = number % 100 / 10;
  unsigned long num_1 = number % 10;
  display_number(num_100000, 1);
  display_number(num_10000, 2);
  display_number(num_1000, 3);
  display_number(num_100, 4);
  display_number(num_10, 5);
  display_number(num_1, 6);
}
//ISR fuction
void timerIsr(void){
  num1++;
}


void setup() {

  display_init();
  Serial.begin(115200);
  Timer1.initialize(1000000/100);
  Timer1.attachInterrupt(timerIsr);
}

void loop() {
  display_numbers(44011);
}
