//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_processing_unit_region.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_region::hahaha_processing_unit_region()
{
    hahahalib::hahaha_image_view_painter_event::Reset();
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region::~hahaha_processing_unit_region()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_region::hahaha_processing_unit_region(const hahaha_processing_unit_region& hpur)
{
    Reset();
    hahahalib::hahaha_image_view_painter_event::Copy(hpur);
	Copy(hpur);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region::hahaha_processing_unit_region(hahaha_processing_unit_region&& hpur) noexcept
{
    hahahalib::hahaha_image_view_painter_event::Move(std::move(hpur));
    Move(std::move(hpur));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region& hahaha_processing_unit_region::operator=(const hahaha_processing_unit_region& hpur)
{
    hahahalib::hahaha_image_view_painter_event::Copy(hpur);
	Copy(hpur);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region& hahaha_processing_unit_region::operator=(hahaha_processing_unit_region&& hpur) noexcept
{
	if (this != &hpur)
    {
        hahahalib::hahaha_image_view_painter_event::Move(std::move(hpur));
        Move(std::move(hpur));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region::Copy(const hahaha_processing_unit_region& hpur)
{

}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region::Move(hahaha_processing_unit_region&& hpur) noexcept
{
    Type_Region_ = hpur.Type_Region_;
    Type_Factory_Region_ = hpur.Type_Factory_Region_;
    Name_Region_ = std::move(hpur.Name_Region_);
    Name_Factory_Region_ = std::move(hpur.Name_Factory_Region_);
    // 候選
    Candidate_ = hpur.Candidate_;
    // 選擇
    Choose_ = hpur.Choose_;
    Roi_ = std::move(hpur.Roi_);
    Down_Mouse_ = hpur.Down_Mouse_;
    // 畫矩形框
    Is_Paint_Frame_ = hpur.Is_Paint_Frame_;
    Is_Create_ = hpur.Is_Create_;

	// ---------------------------------
    // rectangle
    Point_Choose_Down_ = std::move(hpur.Point_Choose_Down_);
    Point_Choose_Move_ = std::move(hpur.Point_Choose_Move_);
    Point_Start_ = std::move(hpur.Point_Start_);
    Point_End_ = std::move(hpur.Point_End_);
    // ---------------------------------
	Paint_Point_Size_ = hpur.Paint_Point_Size_;
    Paint_Line_Size_ = hpur.Paint_Line_Size_;

    State_Region_ = hpur.State_Region_;
    Choose_Region_ = hpur.Choose_Region_;

	Processing_Unit_Base_ = hpur.Processing_Unit_Base_;
    Processing_Unit_Strategy_ = hpur.Processing_Unit_Strategy_;

    //---------------------------------------------------------------------------
    Structure_Main_ = hpur.Structure_Main_;
    Structure_Sub_ = hpur.Structure_Sub_;
    Pointer_Main_ = hpur.Pointer_Main_;
    Pointer_Sub_ = hpur.Pointer_Sub_;
	//---------------------------------------------------------------------------

    hpur.Reset();

}
//---------------------------------------------------------------------------
int hahaha_processing_unit_region::Reset()
{
    Processing_Unit_Base_ = NULL;
    Processing_Unit_Strategy_ = NULL;

    Structure_Main_ = NULL;
    Structure_Sub_ = NULL;
    Pointer_Main_ = NULL;
    Pointer_Sub_ = NULL;

    Type_Region_ = ha_def::processing_unit_region::NONE;
    Type_Factory_Region_ = ha_def::factory_processing_unit_region::NONE;
    //
    //
    State_Region_ = ha_def::processing_unit_region_state::NONE;
    Choose_Region_ = ha_def::processing_unit_region_choose::NONE;
    Candidate_ = false;
    Choose_ = false;
    Down_Mouse_ = false;
    Is_Paint_Frame_ = true;
    Is_Create_ = false;
    //



    //

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_region::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_region::Set_Parameter()
{

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_processing_unit_region::Get_Parameter()
{

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region::On_Mouse_Down_Design(halib::image_view& image_view,
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

halib_def::image_view_result hahaha_processing_unit_region::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region::On_Mouse_Up_Design(halib::image_view& image_view,
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

halib_def::image_view_result hahaha_processing_unit_region::On_Paint_Design(halib::image_view& image_view)
{
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region::Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region::Load_Initial()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_processing_unit_region::Paint_Frame(halib::image_view& image_view)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region::Prepare_Node(
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
halib_def::result hahaha_processing_unit_region::Prepare_Attribute(
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
halib_def::result hahaha_processing_unit_region::Prepare_Value(
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
halib_def::result hahaha_processing_unit_region::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region::Mapping(
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