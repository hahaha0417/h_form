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
#include <view\hahaha_view_view.h>
#include <view\scene\hahaha_view_scene_package.h>
#include <view\view\hahaha_view_view_package.h>
#include <view\form\scene\hahaha_view_form_scene.h>
#include <view\form\view\hahaha_view_form_view.h>
//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
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
#include "hahaha_popup_view_popup_setting_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_popup_view_popup_setting *hahaha_form_popup_view_popup_setting;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_popup_view_popup_setting::Thahaha_form_popup_view_popup_setting(TComponent* Owner)
	: TForm(Owner)
{
    ShowInTaskBar = true;
    //---------------------------------------------------------------------------
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    top_box->Color = (TColor)RGB(210,255,210);
    body_body_box->Color = (TColor)RGB(210,255,210);

    box_main->Color = (TColor)RGB(210,255,210);
    box_processing_unit_base->Color = (TColor)RGB(210,255,210);
    box_processing_unit_region->Color = (TColor)RGB(210,255,210);
    box_processing_unit_strategy->Color = (TColor)RGB(210,255,210);


    BodyBox->BorderStyle = bsNone;
    top_box->BorderStyle = bsNone;
    body_body_box->BorderStyle = bsNone;

    box_main->BorderStyle = bsNone;
    box_processing_unit_base->BorderStyle = bsNone;
    box_processing_unit_region->BorderStyle = bsNone;
    box_processing_unit_strategy->BorderStyle = bsNone;

    box_main->Parent = body_body_box;
    box_processing_unit_base->Parent = body_body_box;
    box_processing_unit_region->Parent = body_body_box;
    box_processing_unit_strategy->Parent = body_body_box;

    box_main->Align = alClient;
    box_processing_unit_base->Align = alClient;
    box_processing_unit_region->Align = alClient;
    box_processing_unit_strategy->Align = alClient;
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------


    Is_Update_ = false;
    //---------------------------------------------------------------------------
    button_mainClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup_view_popup_setting::button_minClick(TObject *Sender)
{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_setting::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_popup_view_popup_setting::button_closeClick(TObject *Sender)

{
    Close();

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_setting::FormShow(TObject *Sender)
{
    //---------------------------------------------------------------------------

    // 避免title bar 異常
    Width++;
    Width--;



    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_setting::button_close_sceneClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_setting::button_ok_sceneClick(TObject *Sender)

{


    Close();

}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup_view_popup_setting::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup_view_popup_setting::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_popup_view_popup_setting::button_processing_unit_baseClick(TObject *Sender)

{
    box_main->Visible = false;
    box_processing_unit_base->Visible = true;
    box_processing_unit_region->Visible = false;
    box_processing_unit_strategy->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_setting::button_processing_unit_regionClick(TObject *Sender)

{
	box_main->Visible = false;
    box_processing_unit_base->Visible = false;
    box_processing_unit_region->Visible = true;
    box_processing_unit_strategy->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_setting::button_processing_unit_strategyClick(TObject *Sender)

{
    box_main->Visible = false;
    box_processing_unit_base->Visible = false;
    box_processing_unit_region->Visible = false;
    box_processing_unit_strategy->Visible = true;

}
//---------------------------------------------------------------------------

int Thahaha_form_popup_view_popup_setting::Update_UI()
{
    if(Pointer_Main_->Select_View_ == NULL)
    {
        return 0;
    }

    // 顯示面板
    for (const auto& item : Page_Bases_)
	{
        if(item.first == Pointer_Main_->Select_View_->Processing_Unit_->Type_Base_)
        {
            item.second->Visible = true;
        }
        else
        {
            item.second->Visible = false;
        }

    }

    for (const auto& item : Page_Regions_)
	{
        if(item.first == Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Region_->Type_Region_)
        {
            item.second->Visible = true;
        }
        else
        {
            item.second->Visible = false;
        }

    }

    for (const auto& item : Page_Strategys_)
	{
        if(item.first == Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_->Type_Strategy_)
        {
            item.second->Visible = true;
        }
        else
        {
            item.second->Visible = false;
        }

    }


    return 0;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup_view_popup_setting::button_mainClick(TObject *Sender)

{
    box_main->Visible = true;
    box_processing_unit_base->Visible = false;
    box_processing_unit_region->Visible = false;
    box_processing_unit_strategy->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_setting::View_NameChange(TObject *Sender)

{
    if(Is_Update_)
    {
        return;
    }

    Pointer_Main_->Select_View_->Get_Parameter();
    Pointer_Main_->Select_View_->Set_Parameter();
}
//---------------------------------------------------------------------------

