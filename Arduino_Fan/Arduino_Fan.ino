// Example of using the Grove Mini Fan on an Arduino Uno (without Grove Shield)

// Connect the Grove mini fan to Arduino:
// Yellow to PIN D5 on Arduino
// White to PIN D6 on Arduino
// Red to 5V on Arduino
// Black to GND on Arduino

int fanPin = 5;

// analog pin, so values between 0 to 1023
int speedOn = 1000; 
int speedOff = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // init serial link for debugging
  pinMode(fanPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(fanPin, speedOn);
  delay(2000);
  analogWrite(fanPin, speedOff);
  delay(2000);
}
