
int sensorValue;
int sensorflow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup()
{
  // put your setup code here, to run once:
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, HIGH);

 while(millis() < 5000){
     sensorValue = analogRead(A0);
 }
}

void loop()
{
  
}