//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_command_sub.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_command_sub::hahaha_command_sub()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_command_sub::~hahaha_command_sub()
{

}
//---------------------------------------------------------------------------
hahaha_command_sub::hahaha_command_sub(const hahaha_command_sub& hcs)
{
    Reset();
	Copy(hcs);
}
//---------------------------------------------------------------------------
hahaha_command_sub::hahaha_command_sub(hahaha_command_sub&& hcs) noexcept
{
    Reset();
	Copy(hcs);
}
//---------------------------------------------------------------------------
hahaha_command_sub& hahaha_command_sub::operator=(const hahaha_command_sub& hcs)
{
	Copy(hcs);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_command_sub& hahaha_command_sub::operator=(hahaha_command_sub&& hcs) noexcept
{
	Copy(hcs);

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_command_sub::Copy(const hahaha_command_sub& hcs)
{
    Structure_Main_ = hcs.Structure_Main_;
    Structure_Sub_ = hcs.Structure_Sub_;
    Pointer_Main_ = hcs.Pointer_Main_;
    Pointer_Sub_ = hcs.Pointer_Sub_;

}
//---------------------------------------------------------------------------
void hahaha_command_sub::Move(hahaha_command_sub&& hcs) noexcept
{
    Structure_Main_ = hcs.Structure_Main_;
    Structure_Sub_ = hcs.Structure_Sub_;
    Pointer_Main_ = hcs.Pointer_Main_;
    Pointer_Sub_ = hcs.Pointer_Sub_;

    hcs.Reset();

}
//---------------------------------------------------------------------------
int hahaha_command_sub::Reset()
{


	return 0;
}

//---------------------------------------------------------------------------
halib_def::result hahaha_command_sub::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_command_sub::Set_Pointer(
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------