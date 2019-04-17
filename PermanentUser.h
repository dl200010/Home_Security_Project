
#ifndef PERMANENTUSER_H
#define PERMANENTUSER_H

#include <wx/wx.h>
#include "User.h" // inheriting class's header file

/*
 * Has access to any Console.
 * PrimaryConsole allows DisplayPermanentMenu().
 */
class PermanentUser : public User
{
	public:
        static const int UserSetting;
		PermanentUser(wxString code);
		~PermanentUser();
		
        int Login(wxString code);
        int Logout();
};

#endif // PERMANENTUSER_H
