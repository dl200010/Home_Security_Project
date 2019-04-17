//---------------------------------------------------------------------------
//
// Name:        Home_Security_ProjectApp.cpp
// Author:      
// Created:     11/17/2006 4:11:34 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "Home_Security_ProjectApp.h"
#include "wxMainPanelDlg.h"

IMPLEMENT_APP(Home_Security_ProjectApp)

bool Home_Security_ProjectApp::OnInit()
{
    wxUpdateUIEvent::SetUpdateInterval(0);
	wxMainPanelDlg* dialog = new wxMainPanelDlg(NULL);
	SetTopWindow(dialog);
	dialog->Show(true);		
	return true;
}
 
int Home_Security_ProjectApp::OnExit()
{
	return 0;
}
