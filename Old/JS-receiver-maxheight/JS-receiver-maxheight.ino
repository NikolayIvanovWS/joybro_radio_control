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


#define SW1 7

OLED  myOLED(SDA, SCL, 8);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


const unsigned int SET_PIN = 13; // Пин для конфигурации радиомодуля



float Altitude = 0.00;
String RFlog = "";
float max_h, cur_h;



void setup() {
  // put your setup code here, to run once:
  myOLED.begin();
  myOLED.setFont(BigNumbers);
  Serial1.begin(9600);
  Serial1.setTimeout(1000);

  Serial.begin(9600);
  Serial.setTimeout(1000);
  digitalWrite(SET_PIN, HIGH);
  pinMode(SW1, INPUT);
}

void loop() {

  GetRF();
myOLED.clrScr();

  delay(30);


  if (digitalRead(SW1) == true) {
    myOLED.print(String(max_h),CENTER,12);
    }
  else
    {
    myOLED.print(String(cur_h),CENTER,12);
    }
  myOLED.update();
  
  }


  void GetRF() {
  if(Serial1.available() > 0)
    {
       RFlog = Serial1.readStringUntil('\n');
       Serial.println(RFlog);
       cur_h = RFlog.toFloat();

       if ( cur_h > max_h) {
         max_h = cur_h;
       }
                    
     
      Serial.println(max_h);
      Serial.println("---");
  }  
  
}
