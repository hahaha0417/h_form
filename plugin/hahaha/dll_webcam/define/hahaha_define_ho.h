//---------------------------------------------------------------------------

#ifndef hahaha_define_hoH
#define hahaha_define_hoH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <post\hahaha_post_package.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <bitmap\hahaha_c_bitmap_alloc.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Thahaha_form_popup_view_popup_item;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Thahaha_image_view_form;
//---------------------------------------------------------------------------

class Thahaha_form_processing_unit_strategy_webcam;
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_factory_processing_unit_base_ha;
class hahaha_factory_processing_unit_region_ha;
class hahaha_factory_processing_unit_strategy_ha;
//
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
//
class hahaha_command_main;
class hahaha_command_sub;
//---------------------------------------------------------------------------
class hahaha_image_view_base;
class hahaha_thread_command_webcam_ha;
class hahaha_thread_pool_time_set_event_timer_webcam_ha;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
namespace ha
{
//---------------------------------------------------------------------------
extern std::unique_ptr<hahaha::hahaha_factory_processing_unit_base_ha> Factory_Processing_Unit_Base_Ha_;
extern std::unique_ptr<hahaha::hahaha_factory_processing_unit_region_ha> Factory_Processing_Unit_Region_Ha_;
extern std::unique_ptr<hahaha::hahaha_factory_processing_unit_strategy_ha> Factory_Processing_Unit_Strategy_Ha_;
// form
extern std::unique_ptr<Thahaha_form_popup_view_popup_item> Form_Popup_View_Popup_Item_;

extern std::unique_ptr<Thahaha_form_processing_unit_strategy_webcam> Form_Processing_Unit_Strategy_Webcam_;


//---------------------------------------------------------------------------
// 變數
//---------------------------------------------------------------------------
extern std::unique_ptr<hahaha::hahaha_image_view_base> Image_View_Ha_;
extern std::unique_ptr<Thahaha_image_view_form> Form_Image_View_Ha_;
//---------------------------------------------------------------------------
extern std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_Argb_Ha_;
extern std::unique_ptr<halib::bitmap_alloc_yuy2> Bitmap_Yuy2_Ha_;
//---------------------------------------------------------------------------
// thread
//---------------------------------------------------------------------------
extern std::unique_ptr<hahaha::hahaha_thread_command_webcam_ha> Thread_Command_Webcam_Ha_;
extern std::unique_ptr<hahaha::hahaha_thread_pool_time_set_event_timer_webcam_ha> Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// 指標
//---------------------------------------------------------------------------
extern hahaha::hahaha_structure_main* Structure_Main_;
extern hahaha::hahaha_structure_sub* Structure_Sub_;
extern hahaha::hahaha_pointer_main* Pointer_Main_;
extern hahaha::hahaha_pointer_sub* Pointer_Sub_;
//
extern hahaha::hahaha_command_main* Command_Main_;
extern hahaha::hahaha_command_sub* Command_Sub_;
//---------------------------------------------------------------------------
// 功能
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

extern int Initial_Environment(hahaha::hahaha_post_package& input,
	hahaha::hahaha_post_package& output,
    hahaha::hahaha_post_package& setting
);
//---------------------------------------------------------------------------
extern int Initial();
//---------------------------------------------------------------------------
extern int Close();
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // ha
//---------------------------------------------------------------------------
#endif
