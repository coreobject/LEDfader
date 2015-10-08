const int ledCount=6;
byte leds[ledCount] = {3, 5, 6, 9, 10, 11};
byte ledsVal[ledCount] = {10,60,120,160,200,255};
byte ledsDir[ledCount] = {0, 1, 2, 1, 1, 2};
int x;
const int interval = 5;
int previousMillis;
void setup() {
    // put your setup code here, to run once:
    for (int i = 0; i < ledCount; i++){
        pinMode(i, OUTPUT);
    }
    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        //Serial.println(ledsDir[2]);
        pulseLED();
        x++;
        //Serial.println(x);
        previousMillis = currentMillis;
    }
}

void pulseLED() {
    for (int i = 0; i < ledCount; i++) {
        switch(ledsDir[i]){
            case 0:
                if (ledsVal[i] > 0) ledsVal[i]--;
                break;
            case 1:
                ledsVal[i]++;
                if (ledsVal[i] >= 255) ledsDir[i] = 2;
                break;
            case 2:
                ledsVal[i]--;
                if (ledsVal[i] <= 0) ledsDir[i] = 1;
                break;
            default:
                Serial.println("default");
                break;
        }
        analogWrite(leds[i], ledsVal[i]);
    }
    /*
        Serial.print(leds[2]);
        Serial.print("\t");
        Serial.println(ledsVal[2]);
        */
}
