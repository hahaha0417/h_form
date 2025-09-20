//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_processing_unit_form_base_base.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
// 要這樣加，編輯器才會出現，應該是Bug
#if defined(DESIGNED_DFM)
	#pragma resource "*.dfm"                // 讓 IDE 找得到設計檔
#else
	#pragma resource "hahaha_processing_unit_form_base_base.dfm"
#endif

//#pragma resource "*.dfm"
Thahaha_form_processing_unit_base_base *hahaha_form_processing_unit_base_base;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_processing_unit_base_base::Thahaha_form_processing_unit_base_base(TComponent* Owner)
	: TForm(Owner)
{
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    main_box->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

    main_box->BorderStyle = bsNone;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_processing_unit_base_base::button_minClick(TObject *Sender)

{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_base_base::button_maxClick(TObject *Sender)

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

void __fastcall Thahaha_form_processing_unit_base_base::button_closeClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

