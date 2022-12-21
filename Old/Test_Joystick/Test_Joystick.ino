#include <OLED_I2C.h>


OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];


// Wiring

#define BTN1 A0
#define BTN2 13
#define BTN4 12
#define BTN5 5

#define POT2 A3
#define POT4 8

#define SW1 6
#define SW2 7
#define SW3 11

#define LJX A1
#define LJY A2
#define LJS A4

#define RJX 10
#define RJY 9
#define RJS 4

#define SetPin A5


String StateLog = "";
String BtnLog = "";
String PotLog = "";
String SwLog = "";
String LjLog = "";
String RjLog = "";



void setup() {


  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN4, INPUT);
  pinMode(BTN5, INPUT);

  pinMode(POT2, INPUT);
  pinMode(POT4, INPUT);
  
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


  Serial1.begin(9600);
  Serial1.setTimeout(200);

  Serial.begin(9600);

  myOLED.begin();
  myOLED.setFont(SmallFont);

}

void loop() {
  Scan();
  myOLED.clrScr();
  myOLED.print("Voltbro joystick test", LEFT, 0);
  myOLED.print(BtnLog, CENTER, 14);
  myOLED.print(PotLog, CENTER, 24);
  myOLED.print(SwLog, CENTER, 34);
  myOLED.print(LjLog, CENTER, 44);
  myOLED.print(RjLog, CENTER, 54);
  myOLED.update();
  
  delay (100);

}



float Scan()
{

 BtnLog =  String(digitalRead(BTN1)) + "|"
          +String(digitalRead(BTN2)) + "|"
          +String(digitalRead(BTN4)) + "|"
          +String(digitalRead(BTN5)) + "|"
          ;


 PotLog =  String(analogRead(POT2)) + "|"
          +String(analogRead(POT4)) + "|"
          ;

 SwLog =   String(digitalRead(SW1)) + "|"
          +String(digitalRead(SW2)) + "|"
          +String(digitalRead(SW3)) + "|"
          ;
          
 LjLog =   String(analogRead(LJX)) + "|"
          +String(analogRead(LJY)) + "|"
          +String(digitalRead(LJS)) + "|"
          ;
          
 RjLog =   String(analogRead(RJX)) + "|"
          +String(analogRead(RJY)) + "|"
          +String(digitalRead(RJS))
          ;

StateLog = BtnLog + PotLog + SwLog + LjLog + RjLog;             


    Serial.println(StateLog);
    Serial1.println(StateLog); // закидываем в радиоканал

 
}


