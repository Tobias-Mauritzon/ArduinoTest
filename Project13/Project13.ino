#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int threshold = 1000;
const int ledPin = 12;



void setup(){
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
}

void loop(){
    long sensorValue = capSensor.capacitiveSensor(30);
    Serial.print(sensorValue);

    if(sensorValue < threshold){
        digitalWrite(ledPin, HIGH);
    }else{
        digitalWrite(ledPin, LOW);
    }
    delay(10);
}


