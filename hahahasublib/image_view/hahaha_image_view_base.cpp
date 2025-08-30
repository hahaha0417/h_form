//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_image_view_base.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view_base::hahaha_image_view_base()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view_base::~hahaha_image_view_base()
{

}
//---------------------------------------------------------------------------
hahaha_image_view_base::hahaha_image_view_base(const hahaha_image_view_base& hivb)
{
    Reset();
    hahahalib::hahaha_image_view::Copy(hivb);
	Copy(hivb);

}
//---------------------------------------------------------------------------
hahaha_image_view_base::hahaha_image_view_base(hahaha_image_view_base&& hivb) noexcept
{
    hahahalib::hahaha_image_view::Move(std::move(hivb));
    Move(std::move(hivb));
}
//---------------------------------------------------------------------------
hahaha_image_view_base& hahaha_image_view_base::operator=(const hahaha_image_view_base& hivb)
{
    hahahalib::hahaha_image_view::Copy(hivb);
    Copy(hivb);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view_base& hahaha_image_view_base::operator=(hahaha_image_view_base&& hivb) noexcept
{
	if (this != &hivb)
    {
        hahahalib::hahaha_image_view::Move(std::move(hivb));
        Move(std::move(hivb));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view_base::Copy(const hahaha_image_view_base& hivb)
{
    Structure_Main_ = hivb.Structure_Main_;
    Structure_Sub_ = hivb.Structure_Sub_;
    Pointer_Main_ = hivb.Pointer_Main_;
    Pointer_Sub_ = hivb.Pointer_Sub_;

}
//---------------------------------------------------------------------------
void hahaha_image_view_base::Move(hahaha_image_view_base&& hivb) noexcept
{
    Structure_Main_ = hivb.Structure_Main_;
    Structure_Sub_ = hivb.Structure_Sub_;
    Pointer_Main_ = hivb.Pointer_Main_;
    Pointer_Sub_ = hivb.Pointer_Sub_;

    hivb.Reset();

}
//---------------------------------------------------------------------------
int hahaha_image_view_base::Reset()
{
    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------

int hahaha_image_view_base::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return 0;
}
//---------------------------------------------------------------------------

int hahaha_image_view_base::Set_Pointer(
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

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------