#include <OLED_I2C.h>


OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];


// Wiring

#define BTN1 A0
#define BTN2 A1
#define BTN3 12
#define BTN4 11

#define SLIDER1 A5
#define SLIDER2 8

#define SW1 7
#define SW2 6
#define SW3 5

#define LJX A4
#define LJY A3
#define LJS A2

#define RJX 9
#define RJY 10
#define RJS 4

#define SetPin 13


int LY;
int RX;
String msg;




void setup() {


  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);

  pinMode(SLIDER1, INPUT);
  pinMode(SLIDER2, INPUT);
  
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  
  pinMode(LJX, INPUT);
  pinMode(LJY, INPUT);
  pinMode(LJS, INPUT);

  pinMode(RJX, INPUT);
  pinMode(RJY, INPUT);
  pinMode(RJS, INPUT);

  pinMode(SetPin, OUTPUT);
  digitalWrite(SetPin, HIGH);


  Serial1.begin(115200);
  Serial1.setTimeout(200);

  Serial.begin(115200);

  myOLED.begin();
  myOLED.setFont(SmallFont);

}

void loop() {

if (digitalRead(SW1) == 0) {
  LY = map(analogRead(LJY),0,1023,-100,100);
  RX = map(analogRead(RJX),0,1023,-100,100);
  if (LY>-10 and LY <10 ) LY = 0; 
  if (RX>-10 and RX <10 ) RX = 0; 
  msg = String(LY)+";"+String(RX);
  Serial1.println(msg);
  Serial.println(msg);
  myOLED.clrScr();
  myOLED.print(msg, LEFT, 0);
  myOLED.update();
  delay (100);
} else {
  
    myOLED.clrScr();
    myOLED.update();
    delay (100);
  }


  

}



