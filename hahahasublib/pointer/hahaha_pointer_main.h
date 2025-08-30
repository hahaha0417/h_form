//---------------------------------------------------------------------------

#ifndef hahaha_pointer_mainH
#define hahaha_pointer_mainH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Thahaha_form_main;
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class hahaha_system_setting;
class hahaha_option;
class hahaha_setting;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class hahaha_view_scene;
class hahaha_view_view;
class hahaha_processing_unit_base;
//
class hahaha_command_main;
class hahaha_command_sub;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_pointer_main
{
public:
	hahaha_pointer_main();
	~hahaha_pointer_main();

	hahaha_pointer_main(const hahaha_pointer_main& hpm);
    hahaha_pointer_main(hahaha_pointer_main&& hpm) noexcept;
	hahaha_pointer_main& operator=(const hahaha_pointer_main& hpm);
    hahaha_pointer_main& operator=(hahaha_pointer_main&& hpm) noexcept;
	void Copy(const hahaha_pointer_main& hpm);
    void Move(hahaha_pointer_main&& hpm) noexcept;
public:
	int Reset();

public:
    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------
    hahaha::hahaha_system_setting* System_Setting_;
    hahaha::hahaha_option* Option_;
    hahaha::hahaha_setting* Setting_;
    //---------------------------------------------------------------------------
    hahaha::hahaha_view_scene* Select_Scene_;
    hahaha::hahaha_view_view* Select_View_;
    hahaha::hahaha_processing_unit_base* Choose_Processing_Unit_;
    hahaha::hahaha_processing_unit_base* Candidate_Processing_Unit_;
    //---------------------------------------------------------------------------
    hahaha::hahaha_command_main* Command_Main_;
	hahaha::hahaha_command_sub* Command_Sub_;
    //---------------------------------------------------------------------------
public:
    Thahaha_form_main* Form_Main_;
public:
public:
	//---------------------------------------------------------------------------
	halib_def::result Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    halib_def::result Set_Pointer(
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
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
