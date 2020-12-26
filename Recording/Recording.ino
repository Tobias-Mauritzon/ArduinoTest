// Temp sensor analog in
int tmp36 = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(tmp36,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float analogReading = analogRead(tmp36);
  Serial.print("Analog: " + String(analogReading));

  //Convert
  float tempVoltage = analogReading * 5.0 / 1023.0;
  Serial.println(" & Volt: " + String(tempVoltage));

  delay(2000);

  float tempC = (tempVoltage - 0.5) * 100;
  Serial.println(String(tempC) + " Celcius\n");

  delay(3000);
}
