//---------------------------------------------------------------------------

#pragma hdrstop

#include <define\processing_unit\hahaha_define_processing_unit_base.h>

//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
#include <function\hahaha_function_vector.h>
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
//---------------------------------------------------------------------------

#include "hahaha_processing_unit_base_base.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_base_base::hahaha_processing_unit_base_base()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base_base::~hahaha_processing_unit_base_base()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_base_base::hahaha_processing_unit_base_base(const hahaha_processing_unit_base_base& hpubb)
{
    Reset();
    hahaha_processing_unit_base_base::Copy(hpubb);
	Copy(hpubb);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base_base::hahaha_processing_unit_base_base(hahaha_processing_unit_base_base &&hpubb) noexcept
{
    hahaha_processing_unit_base_base::Move(std::move(hpubb));
    Move(std::move(hpubb));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base_base& hahaha_processing_unit_base_base::operator=(const hahaha_processing_unit_base_base& hpubb)
{
    hahaha_processing_unit_base_base::Copy(hpubb);
	Copy(hpubb);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base_base& hahaha_processing_unit_base_base::operator=(hahaha_processing_unit_base_base&& hpubb) noexcept
{
    hahaha_processing_unit_base_base::Move(std::move(hpubb));
    Move(std::move(hpubb));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_base_base::Copy(const hahaha_processing_unit_base_base& hpubb)
{

}
//---------------------------------------------------------------------------
void hahaha_processing_unit_base_base::Move(hahaha_processing_unit_base_base&& hpubb) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_processing_unit_base_base::Reset()
{
    Type_Base_ = ha_def::processing_unit_base::BASE;
    Name_Base_ = L"base";



	return 0;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_base_base::Set_Parameter()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_base_base::Get_Parameter()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_base_base::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{


    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_base_base::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_base_base::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_base_base::On_Paint_Design(halib::image_view& image_view)
{
	return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base_base::Prepare_Node(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    std::vector<std::wstring>& node_names_target,
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
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base_base::Prepare_Attribute(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    std::vector<std::wstring>& node_names_target,
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
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base_base::Prepare_Value(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    std::vector<std::wstring>& node_names_target,
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
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base_base::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base_base::Mapping(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    std::vector<std::wstring> node_names_;
    hahahalib::Vector_Copy(node_names, node_names_);


    std::vector<hahahalib::hahaha_parameter_deal_xml_item> items_ = {
        {node_names_,
			L"", halib_def::xml_type::NODE, halib_def::type_variable::NONE, (void*)NULL},
        {{},
			L"Type_Base", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Type_Base_},
        {{},
			L"Type_Factory_Base", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Type_Factory_Base_},

	};



    root.Add(items_);


    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base_base::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;
    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base_base::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;
    return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------