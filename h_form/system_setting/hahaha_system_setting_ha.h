//---------------------------------------------------------------------------

#ifndef hahaha_system_setting_haH
#define hahaha_system_setting_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <system_setting\hahaha_system_setting.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_system_setting_ha : public hahaha_system_setting
{
public:
	hahaha_system_setting_ha();
	~hahaha_system_setting_ha();

	hahaha_system_setting_ha(const hahaha_system_setting_ha& hssh);
    hahaha_system_setting_ha(hahaha_system_setting_ha&& hssh) noexcept;
	hahaha_system_setting_ha& operator=(const hahaha_system_setting_ha& hssh);
    hahaha_system_setting_ha& operator=(hahaha_system_setting_ha&& hssh) noexcept;
	void Copy(const hahaha_system_setting_ha& hssh);
    void Move(hahaha_system_setting_ha&& hssh) noexcept;
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
