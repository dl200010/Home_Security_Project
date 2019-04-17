
#include "Room.h" // class's header file

const int Room::COSENSOR = 0;
const int Room::FIRESENSOR = 1;
const int Room::SECURITYSENSOR = 2;

Room::Room(wxString inName)
{
    name = inName;
    
    this->Enable(COSENSOR);
    this->Enable(FIRESENSOR);
    this->Enable(SECURITYSENSOR);
    this->Reset(COSENSOR);
    this->Reset(FIRESENSOR);
    this->Reset(SECURITYSENSOR);
}

Room::~Room()
{
}

bool Room::Enable(int inSensorType)
{
    if(inSensorType == COSENSOR)
    {
        return CO.EnSensor();
    }
    else if(inSensorType == FIRESENSOR)
    {
        return Fire.EnSensor();
    }
    else if(inSensorType == SECURITYSENSOR)
    {
        return Security.EnSensor();
    }
    else
        return false;
}

bool Room::Disable(int inSensorType)
{
    if(inSensorType == COSENSOR)
    {
        return CO.DisSensor();
    }
    else if(inSensorType == FIRESENSOR)
    {
        return Fire.DisSensor();
    }
    else if(inSensorType == SECURITYSENSOR)
    {
        return Security.DisSensor();
    }
    else
        return false;
    
}

bool Room::Reset(int inSensorType)
{
    if(inSensorType == COSENSOR)
    {
        return CO.ResetSensor();
    }
    else if(inSensorType == FIRESENSOR)
    {
        return Fire.ResetSensor();
    }
    else if(inSensorType == SECURITYSENSOR)
    {
        return Security.ResetSensor();
    }
    else
        return false;
}

bool Room::Trip(int inSensorType)
{
    if(inSensorType == COSENSOR)
    {
        return CO.TripSensor();
    }
    else if(inSensorType == FIRESENSOR)
    {
        return Fire.TripSensor();
    }
    else if(inSensorType == SECURITYSENSOR)
    {
        return Security.TripSensor();
    }
    else
        return false;
}

bool Room::IsEnabled(int inSensorType)
{
    if(inSensorType == COSENSOR)
    {
        return CO.IsEnabled();
    }
    else if(inSensorType == FIRESENSOR)
    {
        return Fire.IsEnabled();
    }
    else if(inSensorType == SECURITYSENSOR)
    {
        return Security.IsEnabled();
    }
    else
        return false;
}

void Room::CheckSensors(bool* output)
{
    output[0] = CO.CheckSensor();
    output[1] = Fire.CheckSensor();
    output[2] = Security.CheckSensor();
}
