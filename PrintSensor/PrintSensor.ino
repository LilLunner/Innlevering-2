int sensor=A1;
int signalArray[10];


void setup() {
    pinMode(sensor, INPUT);
    Serial.begin(9600);
}

void signalPrint() {
    for (int i=0; i<=9; i++) {
        signalArray[i]=analogRead(sensor);
    }
    Serial.println(signalArray[10]);
}

void loop() {
    signalPrint();
    delay(1000);
}