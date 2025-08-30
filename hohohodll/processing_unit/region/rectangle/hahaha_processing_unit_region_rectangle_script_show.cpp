//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_processing_unit_region_rectangle_script_show.h"
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <processing_unit\region\hahaha_processing_unit_region_rectangle.h>
#include <image_view\hahaha_form_image_view.h>

#include <define\hahaha_define_ho.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_show::hahaha_processing_unit_region_rectangle_script_show()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_show::~hahaha_processing_unit_region_rectangle_script_show()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_show::hahaha_processing_unit_region_rectangle_script_show(const hahaha_processing_unit_region_rectangle_script_show& hpurrss)
{
    Reset();
	Copy(hpurrss);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_show::hahaha_processing_unit_region_rectangle_script_show(hahaha_processing_unit_region_rectangle_script_show&& hpurrss) noexcept
{
     Move(std::move(hpurrss));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_show& hahaha_processing_unit_region_rectangle_script_show::operator=(const hahaha_processing_unit_region_rectangle_script_show& hpurrss)
{
	Copy(hpurrss);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_show& hahaha_processing_unit_region_rectangle_script_show::operator=(hahaha_processing_unit_region_rectangle_script_show&& hpurrss) noexcept
{
    Move(std::move(hpurrss));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle_script_show::Copy(const hahaha_processing_unit_region_rectangle_script_show& hpurrss)
{
    Region_ = hpurrss.Region_;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle_script_show::Move(hahaha_processing_unit_region_rectangle_script_show&& hpurrss) noexcept
{
    Region_ = hpurrss.Region_;
}
//---------------------------------------------------------------------------
int hahaha_processing_unit_region_rectangle_script_show::Reset()
{
    Region_ = NULL;

	return 0;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_show::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_show::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_show::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_show::On_Paint_Design(halib::image_view& image_view)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------