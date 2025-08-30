//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_pointer_sub.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_pointer_sub::hahaha_pointer_sub()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_pointer_sub::~hahaha_pointer_sub()
{

}
//---------------------------------------------------------------------------
hahaha_pointer_sub::hahaha_pointer_sub(const hahaha_pointer_sub& hps)
{
    Reset();
	Copy(hps);
}
//---------------------------------------------------------------------------
hahaha_pointer_sub::hahaha_pointer_sub(hahaha_pointer_sub&& hps) noexcept
{
    Move(std::move(hps));

}
//---------------------------------------------------------------------------
hahaha_pointer_sub& hahaha_pointer_sub::operator=(const hahaha_pointer_sub& hps)
{
	Copy(hps);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_pointer_sub& hahaha_pointer_sub::operator=(hahaha_pointer_sub&& hps) noexcept
{
	if (this != &hps)
    {
        Move(std::move(hps));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_pointer_sub::Copy(const hahaha_pointer_sub& hps)
{

}
//---------------------------------------------------------------------------
void hahaha_pointer_sub::Move(hahaha_pointer_sub&& hps) noexcept
{
    Structure_Main_ = hps.Structure_Main_;
    Structure_Sub_ = hps.Structure_Sub_;
    Pointer_Main_ = hps.Pointer_Main_;
    Pointer_Sub_ = hps.Pointer_Sub_;
}
//---------------------------------------------------------------------------
int hahaha_pointer_sub::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_pointer_sub::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_pointer_sub::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------