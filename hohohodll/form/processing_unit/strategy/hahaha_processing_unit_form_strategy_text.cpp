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

#include "hahaha_processing_unit_form_strategy_text.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_processing_unit_strategy_text *hahaha_form_processing_unit_strategy_text;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_processing_unit_strategy_text::Thahaha_form_processing_unit_strategy_text(TComponent* Owner)
	: TForm(Owner)
{
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    main_box->Color = (TColor)RGB(210,255,210);

    font_box->Color = (TColor)RGB(210,255,210);
    text_box->Color = (TColor)RGB(210,255,210);
    color_box->Color = (TColor)RGB(210,255,210);
    size_box->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

    main_box->BorderStyle = bsNone;


    font_box->BorderStyle = bsNone;
    text_box->BorderStyle = bsNone;
    color_box->BorderStyle = bsNone;
    size_box->BorderStyle = bsNone;


    // 访问屏幕对象
    TScreen *screen = Screen;

    combo_box_font->Items->BeginUpdate();
    combo_box_font->Clear();
    // 遍历并显示所有字体
    for (int i = 0; i < screen->Fonts->Count; i++)
    {
        combo_box_font->Items->Add(screen->Fonts->Strings[i].c_str());
//        std::wcout << screen->Fonts->Strings[i].c_str() << std::endl;
    }
    combo_box_font->Items->EndUpdate();


    Is_Update = true;
}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_processing_unit_strategy_text::button_minClick(TObject *Sender)

{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_text::button_maxClick(TObject *Sender)

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

void __fastcall Thahaha_form_processing_unit_strategy_text::button_closeClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_text::combo_box_fontChange(TObject *Sender)

{
    if(Is_Update)
    {
        return;
    }
    ha::Pointer_Main_->Select_View_->Get_Parameter();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_text::memo_textChange(TObject *Sender)

{
    if(Is_Update)
    {
        return;
    }
    ha::Pointer_Main_->Select_View_->Get_Parameter();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_text::panel_colorDblClick(TObject *Sender)

{
    if(Is_Update)
    {
        return;
    }
    if(color_dialog_color->Execute())
    {
        panel_color->Color = color_dialog_color->Color;
        ha::Pointer_Main_->Select_View_->Get_Parameter();
    }
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_text::text_sizeChange(TObject *Sender)

{
    if(Is_Update)
    {
        return;
    }
    ha::Pointer_Main_->Select_View_->Get_Parameter();
}
//---------------------------------------------------------------------------

