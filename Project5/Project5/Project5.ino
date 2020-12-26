#include <Servo.h>
Servo myServo;

int const portPin = A0;
int portVal;
int angle;

void setup()
{
  // put your setup code here, to run once:
  myServo.attach(9);

  Serial.begin(9600);
}

void loop()
{
  portVal = analogRead(portPin);
  Serial.print("portVal: ");
  Serial.print(portVal);

  angle = map(portVal, 0, 1023, 0, 179);
  Serial.print(". angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
