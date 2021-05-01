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

  if (topVal > rightVal && topVal > leftVal && topVal > bottomVal){
    angle = 89;
    digitalWrite(ledPin, LOW);
  }
  else if (rightVal > topVal && rightVal > leftVal && rightVal > bottomVal){
    angle = 0;
    digitalWrite(ledPin, LOW);
  }
  else if (leftVal > rightVal && leftVal > topVal && leftVal > bottomVal){
    angle = 179;
    digitalWrite(ledPin, LOW);
  }else{
    if(!(angle == 44)){
      angle = 44;  
      digitalWrite(ledPin, HIGH);
    }
  }

  Serial.print("Angle: ");
  Serial.println(angle);
  
  Serial.print("TopVal: ");
  Serial.print(topVal);
  
  Serial.print(" RightVal: ");
  Serial.print(rightVal);
  Serial.print(" LeftVal: ");
  Serial.print(leftVal);
  Serial.print(" BottomVal: ");
  Serial.println(bottomVal);
  myServo.write(angle);
  delay(1000);
}
