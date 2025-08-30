//---------------------------------------------------------------------------

#ifndef hahaha_command_subH
#define hahaha_command_subH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 實作在exe，dll者，有需要另外自建
// 非架構者，放在pointer_sub
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_command_sub
{
public:
	hahaha_command_sub();
	~hahaha_command_sub();

	hahaha_command_sub(const hahaha_command_sub& hcs);
    hahaha_command_sub(hahaha_command_sub&& hcs) noexcept;
	hahaha_command_sub& operator=(const hahaha_command_sub& hcs);
    hahaha_command_sub& operator=(hahaha_command_sub&& hcs) noexcept;
	void Copy(const hahaha_command_sub& hcs);
    void Move(hahaha_command_sub&& hcs) noexcept;
public:
	int Reset();

public:

public:
public:
public:
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
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
