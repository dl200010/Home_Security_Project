
#include "SecondaryConsole.h" // class's header file

SecondaryConsole::SecondaryConsole() : Console()
{
    Output = "Enter access code.\n";
}

SecondaryConsole::~SecondaryConsole()
{
}


wxString SecondaryConsole::GetOutput()
{
    SecSystemReseted = false;
    return Output;
}

void SecondaryConsole::DoNextAction()
{
    if(SystemError)
    {
        if( Login(GetBuffer()) )
        {
            SecLogout();
            ResetSystem();
        }
        BufferClear();
        return;
    }

    if( GetBuffer().Cmp(wxString("1")) == 0 )
        EnableSecurity();
    else if( GetBuffer().Cmp(wxString("2")) == 0 )
        DisableSecurity();
    else if( GetBuffer().Cmp(wxString("3")) == 0 )
        SecLogout();
    else
    {
        if( UserType == User::NoUserLoggedIn )
            SecLogin();
    }
}

void SecondaryConsole::SecLogin()
{
    if( Login(GetBuffer()) )
    {
        Output = "1. Enable Security Sensors\n";
        Output += "2. Disable Security Sensors\n";
        Output += "3. Logout\n";
        BufferClear();
    }
    else
    {
        Output = "Incorrect passcode.\nEnter access code.\n";
        BufferClear();
    }
}

void SecondaryConsole::SecLogout()
{
    Output = "Enter access code.\n";
    BufferClear();
    Logout();
}

void SecondaryConsole::EnableSecurity()
{
    G.Enable(G.SECURITYSENSOR);
    F.Enable(F.SECURITYSENSOR);
    K.Enable(K.SECURITYSENSOR);
    D.Enable(D.SECURITYSENSOR);
    Bed.Enable(Bed.SECURITYSENSOR);
    Bath.Enable(Bath.SECURITYSENSOR);
    O.Enable(O.SECURITYSENSOR);

    BufferClear();
    Logout();

    Output = "All security sensors were enabled.\nEnter access code.\n";
}

void SecondaryConsole::DisableSecurity()
{
    G.Disable(G.SECURITYSENSOR);
    F.Disable(F.SECURITYSENSOR);
    K.Disable(K.SECURITYSENSOR);
    D.Disable(D.SECURITYSENSOR);
    Bed.Disable(Bed.SECURITYSENSOR);
    Bath.Disable(Bath.SECURITYSENSOR);
    O.Disable(O.SECURITYSENSOR);

    BufferClear();
    Logout();

    Output = "All security sensors were disabled.\nEnter access code.\n";
}
