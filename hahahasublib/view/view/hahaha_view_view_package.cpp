//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <view\form\view\hahaha_view_form_view.h>
#include "hahaha_view_view_package.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_view_view_package::hahaha_view_view_package()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_view_view_package::~hahaha_view_view_package()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_view_view_package::hahaha_view_view_package(const hahaha_view_view_package& hvvp)
{
    Reset();
	Copy(hvvp);
}
//---------------------------------------------------------------------------
hahaha_view_view_package::hahaha_view_view_package(hahaha_view_view_package&& hvvp) noexcept
{
    Move(std::move(hvvp));
}
//---------------------------------------------------------------------------
hahaha_view_view_package& hahaha_view_view_package::operator=(const hahaha_view_view_package& hvvp)
{
	Copy(hvvp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_view_view_package& hahaha_view_view_package::operator=(hahaha_view_view_package&& hvvp) noexcept
{
	if (this != &hvvp)
    {
        Move(std::move(hvvp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_view_view_package::Copy(const hahaha_view_view_package& hvvp)
{

}
//---------------------------------------------------------------------------
void hahaha_view_view_package::Move(hahaha_view_view_package&& hvvp) noexcept
{
    Structure_Main_ = hvvp.Structure_Main_;
    Structure_Sub_ = hvvp.Structure_Sub_;
    Pointer_Main_ = hvvp.Pointer_Main_;
    Pointer_Sub_ = hvvp.Pointer_Sub_;

    Form_View_ = std::move(Form_View_);
}
//---------------------------------------------------------------------------
int hahaha_view_view_package::Reset()
{
    if(Form_View_.get() == NULL)
    {
        Form_View_.reset(new Thahaha_form_view_view(NULL));
    }

    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------

int hahaha_view_view_package::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return 0;
}
//---------------------------------------------------------------------------

int hahaha_view_view_package::Set_Pointer(
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