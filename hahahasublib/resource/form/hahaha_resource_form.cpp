//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_resource_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_resource *hahaha_form_resource;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_resource::Thahaha_form_resource(TComponent* Owner)
	: TForm(Owner)
{
	CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_resource::button_minClick(TObject *Sender)
{
	PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_resource::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_resource::button_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

