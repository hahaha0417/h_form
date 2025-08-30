//---------------------------------------------------------------------------

#ifndef hahaha_post_packageH
#define hahaha_post_packageH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
#include <vector>
#include <memory>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_post_package
{
public:
	hahaha_post_package();
    hahaha_post_package(
        const std::wstring& name,
        const std::wstring& type,
        const void* object,
        const std::vector<void*>& objects,
        const std::vector<std::wstring>& commands,
        const std::vector<std::wstring>& describes,
        const std::vector<hahaha_post_package>& packages
    );
	~hahaha_post_package();

	hahaha_post_package(const hahaha_post_package& hpp);
    hahaha_post_package(hahaha_post_package&& hpp) noexcept;
	hahaha_post_package& operator=(const hahaha_post_package& hpp);
    hahaha_post_package& operator=(hahaha_post_package&& hpp) noexcept;
	void Copy(const hahaha_post_package& hpp);
    void Move(hahaha_post_package&& hpp) noexcept;
public:
	int Reset();

public:
    std::wstring Name_;
    std::wstring Type_;
    void* Object_;
    std::vector<void*> Objects_;
    std::vector<std::wstring> Commands_;
    std::vector<std::wstring> Describes_;
public:
	std::vector<hahaha_post_package> Packages_;
public:
public:


};


//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------
#endif
