#include <Servo.h>
Servo myServo;

// servo motor
// 4 phototransistors for light sensing
// led for light direction
// move led to light source
// if light comes form the bottom light led

const int servoPin = 9;
const int ledPin = 10;

const int photoTop = A0;
const int photoRight = A1;
const int photoLeft = A2;
const int photoBottom = A3; 

int topVal;
int rightVal;
int leftVal;
int bottomVal;

int angle;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  topVal = analogRead(photoTop);
  rightVal = analogRead(photoRight);
  leftVal = analogRead(photoLeft);
  bottomVal = analogRead(photoBottom);

  angle = map(, 0, 1023, 0, 179);

  if (topVal > (rightVal && leftVal && bottomVal)){
    angle = 89;
    digitalWrite(ledPin, LOW);
  }
  else if (rightVal > (topVal && leftVal && bottomVal)){
    angle = 0;
    digitalWrite(ledPin, LOW);
  }
  else if (leftVal > (rightVal && rightVal && bottomVal)){
    angle = 179;
    digitalWrite(ledPin, LOW);
  }else{
    angle = abs(angle - 45) ;
    digitalWrite(ledPin, HIGH);
  }

  Serial.println(angle);
  myServo.write(angle);
  delay(50);
}
