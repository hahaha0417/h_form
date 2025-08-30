//---------------------------------------------------------------------------

#ifndef hahaha_optionH
#define hahaha_optionH
//---------------------------------------------------------------------------
#pragma once
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
namespace hahaha
{
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_option
{
public:
	hahaha_option();
	~hahaha_option();

	hahaha_option(const hahaha_option& ho);
    hahaha_option(hahaha_option&& ho) noexcept;
	hahaha_option& operator=(const hahaha_option& ho);
    hahaha_option& operator=(hahaha_option&& ho) noexcept;
	void Copy(const hahaha_option& ho);
    void Move(hahaha_option&& ho) noexcept;
public:
	int Reset();

public:
    virtual halib_def::result Load(
		const std::wstring& dir_name
	);
    virtual halib_def::result Save(
		const std::wstring& dir_name
	);
public:
    std::wstring File_Name_;
    // 設定檔名
    std::wstring File_Name_Setting_;
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
    // 初始化設定
    virtual halib_def::result Initial();
    // 載入初始化
    virtual halib_def::result Load_Initial();
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
