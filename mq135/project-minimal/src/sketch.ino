  
void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(5, INPUT);
}
  
void loop() {

    int analog = analogRead(A0);
    Serial.print(" analog : ");
    Serial.print(analog );

    int digital = digitalRead(5);
    Serial.print(" digital : ");
    Serial.print(digital);
    Serial.println();

    delay(500);
}
