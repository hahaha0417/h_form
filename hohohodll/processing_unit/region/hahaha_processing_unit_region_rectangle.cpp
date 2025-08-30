//---------------------------------------------------------------------------

#pragma hdrstop

#include <define\processing_unit\hahaha_define_processing_unit_region.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <processing_unit\region\rectangle\hahaha_processing_unit_region_rectangle_script_create.h>
#include <processing_unit\region\rectangle\hahaha_processing_unit_region_rectangle_script_edit.h>
#include <processing_unit\region\rectangle\hahaha_processing_unit_region_rectangle_script_show.h>

//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
//---------------------------------------------------------------------------
#include <function\hahaha_function_vector.h>
#include <define\hahaha_define_ho.h>
#include <image_view\hahaha_form_image_view.h>
#include "hahaha_processing_unit_region_rectangle.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle::hahaha_processing_unit_region_rectangle()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle::~hahaha_processing_unit_region_rectangle()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle::hahaha_processing_unit_region_rectangle(const hahaha_processing_unit_region_rectangle& hpurr)
{
    Reset();
    hahaha::hahaha_processing_unit_region::Copy(hpurr);
	Copy(hpurr);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle::hahaha_processing_unit_region_rectangle(hahaha_processing_unit_region_rectangle&& hpurr) noexcept
{
    hahaha::hahaha_processing_unit_region::Move(std::move(hpurr));
    Move(std::move(hpurr));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle& hahaha_processing_unit_region_rectangle::operator=(const hahaha_processing_unit_region_rectangle& hpurr)
{
    hahaha::hahaha_processing_unit_region::Copy(hpurr);
	Copy(hpurr);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle& hahaha_processing_unit_region_rectangle::operator=(hahaha_processing_unit_region_rectangle&& hpurr) noexcept
{
    hahaha::hahaha_processing_unit_region::Move(std::move(hpurr));
    Move(std::move(hpurr));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle::Copy(const hahaha_processing_unit_region_rectangle& hpurr)
{

}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle::Move(hahaha_processing_unit_region_rectangle&& hpurr) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_processing_unit_region_rectangle::Reset()
{
    Type_Region_ = ha_def::processing_unit_region::RECTANGLE;
    Name_Region_ = L"rectangle";
    // 預設Create階段，有需要再factory自己設定狀態
    State_Region_ = ha_def::processing_unit_region_state::CREATE;

    if(Roi_.get() == NULL)
    {
        Roi_.reset(new halib::roi_double());
    }

    //---------------------------------------------------------------------------

    if(Script_Create_.get() == NULL)
    {
        Script_Create_.reset(new hahaha::hahaha_processing_unit_region_rectangle_script_create());
    }

    if(Script_Edit_.get() == NULL)
    {
        Script_Edit_.reset(new hahaha::hahaha_processing_unit_region_rectangle_script_edit());
    }

	if(Script_Show_.get() == NULL)
    {
        Script_Show_.reset(new hahaha::hahaha_processing_unit_region_rectangle_script_show());
    }
    //
    if(Point_Start_.get() == NULL)
    {
        Point_Start_.reset(new halib::point_double());
    }

    if(Point_End_.get() == NULL)
    {
        Point_End_.reset(new halib::point_double());
    }

    if(Point_Choose_Down_.get() == NULL)
    {
        Point_Choose_Down_.reset(new halib::point_double());
    }

    if(Point_Choose_Move_.get() == NULL)
    {
        Point_Choose_Move_.reset(new halib::point_double());
    }


    //---------------------------------------------------------------------------
    // 設定指標
    //---------------------------------------------------------------------------
    Script_Create_->Region_ = this;
    Script_Edit_->Region_ = this;
    Script_Show_->Region_ = this;
    //---------------------------------------------------------------------------

    Down_Mouse_ = false;
    // 左右各5
    Paint_Point_Size_ = 5;
    // 2 * 2 + 1
    Paint_Line_Size_ = 2;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region_rectangle::Set_Parameter()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region_rectangle::Get_Parameter()
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {
        result_ = Script_Create_->On_Mouse_Down_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y
        );
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
        result_ = Script_Edit_->On_Mouse_Down_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y
        );
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {
        result_ = Script_Show_->On_Mouse_Down_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y
        );
    }

    return result_;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {
        result_ = Script_Create_->On_Mouse_Move_Design(image_view,
            Sender,
            Shift,
            X,
            Y
        );
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
        result_ = Script_Edit_->On_Mouse_Move_Design(image_view,
            Sender,
            Shift,
            X,
            Y
        );
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {
        result_ = Script_Show_->On_Mouse_Move_Design(image_view,
            Sender,
            Shift,
            X,
            Y
        );
    }

    return result_;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {
        result_ = Script_Create_->On_Mouse_Up_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y
        );
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
        result_ = Script_Edit_->On_Mouse_Up_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y
        );
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {
        result_ = Script_Show_->On_Mouse_Up_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y
        );
    }

    return result_;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle::On_Paint_Design(halib::image_view& image_view)
{
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {
        result_ = Script_Create_->On_Paint_Design(image_view);
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
        result_ = Script_Edit_->On_Paint_Design(image_view);
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {
        result_ = Script_Show_->On_Paint_Design(image_view);
    }

    return result_;

}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_processing_unit_region_rectangle::Paint_Frame(halib::image_view& image_view)
{
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {
//        result_ = Script_Create_->Paint_Frame(image_view);
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
        result_ = Script_Edit_->Paint_Frame(image_view);
    }
    else if(State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {
//        result_ = Script_Show_->Paint_Frame(image_view);
    }

    return result_;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region_rectangle::Prepare_Node(
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
halib_def::result hahaha_processing_unit_region_rectangle::Prepare_Attribute(
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
halib_def::result hahaha_processing_unit_region_rectangle::Prepare_Value(
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
halib_def::result hahaha_processing_unit_region_rectangle::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region_rectangle::Mapping(
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
			L"Type_Region", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Type_Region_},
        {{},
			L"Type_Factory_Region", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Type_Factory_Region_},
        {{},
			L"Is_Create", halib_def::xml_type::VALUE, halib_def::type_variable::BOOL, &Is_Create_},
        //
	};



    node_names_.emplace_back(L"Roi");


    items_.emplace_back(
        node_names_,
			L"X1", halib_def::xml_type::VALUE, halib_def::type_variable::DOUBLE, &Roi_->X1_
    );
    items_.emplace_back(
        node_names_,
			L"Y1", halib_def::xml_type::VALUE, halib_def::type_variable::DOUBLE, &Roi_->Y1_
    );
    items_.emplace_back(
        node_names_,
			L"X2", halib_def::xml_type::VALUE, halib_def::type_variable::DOUBLE, &Roi_->X2_
    );
    items_.emplace_back(
        node_names_,
			L"Y2", halib_def::xml_type::VALUE, halib_def::type_variable::DOUBLE, &Roi_->Y2_
    );

    node_names_.pop_back();

    root.Add(items_);


    return result;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region_rectangle::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;
    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_region_rectangle::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    if(Is_Create_)
    {
        State_Region_ = ha_def::processing_unit_region_state::EDIT;

    }

    return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------