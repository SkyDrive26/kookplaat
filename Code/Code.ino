// Initial Date:  09-09-2016
// Project name:  Broodrooster Prime
// Filename:      kookplaat
// Description:   Building a stove

// Imported libraries

// Pin Declarations
int buttonSelect = 4;                                                   // Button used for selecting which furnace you're using

int pL[] = {0, 0, 0, 0};                                                // Values pitten links
int pR[] = {0, 0, 0, 0};                                                // Values pitten rechts

// Variablen
boolean buttonsRechts = false;                                          // Boolean to store buttonSelect value


// Initial Setup
void setup() {
  Serial.read(9600);
  
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
  
}
