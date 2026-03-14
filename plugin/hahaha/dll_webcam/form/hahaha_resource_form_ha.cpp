//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_resource_form_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_resource_ha *hahaha_form_resource_ha;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_resource_ha::Thahaha_form_resource_ha(TComponent* Owner)
	: TForm(Owner)
{
	CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_resource_ha::button_minClick(TObject *Sender)
{
	PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_resource_ha::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_resource_ha::button_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

