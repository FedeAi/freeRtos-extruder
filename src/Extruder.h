#ifndef EXTRUDER_H
#define EXTRUDER_H

#include <Arduino_FreeRTOS.h>
#include "Thread.h"

class Extruder //: public Thread
{
    public:
        float speed_rpm; //rpm target
        int timer;
        bool is_step = false;
        bool is_enabled = true;
        
        //Extruder( unsigned portSHORT _stackDepth, UBaseType_t _priority, const char* _name, uint32_t _ticks );
        Extruder();
        
        void setSpeedRpm(float speed);
        void incrementSpeed(int i);
        void runSpeed();
        int getSpeed(); // not yet implemented
        
    private:
        void Main();
        void setTimer(float period_us);
        
        float target_period_ms;
        float period_ms;
        float PERIOD_COSTANT_MS ;
        //uint32_t ticks;
};


#endif