//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#include <form\hahaha_main_form.h>
#include <form\hahaha_edit_form.h>
#include <form\hahaha_option_form.h>
#include <form\hahaha_popup_form.h>
#include <form\hahaha_system_setting_form.h>
#include <form\hahaha_view_form.h>
//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <form\popup\hahaha_popup_scene_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_form.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_base.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <factory\processing_unit\hahaha_factory_processing_unit_base.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_region.h>
#include <factory\processing_unit\hahaha_factory_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_base.h>
#include <define\processing_unit\hahaha_define_processing_unit_region.h>
#include <define\processing_unit\hahaha_define_processing_unit_strategy.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_base.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_region.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_strategy.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <form\popup\hahaha_popup_scene_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_form.h>
#include <form\popup\hahaha_popup_scene_popup_setting_form.h>
#include <form\popup\hahaha_popup_view_popup_setting_form.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_view_view.h"
//---------------------------------------------------------------------------
#include <view\view\hahaha_view_view_package.h>
#include <view\form\view\hahaha_view_form_view.h>
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>
#include <function\hahaha_function_vector.h>
#include <convert\hahaha_convert_string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_view_view::hahaha_view_view()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_view_view::~hahaha_view_view()
{

    if(Processing_Unit_ != NULL)
    {
        hahaha::hahaha_processing_unit_base* processing_unit_base_ = Processing_Unit_;
        hahaha::hahaha_processing_unit_region* processing_unit_region_ = Processing_Unit_->Processing_Unit_Region_;
        hahaha::hahaha_processing_unit_strategy* processing_unit_strategy_ = Processing_Unit_->Processing_Unit_Strategy_;
        Structure_Main_->Factory_Processing_Unit_Bases_[processing_unit_base_->Type_Factory_Base_]->Delete(processing_unit_base_);
		Structure_Main_->Factory_Processing_Unit_Regions_[processing_unit_region_->Type_Factory_Region_]->Delete(processing_unit_region_);
		Structure_Main_->Factory_Processing_Unit_Strategys_[processing_unit_strategy_->Type_Factory_Strategy_]->Delete(processing_unit_strategy_);

        Processing_Unit_ = NULL;
    }


}
//---------------------------------------------------------------------------
hahaha_view_view::hahaha_view_view(const hahaha_view_view& hpuv)
{
    Reset();
	Copy(hpuv);
}
//---------------------------------------------------------------------------
hahaha_view_view hahaha_view_view::operator=(const hahaha_view_view& hpuv)
{
	Copy(hpuv);

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_view_view::Copy(const hahaha_view_view& hpuv)
{


}
//---------------------------------------------------------------------------
int hahaha_view_view::Reset()
{
    Name_ = L"";
    Select_ = false;
    Processing_Unit_ = NULL;

    if(Package_.get() == NULL)
    {
        Package_.reset(new hahaha_view_view_package());
    }

	return 0;
}

//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Select()
{
    int n = Pointer_Main_->Select_Scene_->Views_.size();

    if(n == 0)
    {
        Pointer_Main_->Select_View_ = NULL;
        Structure_Main_->Form_Popup_->Update_UI();

    	return halib_def::result::SUCCESS;
    }

    for(int i = 0; i < n; i++)
    {
        Pointer_Main_->Select_Scene_->Views_[i]->Select_ = false;
        if(this != Pointer_Main_->Select_Scene_->Views_[i].get())
        {
            Pointer_Main_->Select_Scene_->Views_[i]->Package_->Form_View_->item_box->Color = (TColor)RGB(60, 60, 60);
            Pointer_Main_->Select_Scene_->Views_[i]->Package_->Form_View_->image_logo->Picture->Assign(
            	Pointer_Main_->Select_Scene_->Views_[i]->Package_->Form_View_->image_icon_on->Picture
            );
            Pointer_Main_->Select_Scene_->Views_[i]->Package_->Form_View_->label_name->Font->Color = (TColor)RGB(255, 255, 255);
        }

    }

    Pointer_Main_->Select_View_ = this;
    Select_ = true;
	Pointer_Main_->Select_View_->Package_->Form_View_->item_box->Color = (TColor)RGB(180, 180, 180);
    Pointer_Main_->Select_View_->Package_->Form_View_->image_logo->Picture->Assign(
    	Pointer_Main_->Select_View_->Package_->Form_View_->image_icon_off->Picture
    );
    Pointer_Main_->Select_View_->Package_->Form_View_->label_name->Font->Color = (TColor)RGB(0, 0, 0);

    Pointer_Main_->Select_View_->Set_Parameter();
    Structure_Main_->Form_Popup_->Update_UI();

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
int hahaha_view_view::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return 0;
}
//---------------------------------------------------------------------------

int hahaha_view_view::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Set_Parameter()
{
    Structure_Main_->Form_Popup_View_Popup_Setting_->Is_Update_ = true;
    Structure_Main_->Form_Popup_View_Popup_Setting_->View_Name->Text = Name_.c_str();
    Pointer_Main_->Select_View_->Package_->Form_View_->label_name->Caption = Name_.c_str();
    Processing_Unit_->Set_Parameter();
    Processing_Unit_->Processing_Unit_Region_->Set_Parameter();
    Processing_Unit_->Processing_Unit_Strategy_->Set_Parameter();

    Structure_Main_->Form_Popup_View_Popup_Setting_->Is_Update_ = false;
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Get_Parameter()
{
    Name_ = Structure_Main_->Form_Popup_View_Popup_Setting_->View_Name->Text.c_str();
	Processing_Unit_->Get_Parameter();
    Processing_Unit_->Processing_Unit_Region_->Get_Parameter();
    Processing_Unit_->Processing_Unit_Strategy_->Get_Parameter();


    Structure_Main_->Image_View_->Is_Repaint_ = true;
    Structure_Main_->Image_View_->Repaint();

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_view::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(Processing_Unit_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }

    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    halib_def::image_view_result result_temp_ = halib_def::image_view_result::SUCCESS;

    result_temp_ = Processing_Unit_->On_Mouse_Down_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Region_->On_Mouse_Down_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Strategy_->On_Mouse_Down_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_view::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(Processing_Unit_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }

    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    halib_def::image_view_result result_temp_ = halib_def::image_view_result::SUCCESS;

    result_temp_ = Processing_Unit_->On_Mouse_Move_Design(image_view,
        Sender,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Region_->On_Mouse_Move_Design(image_view,
        Sender,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Strategy_->On_Mouse_Move_Design(image_view,
        Sender,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_view::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(Processing_Unit_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }

    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    halib_def::image_view_result result_temp_ = halib_def::image_view_result::SUCCESS;

    result_temp_ = Processing_Unit_->On_Mouse_Up_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Region_->On_Mouse_Up_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Strategy_->On_Mouse_Up_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }


    Processing_Unit_->Processing_Unit_Region_->Choose_Region_ = ha_def::processing_unit_region_choose::NONE;



    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_view::On_Paint_Begin(halib::image_view& image_view)
{
    if(Processing_Unit_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    halib_def::image_view_result result_temp_ = halib_def::image_view_result::SUCCESS;

    result_temp_ = Processing_Unit_->On_Paint_Begin(image_view);

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Region_->On_Paint_Begin(image_view);

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Strategy_->On_Paint_Begin(image_view);

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_view::On_Paint_Design(halib::image_view& image_view)
{
    if(Processing_Unit_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }
	halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    halib_def::image_view_result result_temp_ = halib_def::image_view_result::SUCCESS;



    result_temp_ = Processing_Unit_->On_Paint_Design(image_view);

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Region_->On_Paint_Design(image_view);

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    result_temp_ = Processing_Unit_->Processing_Unit_Strategy_->On_Paint_Design(image_view);

    if(result_ == halib_def::image_view_result::BREAK ||
         result_ == halib_def::image_view_result::RETURN ||
        result_ == halib_def::image_view_result::AGAIN
    )
    {
    }
    else
    {
        result_ = result_temp_;
    }

    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_view::Paint_Frame(halib::image_view& image_view)
{
    if(Processing_Unit_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }

	Processing_Unit_->Processing_Unit_Region_->Paint_Frame(image_view);

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Prepare_Node(
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



    if(type == halib_def::type_variable::POINTER)
    {
        bool deal_ = false;

        node_names_target.emplace_back(L"Base");
        if(value == &Processing_Unit_ && node_names_target == node_names)
        {

            int type_base_ = -1;
            int type_factory_base_ = -1;
            // 初始化Processing Unit
            xmlNodePtr xml_node_cur_;
            for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
            {
                std::wstring name_ = hahahalib::utf8_to_wstring(
                    (const char *)xml_node_cur_->name
                );
                if (xml_node_cur_->type == XML_ELEMENT_NODE)
                {
                    if(name_ == L"Type_Base")
                    {
                        std::wstring value_ = hahahalib::utf8_to_wstring(
                            (const char *)xml_node_cur_->children->content
                        );
                        type_base_ = _wtoi(value_.c_str());
                    }
                    if(name_ == L"Type_Factory_Base")
                    {
                        std::wstring value_ = hahahalib::utf8_to_wstring(
                            (const char *)xml_node_cur_->children->content
                        );
                        type_factory_base_ = _wtoi(value_.c_str());
                    }
                }
            }

            //---------------------------------------------------------------------------
            hahaha::hahaha_processing_unit_base* processing_unit_base_ = NULL;
            Structure_Main_->Factory_Processing_Unit_Bases_[(hahaha_define_factory_processing_unit_base)type_factory_base_]->Add((hahaha_define_processing_unit_base)type_base_, processing_unit_base_);

            processing_unit_base_->Set_Structure(
                Structure_Main_,
                Structure_Sub_
            );

            processing_unit_base_->Set_Pointer(
                Pointer_Main_,
                Pointer_Sub_
            );

            Processing_Unit_ = processing_unit_base_;
            //---------------------------------------------------------------------------

            deal_ = true;

        }
        node_names_target.pop_back();


        node_names_target.emplace_back(L"Region");
        if(value == &Processing_Unit_ && node_names_target == node_names)
        {

            int type_region_ = -1;
            int type_factory_region_ = -1;
            // 初始化Processing Unit
            xmlNodePtr xml_node_cur_;
            for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
            {
                std::wstring name_ = hahahalib::utf8_to_wstring(
                    (const char *)xml_node_cur_->name
                );
                if (xml_node_cur_->type == XML_ELEMENT_NODE)
                {
                    if(name_ == L"Type_Region")
                    {
                        std::wstring value_ = hahahalib::utf8_to_wstring(
                            (const char *)xml_node_cur_->children->content
                        );
                        type_region_ = _wtoi(value_.c_str());
                    }
                    if(name_ == L"Type_Factory_Region")
                    {
                        std::wstring value_ = hahahalib::utf8_to_wstring(
                            (const char *)xml_node_cur_->children->content
                        );
                        type_factory_region_ = _wtoi(value_.c_str());
                    }
                }
            }

            //---------------------------------------------------------------------------
            hahaha::hahaha_processing_unit_region* processing_unit_region_ = NULL;
            Structure_Main_->Factory_Processing_Unit_Regions_[(hahaha_define_factory_processing_unit_region)type_factory_region_]->Add((hahaha_define_processing_unit_region)type_region_, processing_unit_region_);

            processing_unit_region_->Set_Structure(
                Structure_Main_,
                Structure_Sub_
            );

            processing_unit_region_->Set_Pointer(
                Pointer_Main_,
                Pointer_Sub_
            );

            Processing_Unit_->Processing_Unit_Region_ = processing_unit_region_;
            //---------------------------------------------------------------------------

            deal_ = true;

        }
        node_names_target.pop_back();


        node_names_target.emplace_back(L"Strategy");
        if(value == &Processing_Unit_ && node_names_target == node_names)
        {

            int type_strategy_ = -1;
            int type_factory_strategy_ = -1;
            // 初始化Processing Unit
            xmlNodePtr xml_node_cur_;
            for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
            {
                std::wstring name_ = hahahalib::utf8_to_wstring(
                    (const char *)xml_node_cur_->name
                );
                if (xml_node_cur_->type == XML_ELEMENT_NODE)
                {
                    if(name_ == L"Type_Strategy")
                    {
                        std::wstring value_ = hahahalib::utf8_to_wstring(
                            (const char *)xml_node_cur_->children->content
                        );
                        type_strategy_ = _wtoi(value_.c_str());
                    }
                    if(name_ == L"Type_Factory_Strategy")
                    {
                        std::wstring value_ = hahahalib::utf8_to_wstring(
                            (const char *)xml_node_cur_->children->content
                        );
                        type_factory_strategy_ = _wtoi(value_.c_str());
                    }
                }
            }

            //---------------------------------------------------------------------------
            hahaha::hahaha_processing_unit_strategy* processing_unit_strategy_ = NULL;
            Structure_Main_->Factory_Processing_Unit_Strategys_[(hahaha_define_factory_processing_unit_strategy)type_factory_strategy_]->Add((hahaha_define_processing_unit_strategy)type_strategy_, processing_unit_strategy_);

            processing_unit_strategy_->Set_Structure(
                Structure_Main_,
                Structure_Sub_
            );

            processing_unit_strategy_->Set_Pointer(
                Pointer_Main_,
                Pointer_Sub_
            );

            Processing_Unit_->Processing_Unit_Strategy_ = processing_unit_strategy_;

            //------------------------------------------
            // 搭橋
//                Processing_Unit_->Processing_Unit_Region_ = processing_unit_region_;
//                Processing_Unit_->Processing_Unit_Strategy_ = processing_unit_strategy_;

            Processing_Unit_->Processing_Unit_Region_->Processing_Unit_Base_ = Processing_Unit_;
            Processing_Unit_->Processing_Unit_Region_->Processing_Unit_Strategy_ = Processing_Unit_->Processing_Unit_Strategy_;

            Processing_Unit_->Processing_Unit_Strategy_->Processing_Unit_Base_ = Processing_Unit_;
            Processing_Unit_->Processing_Unit_Strategy_->Processing_Unit_Region_ = Processing_Unit_->Processing_Unit_Region_;

            // 初始化
            Processing_Unit_->Initial();
            Processing_Unit_->Processing_Unit_Region_->Initial();
            Processing_Unit_->Processing_Unit_Strategy_->Initial();
            //---------------------------------------------------------------------------

            deal_ = true;

        }
        node_names_target.pop_back();



        if(deal_)
        {
            Mapping(xml, node_names_target, root);
        }

    }

    if(Processing_Unit_ != NULL)
    {
        //---------------------------------------------------------------------------

        node_names_target.emplace_back(L"Base");

        result = Processing_Unit_->Prepare_Node(
            xml,
            node_names,
            node_names_target,
            root,
            node,
            mapping,
            xml_doc,
            xml_node_root,
            xml_node_cur,
            xml_wstring,
            type,
            value
        );


        node_names_target.pop_back();

        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Region_ != NULL)
        {
            node_names_target.emplace_back(L"Region");

            result = Processing_Unit_->Processing_Unit_Region_->Prepare_Node(
                xml,
                node_names,
                node_names_target,
                root,
                node,
                mapping,
                xml_doc,
                xml_node_root,
                xml_node_cur,
                xml_wstring,
                type,
                value
            );

            node_names_target.pop_back();
        }


        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Strategy_ != NULL)
        {
            node_names_target.emplace_back(L"Strategy");

            result = Processing_Unit_->Processing_Unit_Strategy_->Prepare_Node(
                xml,
                node_names,
                node_names_target,
                root,
                node,
                mapping,
                xml_doc,
                xml_node_root,
                xml_node_cur,
                xml_wstring,
                type,
                value
            );

            node_names_target.pop_back();
        }


        //---------------------------------------------------------------------------
    }




    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Prepare_Attribute(
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

    std::vector<std::wstring> node_names_;
    hahahalib::Vector_Copy(node_names, node_names_);

    if(Processing_Unit_ != NULL)
    {
        //---------------------------------------------------------------------------

        node_names_target.emplace_back(L"Base");

        result = Processing_Unit_->Prepare_Attribute(
            xml,
            node_names_,
            node_names_target,
            root,
            node,
            mapping,
            xml_doc,
            xml_node_root,
            xml_node_cur,
            xml_wstring,
            type,
            value
        );

        node_names_target.pop_back();

        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Region_ != NULL)
        {
            node_names_target.emplace_back(L"Region");

            result = Processing_Unit_->Processing_Unit_Region_->Prepare_Attribute(
                xml,
                node_names_,
            	node_names_target,
                root,
                node,
                mapping,
                xml_doc,
                xml_node_root,
                xml_node_cur,
                xml_wstring,
                type,
                value
            );

            node_names_target.pop_back();

        }


        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Strategy_ != NULL)
        {
            node_names_target.emplace_back(L"Strategy");

            result = Processing_Unit_->Processing_Unit_Strategy_->Prepare_Attribute(
                xml,
                node_names_,
            	node_names_target,
                root,
                node,
                mapping,
                xml_doc,
                xml_node_root,
                xml_node_cur,
                xml_wstring,
                type,
                value
            );

            node_names_target.pop_back();
        }


        //---------------------------------------------------------------------------
    }




    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Prepare_Value(
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

    std::vector<std::wstring> node_names_;
    hahahalib::Vector_Copy(node_names, node_names_);

    if(Processing_Unit_ != NULL)
    {
        //---------------------------------------------------------------------------

        node_names_target.emplace_back(L"Base");

        result = Processing_Unit_->Prepare_Value(
            xml,
            node_names_,
            node_names_target,
            root,
            node,
            mapping,
            xml_doc,
            xml_node_root,
            xml_node_cur,
            xml_wstring,
            type,
            value
        );

        node_names_target.pop_back();

        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Region_ != NULL)
        {
            node_names_target.emplace_back(L"Region");

            result = Processing_Unit_->Processing_Unit_Region_->Prepare_Value(
                xml,
                node_names_,
            	node_names_target,
                root,
                node,
                mapping,
                xml_doc,
                xml_node_root,
                xml_node_cur,
                xml_wstring,
                type,
                value
            );

            node_names_target.pop_back();
        }
        

        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Strategy_)
        {
            node_names_target.emplace_back(L"Strategy");

            result = Processing_Unit_->Processing_Unit_Strategy_->Prepare_Value(
                xml,
                node_names_,
            	node_names_target,
                root,
                node,
                mapping,
                xml_doc,
                xml_node_root,
                xml_node_cur,
                xml_wstring,
                type,
                value
            );

            node_names_target.pop_back();
        }


        //---------------------------------------------------------------------------

    }



    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    std::vector<std::wstring> node_names_;
    hahahalib::Vector_Copy(node_names, node_names_);

    if(Processing_Unit_ != NULL)
    {
        //---------------------------------------------------------------------------

        node_names_.emplace_back(L"Base");

        result = Processing_Unit_->Prepare(xml, node_names_, root);

        node_names_.pop_back();

        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Region_ != NULL)
        {
            node_names_.emplace_back(L"Region");

            result = Processing_Unit_->Processing_Unit_Region_->Prepare(xml, node_names_, root);

            node_names_.pop_back();
        }

        //---------------------------------------------------------------------------


        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Strategy_ != NULL)
        {
            node_names_.emplace_back(L"Strategy");

            result = Processing_Unit_->Processing_Unit_Strategy_->Prepare(xml, node_names_, root);

            node_names_.pop_back();
        }


        //---------------------------------------------------------------------------
    }




    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Mapping(
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
			L"Base", halib_def::xml_type::NODE, halib_def::type_variable::POINTER, (void*)&Processing_Unit_},
        {node_names_,
			L"Region", halib_def::xml_type::NODE, halib_def::type_variable::POINTER, (void*)&Processing_Unit_},
        {node_names_,
			L"Strategy", halib_def::xml_type::NODE, halib_def::type_variable::POINTER, (void*)&Processing_Unit_},
	};




    //---------------------------------------------------------------------------
    // 注意 : 由於setting parser處理的關係，這裡要照順序，不能改
    //---------------------------------------------------------------------------
    if(Processing_Unit_ != NULL)
    {
        //---------------------------------------------------------------------------

        node_names_.emplace_back(L"Base");

    	result = Processing_Unit_->Mapping(xml, node_names_, root);

        node_names_.pop_back();

    	//---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Region_ != NULL)
        {
            node_names_.emplace_back(L"Region");

            result = Processing_Unit_->Processing_Unit_Region_->Mapping(xml, node_names_, root);

            node_names_.pop_back();
        }
        
        //---------------------------------------------------------------------------

        if(Processing_Unit_->Processing_Unit_Strategy_ != NULL)
        {
            node_names_.emplace_back(L"Strategy");

            result = Processing_Unit_->Processing_Unit_Strategy_->Mapping(xml, node_names_, root);

            node_names_.pop_back();
        }

        //---------------------------------------------------------------------------
    }





    root.Add(items_);

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_view::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    if(Processing_Unit_ != NULL)
    {
        //---------------------------------------------------------------------------

        result = Processing_Unit_->Load_Initial();

    	//---------------------------------------------------------------------------

        result = Processing_Unit_->Processing_Unit_Region_->Load_Initial();

        //---------------------------------------------------------------------------

        result = Processing_Unit_->Processing_Unit_Strategy_->Load_Initial();

        //---------------------------------------------------------------------------
    }

    return result;
}
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------