//---------------------------------------------------------------------------

#ifndef hahaha_view_view_packageH
#define hahaha_view_view_packageH
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
class Thahaha_form_view_view;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_view_view_package
{
public:
	hahaha_view_view_package();
	~hahaha_view_view_package();

	hahaha_view_view_package(const hahaha_view_view_package& hvvp);
    hahaha_view_view_package(hahaha_view_view_package&& hvvp) noexcept;
	hahaha_view_view_package& operator=(const hahaha_view_view_package& hvvp);
    hahaha_view_view_package& operator=(hahaha_view_view_package&& hvvp) noexcept;
	void Copy(const hahaha_view_view_package& hvvp);
    void Move(hahaha_view_view_package&& hvvp) noexcept;
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
public:
    std::unique_ptr<Thahaha_form_view_view> Form_View_;
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
