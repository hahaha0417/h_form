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
#include <view\form\scene\hahaha_view_form_scene.h>
#include <view\view\hahaha_view_view_package.h>
#include <view\form\view\hahaha_view_form_view.h>
//---------------------------------------------------------------------------
#include <factory\processing_unit\hahaha_factory_processing_unit_base.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_region.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view_base.h>
//---------------------------------------------------------------------------
#include <iostream>
#include <filesystem>
//---------------------------------------------------------------------------
#include "hahaha_popup_view_popup_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_popup_view_popup *hahaha_form_popup_view_popup;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_popup_view_popup::Thahaha_form_popup_view_popup(TComponent* Owner)
	: TForm(Owner)
{
    ShowInTaskBar = true;
    //---------------------------------------------------------------------------
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;
    //---------------------------------------------------------------------------



    top_box->BorderStyle = bsNone;
    //---------------------------------------------------------------------------

    box_main->Parent = BodyBox;
    box_sub->Parent = BodyBox;
    box_third_party->Parent = BodyBox;
    box_other->Parent = BodyBox;

    box_main->Color = (TColor)RGB(210,255,210);
    box_sub->Color = (TColor)RGB(210,255,210);
    box_third_party->Color = (TColor)RGB(210,255,210);
    box_other->Color = (TColor)RGB(210,255,210);

    box_main_list_1->Color = (TColor)RGB(210,255,210);
    box_main_list_2->Color = (TColor)RGB(210,255,210);

    bottom_box->Color = (TColor)RGB(190,255,190);

    box_main->BorderStyle = bsNone;
    box_sub->BorderStyle = bsNone;
    box_third_party->BorderStyle = bsNone;
    box_other->BorderStyle = bsNone;
    //
    top_box->BorderStyle = bsNone;
    bottom_box->BorderStyle = bsNone;
    //
    bottom_content_box->BorderStyle = bsNone;
    bottom_confirm_box->BorderStyle = bsNone;
    bottom_setting_box->BorderStyle = bsNone;

    box_main_list_1->BorderStyle = bsNone;
    box_main_list_2->BorderStyle = bsNone;

    box_main->Align = alClient;
    box_sub->Align = alClient;
    box_third_party->Align = alClient;
    box_other->Align = alClient;
    //
    bottom_content_box->Align = alClient;


    box_main_list_1->Align = alLeft;
    box_main_list_2->Align = alClient;

    box_main_list_1->Width = 420;



    //---------------------------------------------------------------------------
    PageControl1->Visible = false;

    Type_Base_ = hahaha::hahaha_define_processing_unit_base::NONE;
    Type_Region_ = hahaha::hahaha_define_processing_unit_region::NONE;
    Type_Strategy_ = hahaha::hahaha_define_processing_unit_strategy::NONE;

    button_mainClick(NULL);

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup_view_popup::button_minClick(TObject *Sender)
{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_popup_view_popup::button_closeClick(TObject *Sender)

{
    Close();

}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_popup_view_popup::button_mainClick(TObject *Sender)
{
    box_main->Visible = true;
    box_sub->Visible = false;
    box_third_party->Visible = false;
    box_other->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::button_subClick(TObject *Sender)
{
    box_main->Visible = false;
    box_sub->Visible = true;
    box_third_party->Visible = false;
    box_other->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::button_third_partyClick(TObject *Sender)

{
    box_main->Visible = false;
    box_sub->Visible = false;
    box_third_party->Visible = true;
    box_other->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::button_otherClick(TObject *Sender)

{
    box_main->Visible = false;
    box_sub->Visible = false;
    box_third_party->Visible = false;
    box_other->Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::FormShow(TObject *Sender)
{
    //---------------------------------------------------------------------------

    // 避免title bar 異常
    Width++;
    Width--;



    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup_view_popup::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup_view_popup::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::button_processing_unit_createClick(TObject *Sender)

{
    if(Pointer_Main_->Select_Scene_ == NULL)
    {
        ShowMessage(L"沒有選擇場景");
        return;
    }

    if(View_Name->Text == L"")
    {
        ShowMessage(L"請輸入顯示名稱");
        return;
    }

    if(Type_Base_ == hahaha::hahaha_define_processing_unit_base::NONE)
    {
        ShowMessage(L"請設定顯示類型基本");
        return;
    }

    if(Type_Region_ == hahaha::hahaha_define_processing_unit_region::NONE)
    {
        ShowMessage(L"請設定顯示類型形狀");
        return;
    }

    if(Type_Strategy_ == hahaha::hahaha_define_processing_unit_strategy::NONE)
    {
        ShowMessage(L"請設定顯示類型方法");
        return;
    }


	Pointer_Main_->Select_Scene_->Add_View(View_Name->Text.c_str());
    hahaha::hahaha_view_view& view_ = *Pointer_Main_->Select_Scene_->Views_.back();

    view_.Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    view_.Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    //---------------------------------------------------------------------------
    // 新增
    //---------------------------------------------------------------------------
    hahaha::hahaha_processing_unit_base* processing_unit_base_ = NULL;
    Structure_Main_->Factory_Processing_Unit_Bases_[Type_Factory_Base_]->Add(Type_Base_, processing_unit_base_);

    hahaha::hahaha_processing_unit_region* processing_unit_region_ = NULL;
    Structure_Main_->Factory_Processing_Unit_Regions_[Type_Factory_Region_]->Add(Type_Region_, processing_unit_region_);

    hahaha::hahaha_processing_unit_strategy* processing_unit_strategy_ = NULL;
    Structure_Main_->Factory_Processing_Unit_Strategys_[Type_Factory_Strategy_]->Add(Type_Strategy_, processing_unit_strategy_);

    //---------------------------------------------------------------------------
    // 指標
    //---------------------------------------------------------------------------
    processing_unit_base_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    processing_unit_base_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    processing_unit_region_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    processing_unit_region_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    processing_unit_strategy_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    processing_unit_strategy_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );
    // 搭橋
    processing_unit_base_->Processing_Unit_Region_ = processing_unit_region_;
    processing_unit_base_->Processing_Unit_Strategy_ = processing_unit_strategy_;

    processing_unit_region_->Processing_Unit_Base_ = processing_unit_base_;
    processing_unit_region_->Processing_Unit_Strategy_ = processing_unit_strategy_;

    processing_unit_strategy_->Processing_Unit_Base_ = processing_unit_base_;
    processing_unit_strategy_->Processing_Unit_Region_ = processing_unit_region_;

    // 初始化
    processing_unit_base_->Initial();
    processing_unit_region_->Initial();
    processing_unit_strategy_->Initial();

    // 掛載指標
    view_.Processing_Unit_ = processing_unit_base_;
    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------


    // 先移出螢幕
    view_.Package_->Form_View_->item_box->Top = 999999;
    view_.Package_->Form_View_->item_box->Parent = Structure_Main_->Form_Popup_->view_list;
    view_.Package_->Form_View_->item_box->Align = alTop;
    view_.Package_->Form_View_->item_box->AlignWithMargins = True;
    view_.Package_->Form_View_->label_name->Caption = view_.Name_.c_str();
    view_.Package_->Form_View_->View_ = Pointer_Main_->Select_Scene_->Views_.back().get();


    int n = Pointer_Main_->Select_Scene_->Views_.size();
    for(int i = 0; i < n; i++)
    {
    	Pointer_Main_->Select_Scene_->Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_ = false;


    }


    view_.Select();
    Structure_Main_->Form_Popup_->Update_UI();
    Structure_Main_->Image_View_->Is_Repaint_ = true;
    Structure_Main_->Image_View_->Repaint();

    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::button_processing_unit_cancelClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup::Popup_Menu_AdvanceClick(TObject *Sender)

{
    ShowMessage(L"有需要再做，目前先用Web列目錄");
}
//---------------------------------------------------------------------------

