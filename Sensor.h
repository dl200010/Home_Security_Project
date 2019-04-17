
#ifndef SENSOR_H
#define SENSOR_H

#include <wx/wx.h>

/*
 * sensor tells whether or not the Sensor is Enabled/Disabled.
 * 
 * alarm tells whether or not the Sensor has gone off.
 */
class Sensor
{
	public:
		Sensor();
		~Sensor();
		
        bool EnSensor();
        bool DisSensor();
        bool TripSensor();
        bool ResetSensor();
        bool CheckSensor();
        bool IsEnabled();
        
    private:
        bool alarm;
        bool sensor;
};

#endif // SENSOR_H
