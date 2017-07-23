// Example of using the Grove Mini Fan on an Arduino Uno with Grove Shield

// Connect the Grove mini fan on PIN D5 on the Grove Shield (this needs to be an pwm enabled pin)
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
