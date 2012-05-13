/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
int B=9;
int G=10;
int R=11;
void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(R, OUTPUT);     
  pinMode(G, OUTPUT);     
  pinMode(B, OUTPUT);     
}

void loop() {
  digitalWrite(R, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(R, LOW);    // set the LED off
  delay(1000);              // wait for a second
  digitalWrite(R, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(R, LOW);    // set the LED off
  delay(1000);              // wait for a second
  digitalWrite(G, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(G, LOW);    // set the LED off
  delay(1000);              // wait for a second
  digitalWrite(B, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(B, LOW);    // set the LED off
  delay(1000);              // wait for a second

}
