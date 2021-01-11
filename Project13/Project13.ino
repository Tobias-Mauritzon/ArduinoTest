#include <CapacitiveSensor.h>
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;


void setup(){
    myServo.attach(9);
    pinMode(yellowLed,OUTPUT);
    pinMode(redLed,OUTPUT);
    pinMode(greenLed,OUTPUT);
    pinMode(switchPin,INPUT);
    Serial.begin(9600);

    digitalWrite(greenLed, HIGH);
    myServo.write(0);
}

void loop(){
  
}


