//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_command_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_command_main::hahaha_command_main()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_command_main::~hahaha_command_main()
{

}
//---------------------------------------------------------------------------
hahaha_command_main::hahaha_command_main(const hahaha_command_main& hcm)
{
    Reset();
	Copy(hcm);
}
//---------------------------------------------------------------------------
hahaha_command_main::hahaha_command_main(hahaha_command_main&& hcm) noexcept
{
    Move(std::move(hcm));

}
//---------------------------------------------------------------------------
hahaha_command_main& hahaha_command_main::operator=(const hahaha_command_main& hcm)
{
	Copy(hcm);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_command_main& hahaha_command_main::operator=(hahaha_command_main&& hcm) noexcept
{
	if (this != &hcm)
    {
        Move(std::move(hcm));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_command_main::Copy(const hahaha_command_main& hcm)
{
    Structure_Main_ = hcm.Structure_Main_;
    Structure_Sub_ = hcm.Structure_Sub_;
    Pointer_Main_ = hcm.Pointer_Main_;
    Pointer_Sub_ = hcm.Pointer_Sub_;
}
//---------------------------------------------------------------------------
void hahaha_command_main::Move(hahaha_command_main&& hcm) noexcept
{
    Structure_Main_ = hcm.Structure_Main_;
    Structure_Sub_ = hcm.Structure_Sub_;
    Pointer_Main_ = hcm.Pointer_Main_;
    Pointer_Sub_ = hcm.Pointer_Sub_;

    hcm.Reset();

}
//---------------------------------------------------------------------------
int hahaha_command_main::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main::Initial_Environment()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main::Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main::Close()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_command_main::Set_Pointer(
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