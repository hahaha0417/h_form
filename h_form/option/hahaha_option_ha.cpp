//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <parameter_deal_system_setting\hahaha_parameter_deal_system_setting_ha.h>
#include <parameter_deal_option\hahaha_parameter_deal_option_ha.h>
#include <parameter_deal_setting\hahaha_parameter_deal_setting_ha.h>
//---------------------------------------------------------------------------
#include <filesystem>
#include <utility>
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_option_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_option_ha::hahaha_option_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_option_ha::~hahaha_option_ha()
{

}
//---------------------------------------------------------------------------
hahaha_option_ha::hahaha_option_ha(const hahaha_option_ha& hoh)
{
    Reset();
    hahaha_option::Copy(hoh);
	Copy(hoh);
}
//---------------------------------------------------------------------------
hahaha_option_ha::hahaha_option_ha(hahaha_option_ha&& hoh) noexcept
{
    hahaha_option::Move(std::move(hoh));
    Move(std::move(hoh));
}
//---------------------------------------------------------------------------
hahaha_option_ha& hahaha_option_ha::operator=(const hahaha_option_ha& hoh)
{
    hahaha_option::Copy(hoh);
	Copy(hoh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_option_ha& hahaha_option_ha::operator=(hahaha_option_ha&& hoh) noexcept
{
	if (this != &hoh)
    {
        hahaha_option::Move(std::move(hoh));
        Move(std::move(hoh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_option_ha::Copy(const hahaha_option_ha& hoh)
{

}
//---------------------------------------------------------------------------
void hahaha_option_ha::Move(hahaha_option_ha&& hoh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_option_ha::Reset()
{
    File_Name_ = L"option.xml";

    File_Name_Setting_ = L"default";

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option_ha::Load(
    const std::wstring& dir_name
)
{
	halib_def::result result_ = halib_def::result::SUCCESS;

    std::wstring file_name_ = dir_name + File_Name_;

    hahaha::hahaha_parameter_deal_option_ha pd_;

    pd_.Set_Structure(
        ha::Structure_Main_,
        ha::Structure_Sub_
    );

    pd_.Set_Pointer(
        ha::Pointer_Main_,
        ha::Pointer_Sub_
    );

    result_ = pd_.Load(file_name_);

    return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option_ha::Save(
    const std::wstring& dir_name
)
{


	halib_def::result result_ = halib_def::result::SUCCESS;

    if(!std::filesystem::is_directory(dir_name.c_str()))
    {
        std::filesystem::create_directories(dir_name.c_str());
    }

    std::wstring file_name_ = dir_name + File_Name_;

    hahaha::hahaha_parameter_deal_option_ha pd_;

    pd_.Set_Structure(
        ha::Structure_Main_,
        ha::Structure_Sub_
    );

    pd_.Set_Pointer(
        ha::Pointer_Main_,
        ha::Pointer_Sub_
    );

    result_ = pd_.Save(file_name_);

    return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option_ha::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option_ha::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------