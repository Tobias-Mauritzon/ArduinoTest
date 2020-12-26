
int switchState = 0;
const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(2, INPUT);

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
}

void loop()
{
    // put your main code here, to run repeatedly:

    switchState = digitalRead(2);
    int sensorVal = analogRead(sensorPin);
    Serial.println("Sensor Value: " + String(sensorVal) + ", Volts:");

    float tempVoltage = sensorVal * 5.0 / 1023.0;

    Serial.print(String(tempVoltage) + ", degres C: ");

    float tempC = (tempVoltage - 0.5) * 100;
    Serial.print(tempC);

    if (switchState == LOW)
    {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
    }
    else
    {
        if (tempC < baselineTemp + 2)
        {
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
        }
        else if (tempC >= baselineTemp + 4 && tempC < baselineTemp + 6)
        {
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
        }
        else if (tempC >= baselineTemp + 6)
        {
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
        }
    }
    delay(5);
}