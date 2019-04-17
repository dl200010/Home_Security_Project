//---------------------------------------------------------------------------
//
// Name:        wxTestPanelDlg.h
// Author:      
// Created:     11/17/2006 3:48:04 PM
// Description: wxTestPanelDlg class declaration
//
//---------------------------------------------------------------------------

#ifndef __WXTESTPANELDLG_h__
#define __WXTESTPANELDLG_h__

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
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/notebook.h>
////Header Include End

#include "Console.h"
#include "wxMasterPanelDlg.h"
#include "wxSecondaryPanelDlg.h"

////Dialog Style Start
#undef wxTestPanelDlg_STYLE
#define wxTestPanelDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class wxTestPanelDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		wxTestPanelDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Test Panel"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTestPanelDlg_STYLE);
		virtual ~wxTestPanelDlg();
	
	private:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *TestButtonSecurity;
		wxCheckBox *O_Security_Check;
		wxCheckBox *Bath_Security_Check;
		wxCheckBox *Bed_Security_Check;
		wxCheckBox *F_Security_Check;
		wxCheckBox *D_Security_Check;
		wxCheckBox *K_Security_Check;
		wxCheckBox *G_Security_Check;
		wxPanel *SecuritySensors;
		wxButton *TestButtonCO;
		wxCheckBox *O_CO_Check;
		wxCheckBox *Bath_CO_Check;
		wxCheckBox *Bed_CO_Check;
		wxCheckBox *F_CO_Check;
		wxCheckBox *D_CO_Check;
		wxCheckBox *K_CO_Check;
		wxCheckBox *G_CO_Check;
		wxPanel *COSensors;
		wxButton *TestButtonFire;
		wxCheckBox *O_Fire_Check;
		wxCheckBox *Bath_Fire_Check;
		wxCheckBox *Bed_Fire_Check;
		wxCheckBox *F_Fire_Check;
		wxCheckBox *D_Fire_Check;
		wxCheckBox *K_Fire_Check;
		wxCheckBox *G_Fire_Check;
		wxPanel *FireSensors;
		wxNotebook *Sensors;
		////GUI Control Declaration End

        void TestClicked(wxCommandEvent& event);
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_TESTBUTTONSECURITY = 1207,
			ID_O_SECURITY_CHECK = 1204,
			ID_BATH_SECURITY_CHECK = 1203,
			ID_BED_SECURITY_CHECK = 1202,
			ID_F_SECURITY_CHECK = 1201,
			ID_D_SECURITY_CHECK = 1200,
			ID_K_SECURITY_CHECK = 1199,
			ID_G_SECURITY_CHECK = 1198,
			ID_SECURITYSENSORS = 1006,
			ID_TESTBUTTONCO = 1206,
			ID_O_CO_CHECK = 1176,
			ID_BATH_CO_CHECK = 1175,
			ID_BED_CO_CHECK = 1174,
			ID_F_CO_CHECK = 1173,
			ID_D_CO_CHECK = 1172,
			ID_K_CO_CHECK = 1171,
			ID_G_CO_CHECK = 1170,
			ID_COSENSORS = 1004,
			ID_TESTBUTTONFIRE = 1205,
			ID_O_FIRE_CHECK = 1148,
			ID_BATH_FIRE_CHECK = 1147,
			ID_BED_FIRE_CHECK = 1146,
			ID_F_FIRE_CHECK = 1145,
			ID_D_FIRE_CHECK = 1144,
			ID_K_FIRE_CHECK = 1143,
			ID_G_FIRE_CHECK = 1142,
			ID_FIRESENSORS = 1003,
			ID_SENSORS = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        Console ConsoleInterface;
};

#endif
