//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
//---------------------------------------------------------------------------
#include <option\hahaha_option.h>
#include <setting\hahaha_setting.h>
//---------------------------------------------------------------------------
#include <define\hahaha_define_ha.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_parameter_deal_option_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_option_ha::hahaha_parameter_deal_option_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option_ha::~hahaha_parameter_deal_option_ha()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option_ha::hahaha_parameter_deal_option_ha(const hahaha_parameter_deal_option_ha& hpdoh)
{
    Reset();
    hahaha_parameter_deal_option::Copy(hpdoh);
	Copy(hpdoh);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option_ha::hahaha_parameter_deal_option_ha(hahaha_parameter_deal_option_ha&& hpdoh) noexcept
{
    hahaha_parameter_deal_option::Move(std::move(hpdoh));
    Move(std::move(hpdoh));

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option_ha hahaha_parameter_deal_option_ha::operator=(const hahaha_parameter_deal_option_ha& hpdoh)
{
    hahaha_parameter_deal_option::Copy(hpdoh);
	Copy(hpdoh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_option_ha hahaha_parameter_deal_option_ha::operator=(hahaha_parameter_deal_option_ha&& hpdoh) noexcept
{
	if (this != &hpdoh)
    {
        hahaha_parameter_deal_option::Move(std::move(hpdoh));
        Move(std::move(hpdoh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_option_ha::Copy(const hahaha_parameter_deal_option_ha& hpdoh)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_option_ha::Move(hahaha_parameter_deal_option_ha&& hpdoh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_option_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_option_ha::Prepare(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{



	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_option_ha::Mapping(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
	hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    root.Name_ = L"H_Form";
	root.Reset();

	std::vector<hahahalib::hahaha_parameter_deal_xml_item> items_ = {
		{{L"Setting"},
			L"", halib_def::xml_type::NODE, halib_def::type_variable::NONE, (void*)NULL},
        {{},
			L"File_Name_Setting", halib_def::xml_type::VALUE, halib_def::type_variable::WSTRING, &ha::Pointer_Main_->Option_->File_Name_Setting_},


	};

	root.Add(items_);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------