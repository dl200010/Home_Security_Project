//---------------------------------------------------------------------------
//
// Name:        wxMainPanelDlg.h
// Author:      
// Created:     11/17/2006 3:38:40 PM
// Description: wxMainPanelDlg class declaration
//
//---------------------------------------------------------------------------

#ifndef __WXMAINPANELDLG_h__
#define __WXMAINPANELDLG_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

#include "wxMasterPanelDlg.h"
#include "wxSecondaryPanelDlg.h"
#include "wxTestPanelDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef wxMainPanelDlg_STYLE
#define wxMainPanelDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class wxMainPanelDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	    wxMasterPanelDlg *Master;
		wxSecondaryPanelDlg *Secondary;
		wxTestPanelDlg *Test;
		
	public:
        wxMainPanelDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Main Panel"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxMainPanelDlg_STYLE);
		virtual ~wxMainPanelDlg();
		void ExitButtonClick(wxCommandEvent& event);
		void MasterButtonClick(wxCommandEvent& event);
		void SecondaryButtonClick(wxCommandEvent& event);
		void TestButtonClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *CurrentTime;
		wxRadioBox *wxRadioBoxMinute;
		wxRadioBox *wxRadioBoxHour;
		wxButton *ExitButton;
		wxButton *TestButton;
		wxButton *SecondaryButton;
		wxButton *MasterButton;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_CURRENTTIME = 1017,
			ID_WXRADIOBOXMINUTE = 1016,
			ID_WXRADIOBOXHOUR = 1015,
			ID_EXITBUTTON = 1010,
			ID_TESTBUTTON = 1009,
			ID_SECONDARYBUTTON = 1008,
			ID_MASTERBUTTON = 1007,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		
    public:
        static int currentTime;
    private:
        void OnTimeUpdated(wxCommandEvent& event);
        void TimeUpdated();
        Console ConsoleInterface;
};

#endif
