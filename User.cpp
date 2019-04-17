
#include "User.h" // class's header file

const int User::NoUserLoggedIn = 0;

User::User(wxString inCode)
{
    accessCode = inCode;
}

User::~User()
{
}

bool User::VerifyLogin(wxString code)
{
    if( (accessCode.Cmp(code)) == 0 )
        return true;
    else
        return false;
}

void User::ChangeAccessCode(wxString code)
{
    accessCode = code;
}

wxString User::GetAccessCode()
{
    return accessCode;
}
