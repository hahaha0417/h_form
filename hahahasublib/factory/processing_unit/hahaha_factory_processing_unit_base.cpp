//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_factory_processing_unit_base.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base::hahaha_factory_processing_unit_base()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base::~hahaha_factory_processing_unit_base()
{

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base::hahaha_factory_processing_unit_base(const hahaha_factory_processing_unit_base& hfpub)
{
    Reset();
	Copy(hfpub);
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base::hahaha_factory_processing_unit_base(hahaha_factory_processing_unit_base&& hfpub) noexcept
{
    Move(std::move(hfpub));

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base& hahaha_factory_processing_unit_base::operator=(const hahaha_factory_processing_unit_base& hfpub)
{
	Copy(hfpub);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_base& hahaha_factory_processing_unit_base::operator=(hahaha_factory_processing_unit_base&& hfpub) noexcept
{
	if (this != &hfpub)
    {
        Move(std::move(hfpub));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_base::Copy(const hahaha_factory_processing_unit_base& hfpub)
{
    Name_ = hfpub.Name_;
}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_base::Move(hahaha_factory_processing_unit_base&& hfpub) noexcept
{
    Name_ = hfpub.Name_;

    hfpub.Reset();

}
//---------------------------------------------------------------------------
int hahaha_factory_processing_unit_base::Reset()
{
    Name_ = L"";

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_base::Add(ha_def::processing_unit_base type, hahaha::hahaha_processing_unit_base*& processing_unit_base)
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_base::Delete(hahaha::hahaha_processing_unit_base* processing_unit_base)
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------