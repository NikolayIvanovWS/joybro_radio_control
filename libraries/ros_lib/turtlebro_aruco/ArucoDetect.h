#ifndef _ROS_SERVICE_ArucoDetect_h
#define _ROS_SERVICE_ArucoDetect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebro_aruco
{

static const char ARUCODETECT[] = "turtlebro_aruco/ArucoDetect";

  class ArucoDetectRequest : public ros::Msg
  {
    public:

    ArucoDetectRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return ARUCODETECT; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ArucoDetectResponse : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;
      typedef uint16_t _size_type;
      _size_type size;

    ArucoDetectResponse():
      id(0),
      size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size >> (8 * 1)) & 0xFF;
      offset += sizeof(this->size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      this->size =  ((uint16_t) (*(inbuffer + offset)));
      this->size |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->size);
     return offset;
    }

    virtual const char * getType() override { return ARUCODETECT; };
    virtual const char * getMD5() override { return "63199263e85758037a78817aec147b5b"; };

  };

  class ArucoDetect {
    public:
    typedef ArucoDetectRequest Request;
    typedef ArucoDetectResponse Response;
  };

}
#endif
