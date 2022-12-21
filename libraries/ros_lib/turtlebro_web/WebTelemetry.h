#ifndef _ROS_turtlebro_web_WebTelemetry_h
#define _ROS_turtlebro_web_WebTelemetry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebro_web
{

  class WebTelemetry : public ros::Msg
  {
    public:
      typedef float _odom_x_type;
      _odom_x_type odom_x;
      typedef float _odom_y_type;
      _odom_y_type odom_y;
      typedef float _odom_z_type;
      _odom_z_type odom_z;
      typedef float _odom_lin_speed_type;
      _odom_lin_speed_type odom_lin_speed;
      typedef int16_t _odom_ang_speed_type;
      _odom_ang_speed_type odom_ang_speed;
      typedef int16_t _imu_yaw_type;
      _imu_yaw_type imu_yaw;
      typedef int16_t _imu_pitch_type;
      _imu_pitch_type imu_pitch;
      typedef int16_t _imu_roll_type;
      _imu_roll_type imu_roll;
      typedef float _bat_voltage_type;
      _bat_voltage_type bat_voltage;

    WebTelemetry():
      odom_x(0),
      odom_y(0),
      odom_z(0),
      odom_lin_speed(0),
      odom_ang_speed(0),
      imu_yaw(0),
      imu_pitch(0),
      imu_roll(0),
      bat_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_odom_x;
      u_odom_x.real = this->odom_x;
      *(outbuffer + offset + 0) = (u_odom_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odom_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odom_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odom_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->odom_x);
      union {
        float real;
        uint32_t base;
      } u_odom_y;
      u_odom_y.real = this->odom_y;
      *(outbuffer + offset + 0) = (u_odom_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odom_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odom_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odom_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->odom_y);
      union {
        float real;
        uint32_t base;
      } u_odom_z;
      u_odom_z.real = this->odom_z;
      *(outbuffer + offset + 0) = (u_odom_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odom_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odom_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odom_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->odom_z);
      union {
        float real;
        uint32_t base;
      } u_odom_lin_speed;
      u_odom_lin_speed.real = this->odom_lin_speed;
      *(outbuffer + offset + 0) = (u_odom_lin_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odom_lin_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odom_lin_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odom_lin_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->odom_lin_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_odom_ang_speed;
      u_odom_ang_speed.real = this->odom_ang_speed;
      *(outbuffer + offset + 0) = (u_odom_ang_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odom_ang_speed.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->odom_ang_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_yaw;
      u_imu_yaw.real = this->imu_yaw;
      *(outbuffer + offset + 0) = (u_imu_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_yaw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_pitch;
      u_imu_pitch.real = this->imu_pitch;
      *(outbuffer + offset + 0) = (u_imu_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_pitch.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_roll;
      u_imu_roll.real = this->imu_roll;
      *(outbuffer + offset + 0) = (u_imu_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_roll.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_roll);
      union {
        float real;
        uint32_t base;
      } u_bat_voltage;
      u_bat_voltage.real = this->bat_voltage;
      *(outbuffer + offset + 0) = (u_bat_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bat_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bat_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bat_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bat_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_odom_x;
      u_odom_x.base = 0;
      u_odom_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odom_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odom_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odom_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->odom_x = u_odom_x.real;
      offset += sizeof(this->odom_x);
      union {
        float real;
        uint32_t base;
      } u_odom_y;
      u_odom_y.base = 0;
      u_odom_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odom_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odom_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odom_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->odom_y = u_odom_y.real;
      offset += sizeof(this->odom_y);
      union {
        float real;
        uint32_t base;
      } u_odom_z;
      u_odom_z.base = 0;
      u_odom_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odom_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odom_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odom_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->odom_z = u_odom_z.real;
      offset += sizeof(this->odom_z);
      union {
        float real;
        uint32_t base;
      } u_odom_lin_speed;
      u_odom_lin_speed.base = 0;
      u_odom_lin_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odom_lin_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odom_lin_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odom_lin_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->odom_lin_speed = u_odom_lin_speed.real;
      offset += sizeof(this->odom_lin_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_odom_ang_speed;
      u_odom_ang_speed.base = 0;
      u_odom_ang_speed.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odom_ang_speed.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->odom_ang_speed = u_odom_ang_speed.real;
      offset += sizeof(this->odom_ang_speed);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_yaw;
      u_imu_yaw.base = 0;
      u_imu_yaw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_yaw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_yaw = u_imu_yaw.real;
      offset += sizeof(this->imu_yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_pitch;
      u_imu_pitch.base = 0;
      u_imu_pitch.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_pitch.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_pitch = u_imu_pitch.real;
      offset += sizeof(this->imu_pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_roll;
      u_imu_roll.base = 0;
      u_imu_roll.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_roll.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_roll = u_imu_roll.real;
      offset += sizeof(this->imu_roll);
      union {
        float real;
        uint32_t base;
      } u_bat_voltage;
      u_bat_voltage.base = 0;
      u_bat_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bat_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bat_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bat_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bat_voltage = u_bat_voltage.real;
      offset += sizeof(this->bat_voltage);
     return offset;
    }

    virtual const char * getType() override { return "turtlebro_web/WebTelemetry"; };
    virtual const char * getMD5() override { return "226b73f74452e2afa7b54fcd15bafe9d"; };

  };

}
#endif
