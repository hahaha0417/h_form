//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_system_setting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting::hahaha_parameter_deal_system_setting()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting::~hahaha_parameter_deal_system_setting()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting::hahaha_parameter_deal_system_setting(const hahaha_parameter_deal_system_setting& hpdss)
{
    Reset();
    hahahalib::hahaha_parameter_deal_xml_mapping::Copy(hpdss);
	Copy(hpdss);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting::hahaha_parameter_deal_system_setting(hahaha_parameter_deal_system_setting&& hpdss) noexcept
{
    hahahalib::hahaha_parameter_deal_xml_mapping::Move(std::move(hpdss));
    Move(std::move(hpdss));
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting& hahaha_parameter_deal_system_setting::operator=(const hahaha_parameter_deal_system_setting& hpdss)
{
    hahahalib::hahaha_parameter_deal_xml_mapping::Copy(hpdss);
	Copy(hpdss);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting& hahaha_parameter_deal_system_setting::operator=(hahaha_parameter_deal_system_setting&& hpdss) noexcept
{
	if (this != &hpdss)
    {
        hahahalib::hahaha_parameter_deal_xml_mapping::Move(std::move(hpdss));
        Move(std::move(hpdss));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_system_setting::Copy(const hahaha_parameter_deal_system_setting& hpdss)
{
    Structure_Main_ = hpdss.Structure_Main_;
    Structure_Sub_ = hpdss.Structure_Sub_;
    Pointer_Main_ = hpdss.Pointer_Main_;
    Pointer_Sub_ = hpdss.Pointer_Sub_;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_system_setting::Move(hahaha_parameter_deal_system_setting&& hpdss) noexcept
{
    Structure_Main_ = hpdss.Structure_Main_;
    Structure_Sub_ = hpdss.Structure_Sub_;
    Pointer_Main_ = hpdss.Pointer_Main_;
    Pointer_Sub_ = hpdss.Pointer_Sub_;

    hpdss.Reset();
}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_system_setting::Reset()
{
    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_system_setting::Prepare(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{



	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_system_setting::Mapping(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
	hahahalib::hahaha_parameter_deal_xml_node& root
)
{


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_parameter_deal_system_setting::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_parameter_deal_system_setting::Set_Pointer(
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