//---------------------------------------------------------------------------
//
// Name:        wxMasterPanelDlg.cpp
// Author:      
// Created:     11/17/2006 3:43:11 PM
// Description: wxMasterPanelDlg class implementation
//
//---------------------------------------------------------------------------

#include "wxMasterPanelDlg.h"

bool wxMasterPanelDlg::updated = false;

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include "Bed_SecurityBitmap_XPM.xpm"
#include "Bed_COBitmap_XPM.xpm"
#include "Bed_FireBitmap_XPM.xpm"
#include "Bath_SecurityBitmap_XPM.xpm"
#include "Bath_COBitmap_XPM.xpm"
#include "Bath_FireBitmap_XPM.xpm"
#include "O_SecurityBitmap_XPM.xpm"
#include "O_COBitmap_XPM.xpm"
#include "O_FireBitmap_XPM.xpm"
#include "D_SecurityBitmap_XPM.xpm"
#include "D_COBitmap_XPM.xpm"
#include "D_FireBitmap_XPM.xpm"
#include "K_SecurityBitmap_XPM.xpm"
#include "K_COBitmap_XPM.xpm"
#include "K_FireBitmap_XPM.xpm"
#include "F_SecurityBitmap_XPM.xpm"
#include "F_COBitmap_XPM.xpm"
#include "F_FireBitmap_XPM.xpm"
#include "G_SecurityBitmap_XPM.xpm"
#include "G_COBitmap_XPM.xpm"
#include "G_FireBitmap_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// wxMasterPanelDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(wxMasterPanelDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(wxMasterPanelDlg::OnClose)
	EVT_BUTTON(ID_BUTTONENTER,wxMasterPanelDlg::ButtonEnterClick)
	EVT_BUTTON(ID_BUTTONZERO,wxMasterPanelDlg::ButtonZeroClick)
	EVT_BUTTON(ID_BUTTONNINE,wxMasterPanelDlg::ButtonNineClick)
	EVT_BUTTON(ID_BUTTONEIGHT,wxMasterPanelDlg::ButtonEightClick)
	EVT_BUTTON(ID_BUTTONSEVEN,wxMasterPanelDlg::ButtonSevenClick)
	EVT_BUTTON(ID_BUTTONSIX,wxMasterPanelDlg::ButtonSixClick)
	EVT_BUTTON(ID_BUTTONFIVE,wxMasterPanelDlg::ButtonFiveClick)
	EVT_BUTTON(ID_BUTTONFOUR,wxMasterPanelDlg::ButtonFourClick)
	EVT_BUTTON(ID_BUTTONTHREE,wxMasterPanelDlg::ButtonThreeClick)
	EVT_BUTTON(ID_BUTTONTWO,wxMasterPanelDlg::ButtonTwoClick)
	EVT_BUTTON(ID_BUTTONONE,wxMasterPanelDlg::ButtonOneClick)
	
	EVT_UPDATE_UI(ID_OUTPUTCTRL,wxMasterPanelDlg::OutputCtrlUpdateUI)
END_EVENT_TABLE()
////Event Table End

wxMasterPanelDlg::wxMasterPanelDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
	OutputCtrl->SetEditable(false);
}

wxMasterPanelDlg::~wxMasterPanelDlg()
{
} 

void wxMasterPanelDlg::CreateGUIControls()
{
	//Do not add custom code here
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	mp_canvas = new wxMasterPanelDlgCanvas(this, ID_MP_CANVAS, wxPoint(0,0), wxSize(716,418));

	OutputCtrl = new wxRichTextCtrl(mp_canvas, ID_OUTPUTCTRL, wxT(""), wxPoint(490,30), wxSize(196,149), wxVSCROLL);
	OutputCtrl->SetMaxLength(0);
	OutputCtrl->AppendText(wxT("Enter access code.\n"));
	OutputCtrl->SetFocus();
	OutputCtrl->SetInsertionPointEnd();

	ButtonOne = new wxButton(mp_canvas, ID_BUTTONONE, wxT("1"), wxPoint(500,186), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonOne"));

	ButtonTwo = new wxButton(mp_canvas, ID_BUTTONTWO, wxT("2"), wxPoint(562,186), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonTwo"));

	ButtonThree = new wxButton(mp_canvas, ID_BUTTONTHREE, wxT("3"), wxPoint(627,186), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonThree"));

	ButtonFour = new wxButton(mp_canvas, ID_BUTTONFOUR, wxT("4"), wxPoint(500,240), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonFour"));

	ButtonFive = new wxButton(mp_canvas, ID_BUTTONFIVE, wxT("5"), wxPoint(562,240), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonFive"));

	ButtonSix = new wxButton(mp_canvas, ID_BUTTONSIX, wxT("6"), wxPoint(627,240), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonSix"));

	ButtonSeven = new wxButton(mp_canvas, ID_BUTTONSEVEN, wxT("7"), wxPoint(500,295), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonSeven"));

	ButtonEight = new wxButton(mp_canvas, ID_BUTTONEIGHT, wxT("8"), wxPoint(562,295), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonEight"));

	ButtonNine = new wxButton(mp_canvas, ID_BUTTONNINE, wxT("9"), wxPoint(627,295), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonNine"));

	ButtonZero = new wxButton(mp_canvas, ID_BUTTONZERO, wxT("0"), wxPoint(500,348), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonZero"));

	ButtonEnter = new wxButton(mp_canvas, ID_BUTTONENTER, wxT("Enter"), wxPoint(627,348), wxSize(56,46), 0, wxDefaultValidator, wxT("ButtonEnter"));

	wxBitmap G_FireBitmap_BITMAP(G_FireBitmap_XPM);
	G_FireBitmap = new wxStaticBitmap(mp_canvas, ID_G_FIREBITMAP, G_FireBitmap_BITMAP, wxPoint(102,73), wxSize(45,45));
	G_FireBitmap->Show(false);
	G_FireBitmap->Enable(false);

	wxBitmap G_COBitmap_BITMAP(G_COBitmap_XPM);
	G_COBitmap = new wxStaticBitmap(mp_canvas, ID_G_COBITMAP, G_COBitmap_BITMAP, wxPoint(103,74), wxSize(45,45));
	G_COBitmap->Show(false);
	G_COBitmap->Enable(false);

	wxBitmap G_SecurityBitmap_BITMAP(G_SecurityBitmap_XPM);
	G_SecurityBitmap = new wxStaticBitmap(mp_canvas, ID_G_SECURITYBITMAP, G_SecurityBitmap_BITMAP, wxPoint(104,74), wxSize(45,45));
	G_SecurityBitmap->Show(false);
	G_SecurityBitmap->Enable(false);

	wxBitmap F_FireBitmap_BITMAP(F_FireBitmap_XPM);
	F_FireBitmap = new wxStaticBitmap(mp_canvas, ID_F_FIREBITMAP, F_FireBitmap_BITMAP, wxPoint(221,53), wxSize(45,45));
	F_FireBitmap->Show(false);
	F_FireBitmap->Enable(false);

	wxBitmap F_COBitmap_BITMAP(F_COBitmap_XPM);
	F_COBitmap = new wxStaticBitmap(mp_canvas, ID_F_COBITMAP, F_COBitmap_BITMAP, wxPoint(221,53), wxSize(45,45));
	F_COBitmap->Show(false);
	F_COBitmap->Enable(false);

	wxBitmap F_SecurityBitmap_BITMAP(F_SecurityBitmap_XPM);
	F_SecurityBitmap = new wxStaticBitmap(mp_canvas, ID_F_SECURITYBITMAP, F_SecurityBitmap_BITMAP, wxPoint(221,54), wxSize(45,45));
	F_SecurityBitmap->Show(false);
	F_SecurityBitmap->Enable(false);

	wxBitmap K_FireBitmap_BITMAP(K_FireBitmap_XPM);
	K_FireBitmap = new wxStaticBitmap(mp_canvas, ID_K_FIREBITMAP, K_FireBitmap_BITMAP, wxPoint(29,197), wxSize(45,45));
	K_FireBitmap->Show(false);
	K_FireBitmap->Enable(false);

	wxBitmap K_COBitmap_BITMAP(K_COBitmap_XPM);
	K_COBitmap = new wxStaticBitmap(mp_canvas, ID_K_COBITMAP, K_COBitmap_BITMAP, wxPoint(30,197), wxSize(45,45));
	K_COBitmap->Show(false);
	K_COBitmap->Enable(false);

	wxBitmap K_SecurityBitmap_BITMAP(K_SecurityBitmap_XPM);
	K_SecurityBitmap = new wxStaticBitmap(mp_canvas, ID_K_SECURITYBITMAP, K_SecurityBitmap_BITMAP, wxPoint(31,198), wxSize(45,45));
	K_SecurityBitmap->Show(false);
	K_SecurityBitmap->Enable(false);

	wxBitmap D_FireBitmap_BITMAP(D_FireBitmap_XPM);
	D_FireBitmap = new wxStaticBitmap(mp_canvas, ID_D_FIREBITMAP, D_FireBitmap_BITMAP, wxPoint(193,240), wxSize(45,45));
	D_FireBitmap->Show(false);
	D_FireBitmap->Enable(false);

	wxBitmap D_COBitmap_BITMAP(D_COBitmap_XPM);
	D_COBitmap = new wxStaticBitmap(mp_canvas, ID_D_COBITMAP, D_COBitmap_BITMAP, wxPoint(193,239), wxSize(45,45));
	D_COBitmap->Show(false);
	D_COBitmap->Enable(false);

	wxBitmap D_SecurityBitmap_BITMAP(D_SecurityBitmap_XPM);
	D_SecurityBitmap = new wxStaticBitmap(mp_canvas, ID_D_SECURITYBITMAP, D_SecurityBitmap_BITMAP, wxPoint(193,240), wxSize(45,45));
	D_SecurityBitmap->Show(false);
	D_SecurityBitmap->Enable(false);

	wxBitmap O_FireBitmap_BITMAP(O_FireBitmap_XPM);
	O_FireBitmap = new wxStaticBitmap(mp_canvas, ID_O_FIREBITMAP, O_FireBitmap_BITMAP, wxPoint(373,350), wxSize(45,45));
	O_FireBitmap->Show(false);
	O_FireBitmap->Enable(false);

	wxBitmap O_COBitmap_BITMAP(O_COBitmap_XPM);
	O_COBitmap = new wxStaticBitmap(mp_canvas, ID_O_COBITMAP, O_COBitmap_BITMAP, wxPoint(372,350), wxSize(45,45));
	O_COBitmap->Show(false);
	O_COBitmap->Enable(false);

	wxBitmap O_SecurityBitmap_BITMAP(O_SecurityBitmap_XPM);
	O_SecurityBitmap = new wxStaticBitmap(mp_canvas, ID_O_SECURITYBITMAP, O_SecurityBitmap_BITMAP, wxPoint(374,350), wxSize(45,45));
	O_SecurityBitmap->Show(false);
	O_SecurityBitmap->Enable(false);

	wxBitmap Bath_FireBitmap_BITMAP(Bath_FireBitmap_XPM);
	Bath_FireBitmap = new wxStaticBitmap(mp_canvas, ID_BATH_FIREBITMAP, Bath_FireBitmap_BITMAP, wxPoint(377,261), wxSize(45,45));
	Bath_FireBitmap->Show(false);
	Bath_FireBitmap->Enable(false);

	wxBitmap Bath_COBitmap_BITMAP(Bath_COBitmap_XPM);
	Bath_COBitmap = new wxStaticBitmap(mp_canvas, ID_BATH_COBITMAP, Bath_COBitmap_BITMAP, wxPoint(378,260), wxSize(45,45));
	Bath_COBitmap->Show(false);
	Bath_COBitmap->Enable(false);

	wxBitmap Bath_SecurityBitmap_BITMAP(Bath_SecurityBitmap_XPM);
	Bath_SecurityBitmap = new wxStaticBitmap(mp_canvas, ID_BATH_SECURITYBITMAP, Bath_SecurityBitmap_BITMAP, wxPoint(378,261), wxSize(45,45));
	Bath_SecurityBitmap->Show(false);
	Bath_SecurityBitmap->Enable(false);

	wxBitmap Bed_FireBitmap_BITMAP(Bed_FireBitmap_XPM);
	Bed_FireBitmap = new wxStaticBitmap(mp_canvas, ID_BED_FIREBITMAP, Bed_FireBitmap_BITMAP, wxPoint(355,194), wxSize(45,45));
	Bed_FireBitmap->Show(false);
	Bed_FireBitmap->Enable(false);

	wxBitmap Bed_COBitmap_BITMAP(Bed_COBitmap_XPM);
	Bed_COBitmap = new wxStaticBitmap(mp_canvas, ID_BED_COBITMAP, Bed_COBitmap_BITMAP, wxPoint(354,194), wxSize(45,45));
	Bed_COBitmap->Show(false);
	Bed_COBitmap->Enable(false);

	wxBitmap Bed_SecurityBitmap_BITMAP(Bed_SecurityBitmap_XPM);
	Bed_SecurityBitmap = new wxStaticBitmap(mp_canvas, ID_BED_SECURITYBITMAP, Bed_SecurityBitmap_BITMAP, wxPoint(355,194), wxSize(45,45));
	Bed_SecurityBitmap->Show(false);
	Bed_SecurityBitmap->Enable(false);

	SetTitle(wxT("Master Panel"));
	SetIcon(wxNullIcon);
	SetSize(8,8,724,452);
	Center();
	
	////GUI Items Creation End
}

void wxMasterPanelDlg::OnClose(wxCloseEvent& /*event*/)
{
	this->Show(false);
}

void wxMasterPanelDlg::ButtonOneClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('1');
}

void wxMasterPanelDlg::ButtonTwoClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('2');
}

void wxMasterPanelDlg::ButtonThreeClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('3');
}

void wxMasterPanelDlg::ButtonFourClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('4');
}

void wxMasterPanelDlg::ButtonFiveClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('5');
}

void wxMasterPanelDlg::ButtonSixClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('6');
}

void wxMasterPanelDlg::ButtonSevenClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('7');
}

void wxMasterPanelDlg::ButtonEightClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('8');
}

void wxMasterPanelDlg::ButtonNineClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('9');
}

void wxMasterPanelDlg::ButtonZeroClick(wxCommandEvent& event)
{
    ConsoleInterface.BufferEnter('0');
}

void wxMasterPanelDlg::ButtonEnterClick(wxCommandEvent& event)
{
    ConsoleInterface.DoNextAction();
    updated = false;
    wxSecondaryPanelDlg::updated = false;
}

void wxMasterPanelDlg::OutputCtrlUpdateUI(wxUpdateUIEvent& event)
{
    if (updated) return;

    wxString* names = new wxString[7];
    bool ** test = new bool*[7];
    for(int count = 0; count < 7; count++)
        test[count] = new bool[3];
    ConsoleInterface.CheckSensors(names, test);
    
    G_FireBitmap->Show(false);
    F_FireBitmap->Show(false);
    K_FireBitmap->Show(false);
    D_FireBitmap->Show(false);
    Bed_FireBitmap->Show(false);
    Bath_FireBitmap->Show(false);
    O_FireBitmap->Show(false);

    G_COBitmap->Show(false);
    F_COBitmap->Show(false);
    K_COBitmap->Show(false);
    D_COBitmap->Show(false);
    Bed_COBitmap->Show(false);
    Bath_COBitmap->Show(false);
    O_COBitmap->Show(false);

    G_SecurityBitmap->Show(false);
    F_SecurityBitmap->Show(false);
    K_SecurityBitmap->Show(false);
    D_SecurityBitmap->Show(false);
    Bed_SecurityBitmap->Show(false);
    Bath_SecurityBitmap->Show(false);
    O_SecurityBitmap->Show(false);

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
        {
            switch(count)
            {
                case 0:
                    G_FireBitmap->Show(true);
                    break;
                case 1:
                    F_FireBitmap->Show(true);
                    break;
                case 2:
                    K_FireBitmap->Show(true);
                    break;
                case 3:
                    D_FireBitmap->Show(true);
                    break;
                case 4:
                    Bed_FireBitmap->Show(true);
                    break;
                case 5:
                    Bath_FireBitmap->Show(true);
                    break;
                case 6:
                    O_FireBitmap->Show(true);
                    break;
            }
        }
        else if(test[count][Room::SECURITYSENSOR])
        {
            switch(count)
            {
                case 0:
                    G_SecurityBitmap->Show(true);
                    break;
                case 1:
                    F_SecurityBitmap->Show(true);
                    break;
                case 2:
                    K_SecurityBitmap->Show(true);
                    break;
                case 3:
                    D_SecurityBitmap->Show(true);
                    break;
                case 4:
                    Bed_SecurityBitmap->Show(true);
                    break;
                case 5:
                    Bath_SecurityBitmap->Show(true);
                    break;
                case 6:
                    O_SecurityBitmap->Show(true);
                    break;
            }
        }
        else if(test[count][Room::COSENSOR])
        {
            switch(count)
            {
                case 0:
                    G_COBitmap->Show(true);
                    break;
                case 1:
                    F_COBitmap->Show(true);
                    break;
                case 2:
                    K_COBitmap->Show(true);
                    break;
                case 3:
                    D_COBitmap->Show(true);
                    break;
                case 4:
                    Bed_COBitmap->Show(true);
                    break;
                case 5:
                    Bath_COBitmap->Show(true);
                    break;
                case 6:
                    O_COBitmap->Show(true);
                    break;
            }
        }
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
