
#include "Sensor.h" // class's header file

Sensor::Sensor()
{
    sensor = false;
    alarm = false;
}

Sensor::~Sensor()
{
}

bool Sensor::EnSensor()
{
    if(sensor)
        return false;
    else
    {
        sensor = true;
        alarm = false;
        return true;
    }
}

bool Sensor::DisSensor()
{
    if(!sensor)
        return false;
    else
    {
        sensor = false;
        alarm = false;
        return true;
    }
}

bool Sensor::ResetSensor()
{
    if(sensor)
    {
        alarm = false;
        return true;
    }
    else
        return false;
}

bool Sensor::CheckSensor()
{
    return alarm;
}

bool Sensor::TripSensor()
{
    if(sensor)
    {
        alarm = true;
        return true;
    }
    else
        return false;
}

bool Sensor::IsEnabled()
{
    return sensor;
}
