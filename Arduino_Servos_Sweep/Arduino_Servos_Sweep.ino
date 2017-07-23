
// Sweep motion
// Button turns the sweeping on and off

#include <Servo.h>

// servos
Servo servoLR;  // create servo object to control a servo - can move Left <> Right
Servo servoTD;  // create servo object to control a servo - can move Top <> Down
int pos = 0;    // variable to store the servo position

// button
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
int newButtonState = 0;
bool active = false;


void setup() {
  servoLR.attach(9);  // attaches the servo on pin to the servo object
  servoTD.attach(10);  // attaches the servo on pin to the servo object
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void sweep() {
  // step 1
  
  servoTD.write(155);
  delay(15);
  for (pos = 45; pos <= 135; pos += 1) {
    servoLR.write(pos);
    delay(15);
  }

  // step 2

  for (pos = 155; pos >= 115; pos -= 1) {
    servoTD.write(pos);
    delay(15);
  }

  // step 3

  for (pos = 135; pos >= 115; pos -= 1) {
    servoLR.write(pos);
    delay(15);
  }

  // step 4

  for (pos = 115; pos >= 90; pos -= 1) {
    servoTD.write(pos);
    delay(15);
  }

  // step 5

  for (pos = 115; pos >= 75; pos -= 1) {
    servoLR.write(pos);
    delay(15);
  }

  // step 6

  for (pos = 90; pos <= 115; pos += 1) {
    servoTD.write(pos);
    delay(15);
  }

  // step 7

  for (pos = 75; pos >= 45; pos -= 1) {
    servoLR.write(pos);
    delay(15);
  }

  // step 8

  for (pos = 115; pos <= 155; pos += 1) {
    servoTD.write(pos);
    delay(15);
  }
}

void loop() {
  newButtonState = digitalRead(buttonPin);
   
   if (newButtonState != buttonState) {
    if (newButtonState == HIGH) {
      // time to change things
      active = !active;
    }
    buttonState = newButtonState;
   }

   Serial.println(newButtonState);
    
   if (active == true) {
        sweep();
   }
}

