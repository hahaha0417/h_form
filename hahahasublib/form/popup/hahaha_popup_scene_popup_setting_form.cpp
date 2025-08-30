//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <setting\hahaha_setting.h>
#include <option\hahaha_option.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <form\hahaha_main_form.h>
#include <form\hahaha_edit_form.h>
#include <form\hahaha_option_form.h>
#include <form\hahaha_popup_form.h>
#include <form\hahaha_system_setting_form.h>
#include <form\hahaha_view_form.h>
//---------------------------------------------------------------------------
#include <form\popup\hahaha_popup_scene_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_form.h>
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#include <view\hahaha_view_scene.h>
#include <view\scene\hahaha_view_scene_package.h>
#include <view\form\scene\hahaha_view_form_scene.h>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <iostream>
#include <filesystem>
//---------------------------------------------------------------------------
#include "hahaha_popup_scene_popup_setting_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_popup_scene_popup_setting *hahaha_form_popup_scene_popup_setting;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_popup_scene_popup_setting::Thahaha_form_popup_scene_popup_setting(TComponent* Owner)
	: TForm(Owner)
{
    ShowInTaskBar = true;
    //---------------------------------------------------------------------------
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    BodyBodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;
    BodyBodyBox->BorderStyle = bsNone;
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------


    Is_Update_ = false;
    //---------------------------------------------------------------------------

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup_scene_popup_setting::button_minClick(TObject *Sender)
{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_scene_popup_setting::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_popup_scene_popup_setting::button_closeClick(TObject *Sender)

{
    Close();

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_scene_popup_setting::FormShow(TObject *Sender)
{
    //---------------------------------------------------------------------------

    // Á×§Ktitle bar ²§±`
    Width++;
    Width--;



    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------



halib_def::result Thahaha_form_popup_scene_popup_setting::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup_scene_popup_setting::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

int Thahaha_form_popup_scene_popup_setting::Update_UI()
{

    return 0;
}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup_scene_popup_setting::Scene_NameChange(TObject *Sender)

{
    if(Is_Update_)
    {
        return;
    }

    Pointer_Main_->Select_Scene_->Get_Parameter();
    Pointer_Main_->Select_Scene_->Set_Parameter();
}
//---------------------------------------------------------------------------

