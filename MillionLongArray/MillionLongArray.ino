
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
// 1000 long is close to max size
char arr[1000];

// output pins;
int pinGreen = 1;
int pinRed = 2;
int pinYellow = 3;

void setup()
{


    // fills the array
    char c; 
    for(int i = 0; i < 1000; i++){
        c = (rand() % 2 + 1);
        arr[i] = c;

    }

    // init pins
    
    // init console
    Serial.begin(9600);
}

void loop()
{
    //Loop through the array and light a led acording to pin
    
    for(char c : arr){
        // Maybe i should add a delay here
        if(c == pinGreen){
            Serial.println("Green Pin: "+c);
        }else if(c == pinRed){
            Serial.println("Red Pin: "+c);
        }else{
            Serial.println("Yellow Pin: "+c);
        }
    }
}
