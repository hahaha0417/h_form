//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_processing_unit_form_region_rectangle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_processing_unit_region_rectangle *hahaha_form_processing_unit_region_rectangle;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_processing_unit_region_rectangle::Thahaha_form_processing_unit_region_rectangle(TComponent* Owner)
	: TForm(Owner)
{
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    main_box->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

    main_box->BorderStyle = bsNone;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_processing_unit_region_rectangle::button_minClick(TObject *Sender)

{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_region_rectangle::button_maxClick(TObject *Sender)

{
    if(WindowState == wsNormal)
	{
		WindowState = wsMaximized;
	}
	else if(WindowState == wsMaximized)
	{
		WindowState = wsNormal;
	}
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_region_rectangle::button_closeClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

