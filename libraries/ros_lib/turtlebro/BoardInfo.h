#ifndef _ROS_SERVICE_BoardInfo_h
#define _ROS_SERVICE_BoardInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Empty.h"
#include "std_msgs/String.h"

namespace turtlebro
{

static const char BOARDINFO[] = "turtlebro/BoardInfo";

  class BoardInfoRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Empty _request_type;
      _request_type request;

    BoardInfoRequest():
      request()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->request.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return BOARDINFO; };
    virtual const char * getMD5() override { return "57c42d82c9bab8a1ec9de111b7540471"; };

  };

  class BoardInfoResponse : public ros::Msg
  {
    public:
      typedef std_msgs::String _mcu_id_type;
      _mcu_id_type mcu_id;
      typedef std_msgs::String _firmware_version_type;
      _firmware_version_type firmware_version;

    BoardInfoResponse():
      mcu_id(),
      firmware_version()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->mcu_id.serialize(outbuffer + offset);
      offset += this->firmware_version.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->mcu_id.deserialize(inbuffer + offset);
      offset += this->firmware_version.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return BOARDINFO; };
    virtual const char * getMD5() override { return "7a66a0b2230d102a5eb7f4c320e4bb20"; };

  };

  class BoardInfo {
    public:
    typedef BoardInfoRequest Request;
    typedef BoardInfoResponse Response;
  };

}
#endif
