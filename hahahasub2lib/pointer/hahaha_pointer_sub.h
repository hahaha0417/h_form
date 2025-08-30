//---------------------------------------------------------------------------

#ifndef hahaha_pointer_subH
#define hahaha_pointer_subH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------

class hahaha_pointer_sub
{
public:
	hahaha_pointer_sub();
	~hahaha_pointer_sub();

	hahaha_pointer_sub(const hahaha_pointer_sub& hps);
    hahaha_pointer_sub(hahaha_pointer_sub&& hps) noexcept;
	hahaha_pointer_sub& operator=(const hahaha_pointer_sub& hps);
    hahaha_pointer_sub& operator=(hahaha_pointer_sub&& hps) noexcept;
	void Copy(const hahaha_pointer_sub& hps);
    void Move(hahaha_pointer_sub&& hps) noexcept;
public:
	int Reset();

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
public:
public:

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
