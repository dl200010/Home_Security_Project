
#include "PermanentUser.h" // class's header file

const int PermanentUser::UserSetting = 2;

PermanentUser::PermanentUser(wxString code) : User(code)
{
}

PermanentUser::~PermanentUser()
{
}

int PermanentUser::Login(wxString code)
{
    if(VerifyLogin(code))
        return UserSetting;
    else
        return NoUserLoggedIn;
}

int PermanentUser::Logout()
{
    return NoUserLoggedIn;
}
