int rLEDpin = 4;
int gLEDpin = 3;
int bLEDpin = 2;
int buttonApin = 9;
int buttonBpin = 8;
int rButtonpin = 10;
int gButtonpin = 11;
int bButtonpin = 12;
int BA;
int celsius = 0;
bool tempOff = true;
bool rLEDon = false;
bool gLEDon = false;
bool bLEDon = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(rLEDpin, OUTPUT);
  pinMode(gLEDpin, OUTPUT);
  pinMode(bLEDpin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
  pinMode(rButtonpin, INPUT_PULLUP);  
  pinMode(gButtonpin, INPUT_PULLUP);  
  pinMode(bButtonpin, INPUT_PULLUP);  
  pinMode(A0, INPUT);
}



void loop() 
    
{
  
  
  if(digitalRead(buttonBpin) == HIGH){
    if(digitalRead(buttonApin) == LOW){
      turnOnAllLights();
    }
    rLEDon=toggleOneLight(rButtonpin,rLEDpin,rLEDon);
    gLEDon=toggleOneLight(gButtonpin,gLEDpin,gLEDon);
    bLEDon=toggleOneLight(bButtonpin,bLEDpin,bLEDon);
  } else {
    turnOffAllLights();
  }
  
   celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

 Serial.print(celsius);
 Serial.println(" °C");
  if (celsius > 20){
    if(tempOff){
        turnOnAllLights();
        tempOff = false;
    }
  } else {
    if(!tempOff) {
        turnOffAllLights();
        tempOff = true;
    }
  }
  
 delay(500); // delay for 500 milliseconds
}

void turnOnAllLights(){
      digitalWrite(rLEDpin,HIGH);
      digitalWrite(gLEDpin,HIGH);
      digitalWrite(bLEDpin,HIGH);
}

void turnOffAllLights(){
    digitalWrite(rLEDpin,LOW);
    digitalWrite(gLEDpin,LOW);
    digitalWrite(bLEDpin,LOW);
}

bool toggleOneLight(int buttonPin,int LEDpin,bool LEDon){
  if(digitalRead(buttonPin)==LOW){
    if (!LEDon){
        digitalWrite(LEDpin,HIGH);
      return !LEDon;
    } else {
      digitalWrite(LEDpin,LOW);
      return !LEDon;
    }
  }
  return LEDon;
}


