int led=3;
int button=4;
int oldMillis;
int interval=100;
int oldBlinkMillis;
int currentMillis;
int lastButtonMillis;
bool lastButtonState=LOW;
bool mode=LOW;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
}

void blink() {
    if (mode=HIGH) {
        interval=10;
    }
    else {
        interval=100;
    } 
    if (millis()-oldBlinkMillis>=interval) {
        digitalWrite(led, HIGH);
        oldBlinkMillis=millis();
    }
    else {
        digitalWrite(led, LOW);
    }
}

void buttonPress() {
    bool buttonState=digitalRead(button);
    while (buttonState==HIGH) {
        currentMillis=millis();
        lastButtonState=buttonState;
        buttonState=digitalRead(button);
        }
    if (buttonState != lastButtonState && currentMillis-lastButtonMillis <= 1000) {
        mode=HIGH;
    }
    else {
        mode=LOW;
    }
    lastButtonMillis=millis();
    lastButtonState=LOW;
}

void loop() {
    blink();
}