int led=3;
int oldMillis;
int interval=500;

void setup() {
    pinMode(led, OUTPUT);
}

void blink() {
    if (millis()-oldMillis>=interval) {
        digitalWrite(led, HIGH);
        oldMillis=millis();
    }
    else {
        digitalWrite(led, LOW);
    }
}

void loop() {
    blink();
}