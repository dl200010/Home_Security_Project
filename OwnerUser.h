
#ifndef OWNERUSER_H
#define OWNERUSER_H

#include <wx/wx.h>
#include "User.h" // inheriting class's header file

/*
 * Has access to any Console.
 * PrimaryConsole allows DisplayOwnerMenu().
 */
class OwnerUser : public User
{
	public:
        static const int UserSetting;
		OwnerUser(wxString code);
		~OwnerUser();
		
        int Login(wxString code);
        int Logout();
};

#endif // OWNERUSER_H
