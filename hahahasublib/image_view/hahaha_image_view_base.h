//---------------------------------------------------------------------------

#ifndef hahaha_image_view_baseH
#define hahaha_image_view_baseH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
//---------------------------------------------------------------------------

class hahaha_image_view_base : public hahahalib::hahaha_image_view
{
public:
	hahaha_image_view_base();
	~hahaha_image_view_base();

	hahaha_image_view_base(const hahaha_image_view_base& hivb);
    hahaha_image_view_base(hahaha_image_view_base&& hivb) noexcept;
	hahaha_image_view_base& operator=(const hahaha_image_view_base& hivb);
    hahaha_image_view_base& operator=(hahaha_image_view_base&& hivb) noexcept;
	void Copy(const hahaha_image_view_base& hivb);
    void Move(hahaha_image_view_base&& hivb) noexcept;
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

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
