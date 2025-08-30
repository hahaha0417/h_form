//---------------------------------------------------------------------------

#ifndef hahaha_option_haH
#define hahaha_option_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <option\hahaha_option.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_option_ha : public hahaha_option
{
public:
	hahaha_option_ha();
	~hahaha_option_ha();

	hahaha_option_ha(const hahaha_option_ha& hoh);
    hahaha_option_ha(hahaha_option_ha&& hoh) noexcept;
	hahaha_option_ha& operator=(const hahaha_option_ha& hoh);
    hahaha_option_ha& operator=(hahaha_option_ha&& hoh) noexcept;
	void Copy(const hahaha_option_ha& hoh);
    void Move(hahaha_option_ha&& hoh) noexcept;
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
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
