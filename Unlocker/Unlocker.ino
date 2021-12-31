
#include <Servo.h>
Servo myServo;

const int servoPin = 9;
const int ledPinRed = 10;
const int ledPinYellow = 8;
const int ledPinGreen = 7;

const int piezo = A0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  
  myServo.attach(servoPin);

}

void loop() {
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinYellow, LOW);
  digitalWrite(ledPinGreen, LOW);
  boolean knocked1 = false;
  boolean knocked2 = false;
  boolean knocked3 = false;
  int firstDelay = 1000;
  int secondDelay = 2000;
  int thirdDelay = 3000;
  
  delay(firstDelay);
  digitalWrite(ledPinRed, HIGH);
  
  for(int i = 0; i<1000; i++){
    int piezoVal = analogRead(piezo);
    if(piezoVal > 10){
      knocked1 = true;
      digitalWrite(ledPinRed, LOW);
      Serial.print("piezoVal: ");
      Serial.println(piezoVal);  
    }
    delay(1);
  }
  

  delay(secondDelay);
  for(int i = 0; i<1000; i++){
    int piezoVal = analogRead(piezo);
    if(piezoVal > 10){
      knocked2 = true;
      digitalWrite(ledPinYellow, HIGH);
      Serial.print("piezoVal: ");
      Serial.println(piezoVal);  
    }
    delay(1);
  }
  
  
  delay(thirdDelay);
  for(int i = 0; i<1000; i++){
    int piezoVal = analogRead(piezo);
    if(piezoVal > 10){
      knocked3 = true;
      digitalWrite(ledPinGreen, HIGH);
      Serial.print("piezoVal: ");
      Serial.println(piezoVal);  
    }
    delay(1);
  }

  boolean unlock = knocked1 & knocked2 & knocked3;

  if(unlock){
    Serial.println("Angle: 180");
    myServo.write(180);
    delay(1000);
  }else{
    Serial.println("Angle: 0");
    myServo.write(0);
    delay(1000);
  }
  

}
