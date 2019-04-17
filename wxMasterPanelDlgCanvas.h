#ifndef WXMASTERPANELDLGCANVAS
#define WXMASTERPANELDLGCANVAS

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/image.h"
#include "wx/file.h"
#include "wx/filename.h"
#include "wx/mstream.h"
#include "wx/wfstream.h"
#include "wx/quantize.h"

class wxMasterPanelDlgCanvas: public wxScrolledWindow
{
public:
    wxMasterPanelDlgCanvas( wxWindow *parent, wxWindowID, const wxPoint &pos, const wxSize &size );
    ~wxMasterPanelDlgCanvas();
    void OnPaint( wxPaintEvent &event );
    
    
    wxBitmap  housepicture_bmp;
    DECLARE_EVENT_TABLE()
};


#endif
