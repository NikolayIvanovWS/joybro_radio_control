#ifndef _ROS_turtlebro_RawOdom_h
#define _ROS_turtlebro_RawOdom_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebro
{

  class RawOdom : public ros::Msg
  {
    public:
      typedef uint64_t _timestamp_type;
      _timestamp_type timestamp;
      typedef int32_t _left_ticks_type;
      _left_ticks_type left_ticks;
      typedef int32_t _right_ticks_type;
      _right_ticks_type right_ticks;
      typedef float _theta_type;
      _theta_type theta;

    RawOdom():
      timestamp(0),
      left_ticks(0),
      right_ticks(0),
      theta(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->timestamp >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->timestamp >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->timestamp >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->timestamp >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->timestamp >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timestamp);
      union {
        int32_t real;
        uint32_t base;
      } u_left_ticks;
      u_left_ticks.real = this->left_ticks;
      *(outbuffer + offset + 0) = (u_left_ticks.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_ticks.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_ticks.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_ticks.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_ticks);
      union {
        int32_t real;
        uint32_t base;
      } u_right_ticks;
      u_right_ticks.real = this->right_ticks;
      *(outbuffer + offset + 0) = (u_right_ticks.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_ticks.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_ticks.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_ticks.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_ticks);
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.real = this->theta;
      *(outbuffer + offset + 0) = (u_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->timestamp =  ((uint64_t) (*(inbuffer + offset)));
      this->timestamp |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timestamp |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->timestamp |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->timestamp |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->timestamp |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->timestamp);
      union {
        int32_t real;
        uint32_t base;
      } u_left_ticks;
      u_left_ticks.base = 0;
      u_left_ticks.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_ticks.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_ticks.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_ticks.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_ticks = u_left_ticks.real;
      offset += sizeof(this->left_ticks);
      union {
        int32_t real;
        uint32_t base;
      } u_right_ticks;
      u_right_ticks.base = 0;
      u_right_ticks.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_ticks.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_ticks.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_ticks.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_ticks = u_right_ticks.real;
      offset += sizeof(this->right_ticks);
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.base = 0;
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->theta = u_theta.real;
      offset += sizeof(this->theta);
     return offset;
    }

    virtual const char * getType() override { return "turtlebro/RawOdom"; };
    virtual const char * getMD5() override { return "a711e872d66081f9ddc66aa47fcb1035"; };

  };

}
#endif
