//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_base.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>
#include <view\scene\hahaha_view_scene_package.h>
#include <view\view\hahaha_view_view_package.h>
#include <view\form\scene\hahaha_view_form_scene.h>
#include <view\form\view\hahaha_view_form_view.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_painter_view.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_painter_view::hahaha_painter_view()
{
    halib::image_view_painter::Reset();
	Reset();
}
//---------------------------------------------------------------------------
hahaha_painter_view::~hahaha_painter_view()
{

}
//---------------------------------------------------------------------------
hahaha_painter_view::hahaha_painter_view(const hahaha_painter_view& hpv)
{
    Reset();
    halib::image_view_painter::Copy(hpv);
	Copy(hpv);
}
//---------------------------------------------------------------------------
hahaha_painter_view::hahaha_painter_view(hahaha_painter_view&& hpv) noexcept
{
    halib::image_view_painter::Move(std::move(hpv));
    Move(std::move(hpv));
}
//---------------------------------------------------------------------------
hahaha_painter_view& hahaha_painter_view::operator=(const hahaha_painter_view& hpv)
{
    halib::image_view_painter::Copy(hpv);
	Copy(hpv);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_painter_view& hahaha_painter_view::operator=(hahaha_painter_view&& hpv) noexcept
{
	if (this != &hpv)
    {
        halib::image_view_painter::Move(std::move(hpv));
        Move(std::move(hpv));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_painter_view::Copy(const hahaha_painter_view& hpv)
{
    Structure_Main_ = hpv.Structure_Main_;
    Structure_Sub_ = hpv.Structure_Sub_;
    Pointer_Main_ = hpv.Pointer_Main_;
    Pointer_Sub_ = hpv.Pointer_Sub_;

    Down_  = hpv.Down_;
}
//---------------------------------------------------------------------------
void hahaha_painter_view::Move(hahaha_painter_view&& hpv) noexcept
{
    Structure_Main_ = hpv.Structure_Main_;
    Structure_Sub_ = hpv.Structure_Sub_;
    Pointer_Main_ = hpv.Pointer_Main_;
    Pointer_Sub_ = hpv.Pointer_Sub_;

    Down_  = hpv.Down_;

    hpv.Reset();

}
//---------------------------------------------------------------------------
int hahaha_painter_view::Reset()
{
    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

    Down_ = false;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_painter_view::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_painter_view::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_painter_view::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(Pointer_Main_->Select_Scene_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }

    halib_def::image_view_result result = halib_def::image_view_result::SUCCESS;

    result = Pointer_Main_->Select_Scene_->On_Mouse_Down_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );


    return result;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_painter_view::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{

    if(Pointer_Main_->Select_Scene_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    result_ = Pointer_Main_->Select_Scene_->On_Mouse_Move_Design(image_view,
        Sender,
        Shift,
        X,
        Y

    );

    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_painter_view::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(Pointer_Main_->Select_Scene_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    result_ = Pointer_Main_->Select_Scene_->On_Mouse_Up_Design(image_view,
        Sender,
        Button,
        Shift,
        X,
        Y

    );

    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_painter_view::On_Paint_Begin(halib::image_view& image_view)
{
    if(Pointer_Main_->Select_Scene_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }

    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    result_ = Pointer_Main_->Select_Scene_->On_Paint_Begin(image_view);

    return result_;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_painter_view::On_Paint_Design(halib::image_view& image_view)
{
    if(Pointer_Main_->Select_Scene_ == NULL)
    {
        return halib_def::image_view_result::SUCCESS;
    }

    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    result_ = Pointer_Main_->Select_Scene_->On_Paint_Design(image_view);

    return result_;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------