//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_view_scene.h"
//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view.h>
#include <function\hahaha_function_vector.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <setting\hahaha_setting.h>
#include <option\hahaha_option.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <form\popup\hahaha_popup_scene_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_form.h>
#include <form\popup\hahaha_popup_scene_popup_setting_form.h>
#include <form\popup\hahaha_popup_view_popup_setting_form.h>
//---------------------------------------------------------------------------
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>
#include <view\scene\hahaha_view_scene_package.h>
#include <view\form\scene\hahaha_view_form_scene.h>
#include <view\view\hahaha_view_view_package.h>
#include <view\form\view\hahaha_view_form_view.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <form\hahaha_main_form.h>
#include <form\hahaha_edit_form.h>
#include <form\hahaha_option_form.h>
#include <form\hahaha_popup_form.h>
#include <form\hahaha_system_setting_form.h>
#include <form\hahaha_view_form.h>
//---------------------------------------------------------------------------
#include <form\popup\hahaha_popup_scene_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_form.h>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <iostream>
#include <filesystem>
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
//---------------------------------------------------------------------------
#include <view\hahaha_view_view.h>
#include <view\scene\hahaha_view_scene_package.h>
#include <view\view\hahaha_view_view_package.h>
#include <view\form\scene\hahaha_view_form_scene.h>
#include <view\form\view\hahaha_view_form_view.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_view_scene::hahaha_view_scene()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_view_scene::~hahaha_view_scene()
{

}
//---------------------------------------------------------------------------
hahaha_view_scene::hahaha_view_scene(const hahaha_view_scene& hpus)
{
    Reset();
	Copy(hpus);
}
//---------------------------------------------------------------------------
hahaha_view_scene hahaha_view_scene::operator=(const hahaha_view_scene& hpus)
{
	Copy(hpus);

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_view_scene::Copy(const hahaha_view_scene& hpus)
{


}
//---------------------------------------------------------------------------
int hahaha_view_scene::Reset()
{
    Name_ = L"";
    Select_ = false;

	if(Package_.get() == NULL)
    {
        Package_.reset(new hahaha_view_scene_package());
    }

    return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Add_View(const std::wstring& name)
{
    Views_.emplace_back(std::unique_ptr<hahaha::hahaha_view_view>(new hahaha::hahaha_view_view()));

    hahaha::hahaha_view_view* view_ = Views_.back().get();
    view_->Name_ = name;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Delete_View(const int& index)
{
    std::vector<std::unique_ptr<hahaha::hahaha_view_view>> temp_;

    int n = Views_.size();

    temp_.reserve(n);

    for(int i = 0; i < n; i++)
    {
        if(i == index)
        {
            continue;
        }
        temp_.emplace_back(std::unique_ptr<hahaha::hahaha_view_view>());
        temp_.back().swap(Views_[i]);

    }

    temp_.swap(Views_);


    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Select()
{
    int n = Pointer_Main_->Setting_->Scenes_.size();

    if(n == 0)
    {
        Pointer_Main_->Select_Scene_ = NULL;
        Pointer_Main_->Select_View_ = NULL;
        Structure_Main_->Form_Popup_->Update_UI();

    	return halib_def::result::SUCCESS;
    }

    // 清空
    for(int i = 0; i < n; i++)
    {
        Pointer_Main_->Setting_->Scenes_[i]->Select_ = false;
        if(this != Pointer_Main_->Setting_->Scenes_[i].get())
        {
            Pointer_Main_->Setting_->Scenes_[i]->Package_->Form_Scene_->item_box->Color = (TColor)RGB(60, 60, 60);
            Pointer_Main_->Setting_->Scenes_[i]->Package_->Form_Scene_->image_logo->Picture->Assign(
            	Pointer_Main_->Setting_->Scenes_[i]->Package_->Form_Scene_->image_icon_on->Picture
            );
            Pointer_Main_->Setting_->Scenes_[i]->Package_->Form_Scene_->label_name->Font->Color = (TColor)RGB(255, 255, 255);

        }

    }

    // 顯示子項
    for(int i = 0; i < n; i++)
    {
        if(this != Pointer_Main_->Setting_->Scenes_[i].get())
        {
            {
                int m = Pointer_Main_->Setting_->Scenes_[i]->Views_.size();
                for(int j = 0; j < m; j++)
                {
                    Pointer_Main_->Setting_->Scenes_[i]->Views_[j]->Package_->Form_View_->item_box->Visible = false;
                }
            }
        }
        else
        {
            {
                int m = Pointer_Main_->Setting_->Scenes_[i]->Views_.size();
                for(int j = 0; j < m; j++)
                {
                    Pointer_Main_->Setting_->Scenes_[i]->Views_[j]->Package_->Form_View_->item_box->Visible = true;
                }
            }
        }

    }

    Pointer_Main_->Select_Scene_ = this;
    Select_ = true;
	Pointer_Main_->Select_Scene_->Package_->Form_Scene_->item_box->Color = (TColor)RGB(180, 180, 180);
    Pointer_Main_->Select_Scene_->Package_->Form_Scene_->image_logo->Picture->Assign(
    	Pointer_Main_->Select_Scene_->Package_->Form_Scene_->image_icon_off->Picture
    );
    Pointer_Main_->Select_Scene_->Package_->Form_Scene_->label_name->Font->Color = (TColor)RGB(0, 0, 0);

    Pointer_Main_->Select_Scene_->Set_Parameter();
    Structure_Main_->Form_Popup_->Update_UI();

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
int hahaha_view_scene::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return 0;
}
//---------------------------------------------------------------------------

int hahaha_view_scene::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return 0;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_view_scene::Set_Parameter()
{
	Structure_Main_->Form_Popup_Scene_Popup_Setting_->Is_Update_ = true;
    Structure_Main_->Form_Popup_Scene_Popup_Setting_->Scene_Name->Text = Name_.c_str();
    Pointer_Main_->Select_Scene_->Package_->Form_Scene_->label_name->Caption = Name_.c_str();

    Structure_Main_->Form_Popup_Scene_Popup_Setting_->Is_Update_ = false;
	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_view_scene::Get_Parameter()
{
    Name_ = Structure_Main_->Form_Popup_Scene_Popup_Setting_->Scene_Name->Text.c_str();

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_scene::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result = halib_def::image_view_result::SUCCESS;

    int n = Views_.size();


    hahaha_view_view* view_select_ = NULL;
    // 目前只有單選
    for(int i = 0; i < n; i++)
    {
    	if(Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_)
        {
            view_select_ = Views_[i].get();
            break;
        }
        //Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_ = false;


    }

    if(view_select_)
    {
        result = view_select_->On_Mouse_Down_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y

        );

        // 數量不會太多，有需要再像image_view那樣實作
        if(result != halib_def::image_view_result::SUCCESS)
        {
            return result;
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            result = Views_[i]->On_Mouse_Down_Design(image_view,
                Sender,
                Button,
                Shift,
                X,
                Y

            );

            // 數量不會太多，有需要再像image_view那樣實作
            if(result != halib_def::image_view_result::SUCCESS)
            {
                return result;
            }
        }
    }


    return result;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_scene::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result = halib_def::image_view_result::SUCCESS;

    int n = Views_.size();

    Pointer_Main_->Candidate_Processing_Unit_ = nullptr;

    hahaha_view_view* view_select_ = NULL;
    // 目前只有單選
    for(int i = 0; i < n; i++)
    {
    	if(Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_)
        {
            view_select_ = Views_[i].get();
            break;
        }


    }



    if(view_select_)
    {
        result = view_select_->On_Mouse_Move_Design(image_view,
            Sender,
            Shift,
            X,
            Y

        );

        // 數量不會太多，有需要再像image_view那樣實作
        if(result != halib_def::image_view_result::SUCCESS)
        {
            return result;
        }

    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            result = Views_[i]->On_Mouse_Move_Design(image_view,
                Sender,
                Shift,
                X,
                Y

            );

            // 數量不會太多，有需要再像image_view那樣實作
            if(result != halib_def::image_view_result::SUCCESS)
            {
                return result;
            }
        }
    }



    return result;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_scene::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result = halib_def::image_view_result::SUCCESS;

    int n = Views_.size();


    hahaha_view_view* view_select_ = NULL;
    // 目前只有單選
    for(int i = 0; i < n; i++)
    {
    	if(Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_)
        {
            view_select_ = Views_[i].get();
            break;
        }


    }



    if(view_select_)
    {
        result = view_select_->On_Mouse_Up_Design(image_view,
            Sender,
            Button,
            Shift,
            X,
            Y

        );

        for(int i = 0; i < n; i++)
        {
            // 清空，不然會殘留
            if(Pointer_Main_->Choose_Processing_Unit_ != Views_[i]->Processing_Unit_)
            {
//                Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_ = false;
            }

            Views_[i]->Processing_Unit_->Processing_Unit_Region_->Down_Mouse_ = false;

        }

        // 數量不會太多，有需要再像image_view那樣實作
        if(result != halib_def::image_view_result::SUCCESS)
        {
            return result;
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            result = Views_[i]->On_Mouse_Up_Design(image_view,
                Sender,
                Button,
                Shift,
                X,
                Y

            );

            // 數量不會太多，有需要再像image_view那樣實作
            if(result != halib_def::image_view_result::SUCCESS)
            {
                return result;
            }
        }

        hahaha_view_view* view_select_ = NULL;
    	// 目前只有單選
        for(int i = 0; i < n; i++)
        {
            if(Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_)
            {
                view_select_ = Views_[i].get();
                break;
            }


        }

        if(view_select_)
        {
            for(int i = 0; i < n; i++)
            {
                // 清空，不然會殘留
                Views_[i]->Processing_Unit_->Processing_Unit_Region_->Candidate_ = false;

            }
        }

    }
    

    return result;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_scene::On_Paint_Begin(halib::image_view& image_view)
{
    halib_def::image_view_result result = halib_def::image_view_result::SUCCESS;

    int n = Views_.size();
    for(int i = 0; i < n; i++)
    {
        result = Views_[i]->On_Paint_Begin(image_view);

        // 數量不會太多，有需要再像image_view那樣實作
        if(result != halib_def::image_view_result::SUCCESS)
        {
            return result;
        }
    }

    return result;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_view_scene::On_Paint_Design(halib::image_view& image_view)
{
    halib_def::image_view_result result = halib_def::image_view_result::SUCCESS;

    int n = Views_.size();

    hahaha_view_view* view_select_ = NULL;
    // 目前只有單選
    for(int i = 0; i < n; i++)
    {
    	if(Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_)
        {
            view_select_ = Views_[i].get();
            break;
        }


    }

    hahaha_view_view* view_candidate_ = NULL;
    // 目前只有單選
    for(int i = 0; i < n; i++)
    {
    	if(Views_[i]->Processing_Unit_->Processing_Unit_Region_->Candidate_)
        {
            view_candidate_ = Views_[i].get();
            break;
        }


    }


    for(int i = 0; i < n; i++)
    {
        // 每個都畫
        result = Views_[i]->On_Paint_Design(image_view);

        // 數量不會太多，有需要再像image_view那樣實作
        if(result != halib_def::image_view_result::SUCCESS)
        {
            return result;
        }
    }

    if(view_select_)
    {
        result = view_select_->Paint_Frame(image_view);
    }
    else if(view_candidate_)
    {
        result = view_candidate_->Paint_Frame(image_view);
    }


    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Prepare_Node(
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

    if(type == halib_def::type_variable::VECTOR_UNIQUE_PTR)
    {
        node_names_target.emplace_back(L"Views");
        if(value == &Views_ && node_names_target == node_names)
        {
            int n = 0;
            xmlNodePtr xml_node_cur_;
            for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
            {
                if (xml_node_cur_->type == XML_ELEMENT_NODE)
                {
                    Add_View(L"");
                    hahaha::hahaha_view_view& view_ = *Views_.back();

                    view_.Set_Structure(
                        Structure_Main_,
                        Structure_Sub_
                    );

                    view_.Set_Pointer(
                        Pointer_Main_,
                        Pointer_Sub_
                    );
                }
            }

        }
        node_names_target.pop_back();

        // 裡面有Views了
        Mapping(xml, node_names_target, root);

    }

    int n = Views_.size();

    std::vector<std::wstring> node_names_target_;
    hahahalib::Vector_Copy(node_names_target, node_names_target_);
    node_names_target_.emplace_back(L"Views");


    for(int i = 0; i < n; i++)
    {
        node_names_target_.emplace_back(L"View" + std::to_wstring(i + 1));

        Views_[i]->Prepare_Node(
            xml,
            node_names,
            node_names_target_,
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

        node_names_target_.pop_back();

    }
    node_names_target_.pop_back();

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Prepare_Attribute(
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

    std::vector<std::wstring> node_names_target_;
    hahahalib::Vector_Copy(node_names_target, node_names_target_);
    node_names_target_.emplace_back(L"Views");

    int n = Views_.size();

    for(int i = 0; i < n; i++)
    {
        node_names_target_.emplace_back(L"View" + std::to_wstring(i + 1));

        Views_[i]->Prepare_Attribute(
            xml,
            node_names,
            node_names_target_,
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

        node_names_target_.pop_back();
    }

    node_names_target_.pop_back();

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Prepare_Value(
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

    std::vector<std::wstring> node_names_target_;
    hahahalib::Vector_Copy(node_names_target, node_names_target_);
    node_names_target_.emplace_back(L"Views");

    int n = Views_.size();

    for(int i = 0; i < n; i++)
    {
        node_names_target_.emplace_back(L"View" + std::to_wstring(i + 1));

        Views_[i]->Prepare_Value(
            xml,
            node_names,
            node_names_target_,
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

        node_names_target_.pop_back();
    }

    node_names_target_.pop_back();

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

	int n = Views_.size();

    for(int i = 0; i < n; i++)
    {
        Views_[i]->Prepare(xml, node_names, root);
    }

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Mapping(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{

    std::vector<std::wstring> node_names_;
    hahahalib::Vector_Copy(node_names, node_names_);
    node_names_.emplace_back(L"Views");


    std::vector<hahahalib::hahaha_parameter_deal_xml_item> items_ = {
		{node_names_,
			L"", halib_def::xml_type::NODE, halib_def::type_variable::VECTOR_UNIQUE_PTR, (void*)&Views_},
//        {{},
//			L"s6", halib_def::xml_type::VALUE, halib_def::type_variable::WSTRING, &ha::Option_->S6_},
//		{{L"test", L"test2"},
//			L"s1", halib_def::xml_type::VALUE, halib_def::type_variable::BOOL, &ha::Option_->S1_},
//		{{},
//			L"s2", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &ha::Option_->S2_},
//		{{L"test2", L"test3"},
//			L"s3", halib_def::xml_type::VALUE, halib_def::type_variable::FLOAT, &ha::Option_->S3_},
//		{{},
//			L"s4", halib_def::xml_type::ATTRIBUTE, halib_def::type_variable::DOUBLE, &ha::Option_->S4_},

	};




	int n = Views_.size();

    for(int i = 0; i < n; i++)
    {
        node_names_.emplace_back(L"View" + std::to_wstring(i + 1));
        items_.emplace_back(
            node_names_,
			L"", halib_def::xml_type::NODE, halib_def::type_variable::UNIQUE_PTR, (void*)&Views_[i]
        );
        items_.emplace_back(
            node_names_,
			L"Name", halib_def::xml_type::VALUE, halib_def::type_variable::WSTRING, (void*)&Views_[i]->Name_
        );
        //



        Views_[i]->Mapping(xml, node_names_, root);

        node_names_.pop_back();
    }

    node_names_.pop_back();

    root.Add(items_);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_view_scene::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    int n = Views_.size();

    for(int i = 0; i < n; i++)
    {
        result = Views_[i]->Load_Initial();

        // 先移出螢幕
        Views_[i]->Package_->Form_View_->item_box->Top = 999999;
        Views_[i]->Package_->Form_View_->item_box->Parent = Structure_Main_->Form_Popup_->view_list;
        Views_[i]->Package_->Form_View_->item_box->Align = alTop;
        Views_[i]->Package_->Form_View_->item_box->AlignWithMargins = True;
        Views_[i]->Package_->Form_View_->label_name->Caption = Views_[i]->Name_.c_str();
        Views_[i]->Package_->Form_View_->View_ = Views_[i].get();


        int n = Views_.size();
        for(int i = 0; i < n; i++)
        {
            Views_[i]->Processing_Unit_->Processing_Unit_Region_->Choose_ = false;


        }
    }

    return result;
}
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------