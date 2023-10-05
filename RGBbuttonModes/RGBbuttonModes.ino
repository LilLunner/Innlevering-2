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
int counter=0;

void setup() {
    for (int i=2; i<5; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(sensor, INPUT);
    pinMode(button, INPUT);
}

void color() {
    if (counter==0) {
        for (int i=2; i<6; i++) {
            digitalWrite(i, signal);
            if (digitalRead(button)==HIGH) {
                break;
            }
        }
    }
}

void fade() {
    if (counter==1){
     for (int i=signal; i>=0; i--) {
        if (digitalRead(button)==HIGH) {
            break;
        }
            signal=signal-1;
            for (int j=2; j<5; j++ ) {
                digitalWrite(j, signal);
                if (digitalRead(button)==HIGH) {
                    break;
                }
                delay(10);
            }

        }
    }
}

void buttonPress() {
    bool buttonState=digitalRead(button);
    if (buttonState != lastButtonState && millis()-lastMillis <= debouceTimer) {
        buttonState=LOW;
        lastMillis=millis();
    }
    
    if (buttonState==HIGH) {
        counter++;
        if (counter>=2) {
            counter=0;
        }
    }
}

void loop () {
    signal=(analogRead(sensor))/4;
    color();
    buttonPress();
}