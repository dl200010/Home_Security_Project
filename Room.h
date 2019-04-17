
#ifndef ROOM_H
#define ROOM_H

#include <wx/wx.h>
#include "COSensor.h"
#include "FireSensor.h"
#include "SecuritySensor.h"

/*
 * Rooms may have any number or type of Sensor.
 */
class Room
{
	public:
		Room(wxString inName);
		~Room();
		
		bool Enable(int inSensorType);
		bool Disable(int inSensorType);
        bool Reset(int inSensorType);
        bool Trip(int inSensorType);
        
        bool IsEnabled(int inSensorType);
        
        void CheckSensors(bool* output);
        
        wxString name;
        
   		//static varibles for sensor selection
        static const int COSENSOR;
        static const int FIRESENSOR;
        static const int SECURITYSENSOR;
        
    private:
        COSensor CO;
        FireSensor Fire;
        SecuritySensor Security;
};

#endif // ROOM_H
