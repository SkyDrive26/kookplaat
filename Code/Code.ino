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

// Variablen
int pL[] = {5, 5, 5, 5};                                                  // Values pitten links
int pR[] = {5, 5, 3, 3};                                                  // Values pitten rechts

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
  //shift_it();
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
      switch(pL[i]){
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
    shiftUit(dataPin, clockPin, shift[i]);
  }
  digitalWrite(latchPin, HIGH);
}

/* Function to shift 4-bit into the shiftregister */
// the heart of the program
void shiftUit(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  /*digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);*/

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i=3; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else { 
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}

