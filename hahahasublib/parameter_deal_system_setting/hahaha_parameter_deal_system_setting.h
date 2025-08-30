//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_system_settingH
#define hahaha_parameter_deal_system_settingH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_mapping.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml;
class hahaha_parameter_deal_xml_node;
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
// link問題，在exe實作，避免dll link爆掉
class hahaha_parameter_deal_system_setting : public hahahalib::hahaha_parameter_deal_xml_mapping
{
public:
	hahaha_parameter_deal_system_setting();
	~hahaha_parameter_deal_system_setting();

	hahaha_parameter_deal_system_setting(const hahaha_parameter_deal_system_setting& hpdss);
    hahaha_parameter_deal_system_setting(hahaha_parameter_deal_system_setting&& hpdss) noexcept;
	hahaha_parameter_deal_system_setting& operator=(const hahaha_parameter_deal_system_setting& hpdss);
    hahaha_parameter_deal_system_setting& operator=(hahaha_parameter_deal_system_setting&& hpdss) noexcept;
	void Copy(const hahaha_parameter_deal_system_setting& hpdss);
    void Move(hahaha_parameter_deal_system_setting&& hpdss) noexcept;
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
public:
	//---------------------------------------------------------------------------
	virtual halib_def::result Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    virtual halib_def::result Set_Pointer(
        hahaha::hahaha_pointer_main* pointer_main,
    	hahaha::hahaha_pointer_sub* pointer_sub
    );
	//---------------------------------------------------------------------------
    hahaha::hahaha_structure_main* Structure_Main_;
    hahaha::hahaha_structure_sub* Structure_Sub_;
    hahaha::hahaha_pointer_main* Pointer_Main_;
    hahaha::hahaha_pointer_sub* Pointer_Sub_;
	//---------------------------------------------------------------------------
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
