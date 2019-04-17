
#ifndef USER_H
#define USER_H

#include <wx/wx.h>

/*
 * Users operate Consoles
 */
class User
{
	public:
        static const int NoUserLoggedIn;
        
		User(wxString inCode);
		~User();
		
        bool VerifyLogin(wxString code);
        
        void ChangeAccessCode(wxString code);
        
        wxString GetAccessCode();
        
    private:
        wxString accessCode;
};

#endif // USER_H
