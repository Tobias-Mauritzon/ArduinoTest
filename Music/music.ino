
int bpm = 60;

int q = 500; // Quarter note

int R = 0;

int F = 349;
int E = 329;
int D = 293;
int C = 261;
int B = 493;
int A = 440;
int G = 391;
int F2 = 349;
int E2 = 329;

int songG[] = { G + B/2, G, G, G + B/2, D/2, B, D/2, 
                G + B/2, G, G, G + B/2, D/2, B, D/2,
                G, F/2, G, A, B + G, A + C,
                B + D, B + D, R};

int songJ[] = { C, D, E, C, 
                C, D, E, C, 
                E, F, G,
                E, F, G,
                G, A*2, G, F, E, C,
                G, A*2, G, F, E, C,
                C, G/2, C, 
                C, G/2, C};

int songE[] = {};
int songTempG[] = { q, q/2, q/4, q, q/2, q, q/2, 
                    q, q/2, q/4, q, q/2, q, q/2,
                    q/2, q/2, q/2, q/2, q/2, q/2,
                    q, q, q};

int songTempJ[] = { q, q, q, q,
                    q, q, q, q,
                    q, q, q*2,
                    q, q, q*2,
                    q/2, q/2, q/2, q/2, q, q,
                    q/2, q/2, q/2, q/2, q, q,
                    q, q, q*2,
                    q, q, q*2};

int songTempE[] = {};


void setup()
{
   Serial.begin(9600);
}

void loop()
{  
    for (byte i = 0; i < (sizeof(songJ) / sizeof(songJ[0])); i++){
        tone(8, songJ[i]);
        Serial.print(songJ[i]);
        Serial.print("  ");
        Serial.println(songTempJ[i]);
        delay(songTempJ[i]);
        noTone(8);
        delay(10);
    }
    delay(5000);
}
