//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_option.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_option::hahaha_parameter_deal_option()
{
    hahahalib::hahaha_parameter_deal_xml_mapping::Reset();
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option::~hahaha_parameter_deal_option()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option::hahaha_parameter_deal_option(const hahaha_parameter_deal_option& hpdo)
{
    Reset();
    hahahalib::hahaha_parameter_deal_xml_mapping::Copy(hpdo);
	Copy(hpdo);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option::hahaha_parameter_deal_option(hahaha_parameter_deal_option&& hpdo) noexcept
{
	hahahalib::hahaha_parameter_deal_xml_mapping::Move(std::move(hpdo));
    Move(std::move(hpdo));
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option hahaha_parameter_deal_option::operator=(const hahaha_parameter_deal_option& hpdo)
{
    hahahalib::hahaha_parameter_deal_xml_mapping::Copy(hpdo);
	Copy(hpdo);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option hahaha_parameter_deal_option::operator=(hahaha_parameter_deal_option&& hpdo) noexcept
{
	if (this != &hpdo)
    {
        hahahalib::hahaha_parameter_deal_xml_mapping::Move(std::move(hpdo));
        Move(std::move(hpdo));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_option::Copy(const hahaha_parameter_deal_option& hpdo)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_option::Move(hahaha_parameter_deal_option&& hpdo) noexcept
{
    Structure_Main_ = hpdo.Structure_Main_;
    Structure_Sub_ = hpdo.Structure_Sub_;
    Pointer_Main_ = hpdo.Pointer_Main_;
    Pointer_Sub_ = hpdo.Pointer_Sub_;

}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_option::Reset()
{
    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_option::Prepare(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{



	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_option::Mapping(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
	hahahalib::hahaha_parameter_deal_xml_node& root
)
{


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_parameter_deal_option::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_parameter_deal_option::Set_Pointer(
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