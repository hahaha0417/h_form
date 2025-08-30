//---------------------------------------------------------------------------

#ifndef hahaha_load_dllH
#define hahaha_load_dllH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
//---------------------------------------------------------------------------
#include <post\hahaha_post_package.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_load_dll
{
public:
	hahaha_load_dll();
	~hahaha_load_dll();

	hahaha_load_dll(const hahaha_load_dll& hld);
    hahaha_load_dll(hahaha_load_dll&& hld) noexcept;
	hahaha_load_dll& operator=(const hahaha_load_dll& hld);
    hahaha_load_dll& operator=(hahaha_load_dll&& hld) noexcept;
	void Copy(const hahaha_load_dll& hld);
    void Move(hahaha_load_dll&& hld) noexcept;
public:
    typedef int (*Hahaha)(std::wstring& cmd);

    typedef int (*Hahaha_Post)(hahaha::hahaha_post_package& input,
        hahaha::hahaha_post_package& output,
        hahaha::hahaha_post_package& setting
    );

public:
	int Reset();

public:
    int Load(const std::wstring& file_name);
public:
    int Close();
public:
    HINSTANCE Dll_;
public:
    Hahaha Hahaha_;
    Hahaha_Post Hahaha_Post_;
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
