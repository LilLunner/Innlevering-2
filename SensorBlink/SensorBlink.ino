int led=3;
int sensor=A1;
int oldMillis;
int oldSignalMillis;
int interval=500;
int timeAverage=5;
int result=0;
int counter=0;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(sensor, INPUT);
}

void signal() {
    int reading=analogRead(sensor);
    if (millis()-oldSignalMillis>=1000) {
        result=result+reading;
        counter++;
        oldSignalMillis=millis();
    }
}

void blink() {
    if(counter>=timeAverage) {
        interval=result/counter;
        counter=0;
    }
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
    signal();
}