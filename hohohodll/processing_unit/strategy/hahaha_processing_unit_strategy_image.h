//---------------------------------------------------------------------------

#ifndef hahaha_processing_unit_strategy_imageH
#define hahaha_processing_unit_strategy_imageH
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
#include <define\processing_unit\strategy\hahaha_define_processing_unit_strategy_direction.h>

//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
//---------------------------------------------------------------------------
#include <bitmap\hahaha_c_bitmap_alloc.h>
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_processing_unit_strategy_image : public hahaha::hahaha_processing_unit_strategy
{
public:
	hahaha_processing_unit_strategy_image();
	~hahaha_processing_unit_strategy_image();

	hahaha_processing_unit_strategy_image(const hahaha_processing_unit_strategy_image& hpusi);
    hahaha_processing_unit_strategy_image(hahaha_processing_unit_strategy_image&& hpusi) noexcept;
	hahaha_processing_unit_strategy_image& operator=(const hahaha_processing_unit_strategy_image& hpusi);
    hahaha_processing_unit_strategy_image& operator=(hahaha_processing_unit_strategy_image&& hpusi) noexcept;
	void Copy(const hahaha_processing_unit_strategy_image& hpusi);
    void Move(hahaha_processing_unit_strategy_image&& hpusi) noexcept;
public:
	int Reset();

public:
	//---------------------------------------------------------------------------
    // 因為在DLL，不會一直include，所以放這邊就好
    //---------------------------------------------------------------------------

public:
    std::wstring File_Name_;
public:
    std::wstring Message_Create_;

public:
    bool Ratio_Fix_;
    ha_def::processing_unit_strategy_direction Direction_;
    bool Is_Load_Bitmap_;
public:
    std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_Load_;
    std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_;
    std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_Thumbnail_;

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
    virtual halib_def::image_view_result On_Paint_Begin(halib::image_view& image_view);
    virtual halib_def::image_view_result On_Paint_Design(halib::image_view& image_view);
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

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
