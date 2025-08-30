//---------------------------------------------------------------------------

#ifndef hahaha_painter_informationH
#define hahaha_painter_informationH
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

class hahaha_painter_information :
	public halib::image_view_painter
{
public:
	hahaha_painter_information();
	~hahaha_painter_information();

	hahaha_painter_information(const hahaha_painter_information& hpi);
    hahaha_painter_information(hahaha_painter_information&& hpi) noexcept;
	hahaha_painter_information& operator=(const hahaha_painter_information& hpi);
    hahaha_painter_information& operator=(hahaha_painter_information&& hpi) noexcept;
	void Copy(const hahaha_painter_information& hpi);
    void Move(hahaha_painter_information&& hpi) noexcept;
public:
	int Reset();
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
public:

	virtual halib_def::image_view_result On_Mouse_Move_Design(halib::image_view& image_view,
		TObject *Sender,
		TShiftState Shift,
		int X,
		int Y
	);

public:
public:
public:

public:

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
