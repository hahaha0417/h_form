//---------------------------------------------------------------------------

#ifndef hahaha_painter_viewH
#define hahaha_painter_viewH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
//---------------------------------------------------------------------------
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
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_painter_view :
	public halib::image_view_painter
{
public:
	hahaha_painter_view();
	~hahaha_painter_view();

	hahaha_painter_view(const hahaha_painter_view& hpv);
    hahaha_painter_view(hahaha_painter_view&& hpv) noexcept;
	hahaha_painter_view& operator=(const hahaha_painter_view& hpv);
    hahaha_painter_view& operator=(hahaha_painter_view&& hpv) noexcept;
	void Copy(const hahaha_painter_view& hpv);
    void Move(hahaha_painter_view&& hpv) noexcept;
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
public:
	int Reset();

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
public:
public:
public:
public:
public:
public:
	bool Down_;
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
