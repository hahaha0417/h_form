//---------------------------------------------------------------------------

#ifndef hahaha_processing_unit_region_rectangle_script_showH
#define hahaha_processing_unit_region_rectangle_script_showH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_processing_unit_region_rectangle;
//---------------------------------------------------------------------------

class hahaha_processing_unit_region_rectangle_script_show
{
public:
	hahaha_processing_unit_region_rectangle_script_show();
	~hahaha_processing_unit_region_rectangle_script_show();

	hahaha_processing_unit_region_rectangle_script_show(const hahaha_processing_unit_region_rectangle_script_show& hpurrss);
    hahaha_processing_unit_region_rectangle_script_show(hahaha_processing_unit_region_rectangle_script_show&& hpurrss) noexcept;
	hahaha_processing_unit_region_rectangle_script_show& operator=(const hahaha_processing_unit_region_rectangle_script_show& hpurrss);
    hahaha_processing_unit_region_rectangle_script_show& operator=(hahaha_processing_unit_region_rectangle_script_show&& hpurrss) noexcept;
	void Copy(const hahaha_processing_unit_region_rectangle_script_show& hpurrss);
    void Move(hahaha_processing_unit_region_rectangle_script_show&& hpurrss) noexcept;
public:
	int Reset();
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
    hahaha_processing_unit_region_rectangle* Region_;
public:

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
