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
#include <view\hahaha_view_view.h>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <iostream>
#include <filesystem>
//---------------------------------------------------------------------------
#include "hahaha_view_form_view.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_view_view *hahaha_form_view_view;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_view_view::Thahaha_form_view_view(TComponent* Owner)
	: TForm(Owner)
{
    CustomTitleBar->BackgroundColor = (TColor)RGB(210, 255, 210);
	BodyBox->Color = (TColor)RGB(210, 255, 210);
    main_box->Color = (TColor)RGB(210, 255, 210);
    sub_box->Color = (TColor)RGB(210, 255, 210);

    item_box->Color = (TColor)RGB(60, 60, 60);
    image_logo->Picture->Assign(image_icon_on->Picture);
    label_name->Font->Color = (TColor)RGB(255, 255, 255);

    BodyBox->BorderStyle = bsNone;
    main_box->BorderStyle = bsNone;
    sub_box->BorderStyle = bsNone;

    item_box->BorderStyle = bsNone;

    Down_Item_ = false;
    View_ = NULL;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_view_view::button_minClick(TObject *Sender)

{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_view_view::button_maxClick(TObject *Sender)

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

void __fastcall Thahaha_form_view_view::button_closeClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_view_view::ItemEnter(TObject *Sender)
{
    if(View_->Select_ || Down_Item_)
    {
        item_box->Color = (TColor)RGB(180, 180, 180);
        image_logo->Picture->Assign(image_icon_off->Picture);
    	label_name->Font->Color = (TColor)RGB(0, 0, 0);
    }
    else
    {
        item_box->Color = (TColor)RGB(120, 120, 120);
        image_logo->Picture->Assign(image_icon_off->Picture);
        label_name->Font->Color = (TColor)RGB(0, 0, 0);
    }

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_view_view::ItemLeave(TObject *Sender)
{
    if(View_->Select_ || Down_Item_)
    {
        item_box->Color = (TColor)RGB(180, 180, 180);
        image_logo->Picture->Assign(image_icon_off->Picture);
    	label_name->Font->Color = (TColor)RGB(0, 0, 0);
    }
    else
    {
        item_box->Color = (TColor)RGB(60, 60, 60);
        image_logo->Picture->Assign(image_icon_on->Picture);
    	label_name->Font->Color = (TColor)RGB(255, 255, 255);
    }

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_view_view::ItemDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    View_->Select();
    Down_Item_ = true;
    item_box->Color = (TColor)RGB(180, 180, 180);
    image_logo->Picture->Assign(image_icon_off->Picture);
    label_name->Font->Color = (TColor)RGB(0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_view_view::ItemUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    Down_Item_ = false;
//    item_box->Color = (TColor)RGB(60, 60, 60);
//    image_logo->Picture->Assign(image_icon_on->Picture);
//    label_name->Font->Color = (TColor)RGB(255, 255, 255);
}
//---------------------------------------------------------------------------

int Thahaha_form_view_view::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return 0;
}
//---------------------------------------------------------------------------

int Thahaha_form_view_view::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return 0;
}
//---------------------------------------------------------------------------

