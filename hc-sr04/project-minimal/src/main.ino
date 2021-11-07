#include "Arduino.h"

#define LED_PIN 13
#define TRIG_PIN 10 
#define ECHO_PIN 11  

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
  
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {

    led(HIGH);

    // для большей точности установим значение LOW на пине Trig
    digitalWrite(TRIG_PIN, LOW); 
    delayMicroseconds(2); 

    // Теперь установим высокий уровень на пине Trig
    digitalWrite(TRIG_PIN, HIGH);

    // Подождем 10 μs 
    delayMicroseconds(10); 
    digitalWrite(TRIG_PIN, LOW); 

    // Узнаем длительность высокого сигнала на пине Echo
    int duration = pulseIn(ECHO_PIN, HIGH); 

    led(LOW);

    // Рассчитаем расстояние
    int distance = duration / 58;
    // Выведем значение в Serial Monitor
    Serial.print(distance); 
    Serial.println(" cm"); 

    delay(100);

}

void led(boolean enable) {
    digitalWrite(LED_PIN, enable);
}

