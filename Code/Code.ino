// Initial Date:  09-09-2016
// Patch Date:    04-10-2016
// Patch Writer:  Daan van Bennekom
// Project name:  Broodrooster Prime
// Filename:      kookplaat
// Description:   Building a stove

// Imported libraries

// Pin Declarations
const int buttonSelect = 4;                                              // Button used for selecting which furnace you're using
const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;;

//Variablen
int pL[] = {0, 0, 0, 0};                                                  // Values pitten links
int pR[] = {0, 0, 0, 0};                                                  // Values pitten rechts

boolean buttonRechts = false;                                             // Boolean to store buttonSelect value
byte shift[] = {B0000, B0000, B0000, B0000, B0000, B0000, B0000, B0000};  // Byte array that holds all values that need to be shifted

// Initial Setup
void setup() {
  Serial.begin(9600);
  Serial.write("Welcome to Broodrooster Furnace!");

  /* Declaring some pinmodes */
  pinMode(buttonSelect, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  /* Initial shift to write a decimal 0 to all 7-segments */
  shift_it();
}

// Main Loop
void loop() {

  /* Detect if button select has been pressed and if so change boolean */
  if(digitalRead(buttonSelect) == HIGH && !buttonRechts){
    buttonRechts = true;
  }else if(digitalRead(buttonSelect) == HIGH && buttonRechts){
    buttonRechts = false;
  }

  /* Decide which pitten array has to be used and proceed with controlling it */
  if(!buttonRechts){
    /* Decide which button has been pressed and change array value */  
    /* Use array pL[] */  
  }else{
    /* Decide which button has been pressed and change array value */
    /* Use array pR[] */
  }

  get_binary();
  shift_it();
  
}

/*  Function get_binary() converts every value in pL[] and pR[]
 *  into their corresponding binary values and stores them in the
 *  right slot of shift[].
 */
void get_binary(){
  for(int i = 0; i < 8 ; i++){
    if(i >= 4){
      int j = i - 4;

      switch(pR[j]){
        case 0:
          shift[i] = B0000;
          break;
        case 1:
          shift[i] = B0001;
          break;
       case 2:
          shift[i] = B0010;
          break;
       case 3:
          shift[i] = B0011;
          break;
       case 4:
          shift[i] = B0100;
          break;
       case 5:
          shift[i] = B0101;
          break;
       case 6:
          shift[i] = B0110;
          break;
       case 7:
          shift[i] = B0111;
          break;
       case 8:
          shift[i] = B1000;
          break;
       case 9:
          shift[i] = B1001;
          break;
      }
    }else{
      switch(pR[i]){
        case 0:
          shift[i] = B0000;
          break;
        case 1:
          shift[i] = B0001;
          break;
       case 2:
          shift[i] = B0010;
          break;
       case 3:
          shift[i] = B0011;
          break;
       case 4:
          shift[i] = B0100;
          break;
       case 5:
          shift[i] = B0101;
          break;
       case 6:
          shift[i] = B0110;
          break;
       case 7:
          shift[i] = B0111;
          break;
       case 8:
          shift[i] = B1000;
          break;
       case 9:
          shift[i] = B1001;
          break;
      }
    }
  }
}

/*  Function shift_it() uses the byte array shift[] to
 *  shift out the binaray values to the the shiftrergisters. 
 */
void shift_it(){
  digitalWrite(latchPin, LOW);
  for(int i = 0; i < 8; i++){
    shiftOut(dataPin, clockPin, MSBFIRST, shift[i]);
  }
  digitalWrite(latchPin, HIGH);
}

