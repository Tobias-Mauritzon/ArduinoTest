#include <Servo.h>
Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;
int knockVal;
int switchVal;
const int quietKnock = 10;
const int loudKnock = 100;
boolean locked = false;
int numberOfKnocks = 0;

void setup(){
    myServo.attach(9);
    pinMode(yellowLed,OUTPUT);
    pinMode(redLed,OUTPUT);
    pinMode(greenLed,OUTPUT);
    pinMode(switchPin,INPUT);

    digitalWrite(greenLed, HIGH);
    myServo.write(0);
}

void loop(){
    if(locked == false){
        switchVal = digitalRead(switchPin);
        if(switchVal == HIGH){
            locked = true;
            digitalWrite(greenLed, LOW);
            digitalWrite(redLed, HIGH);
            myServo.write(90);
            delay(1000);
        }
    }

    if(locked == true){
        knockVal = analogRead(piezo);
        if(numberOfKnocks < 3 && knockVal > 0){
            if(checkForKnocks(knockVal) == true){
                numberOfKnocks++;
            }
        }

        if(numberOfKnocks >= 3){
            locked = false;
            myServo.write(0);
            delay(20);
            digitalWrite(greenLed, HIGH);
            digitalWrite(redLed, LOW);
            numberOfKnocks = 0;
        }
    }
}

boolean checkForKnocks(int val){
    if(val > quietKnock && val < loudKnock){
        digitalWrite(yellowLed, HIGH);
        delay(50);
        digitalWrite(yellowLed, LOW);
        return true;
    }else{
        return false;
    }
}