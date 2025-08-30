//---------------------------------------------------------------------------

#ifndef hahaha_structure_mainH
#define hahaha_structure_mainH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
#include <map>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_base.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_region.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_strategy.h>

//---------------------------------------------------------------------------
#include <bitmap\hahaha_c_bitmap_alloc.h>
//---------------------------------------------------------------------------
class Thahaha_image_view_form;
//---------------------------------------------------------------------------

class Thahaha_form_system_setting;
class Thahaha_form_option;
class Thahaha_form_popup;
class Thahaha_form_edit;
class Thahaha_form_view;
//---------------------------------------------------------------------------
class Thahaha_form_popup_scene_popup;
class Thahaha_form_popup_view_popup;
class Thahaha_form_popup_scene_popup_setting;
class Thahaha_form_popup_view_popup_setting;

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
//---------------------------------------------------------------------------
class hahaha_painter_information;
class hahaha_painter_view;
//---------------------------------------------------------------------------
class hahaha_image_view_base;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_system_setting;
class hahaha_parameter_deal_option;
class hahaha_parameter_deal_setting;
//---------------------------------------------------------------------------
class hahaha_load_dll;
//---------------------------------------------------------------------------
class hahaha_factory_processing_unit_base;
class hahaha_factory_processing_unit_strategy;
class hahaha_factory_processing_unit_region;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_structure_main
{
public:
	hahaha_structure_main();
	~hahaha_structure_main();

	hahaha_structure_main(const hahaha_structure_main& hsm);
    hahaha_structure_main(hahaha_structure_main&& hsm) noexcept;
	hahaha_structure_main& operator=(const hahaha_structure_main& hsm);
    hahaha_structure_main& operator=(hahaha_structure_main&& hsm) noexcept;
	void Copy(const hahaha_structure_main& hsm);
    void Move(hahaha_structure_main&& hsm) noexcept;
public:
	int Reset();

public:
    //---------------------------------------------------------------------------
    // 變數
    //---------------------------------------------------------------------------
    std::unique_ptr<hahaha::hahaha_image_view_base> Image_View_;
    std::unique_ptr<Thahaha_image_view_form> Form_Image_View_;
    // painter
    std::unique_ptr<hahaha::hahaha_painter_information> Painter_Information_;
    std::unique_ptr<hahaha::hahaha_painter_view> Painter_View_;
    //---------------------------------------------------------------------------
    // 主要
    //---------------------------------------------------------------------------

    std::unique_ptr<Thahaha_form_edit> Form_Edit_;
    std::unique_ptr<Thahaha_form_option> Form_Option_;
    std::unique_ptr<Thahaha_form_popup> Form_Popup_;
    std::unique_ptr<Thahaha_form_system_setting> Form_System_Setting_;
    std::unique_ptr<Thahaha_form_view> Form_View_;
    //---------------------------------------------------------------------------
    // 次要
    //---------------------------------------------------------------------------
    std::unique_ptr<Thahaha_form_popup_scene_popup> Form_Popup_Scene_Popup_;
    std::unique_ptr<Thahaha_form_popup_view_popup> Form_Popup_View_Popup_;
    std::unique_ptr<Thahaha_form_popup_scene_popup_setting> Form_Popup_Scene_Popup_Setting_;
    std::unique_ptr<Thahaha_form_popup_view_popup_setting> Form_Popup_View_Popup_Setting_;

    //---------------------------------------------------------------------------
    std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_Argb_;
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Dll
    //----------------------------------------
    std::map<std::wstring, std::unique_ptr<hahaha::hahaha_load_dll>> Dlls_;
    //---------------------------------------------------------------------------
    std::map<ha_def::factory_processing_unit_base, hahaha::hahaha_factory_processing_unit_base*> Factory_Processing_Unit_Bases_;
    std::map<ha_def::factory_processing_unit_region, hahaha::hahaha_factory_processing_unit_region*> Factory_Processing_Unit_Regions_;
    std::map<ha_def::factory_processing_unit_strategy, hahaha::hahaha_factory_processing_unit_strategy*> Factory_Processing_Unit_Strategys_;
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
public:
	//---------------------------------------------------------------------------
	virtual halib_def::result Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    virtual halib_def::result Set_Pointer(
        hahaha::hahaha_pointer_main* pointer_main,
    	hahaha::hahaha_pointer_sub* pointer_sub
    );
	//---------------------------------------------------------------------------
    hahaha::hahaha_structure_main* Structure_Main_;
    hahaha::hahaha_structure_sub* Structure_Sub_;
    hahaha::hahaha_pointer_main* Pointer_Main_;
    hahaha::hahaha_pointer_sub* Pointer_Sub_;
	//---------------------------------------------------------------------------
public:
public:
public:
public:
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
