//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <view\form\scene\hahaha_view_form_scene.h>
#include "hahaha_view_scene_package.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_view_scene_package::hahaha_view_scene_package()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_view_scene_package::~hahaha_view_scene_package()
{

}
//---------------------------------------------------------------------------
hahaha_view_scene_package::hahaha_view_scene_package(const hahaha_view_scene_package& hvsp)
{
    Reset();
	Copy(hvsp);
}
//---------------------------------------------------------------------------
hahaha_view_scene_package::hahaha_view_scene_package(hahaha_view_scene_package&& hvsp) noexcept
{
    Move(std::move(hvsp));
}
//---------------------------------------------------------------------------
hahaha_view_scene_package& hahaha_view_scene_package::operator=(const hahaha_view_scene_package& hvsp)
{
	Copy(hvsp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_view_scene_package& hahaha_view_scene_package::operator=(hahaha_view_scene_package&& hvsp) noexcept
{
	if (this != &hvsp)
    {
        Move(std::move(hvsp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_view_scene_package::Copy(const hahaha_view_scene_package& hvsp)
{

}
//---------------------------------------------------------------------------
void hahaha_view_scene_package::Move(hahaha_view_scene_package&& hvsp) noexcept
{
    Structure_Main_ = hvsp.Structure_Main_;
    Structure_Sub_ = hvsp.Structure_Sub_;
    Pointer_Main_ = hvsp.Pointer_Main_;
    Pointer_Sub_ = hvsp.Pointer_Sub_;
	//---------------------------------------------------------------------------
	Form_Scene_ = std::move(hvsp.Form_Scene_);
}
//---------------------------------------------------------------------------
int hahaha_view_scene_package::Reset()
{
    if(Form_Scene_.get() == NULL)
    {
        Form_Scene_.reset(new Thahaha_form_view_scene(NULL));
    }

	return 0;
}
//---------------------------------------------------------------------------

int hahaha_view_scene_package::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return 0;
}
//---------------------------------------------------------------------------

int hahaha_view_scene_package::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------