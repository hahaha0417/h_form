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
#include <image_view\hahaha_image_view_base.h>
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
#include "hahaha_popup_scene_popup_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_popup_scene_popup *hahaha_form_popup_scene_popup;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_popup_scene_popup::Thahaha_form_popup_scene_popup(TComponent* Owner)
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



    //---------------------------------------------------------------------------

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup_scene_popup::button_minClick(TObject *Sender)
{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_scene_popup::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_popup_scene_popup::button_closeClick(TObject *Sender)

{
    Close();

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_scene_popup::FormShow(TObject *Sender)
{
    //---------------------------------------------------------------------------

    // Á×§Ktitle bar ²§±`
    Width++;
    Width--;



    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_scene_popup::button_close_sceneClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_scene_popup::button_ok_sceneClick(TObject *Sender)

{
    Pointer_Main_->Setting_->Add_Scene(Scene_Name->Text.c_str());
    hahaha::hahaha_view_scene& scene_ = *Pointer_Main_->Setting_->Scenes_.back();

    scene_.Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    scene_.Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    // ¥ý²¾¥X¿Ã¹õ
    scene_.Package_->Form_Scene_->item_box->Top = 999999;
    scene_.Package_->Form_Scene_->item_box->Parent = Structure_Main_->Form_Popup_->scene_list;
    scene_.Package_->Form_Scene_->item_box->Align = alTop;
    scene_.Package_->Form_Scene_->item_box->AlignWithMargins = True;
    scene_.Package_->Form_Scene_->label_name->Caption = scene_.Name_.c_str();
    scene_.Package_->Form_Scene_->Scene_ = Pointer_Main_->Setting_->Scenes_.back().get();

    scene_.Select();
    Structure_Main_->Form_Popup_->Update_UI();

    Structure_Main_->Image_View_->Repaint();

    Close();

}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup_scene_popup::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup_scene_popup::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------


