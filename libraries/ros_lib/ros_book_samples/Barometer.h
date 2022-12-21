#ifndef _ROS_ros_book_samples_Barometer_h
#define _ROS_ros_book_samples_Barometer_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_book_samples
{

  class Barometer : public ros::Msg
  {
    public:
      typedef uint64_t _pressure_type;
      _pressure_type pressure;
      typedef float _temperature_type;
      _temperature_type temperature;

    Barometer():
      pressure(0),
      temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pressure >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pressure >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pressure >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->pressure >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->pressure >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->pressure >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->pressure >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pressure);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->pressure =  ((uint64_t) (*(inbuffer + offset)));
      this->pressure |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pressure |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pressure |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->pressure |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->pressure |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->pressure |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->pressure);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
     return offset;
    }

    virtual const char * getType() override { return "ros_book_samples/Barometer"; };
    virtual const char * getMD5() override { return "60c40281ef0003af83e27ba096cbc048"; };

  };

}
#endif
