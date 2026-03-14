//---------------------------------------------------------------------------

#pragma hdrstop

#include <processing_unit\strategy\hahaha_processing_unit_strategy_webcam.h>

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
    Pu_Strategy_Webcam_ = std::move(hfpush.Pu_Strategy_Webcam_);
}
//---------------------------------------------------------------------------
int hahaha_factory_processing_unit_strategy_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_strategy_ha::Add(ha_def::processing_unit_strategy type, hahaha::hahaha_processing_unit_strategy*& processing_unit_strategy)
{
    if(type == ha_def::processing_unit_strategy::PLUGIN_HAHAHA_WEBCAM)
    {
        std::unique_ptr<hahaha::hahaha_processing_unit_strategy_webcam> pusm_;
        pusm_.reset(new hahaha::hahaha_processing_unit_strategy_webcam);
        // 這要在前
        processing_unit_strategy = pusm_.get();

        processing_unit_strategy->Type_Factory_Strategy_ = ha_def::factory_processing_unit_strategy::PLUGIN_HAHAHA_WEBCAM;
        processing_unit_strategy->Name_Factory_Strategy_ = L"plugin_hahaha_webcam";
        //
        Pu_Strategy_Webcam_.insert(
        	std::pair<hahaha::hahaha_processing_unit_strategy_webcam*, std::unique_ptr<hahaha::hahaha_processing_unit_strategy_webcam>>(
            	pusm_.get(), std::move(pusm_)
            )
        );
    }


    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_strategy_ha::Delete(hahaha::hahaha_processing_unit_strategy* processing_unit_strategy)
{
    if(processing_unit_strategy->Type_Strategy_ == ha_def::processing_unit_strategy::PLUGIN_HAHAHA_WEBCAM)
    {
        Pu_Strategy_Webcam_.erase((hahaha::hahaha_processing_unit_strategy_webcam*)processing_unit_strategy);
    }


    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------