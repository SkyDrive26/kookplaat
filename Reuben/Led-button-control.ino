// Initial Date:  26-09-2016
// Project name:  Broodrooster Prime
// Filename:      kookplaat
// Description:   Building a stove
   
const int Pit1 = 2;
const int Pit2 = 3;
const int Pit3 = 4;
const int Pit4 = 5;

int buttonValue;

void setup()
{
  pinMode(Pit1, OUTPUT);
  pinMode(Pit2, OUTPUT);
  pinMode(Pit3, OUTPUT);
  pinMode(Pit4, OUTPUT);
}

void loop()
{
  buttonValue = analogRead(A0); 

  if (buttonValue>=1010 && buttonValue<=1015){
    digitalWrite(Pit1, HIGH);
  }

  else if (buttonValue>=1000 && buttonValue<=1008){
    digitalWrite(Pit2, HIGH);
  }

  else if (buttonValue>=990  && buttonValue<=998){
    digitalWrite(Pit3, HIGH);
  }

  else if (buttonValue>=870  && buttonValue<=880){
    digitalWrite(Pit4, HIGH);
  }

  else{
    digitalWrite(Pit1, LOW);
      digitalWrite(Pit2, LOW);
      digitalWrite(Pit3, LOW);
      digitalWrite(Pit4, LOW);
  }
  delay(100);


}

