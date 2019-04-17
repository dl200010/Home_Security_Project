
#include "PrimaryConsole.h" // class's header file

PrimaryConsole::PrimaryConsole()
{
    nextAction = "LOGIN";
    SensorType = -1;
    currentRoom = "";
    removePointer = -1;
    tempCode = "";
    tempTime = -1;
    tempHour = -1;
    tempMinute = -1;
    TempPtr = NULL;
    Output = "Enter access code.\n";
}

PrimaryConsole::~PrimaryConsole()
{
}

wxString PrimaryConsole::GetOutput()
{
    PriSystemReseted = false;
    return Output;
}

//user creation
void PrimaryConsole::CreatePermUser(wxString inCode)
{
    if(PermCount == 0)
    {
        PermanentAccounts = new PermanentUser*[PermCount + 1];
        PermanentAccounts[PermCount] = new PermanentUser(inCode);
        PermCount++;
    }
    else
    {
        PermanentUser ** pointerPU;
        pointerPU = PermanentAccounts;
        PermanentAccounts = NULL;
        PermanentAccounts = new PermanentUser*[PermCount + 1];
        for(int count = 0; count < PermCount; count++)
            PermanentAccounts[count] = pointerPU[count];
        PermanentAccounts[PermCount] = new PermanentUser(inCode);
        PermCount++;
        
        for(int count = 0; count < (PermCount - 1); count++)
            pointerPU[count] = NULL;
        delete pointerPU;
        pointerPU = NULL;
    }
}

void PrimaryConsole::CreateTempUser(wxString inCode, int startTime, int endTime)
{
    if(TempCount == 0)
    {
        TemporaryAccounts = new TemporaryUser*[TempCount + 1];
        TemporaryAccounts[TempCount] = new TemporaryUser(inCode);
        TemporaryAccounts[TempCount]->SetTempAccessBegin(startTime);
        TemporaryAccounts[TempCount]->SetTempAccessEnd(endTime);
        TempCount++;
    }
    else
    {
        TemporaryUser ** pointerTU;
        pointerTU = TemporaryAccounts;
        TemporaryAccounts = NULL;
        TemporaryAccounts = new TemporaryUser*[TempCount + 1];
        for(int count = 0; count < TempCount; count++)
            TemporaryAccounts[count] = pointerTU[count];
        TemporaryAccounts[TempCount] = new TemporaryUser(inCode);
        TemporaryAccounts[TempCount]->SetTempAccessBegin(startTime);
        TemporaryAccounts[TempCount]->SetTempAccessEnd(endTime);
        TempCount++;
        
        for(int count = 0; count < (TempCount - 1); count++)
            pointerTU[count] = NULL;
        delete pointerTU;
        pointerTU = NULL;
    }
}

void PrimaryConsole::DoNextAction()
{
    if(SystemError)
    {
        nextAction = "LOGIN";
        if( Login(GetBuffer()) )
        {
            ResetSystem();
            PriLogout();
        }
        BufferClear();
        return;
    }

    if(nextAction.Cmp("LOGIN") == 0)
    {
        PriLogin();
        return;
    }
    
    if(nextAction.Cmp("MAIN") == 0)
    {
        if(UserType == OwnerUser::UserSetting)
            OwnerMenu();
        else if(UserType == PermanentUser::UserSetting)
            PermanentMenu();
        return;
    }
    if(nextAction.Cmp("SELECT-ROOM") == 0)
    {
        SelectRoom();
        return;
    }
    if(nextAction.Cmp("SELECT-SENSOR") == 0)
    {
        SelectSensor();
        return;
    }
    if(nextAction.Cmp("ENABLE-DISABLE") == 0)
    {
        EnableDisable();
        return;
    }

    if(nextAction.Cmp("SETTINGS") == 0)
    {
        Settings();
        return;
    }
    if(nextAction.Cmp("UPDATE-USER") == 0)
    {
        UpdateUsers();
        return;
    }
    if(nextAction.Cmp("UPDATE-OWNER") == 0)
    {
        ChangeCodeOwner();
        return;
    }
    if(nextAction.Cmp("UPDATE-PERM") == 0)
    {
        ChangeCodePerm();
        return;
    }
    if(nextAction.Cmp("UPDATE-TEMP") == 0)
    {
        ChangeCodeTemp();
        return;
    }
    if(nextAction.Cmp("UU-SELECT-PERM") == 0)
    {
        UUSelectPerm();
        return;
    }
    if(nextAction.Cmp("UU-SELECT-TEMP") == 0)
    {
        UUSelectTemp();
        return;
    }
        if(nextAction.Cmp("UU-GET-START-HOUR") == 0)
    {
        UUGetStartHour();
        return;
    }
    if(nextAction.Cmp("UU-GET-START-MINUTE") == 0)
    {
        UUGetStartMinute();
        return;
    }
    if(nextAction.Cmp("UU-GET-END-HOUR") == 0)
    {
        UUGetEndHour();
        return;
    }
    if(nextAction.Cmp("UU-GET-END-MINUTE") == 0)
    {
        UUGetEndMinute();
        return;
    }
    
    if(nextAction.Cmp("ADD-REMOVE-USERS") == 0)
    {
        AddRemoveUsers();
        return;
    }
    if(nextAction.Cmp("ADD-PERM") == 0)
    {
        AddPerm();
        return;
    }
    if(nextAction.Cmp("REMOVE-PERM") == 0)
    {
        RemovePerm();
        return;
    }
    if(nextAction.Cmp("ADD-TEMP") == 0)
    {
        AddTemp();
        return;
    }
    if(nextAction.Cmp("REMOVE-TEMP") == 0)
    {
        RemoveTemp();
        return;
    }
    if(nextAction.Cmp("GET-START-HOUR") == 0)
    {
        GetStartHour();
        return;
    }
    if(nextAction.Cmp("GET-START-MINUTE") == 0)
    {
        GetStartMinute();
        return;
    }
    if(nextAction.Cmp("GET-END-HOUR") == 0)
    {
        GetEndHour();
        return;
    }
    if(nextAction.Cmp("GET-END-MINUTE") == 0)
    {
        GetEndMinute();
        return;
    }
    BufferClear();
}


void PrimaryConsole::PermanentMenu()
{
    if(GetBuffer().Cmp("2") == 0)
    {
        nextAction = "SELECT-ROOM";
        DisplaySelectRoom();
        BufferClear();
    }
    else if(GetBuffer().Cmp("3") == 0)
    {
        PriLogout();
    }
    BufferClear();
}


void PrimaryConsole::Settings()
{
    if(GetBuffer().Cmp("1") == 0)
    {
        DisplayUpdateUser();
        nextAction = "UPDATE-USER";
        BufferClear();
    }
    else if(GetBuffer().Cmp("2") == 0)
    {
        DisplayAddRemoveUser();
        nextAction = "ADD-REMOVE-USERS";
        BufferClear();
    }
    else if(GetBuffer().Cmp("3") == 0)
    {
        nextAction = "MAIN";
        DisplayOwner();
        BufferClear();
    }
    BufferClear();
}
void PrimaryConsole::UpdateUsers()
{
    if(GetBuffer().Cmp("1") == 0)
    {
        Output = "Please enter new code for the owner\n";
        nextAction = "UPDATE-OWNER";
        BufferClear();
    }
    else if(GetBuffer().Cmp("2") == 0)
    {
        DisplayAllPerm();
        nextAction = "UU-SELECT-PERM";
        BufferClear();
    }
    else if(GetBuffer().Cmp("3") == 0)
    {
        DisplayAllTemp();
        nextAction = "UU-SELECT-TEMP";
        BufferClear();
    }
    else if(GetBuffer().Cmp("4") == 0)
    {
        nextAction = "SETTINGS";
        DisplaySettings();
        BufferClear();
    }
    BufferClear();
}
void PrimaryConsole::UUSelectPerm()
{
    if(GetBuffer().Cmp("0") == 0)
    {
        DisplayUpdateUser();
        nextAction = "UPDATE-USER";
        BufferClear();
        return;
    }
    
    tempCode = GetBuffer();
    
    Output = "Enter new code for permanent user\n";
    nextAction = "UPDATE-PERM";
    BufferClear();
}
void PrimaryConsole::UUSelectTemp()
{
    if(GetBuffer().Cmp("0") == 0)
    {
        DisplayUpdateUser();
        nextAction = "UPDATE-USER";
        BufferClear();
        return;
    }

    tempCode = GetBuffer();

    Output = "Enter new code for temporary user\n";
    nextAction = "UPDATE-TEMP";
    BufferClear();
}
void PrimaryConsole::ChangeCodeOwner()
{
    OwnerAccount.ChangeAccessCode(GetBuffer());
    PriLogout();
}
void PrimaryConsole::ChangeCodePerm()
{
    for(int count = 0; count < PermCount; count++)
        if(PermanentAccounts[count]->VerifyLogin(tempCode))
            PermanentAccounts[count]->ChangeAccessCode(GetBuffer());
            
    tempCode = "";
    
    DisplayUpdateUser();
    nextAction = "UPDATE-USER";
    BufferClear();
}
void PrimaryConsole::ChangeCodeTemp()
{
    for(int count = 0; count < TempCount; count++)
        if(TemporaryAccounts[count]->VerifyLogin(tempCode))
            TempPtr = TemporaryAccounts[count];
            
    int begin = TempPtr->GetTempAccessBegin();
    int end = TempPtr->GetTempAccessEnd();
    
    int beginHour = begin/60;
    begin = begin%60;
    int endHour = end/60;
    end = end%60;
    
    tempCode = GetBuffer();
    
    Output = "Begining time is: ";
    Output << beginHour << ":" << begin << "\n";
    Output += "Ending time is: ";
    Output << endHour << ":" << end << "\n";

    BufferClear();
    Output += "Please enter the start hour (0-23)";
    nextAction = "UU-GET-START-HOUR";
}
void PrimaryConsole::UUGetStartHour()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);

    if( (*tempLong) >= 0 && (*tempLong) <= 23 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        TempPtr = NULL;
        tempCode = "";
        DisplayUpdateUser();
        nextAction = "UPDATE-USER";
        BufferClear();
        return;
    }
    tempHour = (int)(*tempLong);
    delete tempLong;

    Output = "Please enter the start minute (0-59)";
    nextAction = "UU-GET-START-MINUTE";
    BufferClear();
}
void PrimaryConsole::UUGetStartMinute()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);

    if( (*tempLong) >= 0 && (*tempLong) <= 59 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        TempPtr = NULL;
        tempCode = "";
        DisplayUpdateUser();
        nextAction = "UPDATE-USER";
        BufferClear();
        return;
    }
    tempMinute = (int)(*tempLong);
    delete tempLong;

    tempTime = (tempHour * 60) + tempMinute;
    tempHour = -1;
    tempMinute = -1;

    Output = "Please enter the end hour (0-23)";
    nextAction = "UU-GET-END-HOUR";
    BufferClear();
}
void PrimaryConsole::UUGetEndHour()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);

    if( (*tempLong) >= 0 && (*tempLong) <= 23 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        TempPtr = NULL;
        tempCode = "";
        DisplayUpdateUser();
        nextAction = "UPDATE-USER";
        BufferClear();
        return;
    }
    tempHour = (int)(*tempLong);
    delete tempLong;

    Output = "Please enter the end minute (0-59)";
    nextAction = "UU-GET-END-MINUTE";
    BufferClear();
}
void PrimaryConsole::UUGetEndMinute()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);

    if( (*tempLong) >= 0 && (*tempLong) <= 59 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        TempPtr = NULL;
        tempCode = "";
        DisplayUpdateUser();
        nextAction = "UPDATE-USER";
        BufferClear();
        return;
    }
    tempMinute = (int)(*tempLong);
    delete tempLong;

    TempPtr->ChangeAccessCode(tempCode);
    TempPtr->SetTempAccessBegin(tempTime);
    TempPtr->SetTempAccessEnd( (tempHour*60) + tempMinute  );

    tempCode = "";
    tempTime = -1;
    tempHour = -1;
    tempMinute = -1;
    TempPtr = NULL;


    DisplayUpdateUser();
    nextAction = "UPDATE-USER";
    BufferClear();
}

void PrimaryConsole::AddRemoveUsers()
{
    if(GetBuffer().Cmp("1") == 0)
    {
        Output = "Please enter the code for the new permanent user\n";
        nextAction = "ADD-PERM";
        BufferClear();
    }
    else if(GetBuffer().Cmp("2") == 0)
    {
        DisplayAllPerm();
        nextAction = "REMOVE-PERM";
        BufferClear();
    }
    else if(GetBuffer().Cmp("3") == 0)
    {
        Output = "Please enter the code for the new temporary user\n";
        nextAction = "ADD-TEMP";
        BufferClear();
    }
    else if(GetBuffer().Cmp("4") == 0)
    {
        DisplayAllTemp();
        nextAction = "REMOVE-TEMP";
        BufferClear();
    }
    else if(GetBuffer().Cmp("5") == 0)
    {
        nextAction = "SETTINGS";
        DisplaySettings();
        BufferClear();
    }
    BufferClear();
}
void PrimaryConsole::AddPerm()
{
    CreatePermUser(GetBuffer());

    DisplayAddRemoveUser();
    nextAction = "ADD-REMOVE-USERS";
    BufferClear();
}
void PrimaryConsole::RemovePerm()
{
    if(GetBuffer().Cmp("0") == 0)
    {
        DisplayAddRemoveUser();
        nextAction = "ADD-REMOVE-USERS";
        BufferClear();
        return;
    }
    bool remove = false;


    if( PermanentAccounts != NULL )
    {
        for(int count = 0; count < PermCount; count++)
        {
            if( PermanentAccounts[count]->VerifyLogin(GetBuffer()) )
            {
                remove = true;
                removePointer = count;
            }
        }
    }

    if(remove)
    {
        if(PermCount == 1)
        {
            delete PermanentAccounts[0];
            PermanentAccounts[0] = NULL;
            delete PermanentAccounts;
            PermanentAccounts = NULL;
            PermCount--;
        }
        else
        {
            PermanentUser ** tempPU = PermanentAccounts;
            PermanentAccounts = NULL;
            PermanentAccounts = new PermanentUser*[PermCount - 1];
            for(int count = 0; count < PermCount; count++)
            {
                if( (removePointer > count) )
                    PermanentAccounts[count] = tempPU[count];
                else if( (removePointer < count) )
                    PermanentAccounts[count-1] = tempPU[count];
            }
            for(int count = 0; count < PermCount; count++)
                tempPU[count] = NULL;
            delete tempPU;
            tempPU = NULL;
            PermCount--;
        }
    }

    DisplayAddRemoveUser();
    nextAction = "ADD-REMOVE-USERS";
    BufferClear();
}
void PrimaryConsole::RemoveTemp()
{
    if(GetBuffer().Cmp("0") == 0)
    {
        DisplayAddRemoveUser();
        nextAction = "ADD-REMOVE-USERS";
        BufferClear();
        return;
    }
    bool remove = false;
    
    if(TemporaryAccounts != NULL)
    {
        for(int count = 0; count < TempCount; count++)
        {
            if( TemporaryAccounts[count]->VerifyLogin(GetBuffer()) )
            {
                remove = true;
                removePointer = count;
            }
        }
    }
    
    if(remove)
    {
        if(TempCount == 1)
        {
            delete TemporaryAccounts[0];
            TemporaryAccounts[0] = NULL;
            delete TemporaryAccounts;
            TemporaryAccounts = NULL;
            TempCount--;
        }
        else
        {
            TemporaryUser ** tempTU = TemporaryAccounts;
            TemporaryAccounts = NULL;
            TemporaryAccounts = new TemporaryUser*[TempCount - 1];
            for(int count = 0; count < TempCount; count++)
            {
                if( (removePointer > count) )
                    TemporaryAccounts[count] = tempTU[count];
                else if( (removePointer < count) )
                    TemporaryAccounts[count-1] = tempTU[count];
            }
            for(int count = 0; count < TempCount; count++)
                tempTU[count] = NULL;
            delete tempTU;
            tempTU = NULL;
            TempCount--;
        }
    }
    
    DisplayAddRemoveUser();
    nextAction = "ADD-REMOVE-USERS";
    BufferClear();
}
void PrimaryConsole::AddTemp()
{
    tempCode = GetBuffer();
    BufferClear();
    Output = "Please enter the start hour (0-23)";
    nextAction = "GET-START-HOUR";
}
void PrimaryConsole::GetStartHour()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);
    
    if( (*tempLong) >= 0 && (*tempLong) <= 23 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        tempCode = "";
        DisplayAddRemoveUser();
        nextAction = "ADD-REMOVE-USERS";
        BufferClear();
        return;
    }
    tempHour = (int)(*tempLong);
    delete tempLong;
    
    Output = "Please enter the start minute (0-59)";
    nextAction = "GET-START-MINUTE";
    BufferClear();
}
void PrimaryConsole::GetStartMinute()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);

    if( (*tempLong) >= 0 && (*tempLong) <= 59 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        tempCode = "";
        DisplayAddRemoveUser();
        nextAction = "ADD-REMOVE-USERS";
        BufferClear();
        return;
    }
    tempMinute = (int)(*tempLong);
    delete tempLong;
    
    tempTime = (tempHour * 60) + tempMinute;
    tempHour = -1;
    tempMinute = -1;
    
    Output = "Please enter the end hour (0-23)";
    nextAction = "GET-END-HOUR";
    BufferClear();
}
void PrimaryConsole::GetEndHour()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);

    if( (*tempLong) >= 0 && (*tempLong) <= 23 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        tempCode = "";
        DisplayAddRemoveUser();
        nextAction = "ADD-REMOVE-USERS";
        BufferClear();
        return;
    }
    tempHour = (int)(*tempLong);
    delete tempLong;
    
    Output = "Please enter the end minute (0-59)";
    nextAction = "GET-END-MINUTE";
    BufferClear();
}
void PrimaryConsole::GetEndMinute()
{
    bool done = false;

    long *tempLong = new long;
    GetBuffer().ToLong(tempLong);

    if( (*tempLong) >= 0 && (*tempLong) <= 59 )
        done = true;
    if(!done)
    {
        tempHour = -1;
        tempMinute = -1;
        tempTime = -1;
        tempCode = "";
        DisplayAddRemoveUser();
        nextAction = "ADD-REMOVE-USERS";
        BufferClear();
        return;
    }
    tempMinute = (int)(*tempLong);
    delete tempLong;

    CreateTempUser(tempCode, tempTime, ( (tempHour*60) + tempMinute ) );
    
    tempCode = "";
    tempTime = -1;
    tempHour = -1;
    tempMinute = -1;

    DisplayAddRemoveUser();
    nextAction = "ADD-REMOVE-USERS";
    BufferClear();
}


void PrimaryConsole::DisplayOwner()
{
    Output = "1. Settings\n";
    Output += "2. Enable/Disable\n";
    Output += "3. Logout\n";
}
void PrimaryConsole::DisplayPermanent()
{
    Output = "2. Enable/Disable\n";
    Output += "3. Logout\n";
}
void PrimaryConsole::DisplaySettings()
{
    Output = "1. Update User Access Codes And Schedules\n";
    Output += "2. Add/Remove Users\n";
    Output += "3. Back\n";
}
void PrimaryConsole::DisplayUpdateUser()
{
    Output = "1. Update Owner\n";
    Output += "2. Update Permament User\n";
    Output += "3. Update Temporary User\n";
    Output += "4. Back\n";
}
void PrimaryConsole::DisplayAddRemoveUser()
{
    Output = "1. Add Permament User\n";
    Output += "2. Remove Permament User\n";
    Output += "3. Add Temporary User\n";
    Output += "4. Remove Temporary User\n";
    Output += "5. Back\n";
}
void PrimaryConsole::DisplaySelectRoom()
{
    Output = "1. Garage\n";
    Output += "2. Family Room\n";
    Output += "3. Kitchen\n";
    Output += "4. Dinning Room\n";
    Output += "5. Bedroom\n";
    Output += "6. Bathroom\n";
    Output += "7. Office\n";
    Output += "8. Back\n";
}
void PrimaryConsole::DisplaySelectSensor()
{
    Output = "1. Fire\n";
    Output += "2. Security\n";
    Output += "3. CO\n";
    Output += "4. Back\n";
}
void PrimaryConsole::DisplayEnableDisable()
{
    Output = "1. Enable\n";
    Output += "2. Disable\n";
    Output += "3. Back\n";
}

void PrimaryConsole::DisplayAllPerm()
{
    if(PermCount == 0)
        Output = "No Permanent Users in system.\n0. Back\n";
    else
    {
        Output = "";
        for(int count = 0; count < PermCount; count++)
        {
            Output += PermanentAccounts[count]->GetAccessCode();
            Output += "\n";
        }
        Output += "0. Back\n";
    }
}

void PrimaryConsole::DisplayAllTemp()
{
    if(TempCount == 0)
        Output = "No Temporary Users in system.\n0. Back\n";
    else
    {
        Output = "";
        for(int count = 0; count < TempCount; count++)
        {
            Output += TemporaryAccounts[count]->GetAccessCode();
            Output += "\n";
        }
        Output += "0. Back\n";
    }
}

void PrimaryConsole::OwnerMenu()
{
    if(GetBuffer().Cmp("1") == 0)
    {
        nextAction = "SETTINGS";
        DisplaySettings();
        BufferClear();
    }
    else if(GetBuffer().Cmp("2") == 0)
    {
        nextAction = "SELECT-ROOM";
        DisplaySelectRoom();
        BufferClear();
    }
    else if(GetBuffer().Cmp("3") == 0)
    {
        PriLogout();
    }
    BufferClear();
}
void PrimaryConsole::SelectRoom()
{
    if(GetBuffer().Cmp("1") == 0)
    {
        currentRoom = G.name;
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    else if(GetBuffer().Cmp("2") == 0)
    {
        currentRoom = F.name;
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    else if(GetBuffer().Cmp("3") == 0)
    {
        currentRoom = K.name;
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    else if(GetBuffer().Cmp("4") == 0)
    {
        currentRoom = D.name;
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    else if(GetBuffer().Cmp("5") == 0)
    {
        currentRoom = Bed.name;
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    else if(GetBuffer().Cmp("6") == 0)
    {
        currentRoom = Bath.name;
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    else if(GetBuffer().Cmp("7") == 0)
    {
        currentRoom = O.name;
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    else if(GetBuffer().Cmp("8") == 0)
    {
        nextAction = "MAIN";
        if(UserType == OwnerUser::UserSetting)
        {
            DisplayOwner();
        }
        else if(UserType == PermanentUser::UserSetting)
        {
            DisplayPermanent();
        }
        BufferClear();
    }
    BufferClear();
}
void PrimaryConsole::SelectSensor()
{
    if(GetBuffer().Cmp("1") == 0)
    {
        SensorType = Room::FIRESENSOR;
        DisplayEnableDisable();
        BufferClear();
        nextAction = "ENABLE-DISABLE";
    }
    else if(GetBuffer().Cmp("2") == 0)
    {
        SensorType = Room::SECURITYSENSOR;
        DisplayEnableDisable();
        BufferClear();
        nextAction = "ENABLE-DISABLE";
    }
    else if(GetBuffer().Cmp("3") == 0)
    {
        SensorType = Room::COSENSOR;
        DisplayEnableDisable();
        BufferClear();
        nextAction = "ENABLE-DISABLE";
    }
    else if(GetBuffer().Cmp("4") == 0)
    {
        nextAction = "SELECT-ROOM";
        DisplaySelectRoom();
        BufferClear();
    }
    BufferClear();
}
void PrimaryConsole::EnableDisable()
{
    if(GetBuffer().Cmp("1") == 0)
    {
        EnableSensor();
        DisplayEnableDisable();
        BufferClear();
    }
    if(GetBuffer().Cmp("2") == 0)
    {
        DisableSensor();
        DisplayEnableDisable();
        BufferClear();
    }
    if(GetBuffer().Cmp("3") == 0)
    {
        nextAction = "SELECT-SENSOR";
        DisplaySelectSensor();
        BufferClear();
    }
    BufferClear();
}
void PrimaryConsole::EnableSensor()
{
    if( currentRoom.Cmp(G.name) == 0 )
    {
        G.Enable(SensorType);
    }
    else if( currentRoom.Cmp(F.name) == 0 )
    {
        F.Enable(SensorType);
    }
    else if( currentRoom.Cmp(K.name) == 0 )
    {
        K.Enable(SensorType);
    }
    else if( currentRoom.Cmp(D.name) == 0 )
    {
        D.Enable(SensorType);
    }
    else if( currentRoom.Cmp(Bed.name) == 0 )
    {
        Bed.Enable(SensorType);
    }
    else if( currentRoom.Cmp(Bath.name) == 0 )
    {
        Bath.Enable(SensorType);
    }
    else if( currentRoom.Cmp(O.name) == 0 )
    {
        O.Enable(SensorType);
    }
}
void PrimaryConsole::DisableSensor()
{
    if( currentRoom.Cmp(G.name) == 0 )
    {
        G.Disable(SensorType);
    }
    else if( currentRoom.Cmp(F.name) == 0 )
    {
        F.Disable(SensorType);
    }
    else if( currentRoom.Cmp(K.name) == 0 )
    {
        K.Disable(SensorType);
    }
    else if( currentRoom.Cmp(D.name) == 0 )
    {
        D.Disable(SensorType);
    }
    else if( currentRoom.Cmp(Bed.name) == 0 )
    {
        Bed.Disable(SensorType);
    }
    else if( currentRoom.Cmp(Bath.name) == 0 )
    {
        Bath.Disable(SensorType);
    }
    else if( currentRoom.Cmp(O.name) == 0 )
    {
        O.Disable(SensorType);
    }
}


void PrimaryConsole::PriLogin()
{
    if( Login(GetBuffer()) )
    {
        nextAction = "MAIN";
        if(UserType == OwnerUser::UserSetting)
        {
            DisplayOwner();
        }
        else if(UserType == PermanentUser::UserSetting)
        {
            DisplayPermanent();
        }
        else if(UserType == TemporaryUser::UserSetting)
        {
            PriLogout();
        }
        BufferClear();
    }
    else
    {
        Output = "Incorrect passcode.\nEnter access code.\n";
        BufferClear();
    }
    BufferClear();
}
void PrimaryConsole::PriLogout()
{
    Output = "Enter access code.\n";
    nextAction = "LOGIN";
    BufferClear();
    Logout();
}
