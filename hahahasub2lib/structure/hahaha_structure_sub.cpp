//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_structure_sub.h"
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_structure_sub::hahaha_structure_sub()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_structure_sub::~hahaha_structure_sub()
{

}
//---------------------------------------------------------------------------
hahaha_structure_sub::hahaha_structure_sub(const hahaha_structure_sub& hss)
{
    Reset();
	Copy(hss);
}
//---------------------------------------------------------------------------
hahaha_structure_sub::hahaha_structure_sub(hahaha_structure_sub&& hss) noexcept
{
    Move(std::move(hss));

}
//---------------------------------------------------------------------------
hahaha_structure_sub& hahaha_structure_sub::operator=(const hahaha_structure_sub& hss)
{
	Copy(hss);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_structure_sub& hahaha_structure_sub::operator=(hahaha_structure_sub&& hss) noexcept
{
	if (this != &hss)
    {
        Move(std::move(hss));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_structure_sub::Copy(const hahaha_structure_sub& hss)
{

}
//---------------------------------------------------------------------------
void hahaha_structure_sub::Move(hahaha_structure_sub&& hss) noexcept
{
    Structure_Main_ = hss.Structure_Main_;
    Structure_Sub_ = hss.Structure_Sub_;
    Pointer_Main_ = hss.Pointer_Main_;
    Pointer_Sub_ = hss.Pointer_Sub_;
}
//---------------------------------------------------------------------------
int hahaha_structure_sub::Reset()
{


	//---------------------------------------------------------------------------




	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------


	return 0;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_structure_sub::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_structure_sub::Set_Pointer(
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