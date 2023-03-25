// controlling RGB LED and a Servo motor with a potentiometer 

#include <Servo.h>

#define RED 13
#define GREEN 12 
#define BLUE 11

#define DELAY 100

int servo_pin = 3;
int servo_delay = 1000;

int pot_pin = A0;
int pot_val = 0;


Servo my_servo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  my_servo.attach(servo_pin);

  // set RGB pins as o/p

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // set pot as i/p
  pinMode(pot_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot_val = analogRead(pot_pin);
  int pot_val_servo = pot_val;

  // use this for RGB LED
  pot_val = map(pot_val, 0, 1023, 0, 5);

  // use this for servo
  pot_val_servo = map(pot_val_servo, 0, 1023, 0, 180);

  Serial.println(pot_val);
  Serial.println(pot_val_servo);

  my_servo.write(pot_val_servo);
  delay(DELAY);

  if (pot_val >= 4) {
    blink_rb();
  } else if (pot_val >= 3) {
    blink_rg();
  } else if (pot_val >= 1) {
    blink_bg();
  } else {
    blink_white();
  }
}


void blink_rb() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);

  delay(DELAY);
}

void blink_rg () {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);

  delay(DELAY);
}

void blink_bg () {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  delay(DELAY);
}

void blink_white() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  delay(DELAY);
}
