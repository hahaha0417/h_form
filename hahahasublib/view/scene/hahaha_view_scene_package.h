//---------------------------------------------------------------------------

#ifndef hahaha_view_scene_packageH
#define hahaha_view_scene_packageH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Thahaha_form_view_scene;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_view_scene_package
{
public:
	hahaha_view_scene_package();
	~hahaha_view_scene_package();

	hahaha_view_scene_package(const hahaha_view_scene_package& hvsp);
    hahaha_view_scene_package(hahaha_view_scene_package&& hvsp) noexcept;
	hahaha_view_scene_package& operator=(const hahaha_view_scene_package& hvsp);
    hahaha_view_scene_package& operator=(hahaha_view_scene_package&& hvsp) noexcept;
	void Copy(const hahaha_view_scene_package& hvsp);
    void Move(hahaha_view_scene_package&& hvsp) noexcept;
public:
	int Reset();
public:
	//---------------------------------------------------------------------------
	int Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    int Set_Pointer(
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
    std::unique_ptr<Thahaha_form_view_scene> Form_Scene_;
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
