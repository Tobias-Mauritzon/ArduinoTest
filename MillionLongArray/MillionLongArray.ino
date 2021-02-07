
/*
*   What would happen if i make an array with one million elements and 
*   fill it with chars or maybe integers and do something with the numbers,
*   will arduino run the code.
*   
*   Update there is not enough dynamic memory but i can hard code it
*   if i use chars or booleans.
*   
*   It could have maybe worked if there was a bit type.
*/

// intit array
// 1000 long is close to max size for dynamic memory on the arduino
unsigned char arr[1000];

// output pins;
int pinGreen = 2;
int pinRed = 3;
int pinYellow = 4;

int potentiometer = A0;
int sensorValue = 0;
int loopDelay = 10;

void setup()
{


    // fills the array
    char c; 
    for(int i = 0; i < 1000; i++){
        c = (rand() % 3 + 2);
        arr[i] = c;

    }

    // init pins
    pinMode(pinGreen,OUTPUT);
    pinMode(pinRed,OUTPUT);
    pinMode(pinYellow,OUTPUT);
    // init console
    Serial.begin(9600);
}

void loop()
{
    //Loop through the array and light a led acording to pin
    
    for(char c : arr){
        //Read potentiometer for new daly
        sensorValue = analogRead(potentiometer);
        if(potentiometer > 10){
            loopDelay = sensorValue;
        }
        
        
        // Maybe i should add a delay here
        delay(loopDelay);

        //Prints loop delay in ms
        Serial.println("Delay in ms "+ String(loopDelay));
        
        if(c == pinGreen){
            //Ligth LEDs
            digitalWrite(pinGreen,HIGH);
            digitalWrite(pinRed,LOW);
            digitalWrite(pinYellow,LOW);

            Serial.println("Green Pin: "+ String(pinGreen));
        }else if(c == pinRed){
            digitalWrite(pinGreen,LOW);
            digitalWrite(pinRed,HIGH);
            digitalWrite(pinYellow,LOW);

            Serial.println("Red Pin: "+ String(pinRed));
        }else{
            digitalWrite(pinGreen,LOW);
            digitalWrite(pinRed,LOW);
            digitalWrite(pinYellow,HIGH);

            Serial.println("Yellow Pin: "+ String(pinYellow));
        }
    }
}
