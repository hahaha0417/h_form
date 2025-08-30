//---------------------------------------------------------------------------

#ifndef hahaha_processing_unit_region_rectangleH
#define hahaha_processing_unit_region_rectangleH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
#include <shape\hahaha_roi.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_mapping.h>
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
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_region_rectangle_script_create;
class hahaha_processing_unit_region_rectangle_script_edit;
class hahaha_processing_unit_region_rectangle_script_show;
//---------------------------------------------------------------------------

class hahaha_processing_unit_region_rectangle : public hahaha::hahaha_processing_unit_region
{
public:
	hahaha_processing_unit_region_rectangle();
	~hahaha_processing_unit_region_rectangle();

	hahaha_processing_unit_region_rectangle(const hahaha_processing_unit_region_rectangle& hpurr);
    hahaha_processing_unit_region_rectangle(hahaha_processing_unit_region_rectangle&& hpurr) noexcept;
	hahaha_processing_unit_region_rectangle& operator=(const hahaha_processing_unit_region_rectangle& hpurr);
    hahaha_processing_unit_region_rectangle& operator=(hahaha_processing_unit_region_rectangle&& hpurr) noexcept;
	void Copy(const hahaha_processing_unit_region_rectangle& hpurr);
    void Move(hahaha_processing_unit_region_rectangle&& hpurr) noexcept;
public:
	int Reset();

public:
	//---------------------------------------------------------------------------
    // 因為在DLL，不會一直include，所以放這邊就好
    //---------------------------------------------------------------------------

public:
public:
    virtual halib_def::result Set_Parameter();
    virtual halib_def::result Get_Parameter();
public:
public:
	virtual halib_def::image_view_result On_Mouse_Down_Design(halib::image_view& image_view,
		TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
		int Y
	);
	virtual halib_def::image_view_result On_Mouse_Move_Design(halib::image_view& image_view,
		TObject *Sender,
		TShiftState Shift,
		int X,
		int Y
	);
	virtual halib_def::image_view_result On_Mouse_Up_Design(halib::image_view& image_view,
		TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
	);
public:
    virtual halib_def::image_view_result On_Paint_Design(halib::image_view& image_view);

public:
    std::unique_ptr<hahaha::hahaha_processing_unit_region_rectangle_script_create> Script_Create_;
    std::unique_ptr<hahaha::hahaha_processing_unit_region_rectangle_script_edit> Script_Edit_;
    std::unique_ptr<hahaha::hahaha_processing_unit_region_rectangle_script_show> Script_Show_;
public:
    virtual halib_def::image_view_result Paint_Frame(halib::image_view& image_view);
public:
	virtual halib_def::result Prepare_Node(
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
	);
    virtual halib_def::result Prepare_Attribute(
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
	);
	virtual halib_def::result Prepare_Value(
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
	);
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
    virtual halib_def::result Initial();
    virtual halib_def::result Load_Initial();

public:


public:
    
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
