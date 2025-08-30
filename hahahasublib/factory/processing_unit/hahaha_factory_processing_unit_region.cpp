//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_factory_processing_unit_region.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region::hahaha_factory_processing_unit_region()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region::~hahaha_factory_processing_unit_region()
{

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region::hahaha_factory_processing_unit_region(const hahaha_factory_processing_unit_region& hfpur)
{
    Reset();
	Copy(hfpur);
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region::hahaha_factory_processing_unit_region(hahaha_factory_processing_unit_region&& hfpur) noexcept
{
    Move(std::move(hfpur));

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region& hahaha_factory_processing_unit_region::operator=(const hahaha_factory_processing_unit_region& hfpur)
{
	Copy(hfpur);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_region& hahaha_factory_processing_unit_region::operator=(hahaha_factory_processing_unit_region&& hfpur) noexcept
{
	if (this != &hfpur)
    {
        Move(std::move(hfpur));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_region::Copy(const hahaha_factory_processing_unit_region& hfpur)
{
    Name_ = hfpur.Name_;

}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_region::Move(hahaha_factory_processing_unit_region&& hfpur) noexcept
{
    Name_ = hfpur.Name_;

    hfpur.Reset();

}
//---------------------------------------------------------------------------
int hahaha_factory_processing_unit_region::Reset()
{
    Name_ = L"";

	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_region::Add(ha_def::processing_unit_region type, hahaha::hahaha_processing_unit_region*& processing_unit_region)
{


    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_region::Delete(hahaha::hahaha_processing_unit_region* processing_unit_region)
{



    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------