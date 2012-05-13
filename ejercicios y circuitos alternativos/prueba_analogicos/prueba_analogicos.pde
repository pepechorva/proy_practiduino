void setup() {
  Serial.begin(9600); 
}

void loop() {
         for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            Serial.print("analog input ");
            Serial.print(analogChannel);
            Serial.print(" is ");
            Serial.println(analogRead(analogChannel));
          }
            Serial.print("\n");


  delay(2000);
}

