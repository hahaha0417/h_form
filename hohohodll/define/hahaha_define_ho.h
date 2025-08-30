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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Thahaha_form_popup_view_popup_item;
//---------------------------------------------------------------------------
class Thahaha_form_processing_unit_base_base;
class Thahaha_form_processing_unit_region_rectangle;
class Thahaha_form_processing_unit_strategy_image;
class Thahaha_form_processing_unit_strategy_text;
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
extern std::unique_ptr<Thahaha_form_processing_unit_base_base> Form_Processing_Unit_Base_Base_;
extern std::unique_ptr<Thahaha_form_processing_unit_region_rectangle> Form_Processing_Unit_Region_Rectangle_;
extern std::unique_ptr<Thahaha_form_processing_unit_strategy_image> Form_Processing_Unit_Strategy_Image_;
extern std::unique_ptr<Thahaha_form_processing_unit_strategy_text> Form_Processing_Unit_Strategy_Text_;


//---------------------------------------------------------------------------
// 變數
//---------------------------------------------------------------------------

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
