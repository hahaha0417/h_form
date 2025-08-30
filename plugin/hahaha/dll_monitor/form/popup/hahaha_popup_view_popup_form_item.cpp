//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <define\hahaha_define_ho.h>

#include "hahaha_popup_view_popup_form_item.h"

#include <form\popup\hahaha_popup_view_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_form_item.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_base.h>
#include <define\processing_unit\hahaha_define_processing_unit_region.h>
#include <define\processing_unit\hahaha_define_processing_unit_strategy.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_base.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_region.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_strategy.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_popup_view_popup_item *hahaha_form_popup_view_popup_item;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_popup_view_popup_item::Thahaha_form_popup_view_popup_item(TComponent* Owner)
	: TForm(Owner)
{
	CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    box_item->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

    box_item->BorderStyle = bsNone;


    item_rect_monitor_box->BorderStyle = bsNone;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup_view_popup_item::button_minClick(TObject *Sender)
{
	PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_item::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_popup_view_popup_item::button_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup_view_popup_item::button_add_rect_monitorClick(TObject *Sender)

{
    int n = ha::Structure_Main_->Form_Popup_View_Popup_->bottom_content_box->ControlCount;
	for (int i = 0; i < n; i++)
    {
        TControl *control = ha::Structure_Main_->Form_Popup_View_Popup_->bottom_content_box->Controls[i];
        control->Visible = false;
    }

    item_rect_monitor_box->Visible = true;
    item_rect_monitor_box->Width++;
    ha::Structure_Main_->Form_Popup_View_Popup_->View_Name->Text = L"顯示器";

    ha::Structure_Main_->Form_Popup_View_Popup_->Label_Type_Base->Caption = L"plugin_hahaha_monitor";
    ha::Structure_Main_->Form_Popup_View_Popup_->Label_Type_Region->Caption = L"矩形";
    ha::Structure_Main_->Form_Popup_View_Popup_->Label_Type_Strategy->Caption = L"顯示器";

    ha::Structure_Main_->Form_Popup_View_Popup_->Type_Factory_Base_ = ha_def::factory_processing_unit_base::HA;
    ha::Structure_Main_->Form_Popup_View_Popup_->Type_Factory_Region_ = ha_def::factory_processing_unit_region::HA;
    ha::Structure_Main_->Form_Popup_View_Popup_->Type_Factory_Strategy_ = ha_def::factory_processing_unit_strategy::PLUGIN_HAHAHA_MONITOR;

    ha::Structure_Main_->Form_Popup_View_Popup_->Type_Base_ = ha_def::processing_unit_base::BASE;
    ha::Structure_Main_->Form_Popup_View_Popup_->Type_Region_ = ha_def::processing_unit_region::RECTANGLE;
    ha::Structure_Main_->Form_Popup_View_Popup_->Type_Strategy_ = ha_def::processing_unit_strategy::PLUGIN_HAHAHA_MONITOR;
}
//---------------------------------------------------------------------------


