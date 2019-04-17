//---------------------------------------------------------------------------
//
// Name:        wxSecondaryPanelDlg.h
// Author:      
// Created:     11/17/2006 3:41:58 PM
// Description: wxSecondaryPanelDlg class declaration
//
//---------------------------------------------------------------------------

#ifndef __WXSECONDARYPANELDLG_h__
#define __WXSECONDARYPANELDLG_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/button.h>
#include <wx/richtext/richtextctrl.h>
////Header Include End

////Dialog Style Start
#undef wxSecondaryPanelDlg_STYLE
#define wxSecondaryPanelDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

#include "SecondaryConsole.h"
#include "wxMasterPanelDlg.h"
#include "Room.h"


class wxSecondaryPanelDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		wxSecondaryPanelDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Secondary Panel"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxSecondaryPanelDlg_STYLE);
		virtual ~wxSecondaryPanelDlg();
		void ButtonOneClick(wxCommandEvent& event);
		void ButtonTwoClick(wxCommandEvent& event);
		void ButtonThreeClick(wxCommandEvent& event);
		void ButtonFourClick(wxCommandEvent& event);
		void ButtonFiveClick(wxCommandEvent& event);
		void ButtonSixClick(wxCommandEvent& event);
		void ButtonSevenClick(wxCommandEvent& event);
		void ButtonEightClick(wxCommandEvent& event);
		void ButtonNineClick(wxCommandEvent& event);
		void ButtonZeroClick(wxCommandEvent& event);
		void ButtonEnterClick(wxCommandEvent& event);
		void OutputCtrlUpdateUI(wxUpdateUIEvent& event);
	
	private:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *ButtonEnter;
		wxButton *ButtonZero;
		wxButton *ButtonNine;
		wxButton *ButtonEight;
		wxButton *ButtonSeven;
		wxButton *ButtonSix;
		wxButton *ButtonFive;
		wxButton *ButtonFour;
		wxButton *ButtonThree;
		wxButton *ButtonTwo;
		wxButton *ButtonOne;
		wxRichTextCtrl *OutputCtrl;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_BUTTONENTER = 1078,
			ID_BUTTONZERO = 1077,
			ID_BUTTONNINE = 1076,
			ID_BUTTONEIGHT = 1075,
			ID_BUTTONSEVEN = 1074,
			ID_BUTTONSIX = 1073,
			ID_BUTTONFIVE = 1072,
			ID_BUTTONFOUR = 1071,
			ID_BUTTONTHREE = 1070,
			ID_BUTTONTWO = 1069,
			ID_BUTTONONE = 1068,
			ID_OUTPUTCTRL = 1067,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
    public:
        static bool updated;
    private:
        SecondaryConsole ConsoleInterface;
};

#endif
