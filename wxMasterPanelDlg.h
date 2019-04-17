//---------------------------------------------------------------------------
//
// Name:        wxMasterPanelDlg.h
// Author:      
// Created:     11/17/2006 3:43:11 PM
// Description: wxMasterPanelDlg class declaration
//
//---------------------------------------------------------------------------

#ifndef __WXMASTERPANELDLG_h__
#define __WXMASTERPANELDLG_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

#include "PrimaryConsole.h"
#include "Room.h"
#include "wxMasterPanelDlgCanvas.h"
#include "wxSecondaryPanelDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/scrolwin.h>
////Header Include End

////Dialog Style Start
#undef wxMasterPanelDlg_STYLE
#define wxMasterPanelDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class wxMasterPanelDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		wxMasterPanelDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Master Panel"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxMasterPanelDlg_STYLE);
		virtual ~wxMasterPanelDlg();
		void ButtonEightClick(wxCommandEvent& event);
		void ButtonEnterClick(wxCommandEvent& event);
		void ButtonNineClick(wxCommandEvent& event);
		void ButtonOneClick(wxCommandEvent& event);
		void ButtonTwoClick(wxCommandEvent& event);
		void ButtonThreeClick(wxCommandEvent& event);
		void ButtonFourClick(wxCommandEvent& event);
		void ButtonFiveClick(wxCommandEvent& event);
		void ButtonSixClick(wxCommandEvent& event);
		void ButtonSevenClick(wxCommandEvent& event);
		void ButtonZeroClick(wxCommandEvent& event);
		void OutputCtrlUpdateUI(wxUpdateUIEvent& event);
	
	private:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticBitmap *Bed_SecurityBitmap;
		wxStaticBitmap *Bed_COBitmap;
		wxStaticBitmap *Bed_FireBitmap;
		wxStaticBitmap *Bath_SecurityBitmap;
		wxStaticBitmap *Bath_COBitmap;
		wxStaticBitmap *Bath_FireBitmap;
		wxStaticBitmap *O_SecurityBitmap;
		wxStaticBitmap *O_COBitmap;
		wxStaticBitmap *O_FireBitmap;
		wxStaticBitmap *D_SecurityBitmap;
		wxStaticBitmap *D_COBitmap;
		wxStaticBitmap *D_FireBitmap;
		wxStaticBitmap *K_SecurityBitmap;
		wxStaticBitmap *K_COBitmap;
		wxStaticBitmap *K_FireBitmap;
		wxStaticBitmap *F_SecurityBitmap;
		wxStaticBitmap *F_COBitmap;
		wxStaticBitmap *F_FireBitmap;
		wxStaticBitmap *G_SecurityBitmap;
		wxStaticBitmap *G_COBitmap;
		wxStaticBitmap *G_FireBitmap;
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
		wxMasterPanelDlgCanvas *mp_canvas;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_BED_SECURITYBITMAP = 1693,
			ID_BED_COBITMAP = 1692,
			ID_BED_FIREBITMAP = 1691,
			ID_BATH_SECURITYBITMAP = 1690,
			ID_BATH_COBITMAP = 1689,
			ID_BATH_FIREBITMAP = 1688,
			ID_O_SECURITYBITMAP = 1687,
			ID_O_COBITMAP = 1686,
			ID_O_FIREBITMAP = 1685,
			ID_D_SECURITYBITMAP = 1684,
			ID_D_COBITMAP = 1683,
			ID_D_FIREBITMAP = 1682,
			ID_K_SECURITYBITMAP = 1681,
			ID_K_COBITMAP = 1680,
			ID_K_FIREBITMAP = 1679,
			ID_F_SECURITYBITMAP = 1678,
			ID_F_COBITMAP = 1677,
			ID_F_FIREBITMAP = 1676,
			ID_G_SECURITYBITMAP = 1675,
			ID_G_COBITMAP = 1674,
			ID_G_FIREBITMAP = 1673,
			ID_BUTTONENTER = 1672,
			ID_BUTTONZERO = 1671,
			ID_BUTTONNINE = 1670,
			ID_BUTTONEIGHT = 1669,
			ID_BUTTONSEVEN = 1668,
			ID_BUTTONSIX = 1667,
			ID_BUTTONFIVE = 1666,
			ID_BUTTONFOUR = 1665,
			ID_BUTTONTHREE = 1664,
			ID_BUTTONTWO = 1663,
			ID_BUTTONONE = 1662,
			ID_OUTPUTCTRL = 1661,
			ID_MP_CANVAS = 1132,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
    public:
       static bool updated;
	private:
        PrimaryConsole ConsoleInterface;
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		bool boolFire[7];
		bool boolCO[7];
        bool boolSecurity[7];
};

#endif
