//---------------------------------------------------------------------------

#ifndef hahaha_factory_processing_unit_strategyH
#define hahaha_factory_processing_unit_strategyH
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
#include <define\processing_unit\hahaha_define_processing_unit_strategy.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_strategy;
//---------------------------------------------------------------------------

class hahaha_factory_processing_unit_strategy
{
public:
	hahaha_factory_processing_unit_strategy();
	~hahaha_factory_processing_unit_strategy();

	hahaha_factory_processing_unit_strategy(const hahaha_factory_processing_unit_strategy& hfpus);
    hahaha_factory_processing_unit_strategy(hahaha_factory_processing_unit_strategy&& hfpus) noexcept;
	hahaha_factory_processing_unit_strategy& operator=(const hahaha_factory_processing_unit_strategy& hfpus);
    hahaha_factory_processing_unit_strategy& operator=(hahaha_factory_processing_unit_strategy&& hfpus) noexcept;
	void Copy(const hahaha_factory_processing_unit_strategy& hfpus);
    void Move(hahaha_factory_processing_unit_strategy&& hfpus) noexcept;
public:
	int Reset();

public:
    std::wstring Name_;
public:
	virtual halib_def::result Add(ha_def::processing_unit_strategy type, hahaha::hahaha_processing_unit_strategy*& processing_unit_strategy);
    virtual halib_def::result Delete(hahaha::hahaha_processing_unit_strategy* processing_unit_strategy);
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
