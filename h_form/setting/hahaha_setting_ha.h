//---------------------------------------------------------------------------

#ifndef hahaha_setting_haH
#define hahaha_setting_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <setting\hahaha_setting.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_setting_ha : public hahaha_setting
{
public:
	hahaha_setting_ha();
	~hahaha_setting_ha();

	hahaha_setting_ha(const hahaha_setting_ha& hsh);
    hahaha_setting_ha(hahaha_setting_ha&& hsh) noexcept;
	hahaha_setting_ha& operator=(const hahaha_setting_ha& hsh);
    hahaha_setting_ha& operator=(hahaha_setting_ha&& hsh) noexcept;
	void Copy(const hahaha_setting_ha& hsh);
    void Move(hahaha_setting_ha&& hsh) noexcept;
public:
	int Reset();

public:

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


public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
