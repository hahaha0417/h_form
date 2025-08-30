//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_optionH
#define hahaha_parameter_deal_optionH
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
namespace hahaha
{
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
}
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
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
// link問題，在exe實作，避免dll link爆掉
class hahaha_parameter_deal_option : public hahahalib::hahaha_parameter_deal_xml_mapping
{
public:
	hahaha_parameter_deal_option();
	~hahaha_parameter_deal_option();

	hahaha_parameter_deal_option(const hahaha_parameter_deal_option& hpdo);
    hahaha_parameter_deal_option(hahaha_parameter_deal_option&& hpdo) noexcept;
	hahaha_parameter_deal_option operator=(const hahaha_parameter_deal_option& hpdo);
    hahaha_parameter_deal_option operator=(hahaha_parameter_deal_option&& hpdo) noexcept;
	void Copy(const hahaha_parameter_deal_option& hpdo);
    void Move(hahaha_parameter_deal_option&& hpdo) noexcept;
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
