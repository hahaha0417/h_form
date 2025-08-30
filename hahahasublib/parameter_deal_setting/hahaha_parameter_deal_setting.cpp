//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_setting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_setting::hahaha_parameter_deal_setting()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting::~hahaha_parameter_deal_setting()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting::hahaha_parameter_deal_setting(const hahaha_parameter_deal_setting& hpds)
{
    Reset();
    hahahalib::hahaha_parameter_deal_xml_mapping::Copy(hpds);
	Copy(hpds);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting::hahaha_parameter_deal_setting(hahaha_parameter_deal_setting&& hpds) noexcept
{
    hahahalib::hahaha_parameter_deal_xml_mapping::Move(std::move(hpds));
    Move(std::move(hpds));
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting hahaha_parameter_deal_setting::operator=(const hahaha_parameter_deal_setting& hpds)
{
    hahahalib::hahaha_parameter_deal_xml_mapping::Copy(hpds);
	Copy(hpds);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting hahaha_parameter_deal_setting::operator=(hahaha_parameter_deal_setting&& hpds) noexcept
{
	if (this != &hpds)
    {
        hahahalib::hahaha_parameter_deal_xml_mapping::Move(std::move(hpds));
        Move(std::move(hpds));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_setting::Copy(const hahaha_parameter_deal_setting& hpds)
{
    Structure_Main_ = hpds.Structure_Main_;
    Structure_Sub_ = hpds.Structure_Sub_;
    Pointer_Main_ = hpds.Pointer_Main_;
    Pointer_Sub_ = hpds.Pointer_Sub_;

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_setting::Move(hahaha_parameter_deal_setting&& hpds) noexcept
{
    Structure_Main_ = hpds.Structure_Main_;
    Structure_Sub_ = hpds.Structure_Sub_;
    Pointer_Main_ = hpds.Pointer_Main_;
    Pointer_Sub_ = hpds.Pointer_Sub_;

    hpds.Reset();
}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_setting::Reset()
{
    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_setting::Prepare_Node(
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
)
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_setting::Prepare_Attribute(
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
)
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_setting::Prepare_Value(
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
)
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_setting::Prepare(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{



	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_setting::Mapping(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
	hahahalib::hahaha_parameter_deal_xml_node& root
)
{


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_parameter_deal_setting::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_parameter_deal_setting::Set_Pointer(
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