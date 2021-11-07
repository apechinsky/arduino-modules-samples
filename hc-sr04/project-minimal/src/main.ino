#define TRIG_PIN 10 
#define ECHO_PIN 11  

#define SOUND_SPEED_AT_20_DEGREE 340

void setup() {
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {

    float distance = getDistance(SOUND_SPEED_AT_20_DEGREE);

    Serial.print(distance * 100); 
    Serial.println(" cm"); 

    delay(500);
}

/**
 * Measures and returns distance in meters.
 *
 * @param soundSpeed sound speed
 */
float getDistance(float soundSpeed) {
    // ensure low level on trig pin
    digitalWrite(TRIG_PIN, LOW); 
    delayMicroseconds(2); 

    // set high level for 10 microseconds
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10); 
    digitalWrite(TRIG_PIN, LOW); 

    // read signal return duration in microseconds
    int duration = pulseIn(ECHO_PIN, HIGH); 

    // compute distance
    return soundSpeed * duration / 1000000 / 2;
}

