//---------------------------------------------------------------------------

#ifndef hahaha_processing_unit_regionH
#define hahaha_processing_unit_regionH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_mapping.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_region.h>
#include <define\processing_unit\region\hahaha_define_processing_unit_region_state.h>
#include <define\processing_unit\region\hahaha_define_processing_unit_region_choose.h>

#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_region.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
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
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_base;
class hahaha_processing_unit_strategy;
//---------------------------------------------------------------------------

class hahaha_processing_unit_region : public hahahalib::hahaha_image_view_painter_event
{
public:
	hahaha_processing_unit_region();
	~hahaha_processing_unit_region();

	hahaha_processing_unit_region(const hahaha_processing_unit_region& hpur);
    hahaha_processing_unit_region(hahaha_processing_unit_region&& hpur) noexcept;
	hahaha_processing_unit_region& operator=(const hahaha_processing_unit_region& hpur);
    hahaha_processing_unit_region& operator=(hahaha_processing_unit_region&& hpur) noexcept;
	void Copy(const hahaha_processing_unit_region& hpur);
    void Move(hahaha_processing_unit_region&& hpur) noexcept;
public:
    // 重設class
	int Reset();

public:
    ha_def::processing_unit_region Type_Region_;
    ha_def::factory_processing_unit_region Type_Factory_Region_;
    std::wstring Name_Region_;
    std::wstring Name_Factory_Region_;
    // 候選
    bool Candidate_;
    // 選擇
    bool Choose_;
    std::unique_ptr<halib::roi_double> Roi_;
    bool Down_Mouse_;
    // 畫矩形框
    bool Is_Paint_Frame_;
    bool Is_Create_;
public:
	// ---------------------------------
    // rectangle
    std::unique_ptr<halib::point_double> Point_Choose_Down_;
    std::unique_ptr<halib::point_double> Point_Choose_Move_;
    std::unique_ptr<halib::point_double> Point_Start_;
    std::unique_ptr<halib::point_double> Point_End_;
    // ---------------------------------
	int Paint_Point_Size_;
    int Paint_Line_Size_;
public:
    ha_def::processing_unit_region_state State_Region_;
    ha_def::processing_unit_region_choose Choose_Region_;
public:

public:
	hahaha_processing_unit_base* Processing_Unit_Base_;
    hahaha_processing_unit_strategy* Processing_Unit_Strategy_;
public:
	//---------------------------------------------------------------------------
	halib_def::result Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    halib_def::result Set_Pointer(
        hahaha::hahaha_pointer_main* pointer_main,
    	hahaha::hahaha_pointer_sub* pointer_sub
    );
	//---------------------------------------------------------------------------
    hahaha::hahaha_structure_main* Structure_Main_;
    hahaha::hahaha_structure_sub* Structure_Sub_;
    hahaha::hahaha_pointer_main* Pointer_Main_;
    hahaha::hahaha_pointer_sub* Pointer_Sub_;
	//---------------------------------------------------------------------------
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

    virtual halib_def::image_view_result Paint_Frame(halib::image_view& image_view);
public:
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
    // 初始化設定
    virtual halib_def::result Initial();
    // 載入初始化
    virtual halib_def::result Load_Initial();
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
