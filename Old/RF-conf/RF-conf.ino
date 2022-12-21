
#include <string.h>

int SetPin = A5; // Пин для конфигурации радиомодуля
String str;


void setup() {
    
  pinMode(SetPin, OUTPUT);
    
  Serial1.begin(9600);
  Serial1.setTimeout(200);

  Serial.begin(9600);
  delay (3000);


  configure_transmitter();
  Serial.println("Done");
  Serial.println("\n");

  Serial.println("Start sending test data, one time per second");
  Serial.println("\n");
  

}

void loop() {
   delay(1000);
   Serial.println("Hello from HC-11/12");
   Serial1.println("Hello from HC-11/12");
}


void configure_transmitter() {
  Serial.println("Start HC-12 Config");
  digitalWrite(SetPin, LOW);
  delay(500);
  Send_command("AT");
  Send_command("AT+V");
  //Send_command("AT+DEFAULT");
  //Send_command("AT+B9600");
  //Send_command("AT+P6");
  Send_command("AT+C010");
  Serial.println("Save & Exit");
  digitalWrite(SetPin, HIGH);
  
}

void Send_command(char* ATcommand) {

  Serial1.println (ATcommand);
  Serial.println (ATcommand);
  delay(1000);
  if(Serial1.available() > 0)
    {
        str = Serial1.readStringUntil('\n');// LF
        Serial.println (str);
    }
  delay(500);  
  }


