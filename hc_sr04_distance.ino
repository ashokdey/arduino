
#define ECHO 6
#define TRIGGER 7

int time_in_micro = 0;
int distance_in_cm = 0;
int distance_in_meter = 0;


void setup() {
  Serial.begin(9600);

  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);

}

void loop () {

  // emit signal
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGER, LOW);

  // receive signal
  time_in_micro = pulseIn(ECHO, HIGH);

  distance_in_cm = ((time_in_micro / 29) / 2);

  Serial.println(distance_in_cm);
  Serial.println(distance_in_meter);

  delay(500);

}
