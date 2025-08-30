//---------------------------------------------------------------------------

#ifndef hahaha_command_mainH
#define hahaha_command_mainH
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
// 實作在exe，dll者，有需要另外自建
// 非架構者，放在pointer_sub
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_command_main
{
public:
	hahaha_command_main();
	~hahaha_command_main();

	hahaha_command_main(const hahaha_command_main& hcm);
    hahaha_command_main(hahaha_command_main&& hcm) noexcept;
	hahaha_command_main& operator=(const hahaha_command_main& hcm);
    hahaha_command_main& operator=(hahaha_command_main&& hcm) noexcept;
	void Copy(const hahaha_command_main& hcm);
    void Move(hahaha_command_main&& hcm) noexcept;
public:
	int Reset();

public:
	virtual halib_def::result Initial_Environment();
    virtual halib_def::result Initial();
    virtual halib_def::result Close();
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
