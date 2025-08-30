//---------------------------------------------------------------------------

#ifndef hahaha_processing_unit_region_rectangle_script_createH
#define hahaha_processing_unit_region_rectangle_script_createH
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

class hahaha_processing_unit_region_rectangle_script_create
{
public:
	hahaha_processing_unit_region_rectangle_script_create();
	~hahaha_processing_unit_region_rectangle_script_create();

	hahaha_processing_unit_region_rectangle_script_create(const hahaha_processing_unit_region_rectangle_script_create& hpurrsc);
    hahaha_processing_unit_region_rectangle_script_create(hahaha_processing_unit_region_rectangle_script_create&& hpurrsc) noexcept;
	hahaha_processing_unit_region_rectangle_script_create& operator=(const hahaha_processing_unit_region_rectangle_script_create& hpurrsc);
    hahaha_processing_unit_region_rectangle_script_create& operator=(hahaha_processing_unit_region_rectangle_script_create&& hpurrsc) noexcept;
	void Copy(const hahaha_processing_unit_region_rectangle_script_create& he);
    void Move(hahaha_processing_unit_region_rectangle_script_create&& he) noexcept;
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
