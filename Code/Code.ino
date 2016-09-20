// Initial Date:  09-09-2016
// Project name:  Broodrooster Prime
// Filename:      kookplaat
// Description:   Building a stove

// Imported libraries

// Pin Declarations
int pinTempLow = A0;
int pinTempUp = A1;

int tempLow[] = {0, 0, 0, 0, 0, 0, 0, 0}; 

// Initial Setup
void setup() {
  //Serial.read(9600);
}

// Main Loop
void loop() {

  // Measure Temp low button value
  switch(analogRead(pinTempLow)){
    case 0:
      tempLow[0]--;
      break;
    case 1:
      tempLow[1]--;
      break;
    case 2:
      tempLow[2]--;
      break;
    case 3:
      tempLow[3]--;
      break;
    case 4:
      tempLow[4]--;
      break;
    case 5:
      tempLow[5]--;
      break;
    case 6:
      tempLow[6]--;
      break;
    case 7:
      tempLow[7]--;
      break;
  }

}

