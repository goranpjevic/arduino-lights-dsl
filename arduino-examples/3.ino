int rLEDpin = 4;
int gLEDpin = 3;
int bLEDpin = 2;
int rButtonpin = 10;
int gButtonpin = 11;
int bButtonpin = 12;
int BA;
bool rLEDon = false;
bool gLEDon = false;
bool bLEDon = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(rLEDpin, OUTPUT);
  pinMode(gLEDpin, OUTPUT);
  pinMode(bLEDpin, OUTPUT);
  pinMode(rButtonpin, INPUT_PULLUP);  
  pinMode(gButtonpin, INPUT_PULLUP);  
  pinMode(bButtonpin, INPUT_PULLUP);  
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
  
 delay(100); // delay for 100 milliseconds
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


