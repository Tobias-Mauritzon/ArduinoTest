const int greenLed = 2;
const int yellowLed = 3;

void setup(){
    Serial.begin(9600);  
    pinMode(greenLed, OUTPUT);  
    pinMode(yellowLed, OUTPUT);  
}

void loop(){
    Serial.print("Potential: ");
    int val = analogRead(A0)/4;
    Serial.println(val);

    if(val < 125 && val > 0){
        digitalWrite(yellowLed, HIGH);
        digitalWrite(greenLed, LOW);
    }else if(val >= 125){
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, HIGH);
    }else{
        digitalWrite(yellowLed, HIGH);
        digitalWrite(greenLed, HIGH);
    }
    delay(1000);
}
