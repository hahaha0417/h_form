//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_option_haH
#define hahaha_parameter_deal_option_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <parameter_deal_option\hahaha_parameter_deal_option.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_option_ha : public hahaha_parameter_deal_option
{
public:
	hahaha_parameter_deal_option_ha();
	~hahaha_parameter_deal_option_ha();

	hahaha_parameter_deal_option_ha(const hahaha_parameter_deal_option_ha& hpdoh);
    hahaha_parameter_deal_option_ha(hahaha_parameter_deal_option_ha&& hpdoh) noexcept;
	hahaha_parameter_deal_option_ha operator=(const hahaha_parameter_deal_option_ha& hpdoh);
    hahaha_parameter_deal_option_ha operator=(hahaha_parameter_deal_option_ha&& hpdoh) noexcept;
	void Copy(const hahaha_parameter_deal_option_ha& hpdoh);
    void Move(hahaha_parameter_deal_option_ha&& hpdoh) noexcept;
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
