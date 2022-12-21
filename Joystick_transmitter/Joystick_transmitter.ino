#define BTN3 12

#define SLIDER1 A5

#define LJX A4
#define LJY A3

#define SetPin 13


String StateLog = "";
String BtnLog = "";
String SliderLog = "";
String LjLog = "";


void setup() {


  pinMode(BTN3, INPUT);

  pinMode(SLIDER1, INPUT);
   
  pinMode(LJX, INPUT);
  pinMode(LJY, INPUT);

  pinMode(SetPin, OUTPUT);
  digitalWrite(SetPin, HIGH);


  Serial1.begin(9600);
  Serial1.setTimeout(200);

  Serial.begin(9600);
}

void loop() {
  Scan();
  Serial.println(StateLog);
  Serial1.println(StateLog); // закидываем в радиоканал
  
  
  delay (100);

}

float Scan()
{

 BtnLog = String(digitalRead(BTN3)) + ";"
          ;

 SliderLog =  String(analogRead(SLIDER1)) + ";"
             ;
          
 LjLog =   String(analogRead(LJX) - 512) + ";"
          +String(analogRead(LJY)- 512)
          ;
        
StateLog = BtnLog + SliderLog + LjLog;             
 
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
