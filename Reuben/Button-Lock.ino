// Initial Date:  28-09-2016
// Project name:  Broodrooster Prime
// Filename:      kookplaat
// Description:   Building a stove

const int buttonPin1 = 1; 
const int buttonPin4 = 4; 
const int buttonPin3 = 3; 
const int buttonPin2 = 2; 		// the pin that the pushbutton is attached to
const int correctLedPin = 7;    // the pin that the LED is attached to
const int wrongLedPin = 6;   
const int motorPin = 11;		// the pin that the LED is attached to

// variables that are changed by the program
int buttonPushCounter = 0;   	// counter for the number of button presses
int val = 0;

int bS1 = 0;   	// current state of the button
int lBS1 = 0; 	// previous state of the button

int bS2 = 0;    // current state of the button
int lBS2 = 0; 

int bS3 = 0;    // current state of the button
int lBS3 = 0; 

int bS4 = 0;    // current state of the button
int lBS4 = 0; 

// configure the pins to the right mode
void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(correctLedPin, OUTPUT);
  pinMode(wrongLedPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

// the main loop will constantly check to see if the button has been pressed
// if it has, a counter is incremented, and then some action can be taken
void loop() {

  // read the state of the button
  static int buttonPushCounter = 0;
  bS1 = digitalRead(buttonPin1);
  bS2 = digitalRead(buttonPin2);
  bS3 = digitalRead(buttonPin3);
  bS4 = digitalRead(buttonPin4);

  // check to see if it different than the last time we checked
  if (bS1 != lBS1) {

    // either the button was just pressed or just released
    if (bS1 == HIGH) {

      // it was just pressed
      buttonPushCounter = buttonPushCounter + 1;
      Serial.println(buttonPushCounter);
      digitalWrite(correctLedPin, HIGH);
      delay(100);
      digitalWrite(correctLedPin, LOW);
      if(val == 0)
      {
        val = 1;
      }
    }
  }
  lBS1 = bS1;


if (bS2 != lBS2) {

    // either the button was just pressed or just released
    if (bS2 == HIGH) {

      // it was just pressed
      buttonPushCounter = buttonPushCounter + 1;
      Serial.println(buttonPushCounter);
      digitalWrite(correctLedPin, HIGH);
      delay(100);
      digitalWrite(correctLedPin, LOW);
      if(val == 1)
      {
        val = 2;
      }
    }
  }
  lBS2 = bS2;


if (bS3 != lBS3) {
    // either the button was just pressed or just released
    if (bS3 == HIGH) {
      // it was just pressed
      buttonPushCounter = buttonPushCounter + 1;
      Serial.println(buttonPushCounter);
      digitalWrite(correctLedPin, HIGH);
      delay(100);
      digitalWrite(correctLedPin, LOW);
      if(val == 2)
      {
        val = 3;
      }
    }
  }
  lBS3 = bS3;


if (bS4 != lBS4) {
    // either the button was just pressed or just released
    if (bS4 == HIGH) {
      // it was just pressed
      buttonPushCounter = buttonPushCounter + 1;
      Serial.println(buttonPushCounter);
      digitalWrite(correctLedPin, HIGH);
      delay(100);
      digitalWrite(correctLedPin, LOW);
      if(val == 3)
      {
        val = 4;
      }
    }
  }
  lBS4 = bS4;

if(val == 4 && buttonPushCounter == 4)
{
  digitalWrite(correctLedPin, HIGH);
  val = 0;
  buttonPushCounter = 0;
  analogWrite(motorPin
}

else if(val != 4 && buttonPushCounter == 4)
{
  digitalWrite(wrongLedPin, HIGH);
  delay(3000);
  digitalWrite(wrongLedPin, LOW);
  val = 0;
    buttonPushCounter = 0;
}


}