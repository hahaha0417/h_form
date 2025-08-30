//---------------------------------------------------------------------------

#ifndef hahaha_factory_processing_unit_regionH
#define hahaha_factory_processing_unit_regionH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>

//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_region.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_region;
//---------------------------------------------------------------------------

class hahaha_factory_processing_unit_region
{
public:
	hahaha_factory_processing_unit_region();
	~hahaha_factory_processing_unit_region();

	hahaha_factory_processing_unit_region(const hahaha_factory_processing_unit_region& hfpur);
    hahaha_factory_processing_unit_region(hahaha_factory_processing_unit_region&& hfpur) noexcept;
	hahaha_factory_processing_unit_region& operator=(const hahaha_factory_processing_unit_region& hfpur);
    hahaha_factory_processing_unit_region& operator=(hahaha_factory_processing_unit_region&& hfpur) noexcept;
	void Copy(const hahaha_factory_processing_unit_region& hfpur);
    void Move(hahaha_factory_processing_unit_region&& hfpur) noexcept;
public:
	int Reset();

public:
    std::wstring Name_;
public:
    virtual halib_def::result Add(ha_def::processing_unit_region type, hahaha::hahaha_processing_unit_region*& processing_unit_region);
    virtual halib_def::result Delete(hahaha::hahaha_processing_unit_region* processing_unit_region);
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
