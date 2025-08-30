//---------------------------------------------------------------------------

#ifndef hahaha_factory_processing_unit_base_haH
#define hahaha_factory_processing_unit_base_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <map>

//---------------------------------------------------------------------------

#include <factory\processing_unit\hahaha_factory_processing_unit_base.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Thahaha_form_factory_processing_unit_base_ha;
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit;

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_factory_processing_unit_base_ha : public hahaha_factory_processing_unit_base
{
public:
	hahaha_factory_processing_unit_base_ha();
	~hahaha_factory_processing_unit_base_ha();

	hahaha_factory_processing_unit_base_ha(const hahaha_factory_processing_unit_base_ha& hfpubh);
    hahaha_factory_processing_unit_base_ha(hahaha_factory_processing_unit_base_ha&& hfpubh) noexcept;
	hahaha_factory_processing_unit_base_ha& operator=(const hahaha_factory_processing_unit_base_ha& hfpubh);
    hahaha_factory_processing_unit_base_ha& operator=(hahaha_factory_processing_unit_base_ha&& hfpubh) noexcept;
	void Copy(const hahaha_factory_processing_unit_base_ha& hfpubh);
    void Move(hahaha_factory_processing_unit_base_ha&& hfpubh) noexcept;
public:
	int Reset();

public:
    // unique_ptr 不要掛繼承的類別，刪除會有問題，所以分開來定義
//    std::map<hahaha::hahaha_processing_unit_base_base*, std::unique_ptr<hahaha::hahaha_processing_unit_base_base>> Pu_Base_Base_;

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
