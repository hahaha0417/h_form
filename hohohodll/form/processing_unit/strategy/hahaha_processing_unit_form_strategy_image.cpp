//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_ho.h>
//---------------------------------------------------------------------------
#include <view\view\hahaha_view_view_package.h>
#include <view\form\view\hahaha_view_form_view.h>
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>

#include "hahaha_processing_unit_form_strategy_image.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_processing_unit_strategy_image *hahaha_form_processing_unit_strategy_image;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_processing_unit_strategy_image::Thahaha_form_processing_unit_strategy_image(TComponent* Owner)
	: TForm(Owner)
{
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    main_box->Color = (TColor)RGB(210,255,210);
    image_box->Color = (TColor)RGB(210,255,210);
    ratio_box->Color = (TColor)RGB(210,255,210);
    direction_box->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

    main_box->BorderStyle = bsNone;

    image_box->BorderStyle = bsNone;
    ratio_box->BorderStyle = bsNone;
    direction_box->BorderStyle = bsNone;


    Is_Update = false;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_processing_unit_strategy_image::button_minClick(TObject *Sender)

{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_image::button_maxClick(TObject *Sender)

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

void __fastcall Thahaha_form_processing_unit_strategy_image::button_closeClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_image::text_image_pathDblClick(TObject *Sender)

{
    if(Is_Update)
    {
        return;
    }
    if(open_dialog_image->Execute())
    {
        // 這要在前
        text_image_path->Text = open_dialog_image->FileName;
        ha::Pointer_Main_->Select_View_->Get_Parameter();
    }
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_processing_unit_strategy_image::check_fix_ratioClick(TObject *Sender)

{
    ha::Pointer_Main_->Select_View_->Get_Parameter();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_image::combo_box_directionChange(TObject *Sender)

{
    ha::Pointer_Main_->Select_View_->Get_Parameter();
}
//---------------------------------------------------------------------------

