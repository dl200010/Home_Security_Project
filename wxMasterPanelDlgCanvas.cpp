#include "wxMasterPanelDlgCanvas.h"

BEGIN_EVENT_TABLE(wxMasterPanelDlgCanvas, wxScrolledWindow)
  EVT_PAINT(wxMasterPanelDlgCanvas::OnPaint)
END_EVENT_TABLE()

wxMasterPanelDlgCanvas::wxMasterPanelDlgCanvas( wxWindow *parent, wxWindowID id,
                    const wxPoint &pos, const wxSize &size )
        : wxScrolledWindow( parent, id, pos, size, wxSUNKEN_BORDER )
{
    wxImage image;
    if ( !image.LoadFile( _T("images/housepicture.bmp"), wxBITMAP_TYPE_BMP ) )
        wxLogError(wxT("Can't load BMP image"));
    else
        housepicture_bmp = wxBitmap( image );
}

wxMasterPanelDlgCanvas::~wxMasterPanelDlgCanvas()
{
}

void wxMasterPanelDlgCanvas::OnPaint( wxPaintEvent &WXUNUSED(event) )
{
    wxPaintDC dc( this );
    PrepareDC( dc );

    if (housepicture_bmp.Ok())
        dc.DrawBitmap( housepicture_bmp, 0, 0 );

}
