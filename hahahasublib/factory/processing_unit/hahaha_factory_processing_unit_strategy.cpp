//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_factory_processing_unit_strategy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy::hahaha_factory_processing_unit_strategy()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy::~hahaha_factory_processing_unit_strategy()
{

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy::hahaha_factory_processing_unit_strategy(const hahaha_factory_processing_unit_strategy& hfpus)
{
    Reset();
	Copy(hfpus);
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy::hahaha_factory_processing_unit_strategy(hahaha_factory_processing_unit_strategy&& hfpus) noexcept
{
    Move(std::move(hfpus));

}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy& hahaha_factory_processing_unit_strategy::operator=(const hahaha_factory_processing_unit_strategy& hfpus)
{
	Copy(hfpus);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_factory_processing_unit_strategy& hahaha_factory_processing_unit_strategy::operator=(hahaha_factory_processing_unit_strategy&& hfpus) noexcept
{
	if (this != &hfpus)
    {
        Move(std::move(hfpus));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_strategy::Copy(const hahaha_factory_processing_unit_strategy& hfpus)
{
    Name_ = hfpus.Name_;
}
//---------------------------------------------------------------------------
void hahaha_factory_processing_unit_strategy::Move(hahaha_factory_processing_unit_strategy&& hfpus) noexcept
{
    Name_ = hfpus.Name_;

    hfpus.Reset();
}
//---------------------------------------------------------------------------
int hahaha_factory_processing_unit_strategy::Reset()
{
    Name_ = L"";

	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_strategy::Add(ha_def::processing_unit_strategy type, hahaha::hahaha_processing_unit_strategy*& processing_unit_strategy)
{


    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_factory_processing_unit_strategy::Delete(hahaha::hahaha_processing_unit_strategy* processing_unit_strategy)
{

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------