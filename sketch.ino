
int minv, maxv;
unsigned long timer;

int sample = 200,
    volume,
    LED = 9;

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    resetv();
}

void loop() {
    
    int current = analogRead(A0);

    if (current > maxv) maxv = current;
    if (current < minv) minv = current;

    if (millis() - timer >= sample) {
        volume = maxv - minv;
        resetv();
    }

    Serial.println(String(volume));

    if (volume > 25) analogWrite(LED, 255);
    else analogWrite(LED, 0);
}

void resetv() {
    maxv = 0;
    minv = 1024;
    timer = millis();
}
