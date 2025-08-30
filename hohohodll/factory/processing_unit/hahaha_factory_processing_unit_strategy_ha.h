//---------------------------------------------------------------------------

#ifndef hahaha_factory_processing_unit_strategy_haH
#define hahaha_factory_processing_unit_strategy_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <map>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_strategy.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_strategy.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_strategy;
class hahaha_processing_unit_strategy_text;
class hahaha_processing_unit_strategy_image;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_factory_processing_unit_strategy_ha : public hahaha_factory_processing_unit_strategy
{
public:
	hahaha_factory_processing_unit_strategy_ha();
	~hahaha_factory_processing_unit_strategy_ha();

	hahaha_factory_processing_unit_strategy_ha(const hahaha_factory_processing_unit_strategy_ha& hfpush);
    hahaha_factory_processing_unit_strategy_ha(hahaha_factory_processing_unit_strategy_ha&& hfpush) noexcept;
	hahaha_factory_processing_unit_strategy_ha& operator=(const hahaha_factory_processing_unit_strategy_ha& hfpush);
    hahaha_factory_processing_unit_strategy_ha& operator=(hahaha_factory_processing_unit_strategy_ha&& hfpush) noexcept;
	void Copy(const hahaha_factory_processing_unit_strategy_ha& hfpush);
    void Move(hahaha_factory_processing_unit_strategy_ha&& hfpush) noexcept;
public:
	int Reset();

public:
    // unique_ptr 不要掛繼承的類別，刪除會有問題，所以分開來定義
    std::map<hahaha::hahaha_processing_unit_strategy_text*, std::unique_ptr<hahaha::hahaha_processing_unit_strategy_text>> Pu_Strategy_Text_;
    std::map<hahaha::hahaha_processing_unit_strategy_image*, std::unique_ptr<hahaha::hahaha_processing_unit_strategy_image>> Pu_Strategy_Image_;
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
