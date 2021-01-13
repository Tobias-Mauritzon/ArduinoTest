
void setup(){
    Serial.begin(9600);    
}

void loop(){
    Serial.print("Potential: ");
    Serial.println(analogRead(A0)/4);
    delay(1000);
}
