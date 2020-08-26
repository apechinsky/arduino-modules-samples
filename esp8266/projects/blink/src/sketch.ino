
#define LED 13

void setup() {
    Serial.begin(115200);
    pinMode(13, OUTPUT);
}

void loop() {
    Serial.println("On1");
    digitalWrite(LED, HIGH);
    delay(1000);
    
    Serial.println("Off2");
    digitalWrite(LED, LOW);
    delay(1000);
}
