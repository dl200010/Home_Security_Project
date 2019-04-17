//---------------------------------------------------------------------------
//
// Name:        wxSecondaryPanelDlg.cpp
// Author:      
// Created:     11/17/2006 3:41:58 PM
// Description: wxSecondaryPanelDlg class implementation
//
//---------------------------------------------------------------------------


#include "wxSecondaryPanelDlg.h"

bool wxSecondaryPanelDlg::updated = false;

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// wxSecondaryPanelDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(wxSecondaryPanelDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(wxSecondaryPanelDlg::OnClose)
	EVT_BUTTON(ID_BUTTONENTER,wxSecondaryPanelDlg::ButtonEnterClick)
	EVT_BUTTON(ID_BUTTONZERO,wxSecondaryPanelDlg::ButtonZeroClick)
	EVT_BUTTON(ID_BUTTONNINE,wxSecondaryPanelDlg::ButtonNineClick)
	EVT_BUTTON(ID_BUTTONEIGHT,wxSecondaryPanelDlg::ButtonEightClick)
	EVT_BUTTON(ID_BUTTONSEVEN,wxSecondaryPanelDlg::ButtonSevenClick)
	EVT_BUTTON(ID_BUTTONSIX,wxSecondaryPanelDlg::ButtonSixClick)
	EVT_BUTTON(ID_BUTTONFIVE,wxSecondaryPanelDlg::ButtonFiveClick)
	EVT_BUTTON(ID_BUTTONFOUR,wxSecondaryPanelDlg::ButtonFourClick)
	EVT_BUTTON(ID_BUTTONTHREE,wxSecondaryPanelDlg::ButtonThreeClick)
	EVT_BUTTON(ID_BUTTONTWO,wxSecondaryPanelDlg::ButtonTwoClick)
	EVT_BUTTON(ID_BUTTONONE,wxSecondaryPanelDlg::ButtonOneClick)
	
	EVT_UPDATE_UI(ID_OUTPUTCTRL,wxSecondaryPanelDlg::OutputCtrlUpdateUI)
END_EVENT_TABLE()
////Event Table End

wxSecondaryPanelDlg::wxSecondaryPanelDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
	OutputCtrl->SetEditable(false);
}

wxSecondaryPanelDlg::~wxSecondaryPanelDlg()
{
} 

void wxSecondaryPanelDlg::CreateGUIControls()
{
	//Do not add custom code here
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("Secondary Panel"));
	SetIcon(wxNullIcon);
	SetSize(8,8,242,434);
	Center();
	

	ButtonEnter = new wxButton(this, ID_BUTTONENTER, wxT("Enter"), wxPoint(157,340), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonEnter"));

	ButtonZero = new wxButton(this, ID_BUTTONZERO, wxT("0"), wxPoint(30,340), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonZero"));

	ButtonNine = new wxButton(this, ID_BUTTONNINE, wxT("9"), wxPoint(157,287), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonNine"));

	ButtonEight = new wxButton(this, ID_BUTTONEIGHT, wxT("8"), wxPoint(92,287), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonEight"));

	ButtonSeven = new wxButton(this, ID_BUTTONSEVEN, wxT("7"), wxPoint(30,287), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonSeven"));

	ButtonSix = new wxButton(this, ID_BUTTONSIX, wxT("6"), wxPoint(157,232), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonSix"));

	ButtonFive = new wxButton(this, ID_BUTTONFIVE, wxT("5"), wxPoint(92,232), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonFive"));

	ButtonFour = new wxButton(this, ID_BUTTONFOUR, wxT("4"), wxPoint(30,232), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonFour"));

	ButtonThree = new wxButton(this, ID_BUTTONTHREE, wxT("3"), wxPoint(157,178), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonThree"));

	ButtonTwo = new wxButton(this, ID_BUTTONTWO, wxT("2"), wxPoint(92,178), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonTwo"));

	ButtonOne = new wxButton(this, ID_BUTTONONE, wxT("1"), wxPoint(30,178), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonOne"));

	OutputCtrl = new wxRichTextCtrl(this, ID_OUTPUTCTRL, wxT(""), wxPoint(20,22), wxSize(196,149), wxVSCROLL);
	OutputCtrl->SetMaxLength(0);
	OutputCtrl->AppendText(wxT("Enter access code.\n"));
	OutputCtrl->SetFocus();
	OutputCtrl->SetInsertionPointEnd();
	////GUI Items Creation End
}

void wxSecondaryPanelDlg::OnClose(wxCloseEvent& event)
{
	this->Show(false);
}

void wxSecondaryPanelDlg::ButtonOneClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('1');
}

void wxSecondaryPanelDlg::ButtonTwoClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('2');
}

void wxSecondaryPanelDlg::ButtonThreeClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('3');
}

void wxSecondaryPanelDlg::ButtonFourClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('4');
}

void wxSecondaryPanelDlg::ButtonFiveClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('5');
}

void wxSecondaryPanelDlg::ButtonSixClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('6');
}

void wxSecondaryPanelDlg::ButtonSevenClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('7');
}

void wxSecondaryPanelDlg::ButtonEightClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('8');
}

void wxSecondaryPanelDlg::ButtonNineClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('9');
}

void wxSecondaryPanelDlg::ButtonZeroClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('0');
}

void wxSecondaryPanelDlg::ButtonEnterClick(wxCommandEvent& event)
{
    ConsoleInterface.DoNextAction();
    updated = false;
    wxMasterPanelDlg::updated = false;
}

void wxSecondaryPanelDlg::OutputCtrlUpdateUI(wxUpdateUIEvent& event)
{
    if (updated) return;

    wxString* names = new wxString[7];
    bool ** test = new bool*[7];
    for(int count = 0; count < 7; count++)
        test[count] = new bool[3];
    ConsoleInterface.CheckSensors(names, test);

    if (ConsoleInterface.GetSystemError())
    {
        updated = true;
        OutputCtrl->Clear();
    }
    else
    {
        updated = true;
        OutputCtrl->Clear();
        OutputCtrl->AppendText( wxT( ConsoleInterface.GetOutput() ) );
        return;
    }

    for(int count = 0; count < 7; count++)
    {
        if(test[count][Room::FIRESENSOR])
            OutputCtrl->AppendText( wxT( "There is a fire in the " + names[count] + ".\n") );
        else if(test[count][Room::SECURITYSENSOR])
            OutputCtrl->AppendText( wxT( "There is a security break in the " + names[count] + ".\n") );
        else if(test[count][Room::COSENSOR])
            OutputCtrl->AppendText( wxT( "There is CO in the " + names[count] + ".\n") );
    }

    delete names;
    names = NULL;

    for(int count = 0; count < 7; count++)
    {
        delete test[count];
        test[count] = NULL;
    }
    delete test;
    test = NULL;
    
    ConsoleInterface.OnSystemError();
    OutputCtrl->AppendText( wxT( ConsoleInterface.GetOutput() ) );
}
