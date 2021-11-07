#include <OneWire.h>
#include <DallasTemperature.h>

// 
// Demonstrates distance measure with temperature correction
// Sound speed depends on temperature (331.5 at 0 celsius degree).
// Speed changes by 0.6m/s for each degree (faster if air is warmer).
// 

#define TRIG_PIN 10 
#define ECHO_PIN 11  

DallasTemperature dallas(new OneWire(3));

void setup() {
    Serial.begin(9600);
  
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    dallas.begin();
}

void loop() {

    float temperature = getTemperature();
    Serial.print(temperature); 
    Serial.print("\t"); 

    int speed = getSoundSpeed(temperature);
    Serial.print(speed); 
    Serial.print("\t" ); 

    float distance = getDistance(speed);

    Serial.print(distance * 100); 
    Serial.println(" cm"); 

    delay(500);
}

float getTemperature() {
    dallas.requestTemperatures();
    return dallas.getTempCByIndex(0);
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

/**
 * Returns sound speed for specified temperature.
 *
 * @param temperature temperature
 * @return sound speed in m/s
 */
float getSoundSpeed(float temperature) {
    const float SOUND_SPEED_AT_ZERO = 331.5;
    const float SOUND_SPEED_DELTA_PER_DEGREE = 0.6;

    return SOUND_SPEED_AT_ZERO + (SOUND_SPEED_DELTA_PER_DEGREE * temperature);
}
