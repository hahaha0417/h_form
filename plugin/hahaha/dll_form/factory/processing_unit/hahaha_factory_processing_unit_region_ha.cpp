//---------------------------------------------------------------------------

#pragma hdrstop


#include "hahaha_factory_processing_unit_region_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region_ha::hahaha_factory_processing_unit_region_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region_ha::~hahaha_factory_processing_unit_region_ha()
{

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region_ha::hahaha_factory_processing_unit_region_ha(const hahaha_factory_processing_unit_region_ha& hfpurh)
{
    Reset();
	Copy(hfpurh);
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region_ha::hahaha_factory_processing_unit_region_ha(hahaha_factory_processing_unit_region_ha&& hfpurh) noexcept
{
    hahaha_factory_processing_unit_region_ha::Move(std::move(hfpurh));
    Move(std::move(hfpurh));
}

//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region_ha& hahaha_factory_processing_unit_region_ha::operator=(const hahaha_factory_processing_unit_region_ha& hfpurh)
{
    hahaha_factory_processing_unit_region_ha::Copy(hfpurh);
	Copy(hfpurh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region_ha& hahaha_factory_processing_unit_region_ha::operator=(hahaha_factory_processing_unit_region_ha&& hfpurh) noexcept
{
    hahaha_factory_processing_unit_region_ha::Move(std::move(hfpurh));
    Move(std::move(hfpurh));

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_region_ha::Copy(const hahaha_factory_processing_unit_region_ha& hfpurh)
{

}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_region_ha::Move(const hahaha_factory_processing_unit_region_ha&& hfpurh) noexcept
{
//    Pu_Region_Rectangle_ = std::move(Pu_Region_Rectangle_);
}
//---------------------------------------------------------------------------
int hahaha_factory_processing_unit_region_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_region_ha::Add(ha_def::processing_unit_region type, hahaha::hahaha_processing_unit_region*& processing_unit_region)
{
//    if(type == ha_def::processing_unit_region::RECTANGLE)
//    {
//        std::unique_ptr<hahaha::hahaha_processing_unit_region_rectangle> purr_;
//        purr_.reset(new hahaha::hahaha_processing_unit_region_rectangle);
//        // 這要在前
//        processing_unit_region = purr_.get();
//
//        processing_unit_region->Type_Factory_Region_ = ha_def::factory_processing_unit_region::HA;
//        processing_unit_region->Name_Factory_Region_ = L"ha";
//
//        //
//        Pu_Region_Rectangle_.insert(
//        	std::pair<hahaha::hahaha_processing_unit_region_rectangle*, std::unique_ptr<hahaha::hahaha_processing_unit_region_rectangle>>(
//            	purr_.get(), std::move(purr_)
//            )
//        );
//    }

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_region_ha::Delete(hahaha::hahaha_processing_unit_region* processing_unit_region)
{
//    if(processing_unit_region->Type_Region_ == ha_def::processing_unit_region::RECTANGLE)
//    {
//        Pu_Region_Rectangle_.erase((hahaha::hahaha_processing_unit_region_rectangle*)processing_unit_region);
//    }


    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------