#include <ros.h>
#include <geometry_msgs/Twist.h>

class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial1, 115200){};
};
ros::NodeHandle_<NewHardware>  nh;

geometry_msgs::Twist velocity_msg;
ros::Publisher pub("/cmd_vel", &velocity_msg);

int SetPin = 40;

String joy_data = "";
int BTN3 = 0;
int SLIDER1 = 0;
int LJX = 0;
int LJY = 0;
double max_linear_vel = 0.5; //0.35
double max_angular_vel = 1.50; //2.00
double linear_vel = 0.00;
double angular_vel = 0.00;
int threshold = 40; //зона "нуля" левого стика


void setup() {
  
  pinMode(SetPin, OUTPUT);
  digitalWrite(SetPin, HIGH);
    
  Serial2.begin(9600);
  Serial2.setTimeout(200);

  Serial.begin(9600);

  nh.initNode();
  nh.advertise(pub);

}

void loop() {

  getPos();
  delay (10);

}

float getPos()
{
  if(Serial2.available() > 0) {
      joy_data = Serial2.readStringUntil('\n');

      int CI1 = joy_data.indexOf(';');
      int CI2 = joy_data.indexOf(';', CI1+1);
      int CI3 = joy_data.indexOf(';', CI2+1);
      int CI4 = joy_data.indexOf(';', CI3+1);

      BTN3 = joy_data.substring(0, CI1).toInt();
      SLIDER1 = joy_data.substring(CI1+1, CI2).toDouble();
      LJX = joy_data.substring(CI2+1,CI3).toDouble();
      LJY = joy_data.substring(CI3+1,CI4).toDouble();  


      if(BTN3 == 1)
      {
        if(abs(LJY) > threshold)
        {
          linear_vel = ((LJY/512.0)*max_linear_vel)*(SLIDER1/1024.0);
        }
        else
        {
          linear_vel = 0.0;
        }

        if(abs(LJX) > threshold)  
        { 
          angular_vel = -((LJX/512.0)*max_angular_vel)*(SLIDER1/1024.0);
        }
        else
        {
          angular_vel = 0.0;
        }
      }
      else
      {
        linear_vel = 0.0;
        angular_vel = 0.0;
      }


      velocity_msg.linear.x = linear_vel;
      velocity_msg.angular.z = angular_vel;

      pub.publish( &velocity_msg );
      nh.spinOnce();


      //Serial.println(joy_data);
      //Serial.println(linear_vel);
      //Serial.println(angular_vel);
  }

}