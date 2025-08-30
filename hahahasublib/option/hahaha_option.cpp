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
#include "hahaha_option.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_option::hahaha_option()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_option::~hahaha_option()
{

}
//---------------------------------------------------------------------------
hahaha_option::hahaha_option(const hahaha_option& ho)
{
    Reset();
	Copy(ho);
}
//---------------------------------------------------------------------------
hahaha_option::hahaha_option(hahaha_option&& ho) noexcept
{
    Move(std::move(ho));

}
//---------------------------------------------------------------------------
hahaha_option& hahaha_option::operator=(const hahaha_option& ho)
{
	Copy(ho);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_option& hahaha_option::operator=(hahaha_option&& ho) noexcept
{
	if (this != &ho)
    {
        Move(std::move(ho));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_option::Copy(const hahaha_option& ho)
{
    File_Name_ = ho.File_Name_;
    File_Name_Setting_ = ho.File_Name_Setting_;

    Structure_Main_ = ho.Structure_Main_;
    Structure_Sub_ = ho.Structure_Sub_;
    Pointer_Main_ = ho.Pointer_Main_;
    Pointer_Sub_ = ho.Pointer_Sub_;

}
//---------------------------------------------------------------------------
void hahaha_option::Move(hahaha_option&& ho) noexcept
{
    File_Name_ = ho.File_Name_;
    File_Name_Setting_ = ho.File_Name_Setting_;

    Structure_Main_ = ho.Structure_Main_;
    Structure_Sub_ = ho.Structure_Sub_;
    Pointer_Main_ = ho.Pointer_Main_;
    Pointer_Sub_ = ho.Pointer_Sub_;

    ho.Reset();

}
//---------------------------------------------------------------------------
int hahaha_option::Reset()
{
    File_Name_ = L"";
    File_Name_Setting_ = L"";

    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option::Load(
    const std::wstring& dir_name
)
{
    halib_def::result result_ = halib_def::result::SUCCESS;

    return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option::Save(
    const std::wstring& dir_name
)
{
    halib_def::result result_ = halib_def::result::SUCCESS;

    return result_;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_option::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_option::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_option::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------