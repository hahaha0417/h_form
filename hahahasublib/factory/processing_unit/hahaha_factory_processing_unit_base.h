//---------------------------------------------------------------------------

#ifndef hahaha_factory_processing_unit_baseH
#define hahaha_factory_processing_unit_baseH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>

//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_base.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_base;
//---------------------------------------------------------------------------

class hahaha_factory_processing_unit_base
{
public:
	hahaha_factory_processing_unit_base();
	~hahaha_factory_processing_unit_base();

	hahaha_factory_processing_unit_base(const hahaha_factory_processing_unit_base& hfpub);
    hahaha_factory_processing_unit_base(hahaha_factory_processing_unit_base&& hfpub) noexcept;
	hahaha_factory_processing_unit_base& operator=(const hahaha_factory_processing_unit_base& hfpub);
    hahaha_factory_processing_unit_base& operator=(hahaha_factory_processing_unit_base&& hfpub) noexcept;
	void Copy(const hahaha_factory_processing_unit_base& hfpub);
    void Move(hahaha_factory_processing_unit_base&& hfpub) noexcept;
public:
	int Reset();

public:
    std::wstring Name_;
public:
    virtual halib_def::result Add(ha_def::processing_unit_base type, hahaha::hahaha_processing_unit_base*& processing_unit_base);
    virtual halib_def::result Delete(hahaha::hahaha_processing_unit_base* processing_unit_base);
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
