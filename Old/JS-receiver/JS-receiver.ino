/* 
 *Формат передачи данных по радио CSJunior2017
 *TeamID;Time;Altitude;A;Start point;Separate point;Recovery point;Landing point \n
 *TeamID –  код команды, 2 символа. Код команды выдается организаторами
 *Time – ms, таймер ардуино (функция millis();)
 *Altitude – Высота в метрах, относительно уровня старта
 *A – Модуль вектора ускорения м/с2
 *Start point - 0 или 1,  должен быть  «1»  после того как вы зафиксировали старт ракеты
 *Separate point  - 0 или 1,  должен быть  «1»  после того как вы зафиксировали отделение отсека полезной нагрузки от первой ступени
 *Recovery  - 0 или 1,  должен быть  «1»  после того как ваша система спасения была активирована
 *Landing  - 0 или 1,  должен быть  «1»  после того как вы зафиксировали приземление отсека полезной нагрузки 
 *\n  - конец строки
 *Пример
 *1A;678903;44.5;9.8;1;0;0;0    // end of line is  ”\n” (LN)

 */

#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];


const unsigned int SET_PIN = 13; // Пин для конфигурации радиомодуля


String  TeamID;
double Time = 0;
float Altitude = 0.00;
float A = 0.00;
int Start = 0;
int Separate = 0;
int Recovery = 0;
int Landing = 0;


String RFlog = "";



void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  myOLED.setFont(SmallFont);
  Serial1.begin(9600);
  Serial1.setTimeout(1000);

  Serial.begin(9600);
  Serial.setTimeout(1000);
  digitalWrite(SET_PIN, HIGH);
}

void loop() {

  GetRF();
  Screen1("TeamID");
  delay(10);

}

void Screen1(String TeamID) {
    myOLED.drawRect(0,0,127,63);
  
    myOLED.print("CH: 20 / 0x14",CENTER,12);
  
   myOLED.drawLine(0, 29, 127, 29);
    myOLED.print("ID: 99",1,31);
    myOLED.print("T: 3604",64,31);
  
  myOLED.drawLine(0, 40, 127, 40);
    myOLED.print("Ac: 9.81",1,42);
    myOLED.print("H: 87.54",64,42);
  
  myOLED.drawLine(0, 51, 127, 51);
    myOLED.print("0",13,54);
    myOLED.drawLine(31, 51, 31, 63);
    myOLED.print("0",44,54);
    myOLED.drawLine(63, 51, 63, 63);
    myOLED.print("0",76,54);
    myOLED.drawLine(94, 51, 94, 63);
    myOLED.print("0",107,54);
  

  myOLED.update();
  }


  void GetRF() {
  if(Serial1.available() > 0)
    {
       RFlog = Serial1.readStringUntil('\n');
       //Serial.println(RFlog);
       
       int CI1 = RFlog.indexOf(';');
       int CI2 = RFlog.indexOf(';', CI1+1);
       int CI3 = RFlog.indexOf(';', CI2+1);
       int CI4 = RFlog.indexOf(';', CI3+1);
       int CI5 = CI4+2;
       int CI6 = CI5+2;
       int CI7 = CI6+2;
       int CI8 = CI7+2;
       

       
       TeamID = RFlog.substring(0, CI1);
       Time = RFlog.substring(CI1+1, CI2).toDouble();
       Altitude = RFlog.substring(CI2+1,CI3).toFloat();
       A = RFlog.substring(CI3+1,CI4).toFloat();

       Start = RFlog.substring(CI4+1, CI5).toInt();
       Separate = RFlog.substring(CI5+1, CI6).toInt();

       Recovery = RFlog.substring(CI6+1,CI7).toInt(); 
       Landing = RFlog.substring(CI7+1,CI8).toInt();
      
       String TestLog = String (TeamID) + "|"
                    + String (Time) + "|"
                    + String (Altitude) + "|"
                    + String (A) + "|"
                    + String (Start) + "|"
                    + String (Separate) + "|"
                    + String (Recovery) + "|"
                    + String (Landing) + "|"
                    ;
                    
      Serial.println(RFlog);
      Serial.println(TestLog);
      Serial.println("---");
  }  
  
}
