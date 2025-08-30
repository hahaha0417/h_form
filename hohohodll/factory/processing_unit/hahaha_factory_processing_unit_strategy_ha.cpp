//---------------------------------------------------------------------------

#pragma hdrstop

#include <processing_unit\strategy\hahaha_processing_unit_strategy_text.h>
#include <processing_unit\strategy\hahaha_processing_unit_strategy_image.h>

#include "hahaha_factory_processing_unit_strategy_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy_ha::hahaha_factory_processing_unit_strategy_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy_ha::~hahaha_factory_processing_unit_strategy_ha()
{

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy_ha::hahaha_factory_processing_unit_strategy_ha(const hahaha_factory_processing_unit_strategy_ha& hfpush)
{
    Reset();
	Copy(hfpush);
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy_ha::hahaha_factory_processing_unit_strategy_ha(hahaha_factory_processing_unit_strategy_ha&& hfpush) noexcept
{
    hahaha_factory_processing_unit_strategy_ha::Move(std::move(hfpush));
    Move(std::move(hfpush));
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy_ha& hahaha_factory_processing_unit_strategy_ha::operator=(const hahaha_factory_processing_unit_strategy_ha& hfpush)
{
	Copy(hfpush);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy_ha& hahaha_factory_processing_unit_strategy_ha::operator=(hahaha_factory_processing_unit_strategy_ha&& hfpush) noexcept
{
    hahaha_factory_processing_unit_strategy_ha::Move(std::move(hfpush));
    Move(std::move(hfpush));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_strategy_ha::Copy(const hahaha_factory_processing_unit_strategy_ha& hfpush)
{

}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_strategy_ha::Move(hahaha_factory_processing_unit_strategy_ha&& hfpush) noexcept
{
    Pu_Strategy_Text_ = std::move(hfpush.Pu_Strategy_Text_);
    Pu_Strategy_Image_ = std::move(hfpush.Pu_Strategy_Image_);
}
//---------------------------------------------------------------------------
int hahaha_factory_processing_unit_strategy_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_strategy_ha::Add(ha_def::processing_unit_strategy type, hahaha::hahaha_processing_unit_strategy*& processing_unit_strategy)
{
    if(type == ha_def::processing_unit_strategy::TEXT)
    {
        std::unique_ptr<hahaha::hahaha_processing_unit_strategy_text> pust_;
        pust_.reset(new hahaha::hahaha_processing_unit_strategy_text);
        // 這要在前
        processing_unit_strategy = pust_.get();

        processing_unit_strategy->Type_Factory_Strategy_ = ha_def::factory_processing_unit_strategy::HA;
        processing_unit_strategy->Name_Factory_Strategy_ = L"ha";
        //
        Pu_Strategy_Text_.insert(
        	std::pair<hahaha::hahaha_processing_unit_strategy_text*, std::unique_ptr<hahaha::hahaha_processing_unit_strategy_text>>(
            	pust_.get(), std::move(pust_)
            )
        );
    }
    else if(type == ha_def::processing_unit_strategy::IMAGE)
    {
        std::unique_ptr<hahaha::hahaha_processing_unit_strategy_image> pusi_;
        pusi_.reset(new hahaha::hahaha_processing_unit_strategy_image);
        // 這要在前
        processing_unit_strategy = pusi_.get();

        processing_unit_strategy->Type_Factory_Strategy_ = ha_def::factory_processing_unit_strategy::HA;
        processing_unit_strategy->Name_Factory_Strategy_ = L"ha";
        //
        Pu_Strategy_Image_.insert(
        	std::pair<hahaha::hahaha_processing_unit_strategy_image*, std::unique_ptr<hahaha::hahaha_processing_unit_strategy_image>>(
            	pusi_.get(), std::move(pusi_)
            )
        );
    }

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_strategy_ha::Delete(hahaha::hahaha_processing_unit_strategy* processing_unit_strategy)
{
    if(processing_unit_strategy->Type_Strategy_ == ha_def::processing_unit_strategy::TEXT)
    {
        Pu_Strategy_Text_.erase((hahaha::hahaha_processing_unit_strategy_text*)processing_unit_strategy);
    }
    else if(processing_unit_strategy->Type_Strategy_ == ha_def::processing_unit_strategy::IMAGE)
    {
        Pu_Strategy_Image_.erase((hahaha::hahaha_processing_unit_strategy_image*)processing_unit_strategy);
    }

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------