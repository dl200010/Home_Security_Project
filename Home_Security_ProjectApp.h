//---------------------------------------------------------------------------
//
// Name:        Home_Security_ProjectApp.h
// Author:      
// Created:     11/17/2006 4:11:34 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __HOME_SECURITY_PROJECTApp_h__
#define __HOME_SECURITY_PROJECTApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Home_Security_ProjectApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
