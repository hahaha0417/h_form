//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting_ha.h>
#include <option\hahaha_option_ha.h>
#include <setting\hahaha_setting_ha.h>
//
#include <command\hahaha_command_main_ha.h>
#include <command\hahaha_command_sub_ha.h>
//---------------------------------------------------------------------------
#include <dll\hahaha_load_dll.h>
#include <post\hahaha_post_package.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_ha.h>
//---------------------------------------------------------------------------
#include "hahaha_command_sub_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_command_sub_ha::hahaha_command_sub_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_command_sub_ha::~hahaha_command_sub_ha()
{

}
//---------------------------------------------------------------------------
hahaha_command_sub_ha::hahaha_command_sub_ha(const hahaha_command_sub_ha& hcsh)
{
    Reset();
    hahaha_command_sub::Copy(hcsh);
	Copy(hcsh);
}
//---------------------------------------------------------------------------
hahaha_command_sub_ha::hahaha_command_sub_ha(hahaha_command_sub_ha&& hcsh) noexcept
{
    hahaha_command_sub::Move(std::move(hcsh));
    Move(std::move(hcsh));

}
//---------------------------------------------------------------------------
hahaha_command_sub_ha& hahaha_command_sub_ha::operator=(const hahaha_command_sub_ha& hcsh)
{
    hahaha_command_sub::Copy(hcsh);
	Copy(hcsh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_command_sub_ha& hahaha_command_sub_ha::operator=(hahaha_command_sub_ha&& hcsh) noexcept
{
	if (this != &hcsh)
    {
        hahaha_command_sub::Move(std::move(hcsh));
        Move(std::move(hcsh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_command_sub_ha::Copy(const hahaha_command_sub_ha& hcsh)
{

}
//---------------------------------------------------------------------------
void hahaha_command_sub_ha::Move(hahaha_command_sub_ha&& hcsh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_command_sub_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_sub_ha::Initial_Environment()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_sub_ha::Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_sub_ha::Close()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_sub_ha::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_command_sub_ha::Set_Pointer(
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