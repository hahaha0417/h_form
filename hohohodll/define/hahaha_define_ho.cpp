//---------------------------------------------------------------------------

#pragma hdrstop

#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_base.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_region.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_strategy.h>

#include <factory\processing_unit\hahaha_factory_processing_unit_base_ha.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_region_ha.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_strategy_ha.h>

#include <form\popup\hahaha_popup_view_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_setting_form.h>
#include <form\popup\hahaha_popup_view_popup_form_item.h>
#include <form\processing_unit\base\hahaha_processing_unit_form_base_base.h>
#include <form\processing_unit\region\hahaha_processing_unit_form_region_rectangle.h>
#include <form\processing_unit\strategy\hahaha_processing_unit_form_strategy_text.h>
#include <form\processing_unit\strategy\hahaha_processing_unit_form_strategy_image.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//
#include <command\hahaha_command_main.h>
#include <command\hahaha_command_sub.h>
//---------------------------------------------------------------------------


#include "hahaha_define_ho.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// 猔種 :
// exe & dll ぃノ办跑计璶ノ璶class柑
// ⊿璶肚繦獽
//---------------------------------------------------------------------------
namespace ha
{
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_factory_processing_unit_base_ha> Factory_Processing_Unit_Base_Ha_;
std::unique_ptr<hahaha::hahaha_factory_processing_unit_region_ha> Factory_Processing_Unit_Region_Ha_;
std::unique_ptr<hahaha::hahaha_factory_processing_unit_strategy_ha> Factory_Processing_Unit_Strategy_Ha_;
// form
std::unique_ptr<Thahaha_form_popup_view_popup_item> Form_Popup_View_Popup_Item_;
std::unique_ptr<Thahaha_form_processing_unit_base_base> Form_Processing_Unit_Base_Base_;
std::unique_ptr<Thahaha_form_processing_unit_region_rectangle> Form_Processing_Unit_Region_Rectangle_;
std::unique_ptr<Thahaha_form_processing_unit_strategy_image> Form_Processing_Unit_Strategy_Image_;
std::unique_ptr<Thahaha_form_processing_unit_strategy_text> Form_Processing_Unit_Strategy_Text_;
//---------------------------------------------------------------------------
// 跑计
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// 夹
//---------------------------------------------------------------------------
hahaha::hahaha_structure_main* Structure_Main_;
hahaha::hahaha_structure_sub* Structure_Sub_;
hahaha::hahaha_pointer_main* Pointer_Main_;
hahaha::hahaha_pointer_sub* Pointer_Sub_;
//
hahaha::hahaha_command_main* Command_Main_;
hahaha::hahaha_command_sub* Command_Sub_;
//---------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------
int Initial_Environment(hahaha::hahaha_post_package& input,
	hahaha::hahaha_post_package& output,
    hahaha::hahaha_post_package& setting
)
{
    std::vector<void*>& objects_ = input.Objects_;

    ha::Structure_Main_ = (hahaha::hahaha_structure_main*)objects_[0];
    ha::Structure_Sub_ = (hahaha::hahaha_structure_sub*)objects_[1];
    ha::Pointer_Main_ = (hahaha::hahaha_pointer_main*)objects_[2];
    ha::Pointer_Sub_ = (hahaha::hahaha_pointer_sub*)objects_[3];
    //


    return 0;
}
//---------------------------------------------------------------------------
int Initial()
{
    if(Factory_Processing_Unit_Base_Ha_.get() == NULL)
    {
        Factory_Processing_Unit_Base_Ha_.reset(new hahaha::hahaha_factory_processing_unit_base_ha);
    }

    if(Factory_Processing_Unit_Region_Ha_.get() == NULL)
    {
        Factory_Processing_Unit_Region_Ha_.reset(new hahaha::hahaha_factory_processing_unit_region_ha);
    }

    if(Factory_Processing_Unit_Strategy_Ha_.get() == NULL)
    {
        Factory_Processing_Unit_Strategy_Ha_.reset(new hahaha::hahaha_factory_processing_unit_strategy_ha);
    }
    // form
    if(Form_Popup_View_Popup_Item_.get() == NULL)
    {
        Form_Popup_View_Popup_Item_.reset(new Thahaha_form_popup_view_popup_item(NULL));
    }
    if(Form_Processing_Unit_Base_Base_.get() == NULL)
    {
        Form_Processing_Unit_Base_Base_.reset(new Thahaha_form_processing_unit_base_base(NULL));
    }
    if(Form_Processing_Unit_Region_Rectangle_.get() == NULL)
    {
        Form_Processing_Unit_Region_Rectangle_.reset(new Thahaha_form_processing_unit_region_rectangle(NULL));
    }
    if(Form_Processing_Unit_Strategy_Text_.get() == NULL)
    {
        Form_Processing_Unit_Strategy_Text_.reset(new Thahaha_form_processing_unit_strategy_text(NULL));
    }
    if(Form_Processing_Unit_Strategy_Image_.get() == NULL)
    {
        Form_Processing_Unit_Strategy_Image_.reset(new Thahaha_form_processing_unit_strategy_image(NULL));
    }


    //

    ha::Structure_Main_->Factory_Processing_Unit_Bases_[ha_def::factory_processing_unit_base::HA] = Factory_Processing_Unit_Base_Ha_.get();
    ha::Structure_Main_->Factory_Processing_Unit_Regions_[ha_def::factory_processing_unit_region::HA] = Factory_Processing_Unit_Region_Ha_.get();
    ha::Structure_Main_->Factory_Processing_Unit_Strategys_[ha_def::factory_processing_unit_strategy::HA] = Factory_Processing_Unit_Strategy_Ha_.get();

    ha::Form_Popup_View_Popup_Item_->box_item->Parent = ha::Structure_Main_->Form_Popup_View_Popup_->box_main_list_1;
    ha::Form_Popup_View_Popup_Item_->box_item->Align = alTop;
    ha::Form_Popup_View_Popup_Item_->box_item->Height = 66;

    ha::Form_Popup_View_Popup_Item_->item_rect_text_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_->bottom_content_box;
    ha::Form_Popup_View_Popup_Item_->item_rect_text_box->Align = alTop;
    ha::Form_Popup_View_Popup_Item_->item_rect_text_box->Visible = false;

    ha::Form_Popup_View_Popup_Item_->item_rect_image_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_->bottom_content_box;
    ha::Form_Popup_View_Popup_Item_->item_rect_image_box->Align = alTop;
    ha::Form_Popup_View_Popup_Item_->item_rect_image_box->Visible = false;
    //
    Form_Processing_Unit_Base_Base_->main_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_Setting_->box_processing_unit_base;
    Form_Processing_Unit_Base_Base_->main_box->Align = alClient;
    Form_Processing_Unit_Base_Base_->main_box->Visible = false;

    Form_Processing_Unit_Region_Rectangle_->main_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_Setting_->box_processing_unit_region;
    Form_Processing_Unit_Region_Rectangle_->main_box->Align = alClient;
    Form_Processing_Unit_Region_Rectangle_->main_box->Visible = false;

    Form_Processing_Unit_Strategy_Text_->main_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_Setting_->box_processing_unit_strategy;
    Form_Processing_Unit_Strategy_Text_->main_box->Align = alClient;
    Form_Processing_Unit_Strategy_Text_->main_box->Visible = false;

    Form_Processing_Unit_Strategy_Image_->main_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_Setting_->box_processing_unit_strategy;
    Form_Processing_Unit_Strategy_Image_->main_box->Align = alClient;
    Form_Processing_Unit_Strategy_Image_->main_box->Visible = false;
    //
    // 矪瞶把计ノ
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Form_Bases_[ha_def::processing_unit_base::BASE] = Form_Processing_Unit_Base_Base_.get();
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Form_Regions_[ha_def::processing_unit_region::RECTANGLE] = Form_Processing_Unit_Region_Rectangle_.get();
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Form_Strategys_[ha_def::processing_unit_strategy::TEXT] = Form_Processing_Unit_Strategy_Text_.get();
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Form_Strategys_[ha_def::processing_unit_strategy::IMAGE] = Form_Processing_Unit_Strategy_Image_.get();


    // ち传陪ボノ
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Page_Bases_[ha_def::processing_unit_base::BASE] = Form_Processing_Unit_Base_Base_->main_box;
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Page_Regions_[ha_def::processing_unit_region::RECTANGLE] = Form_Processing_Unit_Region_Rectangle_->main_box;
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Page_Strategys_[ha_def::processing_unit_strategy::TEXT] = Form_Processing_Unit_Strategy_Text_->main_box;
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Page_Strategys_[ha_def::processing_unit_strategy::IMAGE] = Form_Processing_Unit_Strategy_Image_->main_box;


    return 0;

}
//---------------------------------------------------------------------------
int Close()
{
    return 0;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // ha
//---------------------------------------------------------------------------