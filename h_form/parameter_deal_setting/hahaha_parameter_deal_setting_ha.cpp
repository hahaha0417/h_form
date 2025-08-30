//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
//---------------------------------------------------------------------------
#include <setting\hahaha_setting.h>
#include <define\hahaha_define_ha.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>
//---------------------------------------------------------------------------
#include <function\hahaha_function_vector.h>
//---------------------------------------------------------------------------
#include "hahaha_parameter_deal_setting_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_setting_ha::hahaha_parameter_deal_setting_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting_ha::~hahaha_parameter_deal_setting_ha()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting_ha::hahaha_parameter_deal_setting_ha(const hahaha_parameter_deal_setting_ha& hpdsh)
{
    Reset();
	Copy(hpdsh);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting_ha::hahaha_parameter_deal_setting_ha(hahaha_parameter_deal_setting_ha&& hpdsh) noexcept
{
    Reset();
	Copy(hpdsh);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting_ha& hahaha_parameter_deal_setting_ha::operator=(const hahaha_parameter_deal_setting_ha& hpdsh)
{
	Copy(hpdsh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_setting_ha& hahaha_parameter_deal_setting_ha::operator=(hahaha_parameter_deal_setting_ha&& hpdsh) noexcept
{
	hahaha_parameter_deal_setting::Move(std::move(hpdsh));
    Move(std::move(hpdsh));

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_setting_ha::Copy(const hahaha_parameter_deal_setting_ha& hpdsh)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_setting_ha::Move(hahaha_parameter_deal_setting_ha&& hpdsh) noexcept
{
    if (this != &hpdsh)
    {
        hahaha_parameter_deal_setting::Move(std::move(hpdsh));
        Move(std::move(hpdsh));
    }
}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_setting_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_setting_ha::Prepare_Node(
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
	if(type == halib_def::type_variable::VECTOR_UNIQUE_PTR)
    {
        if(value == &ha::Pointer_Main_->Setting_->Scenes_)
        {
            int n = 0;
            xmlNodePtr xml_node_cur_;
            for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
            {
                if (xml_node_cur_->type == XML_ELEMENT_NODE)
                {
                    ha::Pointer_Main_->Setting_->Add_Scene(L"");
                    hahaha::hahaha_view_scene& scene_ = *ha::Pointer_Main_->Setting_->Scenes_.back();

                    scene_.Set_Structure(
                        Structure_Main_,
                        Structure_Sub_
                    );

                    scene_.Set_Pointer(
                        Pointer_Main_,
                        Pointer_Sub_
                    );
                }
            }

            // root
            std::vector<std::wstring> node_names_;
            Mapping(xml, node_names_, root);
        }


    }

    std::vector<std::wstring> node_names_target_;
    node_names_target_.emplace_back(L"Scenes");

    int n = ha::Pointer_Main_->Setting_->Scenes_.size();

    for(int i = 0; i < n; i++)
    {
        node_names_target_.emplace_back(L"Scene" + std::to_wstring(i + 1));

        ha::Pointer_Main_->Setting_->Scenes_[i]->Prepare_Node(
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
halib_def::result hahaha_parameter_deal_setting_ha::Prepare_Attribute(
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
    if(type == halib_def::type_variable::VECTOR_UNIQUE_PTR)
    {


    }

    std::vector<std::wstring> node_names_target_;
    node_names_target_.emplace_back(L"Scenes");

    int n = ha::Pointer_Main_->Setting_->Scenes_.size();

    for(int i = 0; i < n; i++)
    {
        node_names_target_.emplace_back(L"Scene" + std::to_wstring(i + 1));

        ha::Pointer_Main_->Setting_->Scenes_[i]->Prepare_Attribute(
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
halib_def::result hahaha_parameter_deal_setting_ha::Prepare_Value(
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
	if(type == halib_def::type_variable::VECTOR_UNIQUE_PTR)
    {



    }

    std::vector<std::wstring> node_names_target_;
    node_names_target_.emplace_back(L"Scenes");

    int n = ha::Pointer_Main_->Setting_->Scenes_.size();

    for(int i = 0; i < n; i++)
    {
        node_names_target_.emplace_back(L"Scene" + std::to_wstring(i + 1));

        ha::Pointer_Main_->Setting_->Scenes_[i]->Prepare_Value(
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
halib_def::result hahaha_parameter_deal_setting_ha::Prepare(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
	int n = ha::Pointer_Main_->Setting_->Scenes_.size();

//    for(int i = 0; i < n; i++)
//    {
//        ha::Pointer_Main_->Setting_->Scenes_[i]->Prepare(xml, root);
//    }


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_setting_ha::Mapping(
	hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
	hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    root.Name_ = L"H_Form";
	root.Reset();

    std::vector<std::wstring> node_names_;
    hahahalib::Vector_Copy(node_names, node_names_);
    node_names_.emplace_back(L"Scenes");


    std::vector<hahahalib::hahaha_parameter_deal_xml_item> items_ = {
		{node_names_,
			L"", halib_def::xml_type::NODE, halib_def::type_variable::VECTOR_UNIQUE_PTR, (void*)&ha::Pointer_Main_->Setting_->Scenes_},
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




	int n = ha::Pointer_Main_->Setting_->Scenes_.size();

    for(int i = 0; i < n; i++)
    {
        node_names_.emplace_back(L"Scene" + std::to_wstring(i + 1));
        items_.emplace_back(
            node_names_,
			L"", halib_def::xml_type::NODE, halib_def::type_variable::NONE, (void*)NULL
        );
        items_.emplace_back(
            node_names_,
			L"Name", halib_def::xml_type::VALUE, halib_def::type_variable::WSTRING, (void*)&ha::Pointer_Main_->Setting_->Scenes_[i]->Name_
        );

        ha::Pointer_Main_->Setting_->Scenes_[i]->Mapping(xml, node_names_, root);

        node_names_.pop_back();
    }

    node_names_.pop_back();

    root.Add(items_);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------