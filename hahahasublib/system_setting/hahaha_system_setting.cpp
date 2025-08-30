//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <parameter_deal_system_setting\hahaha_parameter_deal_system_setting.h>
#include <parameter_deal_option\hahaha_parameter_deal_option.h>
#include <parameter_deal_setting\hahaha_parameter_deal_setting.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_system_setting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_system_setting::hahaha_system_setting()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_system_setting::~hahaha_system_setting()
{

}
//---------------------------------------------------------------------------
hahaha_system_setting::hahaha_system_setting(const hahaha_system_setting& hss)
{
    Reset();
	Copy(hss);
}
//---------------------------------------------------------------------------
hahaha_system_setting::hahaha_system_setting(hahaha_system_setting&& hss) noexcept
{
    Move(std::move(hss));

}
//---------------------------------------------------------------------------
hahaha_system_setting& hahaha_system_setting::operator=(const hahaha_system_setting& hss)
{
	Copy(hss);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_system_setting& hahaha_system_setting::operator=(hahaha_system_setting&& hss) noexcept
{
	if (this != &hss)
    {
        Move(std::move(hss));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_system_setting::Copy(const hahaha_system_setting& hss)
{
    File_Name_ = hss.File_Name_;

    Folder_Plugin_ = hss.Folder_Plugin_;

	//---------------------------------------------------------------------------
    Structure_Main_ = hss.Structure_Main_;
    Structure_Sub_ = hss.Structure_Sub_;
    Pointer_Main_ = hss.Pointer_Main_;
    Pointer_Sub_ = hss.Pointer_Sub_;


}
//---------------------------------------------------------------------------
void hahaha_system_setting::Move(hahaha_system_setting&& hss) noexcept
{
    File_Name_ = hss.File_Name_;

    Folder_Plugin_ = hss.Folder_Plugin_;

	//---------------------------------------------------------------------------
    Structure_Main_ = hss.Structure_Main_;
    Structure_Sub_ = hss.Structure_Sub_;
    Pointer_Main_ = hss.Pointer_Main_;
    Pointer_Sub_ = hss.Pointer_Sub_;

    hss.Reset();

}
//---------------------------------------------------------------------------
int hahaha_system_setting::Reset()
{
    File_Name_ = L"";

    Folder_Plugin_ = L"";

	//---------------------------------------------------------------------------
    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_system_setting::Load(
    const std::wstring& dir_name
)
{
    halib_def::result result_ = halib_def::result::SUCCESS;

    return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_system_setting::Save(
    const std::wstring& dir_name
)
{
    halib_def::result result_ = halib_def::result::SUCCESS;

    return result_;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_system_setting::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_system_setting::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_system_setting::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_system_setting::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------