#ifndef _ROS_SERVICE_AddTwoInts_h
#define _ROS_SERVICE_AddTwoInts_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_book_samples
{

static const char ADDTWOINTS[] = "ros_book_samples/AddTwoInts";

  class AddTwoIntsRequest : public ros::Msg
  {
    public:
      typedef uint32_t _x_type;
      _x_type x;
      typedef uint32_t _y_type;
      _y_type y;

    AddTwoIntsRequest():
      x(0),
      y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->x >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      *(outbuffer + offset + 0) = (this->y >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->x =  ((uint32_t) (*(inbuffer + offset)));
      this->x |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->x |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->x |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->x);
      this->y =  ((uint32_t) (*(inbuffer + offset)));
      this->y |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->y |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->y |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->y);
     return offset;
    }

    virtual const char * getType() override { return ADDTWOINTS; };
    virtual const char * getMD5() override { return "64be90712af6ea79ae6f103da824ffcf"; };

  };

  class AddTwoIntsResponse : public ros::Msg
  {
    public:
      typedef uint32_t _sum_type;
      _sum_type sum;

    AddTwoIntsResponse():
      sum(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sum >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sum >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sum >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sum >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sum);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->sum =  ((uint32_t) (*(inbuffer + offset)));
      this->sum |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sum |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sum |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sum);
     return offset;
    }

    virtual const char * getType() override { return ADDTWOINTS; };
    virtual const char * getMD5() override { return "9d46c5ee6500804e92145794264c0ccb"; };

  };

  class AddTwoInts {
    public:
    typedef AddTwoIntsRequest Request;
    typedef AddTwoIntsResponse Response;
  };

}
#endif
