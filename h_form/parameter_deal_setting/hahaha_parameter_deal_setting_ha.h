//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_setting_haH
#define hahaha_parameter_deal_setting_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <parameter_deal_setting\hahaha_parameter_deal_setting.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_setting_ha : public hahaha_parameter_deal_setting
{
public:
	hahaha_parameter_deal_setting_ha();
	~hahaha_parameter_deal_setting_ha();

	hahaha_parameter_deal_setting_ha(const hahaha_parameter_deal_setting_ha& hpdsh);
    hahaha_parameter_deal_setting_ha(hahaha_parameter_deal_setting_ha&& hpdsh) noexcept;
	hahaha_parameter_deal_setting_ha& operator=(const hahaha_parameter_deal_setting_ha& hpdsh);
    hahaha_parameter_deal_setting_ha& operator=(hahaha_parameter_deal_setting_ha&& hpdsh) noexcept;
	void Copy(const hahaha_parameter_deal_setting_ha& hpdsh);
    void Move(hahaha_parameter_deal_setting_ha&& hpdsh) noexcept;
public:
	int Reset();
public:
    virtual halib_def::result Prepare_Node(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
    virtual halib_def::result Prepare_Attribute(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
	virtual halib_def::result Prepare_Value(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
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
