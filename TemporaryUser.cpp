
#include "TemporaryUser.h" // class's header file
#include "wxMainPanelDlg.h"

const int TemporaryUser::UserSetting = 3;

TemporaryUser::TemporaryUser(wxString code) : User(code)
{
    tempAccessBegin = 0;
    tempAccessEnd = 0;
}

TemporaryUser::~TemporaryUser()
{
}

int TemporaryUser::Login(wxString code)
{
    int current = wxMainPanelDlg::currentTime;
    
    if( (tempAccessEnd - tempAccessBegin) <= 0 )
        return NoUserLoggedIn;
    else if( (current - tempAccessBegin) < 0 )
        return NoUserLoggedIn;
    else if( (tempAccessEnd - current) < 0 )
        return NoUserLoggedIn;
    else if(VerifyLogin(code))
        return UserSetting;
    else
        return NoUserLoggedIn;
}

int TemporaryUser::Logout()
{
    return NoUserLoggedIn;
}

bool TemporaryUser::SetTempAccessBegin(int begin)
{
    tempAccessBegin = begin;
    return true;
}

bool TemporaryUser::SetTempAccessEnd(int end)
{
    tempAccessEnd = end;
    return true;
}

int TemporaryUser::GetTempAccessBegin()
{
    return tempAccessBegin;
}

int TemporaryUser::GetTempAccessEnd()
{
    return tempAccessEnd;
}
