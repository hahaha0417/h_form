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
#include <form\processing_unit\strategy\hahaha_processing_unit_form_strategy_webcam.h>
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//
#include <command\hahaha_command_main.h>
#include <command\hahaha_command_sub.h>
//---------------------------------------------------------------------------
#include <capture\webcam\hahaha_capture_webcam_direct_show.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_base.h>
#include <thread\base\hahaha_thread_command_command.h>
#include <thread\hahaha_thread_command_webcam_ha.h>
#include <thread_pool\hahaha_thread_pool_time_set_event_timer_webcam_ha.h>
//---------------------------------------------------------------------------

#include "hahaha_define_ho.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// 注意 :
// exe & dll 不共用全域變數，要共用要放在class裡面
// 沒要傳的隨便
//---------------------------------------------------------------------------
namespace ha
{
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_factory_processing_unit_base_ha> Factory_Processing_Unit_Base_Ha_;
std::unique_ptr<hahaha::hahaha_factory_processing_unit_region_ha> Factory_Processing_Unit_Region_Ha_;
std::unique_ptr<hahaha::hahaha_factory_processing_unit_strategy_ha> Factory_Processing_Unit_Strategy_Ha_;
// form
std::unique_ptr<Thahaha_form_popup_view_popup_item> Form_Popup_View_Popup_Item_;

std::unique_ptr<Thahaha_form_processing_unit_strategy_webcam> Form_Processing_Unit_Strategy_Webcam_;
//---------------------------------------------------------------------------
// 變數
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_image_view_base> Image_View_Ha_;
std::unique_ptr<Thahaha_image_view_form> Form_Image_View_Ha_;
//---------------------------------------------------------------------------
std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_Argb_Ha_;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// thread
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_thread_command_webcam_ha> Thread_Command_Webcam_Ha_;
std::unique_ptr<hahaha::hahaha_thread_pool_time_set_event_timer_webcam_ha> Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// 指標
//---------------------------------------------------------------------------
hahaha::hahaha_structure_main* Structure_Main_;
hahaha::hahaha_structure_sub* Structure_Sub_;
hahaha::hahaha_pointer_main* Pointer_Main_;
hahaha::hahaha_pointer_sub* Pointer_Sub_;
//
hahaha::hahaha_command_main* Command_Main_;
hahaha::hahaha_command_sub* Command_Sub_;
//---------------------------------------------------------------------------
// 功能
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
    // 1ms
    timeBeginPeriod(1);
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
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

    if(Form_Processing_Unit_Strategy_Webcam_.get() == NULL)
    {
		Form_Processing_Unit_Strategy_Webcam_.reset(new Thahaha_form_processing_unit_strategy_webcam(NULL));
	}
    // thread
    if(Thread_Command_Webcam_Ha_.get() == NULL)
    {
		Thread_Command_Webcam_Ha_.reset(new hahaha::hahaha_thread_command_webcam_ha);
	}
    if(Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_.get() == NULL)
    {
		Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_.reset(new hahaha::hahaha_thread_pool_time_set_event_timer_webcam_ha);
	}


    ha::Thread_Command_Webcam_Ha_->Create();

	//---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
	if(Image_View_Ha_.get() == NULL)
	{
		Image_View_Ha_.reset(new hahaha::hahaha_image_view_base);
	}
	if(Form_Image_View_Ha_.get() == NULL)
	{

		Form_Image_View_Ha_.reset(new Thahaha_image_view_form(NULL));
	}
	if(Bitmap_Argb_Ha_.get() == NULL)
	{
		Bitmap_Argb_Ha_.reset(new halib::bitmap_alloc_argb());
	}

    //---------------------------------------------------------------------------
	Form_Image_View_Ha_->Set_Image_View(Image_View_Ha_.get());
	Form_Image_View_Ha_->DoubleBuffered = true;

	Image_View_Ha_->View_Thumbnail_Interpolation_ = halib_def::image_view_view_thumbnail_interpolation::NEAREST;
	Image_View_Ha_->View_Direction_ = halib_def::image_view_view_direction::NORMAL;
	Image_View_Ha_->View_Ratio_ = 1.0;
	Image_View_Ha_->Is_View_Scroll_ = true;
	//
	Bitmap_Argb_Ha_->Resize(1920, 1080);
	Bitmap_Argb_Ha_->Clear();

	Image_View_Ha_->Bitmap_ = Bitmap_Argb_Ha_.get();
	Image_View_Ha_->Is_View_Thumbnail_ = false;
	Image_View_Ha_->Image_Center_ = halib::point_double((double)(Bitmap_Argb_Ha_->Width_ - 1 ) / 2,
		(double)(Bitmap_Argb_Ha_->Height_ - 1 ) / 2
	);

	Image_View_Ha_->Background_Color_ = TColor(RGB(60, 60, 60));

	Image_View_Ha_->Is_View_Bitmap_Full_ = true;
	//---------------------------------------------------------------------------

	//---------------------------------------------------------------------------

    ha::Structure_Main_->Factory_Processing_Unit_Bases_[ha_def::factory_processing_unit_base::PLUGIN_HAHAHA_WEBCAM] = Factory_Processing_Unit_Base_Ha_.get();
	ha::Structure_Main_->Factory_Processing_Unit_Regions_[ha_def::factory_processing_unit_region::PLUGIN_HAHAHA_WEBCAM] = Factory_Processing_Unit_Region_Ha_.get();
    ha::Structure_Main_->Factory_Processing_Unit_Strategys_[ha_def::factory_processing_unit_strategy::PLUGIN_HAHAHA_WEBCAM] = Factory_Processing_Unit_Strategy_Ha_.get();

    ha::Form_Popup_View_Popup_Item_->box_item->Parent = ha::Structure_Main_->Form_Popup_View_Popup_->box_main_list_1;
    ha::Form_Popup_View_Popup_Item_->box_item->Align = alTop;
    ha::Form_Popup_View_Popup_Item_->box_item->Height = 66;

    ha::Form_Popup_View_Popup_Item_->item_rect_monitor_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_->bottom_content_box;
    ha::Form_Popup_View_Popup_Item_->item_rect_monitor_box->Align = alTop;
    ha::Form_Popup_View_Popup_Item_->item_rect_monitor_box->Visible = false;
	//

    Form_Processing_Unit_Strategy_Webcam_->main_box->Parent = ha::Structure_Main_->Form_Popup_View_Popup_Setting_->box_processing_unit_strategy;
	Form_Processing_Unit_Strategy_Webcam_->main_box->Align = alClient;
	Form_Processing_Unit_Strategy_Webcam_->main_box->Visible = false;

	// --------------------------------------------------
	// 移到視窗外，讓DLL先處理畫面
	Form_Image_View_Ha_->Left = -10000;
	Form_Image_View_Ha_->Top = 0;
	Form_Image_View_Ha_->Width = 0;
	Form_Image_View_Ha_->Height = 0;
	// 這要先，不然畫面更新會不對
	Form_Image_View_Ha_->Visible = true;
	// 插入
	Form_Image_View_Ha_->MainBox->Parent = Form_Processing_Unit_Strategy_Webcam_->view_box;
	Form_Image_View_Ha_->MainBox->Align = alClient;
	// 隱藏
	Form_Image_View_Ha_->Visible = false;
	// --------------------------------------------------

	Form_Processing_Unit_Strategy_Webcam_->view_box->BorderStyle = bsNone;
    //
    // 處理參數用
    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Form_Strategys_[ha_def::processing_unit_strategy::PLUGIN_HAHAHA_WEBCAM] = Form_Processing_Unit_Strategy_Webcam_.get();


    // 切換顯示用

    ha::Structure_Main_->Form_Popup_View_Popup_Setting_->Page_Strategys_[ha_def::processing_unit_strategy::PLUGIN_HAHAHA_WEBCAM] = Form_Processing_Unit_Strategy_Webcam_->main_box;


    return 0;

}
//---------------------------------------------------------------------------
int Close()
{
    ha::Thread_Command_Webcam_Ha_->Wait();
    ha::Thread_Command_Webcam_Ha_->Close();
    // 1ms
	timeEndPeriod(1); // 恢復系統 timer resolution
	CoUninitialize();
    return 0;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // ha
//---------------------------------------------------------------------------