
#include "Console.h" // class's header file

wxString Console::OwnerCode = "4343";
OwnerUser Console::OwnerAccount(OwnerCode);

PermanentUser ** Console::PermanentAccounts = NULL;
int Console::PermCount = 0;

TemporaryUser ** Console::TemporaryAccounts = NULL;
int Console::TempCount = 0;

bool Console::SystemError = false;
bool Console::PriSystemReseted = false;
bool Console::SecSystemReseted = false;

Room Console::G( wxString("Garage") );
Room Console::F( wxString("Family Room") );
Room Console::K( wxString("Kitchen") );
Room Console::D( wxString("Dining Room") );
Room Console::Bed( wxString("Bedroom") );
Room Console::Bath( wxString("Bathroom") );
Room Console::O( wxString("Office") );

Console::Console()
{
    UserType = User::NoUserLoggedIn;
    pointer = -1;
    BufferString = "";
}

Console::~Console()
{
}


bool Console::Login(wxString inCode)
{
    if( OwnerAccount.VerifyLogin(inCode) )
    {
        UserType = OwnerAccount.Login(inCode);
        return true;
    }

    if( PermanentAccounts != NULL)
        for(int count = 0; count < PermCount; count++)
        {
            if( PermanentAccounts[count]->VerifyLogin(inCode) )
            {
                UserType = PermanentAccounts[count]->Login(inCode);
                pointer = count;
                return true;
            }
        }

    if( TemporaryAccounts != NULL)
        for(int count = 0; count < TempCount; count++)
        {
            if( TemporaryAccounts[count]->VerifyLogin(inCode) )
            {
                UserType = TemporaryAccounts[count]->Login(inCode);
                pointer = count;
                if(UserType == User::NoUserLoggedIn)
                {
                    pointer = -1;
                    return false;
                }
                return true;
            }
        }

    return false;

}

bool Console::Logout()
{
    if( UserType == OwnerUser::UserSetting )
    {
        UserType = OwnerAccount.Logout();
        return true;
    }
    else if( UserType == PermanentUser::UserSetting )
    {
        UserType = PermanentAccounts[pointer]->Logout();
        pointer = -1;
        return true;
    }
    else if( UserType == TemporaryUser::UserSetting )
    {
        UserType = TemporaryAccounts[pointer]->Logout();
        pointer = -1;
        return true;
    }
    else
    {
        UserType = User::NoUserLoggedIn;
        pointer = -1;
        return true;
    }
}

void Console::BufferClear()
{
    BufferString = "";
}
        
void Console::BufferEnter(char input)
{
    BufferString += input;
}

wxString Console::GetBuffer()
{
    return BufferString;
}

//checking sensors
void Console::CheckSensors(wxString* inNames, bool ** output)
{
    bool *boolG = new bool[3];
    bool *boolF = new bool[3];
    bool *boolK = new bool[3];
    bool *boolD = new bool[3];
    bool *boolBed = new bool[3];
    bool *boolBath = new bool[3];
    bool *boolO = new bool[3];
    
    G.CheckSensors(boolG);
    F.CheckSensors(boolF);
    K.CheckSensors(boolK);
    D.CheckSensors(boolD);
    Bed.CheckSensors(boolBed);
    Bath.CheckSensors(boolBath);
    O.CheckSensors(boolO);
    
    inNames[0] = G.name;
    inNames[1] = F.name;
    inNames[2] = K.name;
    inNames[3] = D.name;
    inNames[4] = Bed.name;
    inNames[5] = Bath.name;
    inNames[6] = O.name;

    SystemError = false;
    for(int room = 0; room < 7; room++)
    {
        for(int count = 0; count < 3; count++)
        {
            if(room == 0)
            {
                if(boolG[count])
                    SystemError = true;
                output[room][count] = boolG[count];
            }
            else if(room == 1)
            {
                if(boolF[count])
                    SystemError = true;
                output[room][count] = boolF[count];
            }
            else if(room == 2)
            {
                if(boolK[count])
                    SystemError = true;
                output[room][count] = boolK[count];
            }
            else if(room == 3)
            {
                if(boolD[count])
                    SystemError = true;
                output[room][count] = boolD[count];
            }
            else if(room == 4)
            {
                if(boolBed[count])
                    SystemError = true;
                output[room][count] = boolBed[count];
            }
            else if(room == 5)
            {
                if(boolBath[count])
                    SystemError = true;
                output[room][count] = boolBath[count];
            }
            else if(room == 6)
            {
                if(boolO[count])
                    SystemError = true;
                output[room][count] = boolO[count];
            }
        }
    }

    if(SystemError)
    {
        PriSystemReseted = false;
        SecSystemReseted = false;
    }
        
    if(PriSystemReseted)
        Output = "Enter access code.\n";
    if(SecSystemReseted)
        Output = "Enter access code.\n";
    
    delete boolG;
    delete boolF;
    delete boolK;
    delete boolD;
    delete boolBed;
    delete boolBath;
    delete boolO;
}

bool Console::TripG(int inSensorType)
{
    return G.Trip(inSensorType);
}

bool Console::TripF(int inSensorType)
{
    return F.Trip(inSensorType);
}

bool Console::TripK(int inSensorType)
{
    return K.Trip(inSensorType);
}

bool Console::TripD(int inSensorType)
{
    return D.Trip(inSensorType);
}

bool Console::TripBed(int inSensorType)
{
    return Bed.Trip(inSensorType);
}

bool Console::TripBath(int inSensorType)
{
    return Bath.Trip(inSensorType);
}

bool Console::TripO(int inSensorType)
{
    return O.Trip(inSensorType);
}

bool Console::ResetG(int inSensorType)
{
    return G.Reset(inSensorType);
}

bool Console::ResetF(int inSensorType)
{
    return F.Reset(inSensorType);
}

bool Console::ResetK(int inSensorType)
{
    return K.Reset(inSensorType);
}

bool Console::ResetD(int inSensorType)
{
    return D.Reset(inSensorType);
}

bool Console::ResetBed(int inSensorType)
{
    return Bed.Reset(inSensorType);
}

bool Console::ResetBath(int inSensorType)
{
    return Bath.Reset(inSensorType);
}

bool Console::ResetO(int inSensorType)
{
    return O.Reset(inSensorType);
}

bool Console::ResetSystem()
{
    for(int count = 0; count <= Room::SECURITYSENSOR; count++)
    {
        ResetG(count);
        ResetF(count);
        ResetK(count);
        ResetD(count);
        ResetBed(count);
        ResetBath(count);
        ResetO(count);
    }
    SystemError = false;
    PriSystemReseted = true;
    SecSystemReseted = true;
    return true;
}

void Console::OnSystemError()
{
    Logout();
    Output = "Enter access code to reset alarms.\n";
}

bool Console::GetSystemError()
{
    return SystemError;
}
