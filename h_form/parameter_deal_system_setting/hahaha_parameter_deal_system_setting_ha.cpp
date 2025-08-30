//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_system_setting_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <define\hahaha_define_ha.h>

//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting_ha::hahaha_parameter_deal_system_setting_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting_ha::~hahaha_parameter_deal_system_setting_ha()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting_ha::hahaha_parameter_deal_system_setting_ha(const hahaha_parameter_deal_system_setting_ha& hpdssh)
{
    Reset();
    hahaha_parameter_deal_system_setting::Copy(hpdssh);
	Copy(hpdssh);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting_ha::hahaha_parameter_deal_system_setting_ha(hahaha_parameter_deal_system_setting_ha&& hpdssh) noexcept
{
    hahaha_parameter_deal_system_setting::Move(std::move(hpdssh));
    Move(std::move(hpdssh));
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting_ha& hahaha_parameter_deal_system_setting_ha::operator=(const hahaha_parameter_deal_system_setting_ha& hpdssh)
{
    hahaha_parameter_deal_system_setting::Copy(hpdssh);
	Copy(hpdssh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_system_setting_ha& hahaha_parameter_deal_system_setting_ha::operator=(hahaha_parameter_deal_system_setting_ha&& hpdssh) noexcept
{
	if (this != &hpdssh)
    {
        hahaha_parameter_deal_system_setting::Move(std::move(hpdssh));
        Move(std::move(hpdssh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_system_setting_ha::Copy(const hahaha_parameter_deal_system_setting_ha& hpdssh)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_system_setting_ha::Move(hahaha_parameter_deal_system_setting_ha&& hpdssh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_system_setting_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_system_setting_ha::Prepare(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{



	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_system_setting_ha::Mapping(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
	hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    root.Name_ = L"H_Form";
	root.Reset();

	std::vector<hahahalib::hahaha_parameter_deal_xml_item> items_ = {
    	{{L"Plug_In"},
			L"", halib_def::xml_type::NODE, halib_def::type_variable::NONE, (void*)NULL},
        {{},
			L"Folder", halib_def::xml_type::VALUE, halib_def::type_variable::WSTRING, &ha::Pointer_Main_->System_Setting_->Folder_Plugin_},



	};

	root.Add(items_);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------