float Linear = 0.00;
float Angular = 0.00;

int SetPin = 4;


String RFlog = "";



void setup() {
  Serial1.begin(115200);
  Serial1.setTimeout(1000);

  Serial.begin(115200);
  Serial.setTimeout(1000);
  digitalWrite(SetPin, HIGH);
}

void loop() {

  GetRF();
  Serial.print(Linear);
  Serial.print(,);
  Serial.println(Angular);

}



  void GetRF() {
  if(Serial1.available() > 0)
    {
       RFlog = Serial1.readStringUntil('\n');
       //Serial.println(RFlog);
       
       int CI1 = RFlog.indexOf(';');
       int CI2 = RFlog.indexOf(';', CI1+1);

       
       Linear = RFlog.substring(0,CI1).toFloat();
       Angular = RFlog.substring(CI1+1, CI2).toFloat();

       Start = RFlog.substring(CI4+1, CI5).toInt();
       Separate = RFlog.substring(CI5+1, CI6).toInt();

       Recovery = RFlog.substring(CI6+1,CI7).toInt(); 
       Landing = RFlog.substring(CI7+1,CI8).toInt();
      
                    
      Serial.println(RFlog);
      Serial.println("---");
  }  
  
}
