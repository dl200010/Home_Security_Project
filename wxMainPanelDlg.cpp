//---------------------------------------------------------------------------
//
// Name:        wxMainPanelDlg.cpp
// Author:
// Created:     11/17/2006 3:38:40 PM
// Description: wxMainPanelDlg class implementation
//
//---------------------------------------------------------------------------

#include "wxMainPanelDlg.h"

int wxMainPanelDlg::currentTime = 0;

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// wxMainPanelDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(wxMainPanelDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(wxMainPanelDlg::OnClose)
	EVT_RADIOBOX(ID_WXRADIOBOXMINUTE,wxMainPanelDlg::OnTimeUpdated)
	EVT_RADIOBOX(ID_WXRADIOBOXHOUR,wxMainPanelDlg::OnTimeUpdated)
	EVT_BUTTON(ID_EXITBUTTON,wxMainPanelDlg::ExitButtonClick)
	EVT_BUTTON(ID_TESTBUTTON,wxMainPanelDlg::TestButtonClick)
	EVT_BUTTON(ID_SECONDARYBUTTON,wxMainPanelDlg::SecondaryButtonClick)
	EVT_BUTTON(ID_MASTERBUTTON,wxMainPanelDlg::MasterButtonClick)
END_EVENT_TABLE()
////Event Table End

wxMainPanelDlg::wxMainPanelDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    Master = new wxMasterPanelDlg(this);
    Secondary = new wxSecondaryPanelDlg(this);
    Test = new wxTestPanelDlg(this);
    CreateGUIControls();
    TimeUpdated();
}

wxMainPanelDlg::~wxMainPanelDlg()
{
}

void wxMainPanelDlg::CreateGUIControls()
{
    //Do not add custom code here
    //wxDev-C++ designer will remove them.
    //Add the custom code before or after the blocks
    ////GUI Items Creation Start

	SetTitle(wxT("Main Panel"));
	SetIcon(wxNullIcon);
	SetSize(50,50,242,438);
	

	CurrentTime = new wxStaticText(this, ID_CURRENTTIME, wxT(""), wxPoint(15,371), wxSize(208, 22), wxST_NO_AUTORESIZE, wxT("CurrentTime"));

	wxArrayString arrayStringFor_wxRadioBoxMinute;
	arrayStringFor_wxRadioBoxMinute.Add(wxT("00"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("05"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("10"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("15"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("20"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("25"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("30"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("35"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("40"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("45"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("50"));
	arrayStringFor_wxRadioBoxMinute.Add(wxT("55"));
	wxRadioBoxMinute = new wxRadioBox(this, ID_WXRADIOBOXMINUTE, wxT("Minute"), wxPoint(128,100), wxSize(51,252), arrayStringFor_wxRadioBoxMinute, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, wxT("wxRadioBoxMinute"));
	wxRadioBoxMinute->SetSelection(0);

	wxArrayString arrayStringFor_wxRadioBoxHour;
	arrayStringFor_wxRadioBoxHour.Add(wxT("0"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("1"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("2"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("3"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("4"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("5"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("6"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("7"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("8"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("9"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("10"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("11"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("12"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("13"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("14"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("15"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("16"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("17"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("18"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("19"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("20"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("21"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("22"));
	arrayStringFor_wxRadioBoxHour.Add(wxT("23"));
	wxRadioBoxHour = new wxRadioBox(this, ID_WXRADIOBOXHOUR, wxT("Hour"), wxPoint(15,100), wxSize(84,252), arrayStringFor_wxRadioBoxHour, 2, wxRA_SPECIFY_COLS, wxDefaultValidator, wxT("wxRadioBoxHour"));
	wxRadioBoxHour->SetSelection(0);

	ExitButton = new wxButton(this, ID_EXITBUTTON, wxT("Exit"), wxPoint(128,62), wxSize(91,26), 0, wxDefaultValidator, wxT("ExitButton"));

	TestButton = new wxButton(this, ID_TESTBUTTON, wxT("Test Panel"), wxPoint(15,62), wxSize(93,26), 0, wxDefaultValidator, wxT("TestButton"));

	SecondaryButton = new wxButton(this, ID_SECONDARYBUTTON, wxT("Secondary Panel"), wxPoint(128,16), wxSize(91,29), 0, wxDefaultValidator, wxT("SecondaryButton"));

	MasterButton = new wxButton(this, ID_MASTERBUTTON, wxT("Master Panel"), wxPoint(16,16), wxSize(93,28), 0, wxDefaultValidator, wxT("MasterButton"));
    ////GUI Items Creation End
}

void wxMainPanelDlg::OnClose(wxCloseEvent& event)
{
    Destroy();
    Master->Destroy();
    Secondary->Destroy();
    Test->Destroy();
}

void wxMainPanelDlg::ExitButtonClick(wxCommandEvent& event)
{
    Destroy();
    Master->Destroy();
    Secondary->Destroy();
    Test->Destroy();
}

void wxMainPanelDlg::MasterButtonClick(wxCommandEvent& event)
{
    Secondary->Show(false);
    Master->Show(true);
}

void wxMainPanelDlg::SecondaryButtonClick(wxCommandEvent& event)
{
    Master->Show(false);
    Secondary->Show(true);
}

void wxMainPanelDlg::TestButtonClick(wxCommandEvent& event)
{
    Test->Show(true);
}

void wxMainPanelDlg::OnTimeUpdated(wxCommandEvent& event)
{
    TimeUpdated();
}

void wxMainPanelDlg::TimeUpdated()
{
    long *hour = new long;
    (*hour) = 0;
    long *minute = new long;
    (*minute) = 0;

    wxString strHour = wxRadioBoxHour->GetStringSelection();
    wxString strMinute = wxRadioBoxMinute->GetStringSelection();
    
    strHour.Shrink();
    strMinute.Shrink();

    strHour.ToLong(hour);
    strMinute.ToLong(minute);

    currentTime = ((int)(*hour) * 60) + (int)(*minute);
    CurrentTime->SetLabel( "Current Time: " + strHour + ":" + strMinute );
    
    delete hour;
    delete minute;
}

