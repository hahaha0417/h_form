//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_system_setting_haH
#define hahaha_parameter_deal_system_setting_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <parameter_deal_system_setting\hahaha_parameter_deal_system_setting.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_system_setting_ha : public hahaha_parameter_deal_system_setting
{
public:
	hahaha_parameter_deal_system_setting_ha();
	~hahaha_parameter_deal_system_setting_ha();

	hahaha_parameter_deal_system_setting_ha(const hahaha_parameter_deal_system_setting_ha& hpdssh);
    hahaha_parameter_deal_system_setting_ha(hahaha_parameter_deal_system_setting_ha&& hpdssh) noexcept;
	hahaha_parameter_deal_system_setting_ha& operator=(const hahaha_parameter_deal_system_setting_ha& hpdssh);
    hahaha_parameter_deal_system_setting_ha& operator=(hahaha_parameter_deal_system_setting_ha&& hpdssh) noexcept;
	void Copy(const hahaha_parameter_deal_system_setting_ha& hpdssh);
    void Move(hahaha_parameter_deal_system_setting_ha&& hpdssh) noexcept;
public:
	int Reset();
public:
	virtual halib_def::result Prepare(
		hahahalib::hahaha_parameter_deal_xml& xml,
        std::vector<std::wstring>& node_names,
		hahahalib::hahaha_parameter_deal_xml_node& root
	);
	virtual halib_def::result Mapping(
		hahahalib::hahaha_parameter_deal_xml& xml,
        std::vector<std::wstring>& node_names,
		hahahalib::hahaha_parameter_deal_xml_node& root
	);
public:

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
