//---------------------------------------------------------------------------

#pragma hdrstop




#include "hahaha_factory_processing_unit_base_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base_ha::hahaha_factory_processing_unit_base_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base_ha::~hahaha_factory_processing_unit_base_ha()
{

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base_ha::hahaha_factory_processing_unit_base_ha(const hahaha_factory_processing_unit_base_ha& hfpubh)
{
    Reset();
    hahaha_factory_processing_unit_base::Copy(hfpubh);
	Copy(hfpubh);
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base_ha::hahaha_factory_processing_unit_base_ha(hahaha_factory_processing_unit_base_ha&& hfpubh) noexcept
{
    hahaha_factory_processing_unit_base::Move(std::move(hfpubh));
    Move(std::move(hfpubh));
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base_ha& hahaha_factory_processing_unit_base_ha::operator=(const hahaha_factory_processing_unit_base_ha& hfpubh)
{
    hahaha_factory_processing_unit_base::Copy(std::move(hfpubh));
	Copy(hfpubh);

	return *this;
}
//---------------------------------------------------------------------------
 hahaha_factory_processing_unit_base_ha& hahaha_factory_processing_unit_base_ha::operator=(hahaha_factory_processing_unit_base_ha&& hfpubh) noexcept
 {
     hahaha_factory_processing_unit_base::Move(std::move(hfpubh));
     Move(std::move(hfpubh));

     return *this;
 }
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_base_ha::Copy(const hahaha_factory_processing_unit_base_ha& hfpubh)
{

}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_base_ha::Move(hahaha_factory_processing_unit_base_ha&& hfpubh) noexcept
{
//    Pu_Base_Base_ = std::move(hfpubh.Pu_Base_Base_);
}
//---------------------------------------------------------------------------
int hahaha_factory_processing_unit_base_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_base_ha::Add(ha_def::processing_unit_base type, hahaha::hahaha_processing_unit_base*& processing_unit_base)
{
//    if(type == ha_def::processing_unit_base::BASE)
//    {
//        std::unique_ptr<hahaha::hahaha_processing_unit_base_base> pubb_;
//        pubb_.reset(new hahaha::hahaha_processing_unit_base_base);
//
//        // 這要在前
//        processing_unit_base = pubb_.get();
//
//        processing_unit_base->Type_Factory_Base_ = ha_def::factory_processing_unit_base::HA;
//        processing_unit_base->Name_Factory_Base_ = L"ha";
//        //
//        Pu_Base_Base_.insert(
//        	std::pair<hahaha::hahaha_processing_unit_base_base*, std::unique_ptr<hahaha::hahaha_processing_unit_base_base>>(
//            	pubb_.get(), std::move(pubb_)
//            )
//        );
//
//    }

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_base_ha::Delete(hahaha::hahaha_processing_unit_base* processing_unit_base)
{
//    if(processing_unit_base->Type_Base_ == ha_def::processing_unit_base::BASE)
//    {
//        Pu_Base_Base_.erase((hahaha::hahaha_processing_unit_base_base*)processing_unit_base);
//    }


    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------