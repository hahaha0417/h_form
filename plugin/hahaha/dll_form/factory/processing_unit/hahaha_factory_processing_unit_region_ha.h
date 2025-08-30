//---------------------------------------------------------------------------

#ifndef hahaha_factory_processing_unit_region_haH
#define hahaha_factory_processing_unit_region_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <map>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_region.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_region.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_region;
class hahaha_processing_unit_region_rectangle;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_factory_processing_unit_region_ha : public hahaha_factory_processing_unit_region
{
public:
	hahaha_factory_processing_unit_region_ha();
	~hahaha_factory_processing_unit_region_ha();

	hahaha_factory_processing_unit_region_ha(const hahaha_factory_processing_unit_region_ha& hfpurh);
    hahaha_factory_processing_unit_region_ha(hahaha_factory_processing_unit_region_ha&& hfpurh) noexcept;
	hahaha_factory_processing_unit_region_ha& operator=(const hahaha_factory_processing_unit_region_ha& hfpurh);
    hahaha_factory_processing_unit_region_ha& operator=(hahaha_factory_processing_unit_region_ha&& hfpurh) noexcept;
	void Copy(const hahaha_factory_processing_unit_region_ha& hfpurh);
    void Move(const hahaha_factory_processing_unit_region_ha&& hfpurh) noexcept;
public:
	int Reset();

public:
    // unique_ptr 不要掛繼承的類別，刪除會有問題，所以分開來定義
//    std::map<hahaha::hahaha_processing_unit_region_rectangle*, std::unique_ptr<hahaha::hahaha_processing_unit_region_rectangle>> Pu_Region_Rectangle_;
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
