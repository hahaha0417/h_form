//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_edit_form.h"
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view.h>
//---------------------------------------------------------------------------
#include <form\hahaha_option_form.h>
#include <form\hahaha_popup_form.h>
#include <form\hahaha_system_setting_form.h>
#include <form\hahaha_view_form.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <option\hahaha_option.h>
#include <setting\hahaha_setting.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_edit *hahaha_form_edit;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_edit::Thahaha_form_edit(TComponent* Owner)
	: TForm(Owner)
{
    ShowInTaskBar = true;
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
	CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_edit::button_minClick(TObject *Sender)
{
	PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_edit::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_edit::button_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_edit::FormShow(TObject *Sender)
{
	Structure_Main_->Form_Image_View_->MainBox->Parent = Structure_Main_->Form_Edit_->BodyBox;

    //---------------------------------------------------------------------------

    // Á×§Ktitle bar ²§±`
    Width++;
    Width--;



    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_edit::popup_menuPopup(TObject *Sender)
{
    Structure_Main_->Form_Popup_->Update_UI();
    Structure_Main_->Form_Popup_->Show();

}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_edit::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_edit::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------





