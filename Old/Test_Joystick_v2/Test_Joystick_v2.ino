#include <OLED_I2C.h>


OLED  myOLED(SDA, SCL);
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


String StateLog = "";
String BtnLog = "";
String SliderLog = "";
String SwLog = "";
String LjLog = "";
String RjLog = "";



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


  Serial1.begin(9600);
  Serial1.setTimeout(200);

  Serial.begin(9600);

  //configure_transmitter();
  myOLED.begin();
  myOLED.setFont(SmallFont);

}

void loop() {
  Scan();
  Screen();  
  Serial.println(StateLog);
  Serial1.println(StateLog); // закидываем в радиоканал
  
  
  delay (100);

}

CENTER

float Scan()
{

 BtnLog =  String(digitalRead(BTN1)) + "|"
          +String(digitalRead(BTN2)) + "|"
          +String(digitalRead(BTN3)) + "|"
          +String(digitalRead(BTN4)) + "|"
          ;


 SliderLog =  String(analogRead(SLIDER1)) + "|"
             +String(analogRead(SLIDER2)) + "|"
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

StateLog = BtnLog + SliderLog + SwLog + LjLog + RjLog;             
 
}

int Screen() {
  myOLED.clrScr();
  myOLED.print("Voltbro joystick test", LEFT, 0);
  myOLED.print(BtnLog, CENTER, 14);
  myOLED.print(SliderLog, CENTER, 24);
  myOLED.print(SwLog, CENTER, 34);
  myOLED.print(LjLog, CENTER, 44);
  myOLED.print(RjLog, CENTER, 54);
  myOLED.update();
}

void configure_transmitter() {
    Serial.println("Start HC-12 Config");
    digitalWrite(SetPin, LOW);
    delay(500);
    Send_command("AT");
    Send_command("AT+V");
    Send_command("AT+DEFAULT");
    Send_command("AT+C001");
    Send_command("AT+P6");
    //Send_command("AT+B115200");
    Serial.println("Save & Exit");
    digitalWrite(SetPin, HIGH);
  
}

void Send_command(char* ATcommand) {

  Serial1.println (ATcommand);
  Serial.println (ATcommand);
  delay(1000);
  if(Serial1.available() > 0)
    {
        String str = Serial1.readStringUntil('\n');// LF
        Serial.println (str);
    }
  delay(500);  
  }
