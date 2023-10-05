int green=2;
int blue=3;
int red=4;
int sensor=A1;
int button=5;
bool lastButtonState=LOW;
int lastMillis;
int debouceTimer=200;
bool buttonState;
int signal;

void setup() {
    for (int i=2; i<5; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(sensor, INPUT);
    pinMode(button, INPUT);
}

void color() {
    signal=(analogRead(sensor))/4;
    for (int i=2; i<6; i++) {
        digitalWrite(i, signal);
    }
}

void buttonPress() {
    bool buttonState=digitalRead(button);
    if (buttonState != lastButtonState && millis()-lastMillis <= debouceTimer) {
        buttonState=LOW;
        lastMillis=millis();
    }
    
    if (buttonState==HIGH) {
        for (int i=signal; i>=0; i--) {
            signal=signal-1;
            for (int j=2; j<5; j++ ) {
                digitalWrite(j, signal);
                delay(10);
            }

        }
    }
    

}

void loop () {
    color();
    buttonPress();
}