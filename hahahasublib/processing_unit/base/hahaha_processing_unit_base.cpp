//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_processing_unit_base.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_base::hahaha_processing_unit_base()
{
    hahahalib::hahaha_image_view_painter_event::Reset();
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base::~hahaha_processing_unit_base()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_base::hahaha_processing_unit_base(const hahaha_processing_unit_base& hpub)
{
    Reset();
    hahahalib::hahaha_image_view_painter_event::Copy(hpub);
	Copy(hpub);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base::hahaha_processing_unit_base(hahaha_processing_unit_base&& hpub) noexcept
{
    hahahalib::hahaha_image_view_painter_event::Move(std::move(hpub));
    Move(std::move(hpub));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base& hahaha_processing_unit_base::operator=(const hahaha_processing_unit_base& hpub)
{
    hahahalib::hahaha_image_view_painter_event::Copy(hpub);
	Copy(hpub);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_base& hahaha_processing_unit_base::operator=(hahaha_processing_unit_base&& hpub) noexcept
{
	if (this != &hpub)
    {
        hahahalib::hahaha_image_view_painter_event::Move(std::move(hpub));
        Move(std::move(hpub));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_base::Copy(const hahaha_processing_unit_base& hpub)
{
    Processing_Unit_Region_ = hpub.Processing_Unit_Region_;
    Processing_Unit_Strategy_ = hpub.Processing_Unit_Strategy_;

    Structure_Main_ = hpub.Structure_Main_;
    Structure_Sub_ = hpub.Structure_Sub_;
    Pointer_Main_ = hpub.Pointer_Main_;
    Pointer_Sub_ = hpub.Pointer_Sub_;

    Type_Base_ = hpub.Type_Base_;
    Type_Factory_Base_ = hpub.Type_Factory_Base_;
    Name_Base_ = hpub.Name_Base_;
    Name_Factory_Base_ = hpub.Name_Factory_Base_;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_base::Move(hahaha_processing_unit_base&& hpub) noexcept
{
    Processing_Unit_Region_ = hpub.Processing_Unit_Region_;
    Processing_Unit_Strategy_ = hpub.Processing_Unit_Strategy_;

    Structure_Main_ = hpub.Structure_Main_;
    Structure_Sub_ = hpub.Structure_Sub_;
    Pointer_Main_ = hpub.Pointer_Main_;
    Pointer_Sub_ = hpub.Pointer_Sub_;

    Type_Base_ = hpub.Type_Base_;
    Type_Factory_Base_ = hpub.Type_Factory_Base_;
    Name_Base_ = hpub.Name_Base_;
    Name_Factory_Base_ = hpub.Name_Factory_Base_;

    hpub.Reset();

}
//---------------------------------------------------------------------------
int hahaha_processing_unit_base::Reset()
{
    Processing_Unit_Region_ = nullptr;
    Processing_Unit_Strategy_ = nullptr;

    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

    Type_Base_ = ha_def::processing_unit_base::NONE;
    Type_Factory_Base_ = ha_def::factory_processing_unit_base::NONE;
    Name_Base_ = L"";
    Name_Factory_Base_ = L"";

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_base::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_base::Set_Parameter()
{

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_base::Get_Parameter()
{

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_base::On_Mouse_Down_Design(halib::image_view& image_view,
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

halib_def::image_view_result hahaha_processing_unit_base::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_base::On_Mouse_Up_Design(halib::image_view& image_view,
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

halib_def::image_view_result hahaha_processing_unit_base::On_Paint_Design(halib::image_view& image_view)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base::Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base::Load_Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base::Prepare_Node(
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
halib_def::result hahaha_processing_unit_base::Prepare_Attribute(
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
halib_def::result hahaha_processing_unit_base::Prepare_Value(
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
halib_def::result hahaha_processing_unit_base::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_base::Mapping(
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------