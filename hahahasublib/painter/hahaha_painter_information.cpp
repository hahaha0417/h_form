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
#include <bitmap\function\base\hahaha_bitmap_function_bitmap.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_painter_information.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_painter_information::hahaha_painter_information()
{
    halib::image_view_painter::Reset();
	Reset();
}
//---------------------------------------------------------------------------
hahaha_painter_information::~hahaha_painter_information()
{

}
//---------------------------------------------------------------------------
hahaha_painter_information::hahaha_painter_information(const hahaha_painter_information& hpi)
{
    Reset();
    halib::image_view_painter::Copy(hpi);
	Copy(hpi);
}
//---------------------------------------------------------------------------
hahaha_painter_information::hahaha_painter_information(hahaha_painter_information&& hpi) noexcept
{
    halib::image_view_painter::Move(std::move(hpi));
    Move(std::move(hpi));
}
//---------------------------------------------------------------------------
hahaha_painter_information& hahaha_painter_information::operator=(const hahaha_painter_information& hpi)
{
    halib::image_view_painter::Copy(hpi);
	Copy(hpi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_painter_information& hahaha_painter_information::operator=(hahaha_painter_information&& hpi) noexcept
{
	if (this != &hpi)
    {
        halib::image_view_painter::Move(std::move(hpi));
        Move(std::move(hpi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_painter_information::Copy(const hahaha_painter_information& hpi)
{

}
//---------------------------------------------------------------------------
void hahaha_painter_information::Move(hahaha_painter_information&& hpi) noexcept
{
	Structure_Main_ = hpi.Structure_Main_;
    Structure_Sub_ = hpi.Structure_Sub_;
    Pointer_Main_ = hpi.Pointer_Main_;
    Pointer_Sub_ = hpi.Pointer_Sub_;

}
//---------------------------------------------------------------------------
int hahaha_painter_information::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_painter_information::On_Mouse_Move_Design(halib::image_view& image_view,
	TObject *Sender,
	TShiftState Shift,
	int X,
	int Y
)
{
	halib::point_double pt_;
	Structure_Main_->Image_View_->View_To_Image(
		halib::point_double(
			X,
			Y
		),
		pt_
	);

	Structure_Main_->Form_Image_View_->Panel_X->Caption = UnicodeString(L"X = ") + (int)pt_.X_;
	Structure_Main_->Form_Image_View_->Panel_Y->Caption = UnicodeString(L"Y = ") + (int)pt_.Y_;

    if(Structure_Main_->Image_View_->Bitmap_ != NULL && halib_bitmap::bitmap::Is_In_Image(halib::point((int)pt_.X_, (int)pt_.Y_), *Structure_Main_->Image_View_->Bitmap_))
    {
        if(Structure_Main_->Image_View_->Bitmap_->Bits_ == 8)
        {
            halib::bitmap_gray& bmp_ = *(halib::bitmap_gray*)Structure_Main_->Image_View_->Bitmap_;

            Structure_Main_->Form_Image_View_->Panel_R->Caption = UnicodeString(L"R = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_ + 2];
            Structure_Main_->Form_Image_View_->Panel_G->Caption = UnicodeString(L"G = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_ + 1];
            Structure_Main_->Form_Image_View_->Panel_B->Caption = UnicodeString(L"B = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_];

        }
        else if(Structure_Main_->Image_View_->Bitmap_->Bits_ == 24)
        {
            halib::bitmap_rgb& bmp_ = *(halib::bitmap_rgb*)Structure_Main_->Image_View_->Bitmap_;

            Structure_Main_->Form_Image_View_->Panel_R->Caption = UnicodeString(L"R = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_ + 2];
            Structure_Main_->Form_Image_View_->Panel_G->Caption = UnicodeString(L"G = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_ + 1];
            Structure_Main_->Form_Image_View_->Panel_B->Caption = UnicodeString(L"B = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_];
        }
        else if(Structure_Main_->Image_View_->Bitmap_->Bits_ == 32)
        {
            halib::bitmap_argb& bmp_ = *(halib::bitmap_argb*)Structure_Main_->Image_View_->Bitmap_;

            Structure_Main_->Form_Image_View_->Panel_R->Caption = UnicodeString(L"R = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_ + 2];
            Structure_Main_->Form_Image_View_->Panel_G->Caption = UnicodeString(L"G = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_ + 1];
            Structure_Main_->Form_Image_View_->Panel_B->Caption = UnicodeString(L"B = ") + bmp_[(int)pt_.Y_][(int)pt_.X_ * Structure_Main_->Image_View_->Bitmap_->Channel_];
        }



    }
    else
    {
        Structure_Main_->Form_Image_View_->Panel_R->Caption = UnicodeString(L"R = ");
        Structure_Main_->Form_Image_View_->Panel_G->Caption = UnicodeString(L"G = ");
        Structure_Main_->Form_Image_View_->Panel_B->Caption = UnicodeString(L"B = ");
    }




	return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_painter_information::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_painter_information::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------