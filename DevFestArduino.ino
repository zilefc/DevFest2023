#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3);


int motor2Pin1 = 6;
int motor2Pin2 = 7;

int motor1Pin1 = 4;
int motor1Pin2 = 5;


void setup() {

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);
  delay(500);
}

void loop() {

  if (BT.available() > 0) {
    int state = BT.read();
    Serial.println(state);
    switch (state) {
      case 2:
        forword()
        break;
      case 4:
        turnLeft();
        break;
       case 6:
       turnright();
       break;
       case 8:
       backword();
       break;
       case 0:
       Stop();
       break;
    }



    delay(1);
  }
}
void forword() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void backword() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void Stop() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
