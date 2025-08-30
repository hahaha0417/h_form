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
#include "hahaha_command_main_ha.h"
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
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_command_main_ha::hahaha_command_main_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_command_main_ha::~hahaha_command_main_ha()
{

}
//---------------------------------------------------------------------------
hahaha_command_main_ha::hahaha_command_main_ha(const hahaha_command_main_ha& hcmh)
{
    Reset();
    hahaha_command_main::Copy(hcmh);
	Copy(hcmh);
}
//---------------------------------------------------------------------------
hahaha_command_main_ha::hahaha_command_main_ha(hahaha_command_main_ha&& hcmh) noexcept
{
    hahaha_command_main::Move(std::move(hcmh));
    Move(std::move(hcmh));
}
//---------------------------------------------------------------------------
hahaha_command_main_ha& hahaha_command_main_ha::operator=(const hahaha_command_main_ha& hcmh)
{
    hahaha_command_main::Copy(hcmh);
	Copy(hcmh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_command_main_ha& hahaha_command_main_ha::operator=(hahaha_command_main_ha&& hcmh) noexcept
{
	if (this != &hcmh)
    {
        hahaha_command_main::Move(std::move(hcmh));
        Move(std::move(hcmh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_command_main_ha::Copy(const hahaha_command_main_ha& hcmh)
{

}
//---------------------------------------------------------------------------
void hahaha_command_main_ha::Move(hahaha_command_main_ha&& hcmh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_command_main_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main_ha::Initial_Environment()
{
    for (const auto& item: ha::Structure_Main_->Dlls_)
    {
        hahaha::hahaha_post_package input_{
            L"",
            L"",
            NULL,
            {
                ha::Structure_Main_,
                ha::Structure_Sub_,
                ha::Pointer_Main_,
                ha::Pointer_Sub_,
              
            },
            {L"initial_environment"},
            {},
            {}
        };
        hahaha::hahaha_post_package output_{};
        hahaha::hahaha_post_package setting_{};
        item.second->Hahaha_Post_(input_,
            output_,
            setting_
        );

    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main_ha::Initial()
{
    for (const auto& item: ha::Structure_Main_->Dlls_)
    {
        hahaha::hahaha_post_package input_{
            L"",
            L"",
            NULL,
            {},
            {L"initial"},
            {},
            {}
        };
        hahaha::hahaha_post_package output_{};
        hahaha::hahaha_post_package setting_{};
        item.second->Hahaha_Post_(input_,
            output_,
            setting_
        );

    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main_ha::Close()
{
    for (const auto& item: ha::Structure_Main_->Dlls_)
    {
        hahaha::hahaha_post_package input_{
            L"",
            L"",
            NULL,
            {},
            {L"close"},
            {},
            {}
        };
        hahaha::hahaha_post_package output_{};
        hahaha::hahaha_post_package setting_{};
        item.second->Hahaha_Post_(input_,
            output_,
            setting_
        );

    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_command_main_ha::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_command_main_ha::Set_Pointer(
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