//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <parameter_deal_system_setting\hahaha_parameter_deal_system_setting_ha.h>
#include <parameter_deal_option\hahaha_parameter_deal_option_ha.h>
#include <parameter_deal_setting\hahaha_parameter_deal_setting_ha.h>
//---------------------------------------------------------------------------
#include <filesystem>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_ha.h>
#include <view\hahaha_view_scene.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_setting_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_setting_ha::hahaha_setting_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_setting_ha::~hahaha_setting_ha()
{

}
//---------------------------------------------------------------------------
hahaha_setting_ha::hahaha_setting_ha(const hahaha_setting_ha& hsh)
{
    Reset();
	Copy(hsh);
}
//---------------------------------------------------------------------------
hahaha_setting_ha::hahaha_setting_ha(hahaha_setting_ha&& hsh) noexcept
{
    hahaha_setting::Move(std::move(hsh));
    Move(std::move(hsh));
}
//---------------------------------------------------------------------------
hahaha_setting_ha& hahaha_setting_ha::operator=(const hahaha_setting_ha& hsh)
{
	Copy(hsh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_setting_ha& hahaha_setting_ha::operator=(hahaha_setting_ha&& hsh) noexcept
{
	if (this != &hsh)
    {
        hahaha_setting::Move(std::move(hsh));
        Move(std::move(hsh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_setting_ha::Copy(const hahaha_setting_ha& hsh)
{
    File_Name_ = hsh.File_Name_;
}
//---------------------------------------------------------------------------
void hahaha_setting_ha::Move(hahaha_setting_ha&& hsh) noexcept
{


}
//---------------------------------------------------------------------------
int hahaha_setting_ha::Reset()
{
    File_Name_ = L"setting.xml";



	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_setting_ha::Load(
    const std::wstring& dir_name
)
{
	halib_def::result result_ = halib_def::result::SUCCESS;

    std::wstring file_name_ = dir_name + File_Name_;

    hahaha::hahaha_parameter_deal_setting_ha pd_;

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
halib_def::result hahaha_setting_ha::Save(
    const std::wstring& dir_name
)
{
	halib_def::result result_ = halib_def::result::SUCCESS;

    if(!std::filesystem::is_directory(dir_name.c_str()))
    {
        std::filesystem::create_directories(dir_name.c_str());
    }

    std::wstring file_name_ = dir_name + File_Name_;

    hahaha::hahaha_parameter_deal_setting_ha pd_;

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
halib_def::result hahaha_setting_ha::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_setting_ha::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    int n = Scenes_.size();

    for(int i = 0; i < n; i++)
    {
        result = Scenes_[i]->Load_Initial();
    }


    return result;
}
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------