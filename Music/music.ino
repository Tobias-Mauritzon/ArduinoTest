
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
int songE[] = {};
int songTempG[] = { q, q/2, q/4, q, q/2, q, q/2, 
                    q, q/2, q/4, q, q/2, q, q/2,
                    q/2, q/2, q/2, q/2, q/2, q/2,
                    q, q, q};
int songTempE[] = {};


void setup()
{
    pinMode(8, OUTPUT);
}

void loop()
{  
    for (byte i = 0; i < (sizeof(songG) / sizeof(songG[0])); i++){
        tone(8, songG[i], songTempG[i]);
        delay(10);
    }
    delay(5000);
}
