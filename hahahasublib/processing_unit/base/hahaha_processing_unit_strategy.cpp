//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_processing_unit_strategy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_strategy::hahaha_processing_unit_strategy()
{
    hahahalib::hahaha_image_view_painter_event::Reset();
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy::~hahaha_processing_unit_strategy()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy::hahaha_processing_unit_strategy(const hahaha_processing_unit_strategy& hpus)
{
    Reset();
    hahahalib::hahaha_image_view_painter_event::Copy(hpus);
	Copy(hpus);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy::hahaha_processing_unit_strategy(hahaha_processing_unit_strategy&& hpus) noexcept
{
    hahahalib::hahaha_image_view_painter_event::Move(std::move(hpus));
    Move(std::move(hpus));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy& hahaha_processing_unit_strategy::operator=(const hahaha_processing_unit_strategy& hpus)
{
    hahahalib::hahaha_image_view_painter_event::Copy(hpus);
	Copy(hpus);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy& hahaha_processing_unit_strategy::operator=(hahaha_processing_unit_strategy&& hpus) noexcept
{
	if (this != &hpus)
    {
        hahahalib::hahaha_image_view_painter_event::Move(std::move(hpus));
        Move(std::move(hpus));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_strategy::Copy(const hahaha_processing_unit_strategy& hpus)
{
    Type_Strategy_ = hpus.Type_Strategy_;
    Type_Factory_Strategy_ = hpus.Type_Factory_Strategy_;
    Name_Strategy_ = hpus.Name_Strategy_;
    Name_Factory_Strategy_ = hpus.Name_Factory_Strategy_;

	//---------------------------------------------------------------------------
    Structure_Main_ = hpus.Structure_Main_;
    Structure_Sub_ = hpus.Structure_Sub_;
    Pointer_Main_ = hpus.Pointer_Main_;
    Pointer_Sub_ = hpus.Pointer_Sub_;

}
//---------------------------------------------------------------------------
void hahaha_processing_unit_strategy::Move(hahaha_processing_unit_strategy&& hpus) noexcept
{
    Type_Strategy_ = hpus.Type_Strategy_;
    Type_Factory_Strategy_ = hpus.Type_Factory_Strategy_;
    Name_Strategy_ = std::move(hpus.Name_Strategy_);
    Name_Factory_Strategy_ = std::move(hpus.Name_Factory_Strategy_);

	//---------------------------------------------------------------------------
    Structure_Main_ = hpus.Structure_Main_;
    Structure_Sub_ = hpus.Structure_Sub_;
    Pointer_Main_ = hpus.Pointer_Main_;
    Pointer_Sub_ = hpus.Pointer_Sub_;

    hpus.Reset();

}
//---------------------------------------------------------------------------
int hahaha_processing_unit_strategy::Reset()
{
    Processing_Unit_Base_ = NULL;
    Processing_Unit_Region_ = NULL;

    Structure_Main_ = NULL;
    Structure_Sub_ = NULL;
    Pointer_Main_ = NULL;
    Pointer_Sub_ = NULL;

    Type_Strategy_ = ha_def::processing_unit_strategy::NONE;
    Type_Factory_Strategy_ = ha_def::factory_processing_unit_strategy::NONE;

    Is_Deal_ = false;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_strategy::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_strategy::Set_Parameter()
{

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_strategy::Get_Parameter()
{

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy::On_Mouse_Down_Design(halib::image_view& image_view,
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

halib_def::image_view_result hahaha_processing_unit_strategy::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy::On_Mouse_Up_Design(halib::image_view& image_view,
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

halib_def::image_view_result hahaha_processing_unit_strategy::On_Paint_Design(halib::image_view& image_view)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy::Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy::Load_Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy::Prepare_Node(
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
halib_def::result hahaha_processing_unit_strategy::Prepare_Attribute(
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
halib_def::result hahaha_processing_unit_strategy::Prepare_Value(
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
halib_def::result hahaha_processing_unit_strategy::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy::Mapping(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------