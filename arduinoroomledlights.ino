int BA;
int celsius = 0;
bool tempOff = true;


const int delayTime = 400;


red = 0;
LEDredon = false;

green = 0;
LEDgreenon = false;

blue = 0;
LEDblueon = false;

cyan = 0;
LEDcyanon = false;

rgb = 0;
LEDrgbon = false;
red = 0;

green = 0;

blue = 0;

turnOnAll = 0;

turnOffAll = 0;
void setup()
{
  Serial.begin(9600);
pinMode(red, OUTPUT);

pinMode(green, OUTPUT);

pinMode(blue, OUTPUT);

pinMode(cyan, OUTPUT);

pinMode(rgb, OUTPUT);
pinMode(red, INPUT_PULLUP);

pinMode(green, INPUT_PULLUP);

pinMode(blue, INPUT_PULLUP);

pinMode(turnOnAll, INPUT_PULLUP);

pinMode(turnOffAll, INPUT_PULLUP);
}


void loop()

{
if(digitalRead(red) == HIGH){
      turnOnAllLights();
  } else {
    turnOffAllLights();
  }

if(digitalRead(green) == HIGH){
      turnOnAllLights();
  } else {
    turnOffAllLights();
  }

if(digitalRead(blue) == HIGH){
      turnOnAllLights();
  } else {
    turnOffAllLights();
  }

if(digitalRead(turnOnAll) == HIGH){
      turnOnAllLights();
  } else {
    turnOffAllLights();
  }

if(digitalRead(turnOffAll) == HIGH){
      turnOnAllLights();
  } else {
    turnOffAllLights();
  }

   celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

 Serial.print(celsius);
 Serial.println(" °C");
  if (celsius > 30){
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


 delay(delayTime); // delay for 'delayTime' milliseconds
}


void turnOnAllLights(){
 digitalWrite(red,HIGH);

 digitalWrite(green,HIGH);

 digitalWrite(blue,HIGH);

 digitalWrite(cyan,HIGH);

 digitalWrite(rgb,HIGH);
}

void turnOffAllLights(){
 digitalWrite(red,LOW);

 digitalWrite(green,LOW);

 digitalWrite(blue,LOW);

 digitalWrite(cyan,LOW);

 digitalWrite(rgb,LOW);
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


