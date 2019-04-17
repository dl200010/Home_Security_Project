
#ifndef SECONDARYCONSOLE_H
#define SECONDARYCONSOLE_H

#include <wx/wx.h>
#include "Console.h" // inheriting class's header file

/*
 * Allows any User with access rights to Enable/Disable SecuritySensors.
 */
class SecondaryConsole : public Console
{
	public:
		SecondaryConsole();
		~SecondaryConsole();
		
		void SecLogin();
		void SecLogout();
		
		void EnableSecurity();
		void DisableSecurity();

        void DoNextAction();
        wxString GetOutput();
};

#endif // SECONDARYCONSOLE_H
