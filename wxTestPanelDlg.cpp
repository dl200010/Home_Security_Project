//---------------------------------------------------------------------------
//
// Name:        wxTestPanelDlg.cpp
// Author:      
// Created:     11/17/2006 3:48:04 PM
// Description: wxTestPanelDlg class implementation
//
//---------------------------------------------------------------------------

#include "wxTestPanelDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// wxTestPanelDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(wxTestPanelDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(wxTestPanelDlg::OnClose)
	EVT_BUTTON(ID_TESTBUTTONSECURITY,wxTestPanelDlg::TestClicked)
	EVT_BUTTON(ID_TESTBUTTONCO,wxTestPanelDlg::TestClicked)
	EVT_BUTTON(ID_TESTBUTTONFIRE,wxTestPanelDlg::TestClicked)
END_EVENT_TABLE()
////Event Table End

wxTestPanelDlg::wxTestPanelDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

wxTestPanelDlg::~wxTestPanelDlg()
{
} 

void wxTestPanelDlg::CreateGUIControls()
{
	//Do not add custom code here
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	Sensors = new wxNotebook(this, ID_SENSORS, wxPoint(0,0),wxSize(237,464));

	FireSensors = new wxPanel(Sensors, ID_FIRESENSORS, wxPoint(4,24), wxSize(229,436));
	Sensors->AddPage(FireSensors, wxT("Fire Sensors"));

	G_Fire_Check = new wxCheckBox(FireSensors, ID_G_FIRE_CHECK, wxT("Garage"), wxPoint(75,51), wxSize(97,17), 0, wxDefaultValidator, wxT("G_Fire_Check"));

	K_Fire_Check = new wxCheckBox(FireSensors, ID_K_FIRE_CHECK, wxT("Kitchen"), wxPoint(75,76), wxSize(97,17), 0, wxDefaultValidator, wxT("K_Fire_Check"));

	D_Fire_Check = new wxCheckBox(FireSensors, ID_D_FIRE_CHECK, wxT("Dining Room"), wxPoint(75,99), wxSize(97,17), 0, wxDefaultValidator, wxT("D_Fire_Check"));

	F_Fire_Check = new wxCheckBox(FireSensors, ID_F_FIRE_CHECK, wxT("Family Room"), wxPoint(75,125), wxSize(97,17), 0, wxDefaultValidator, wxT("F_Fire_Check"));

	Bed_Fire_Check = new wxCheckBox(FireSensors, ID_BED_FIRE_CHECK, wxT("Bedroom"), wxPoint(75,149), wxSize(97,17), 0, wxDefaultValidator, wxT("Bed_Fire_Check"));

	Bath_Fire_Check = new wxCheckBox(FireSensors, ID_BATH_FIRE_CHECK, wxT("Bathroom"), wxPoint(75,174), wxSize(97,17), 0, wxDefaultValidator, wxT("Bath_Fire_Check"));

	O_Fire_Check = new wxCheckBox(FireSensors, ID_O_FIRE_CHECK, wxT("Office"), wxPoint(75,197), wxSize(97,17), 0, wxDefaultValidator, wxT("O_Fire_Check"));

	TestButtonFire = new wxButton(FireSensors, ID_TESTBUTTONFIRE, wxT("Test"), wxPoint(60,372), wxSize(98,33), 0, wxDefaultValidator, wxT("TestButtonFire"));

	COSensors = new wxPanel(Sensors, ID_COSENSORS, wxPoint(4,24), wxSize(229,436));
	Sensors->AddPage(COSensors, wxT("CO Sensors"));

	G_CO_Check = new wxCheckBox(COSensors, ID_G_CO_CHECK, wxT("Garage"), wxPoint(75,51), wxSize(97,17), 0, wxDefaultValidator, wxT("G_CO_Check"));

	K_CO_Check = new wxCheckBox(COSensors, ID_K_CO_CHECK, wxT("Kitchen"), wxPoint(75,76), wxSize(97,17), 0, wxDefaultValidator, wxT("K_CO_Check"));

	D_CO_Check = new wxCheckBox(COSensors, ID_D_CO_CHECK, wxT("Dining Room"), wxPoint(75,99), wxSize(97,17), 0, wxDefaultValidator, wxT("D_CO_Check"));

	F_CO_Check = new wxCheckBox(COSensors, ID_F_CO_CHECK, wxT("Family Room"), wxPoint(75,125), wxSize(97,17), 0, wxDefaultValidator, wxT("F_CO_Check"));

	Bed_CO_Check = new wxCheckBox(COSensors, ID_BED_CO_CHECK, wxT("Bedroom"), wxPoint(75,149), wxSize(97,17), 0, wxDefaultValidator, wxT("Bed_CO_Check"));

	Bath_CO_Check = new wxCheckBox(COSensors, ID_BATH_CO_CHECK, wxT("Bathroom"), wxPoint(75,174), wxSize(97,17), 0, wxDefaultValidator, wxT("Bath_CO_Check"));

	O_CO_Check = new wxCheckBox(COSensors, ID_O_CO_CHECK, wxT("Office"), wxPoint(75,197), wxSize(97,17), 0, wxDefaultValidator, wxT("O_CO_Check"));

	TestButtonCO = new wxButton(COSensors, ID_TESTBUTTONCO, wxT("Test"), wxPoint(60,372), wxSize(98,33), 0, wxDefaultValidator, wxT("TestButtonCO"));

	SecuritySensors = new wxPanel(Sensors, ID_SECURITYSENSORS, wxPoint(4,24), wxSize(229,436));
	Sensors->AddPage(SecuritySensors, wxT("Security Sensors"));

	G_Security_Check = new wxCheckBox(SecuritySensors, ID_G_SECURITY_CHECK, wxT("Garage"), wxPoint(75,51), wxSize(97,17), 0, wxDefaultValidator, wxT("G_Security_Check"));

	K_Security_Check = new wxCheckBox(SecuritySensors, ID_K_SECURITY_CHECK, wxT("Kitchen"), wxPoint(75,76), wxSize(97,17), 0, wxDefaultValidator, wxT("K_Security_Check"));

	D_Security_Check = new wxCheckBox(SecuritySensors, ID_D_SECURITY_CHECK, wxT("Dining Room"), wxPoint(75,99), wxSize(97,17), 0, wxDefaultValidator, wxT("D_Security_Check"));

	F_Security_Check = new wxCheckBox(SecuritySensors, ID_F_SECURITY_CHECK, wxT("Family Room"), wxPoint(75,125), wxSize(97,17), 0, wxDefaultValidator, wxT("F_Security_Check"));

	Bed_Security_Check = new wxCheckBox(SecuritySensors, ID_BED_SECURITY_CHECK, wxT("Bedroom"), wxPoint(75,149), wxSize(97,17), 0, wxDefaultValidator, wxT("Bed_Security_Check"));

	Bath_Security_Check = new wxCheckBox(SecuritySensors, ID_BATH_SECURITY_CHECK, wxT("Bathroom"), wxPoint(75,174), wxSize(97,17), 0, wxDefaultValidator, wxT("Bath_Security_Check"));

	O_Security_Check = new wxCheckBox(SecuritySensors, ID_O_SECURITY_CHECK, wxT("Office"), wxPoint(75,197), wxSize(97,17), 0, wxDefaultValidator, wxT("O_Security_Check"));

	TestButtonSecurity = new wxButton(SecuritySensors, ID_TESTBUTTONSECURITY, wxT("Test"), wxPoint(60,372), wxSize(98,33), 0, wxDefaultValidator, wxT("TestButtonSecurity"));

	SetTitle(wxT("Test Panel"));
	SetIcon(wxNullIcon);
	SetSize(1000,50,245,498);
	
	////GUI Items Creation End
}

void wxTestPanelDlg::TestClicked(wxCommandEvent& event)
{
    //all the fire sensors
	if( G_Fire_Check->GetValue() )
        ConsoleInterface.TripG(Room::FIRESENSOR);
	else
        ConsoleInterface.ResetG(Room::FIRESENSOR);
	if( K_Fire_Check->GetValue() )
        ConsoleInterface.TripK(Room::FIRESENSOR);
	else
        ConsoleInterface.ResetK(Room::FIRESENSOR);
	if( D_Fire_Check->GetValue() )
        ConsoleInterface.TripD(Room::FIRESENSOR);
	else
        ConsoleInterface.ResetD(Room::FIRESENSOR);
	if( F_Fire_Check->GetValue() )
        ConsoleInterface.TripF(Room::FIRESENSOR);
	else
        ConsoleInterface.ResetF(Room::FIRESENSOR);
	if( Bed_Fire_Check->GetValue() )
        ConsoleInterface.TripBed(Room::FIRESENSOR);
	else
        ConsoleInterface.ResetBed(Room::FIRESENSOR);
	if( Bath_Fire_Check->GetValue() )
        ConsoleInterface.TripBath(Room::FIRESENSOR);
	else
        ConsoleInterface.ResetBath(Room::FIRESENSOR);
	if( O_Fire_Check->GetValue() )
        ConsoleInterface.TripO(Room::FIRESENSOR);
	else
        ConsoleInterface.ResetO(Room::FIRESENSOR);

    //all the CO sensors
	if( G_CO_Check->GetValue() )
        ConsoleInterface.TripG(Room::COSENSOR);
	else
        ConsoleInterface.ResetG(Room::COSENSOR);
	if( K_CO_Check->GetValue() )
        ConsoleInterface.TripK(Room::COSENSOR);
	else
        ConsoleInterface.ResetK(Room::COSENSOR);
	if( D_CO_Check->GetValue() )
        ConsoleInterface.TripD(Room::COSENSOR);
	else
        ConsoleInterface.ResetD(Room::COSENSOR);
	if( F_CO_Check->GetValue() )
        ConsoleInterface.TripF(Room::COSENSOR);
	else
        ConsoleInterface.ResetF(Room::COSENSOR);
	if( Bed_CO_Check->GetValue() )
        ConsoleInterface.TripBed(Room::COSENSOR);
	else
        ConsoleInterface.ResetBed(Room::COSENSOR);
	if( Bath_CO_Check->GetValue() )
        ConsoleInterface.TripBath(Room::COSENSOR);
	else
        ConsoleInterface.ResetBath(Room::COSENSOR);
	if( O_CO_Check->GetValue() )
        ConsoleInterface.TripO(Room::COSENSOR);
	else
        ConsoleInterface.ResetO(Room::COSENSOR);

    //all the security sensors
	if( G_Security_Check->GetValue() )
        ConsoleInterface.TripG(Room::SECURITYSENSOR);
	else
        ConsoleInterface.ResetG(Room::SECURITYSENSOR);
	if( K_Security_Check->GetValue() )
        ConsoleInterface.TripK(Room::SECURITYSENSOR);
	else
        ConsoleInterface.ResetK(Room::SECURITYSENSOR);
	if( D_Security_Check->GetValue() )
        ConsoleInterface.TripD(Room::SECURITYSENSOR);
	else
        ConsoleInterface.ResetD(Room::SECURITYSENSOR);
	if( F_Security_Check->GetValue() )
        ConsoleInterface.TripF(Room::SECURITYSENSOR);
	else
        ConsoleInterface.ResetF(Room::SECURITYSENSOR);
	if( Bed_Security_Check->GetValue() )
        ConsoleInterface.TripBed(Room::SECURITYSENSOR);
	else
        ConsoleInterface.ResetBed(Room::SECURITYSENSOR);
	if( Bath_Security_Check->GetValue() )
        ConsoleInterface.TripBath(Room::SECURITYSENSOR);
	else
        ConsoleInterface.ResetBath(Room::SECURITYSENSOR);
	if( O_Security_Check->GetValue() )
        ConsoleInterface.TripO(Room::SECURITYSENSOR);
	else
        ConsoleInterface.ResetO(Room::SECURITYSENSOR);

    wxMasterPanelDlg::updated = false;
    wxSecondaryPanelDlg::updated = false;
}

void wxTestPanelDlg::OnClose(wxCloseEvent& event)
{
	this->Show(false);
}
