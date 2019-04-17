
#include "OwnerUser.h" // class's header file

const int OwnerUser::UserSetting = 1;

OwnerUser::OwnerUser(wxString code) : User(code)
{
}

OwnerUser::~OwnerUser()
{
}

int OwnerUser::Login(wxString code)
{
    if(VerifyLogin(code))
        return UserSetting;
    else
        return NoUserLoggedIn;
}

int OwnerUser::Logout()
{
    return NoUserLoggedIn;
}
