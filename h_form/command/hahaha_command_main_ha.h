//---------------------------------------------------------------------------

#ifndef hahaha_command_main_haH
#define hahaha_command_main_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <command\hahaha_command_main.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_command_main_ha :public hahaha_command_main
{
public:
	hahaha_command_main_ha();
	~hahaha_command_main_ha();

	hahaha_command_main_ha(const hahaha_command_main_ha& hcmh);
    hahaha_command_main_ha(hahaha_command_main_ha&& hcmh) noexcept;
	hahaha_command_main_ha& operator=(const hahaha_command_main_ha& hcmh);
    hahaha_command_main_ha& operator=(hahaha_command_main_ha&& hcmh) noexcept;
	void Copy(const hahaha_command_main_ha& hcmh);
    void Move(hahaha_command_main_ha&& hcmh) noexcept;
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

	//---------------------------------------------------------------------------
public:

public:

public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
