
#ifndef TEMPORARYUSER_H
#define TEMPORARYUSER_H

#include <wx/wx.h>
#include "User.h" // inheriting class's header file

/*
 * Has access to only SecondaryConsole within a specified time period.
 */
class TemporaryUser : public User
{
	public:
        static const int UserSetting;
		TemporaryUser(wxString code);
		~TemporaryUser();
		
        int Login(wxString code);
        int Logout();
        
        bool SetTempAccessBegin(int begin);
        bool SetTempAccessEnd(int end);
        
        int GetTempAccessBegin();
        int GetTempAccessEnd();
		
    private:
        int tempAccessBegin;
        int tempAccessEnd;
};

#endif // TEMPORARYUSER_H
