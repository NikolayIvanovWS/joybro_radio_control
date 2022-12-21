
int SetPin = 40; // Set pin HC-12
String str;


void setup() {
    
  pinMode(SetPin, OUTPUT);
    
  Serial2.begin(9600);
  Serial2.setTimeout(200);

  Serial.begin(9600);
  /*
  while (!Serial) {
      ; // wait for Serial Port on USB
  }
 */

  configure_transmitter();
  Serial.println("Done");
  Serial.println("\n");

  Serial.println("Start sending test data, one time per second");
  Serial.println("\n");
  

}

void loop() {
   Serial2.println("1");
   delay(50);
}  


void configure_transmitter() {
  Serial.println("Start HC-12 Config");
  digitalWrite(SetPin, LOW);
  delay(500);
  Send_command("AT");
  Send_command("AT+V");
  Send_command("AT+DEFAULT");
  //Send_command("AT+P8");
  //Send_command("AT+C060");  //Set channel  001 - 099
  //Send_command("AT+B115200");
  Serial.println("Save & Exit");
  digitalWrite(SetPin, HIGH);
  
}

void Send_command(char* ATcommand) {

  Serial2.println (ATcommand);
  Serial.println (ATcommand);
  delay(1000);
  if(Serial2.available() > 0)
    {
        str = Serial2.readStringUntil('\n');
        Serial.println (str);
    }
  delay(500);  
  }
