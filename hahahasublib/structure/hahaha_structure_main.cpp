//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_structure_main.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_base.h>
//---------------------------------------------------------------------------
#include <form\hahaha_main_form.h>
#include <form\hahaha_edit_form.h>
#include <form\hahaha_option_form.h>
#include <form\hahaha_popup_form.h>
#include <form\hahaha_system_setting_form.h>
#include <form\hahaha_view_form.h>
//---------------------------------------------------------------------------
#include <form\popup\hahaha_popup_scene_popup_form.h>
#include <form\popup\hahaha_popup_view_popup_form.h>
#include <form\popup\hahaha_popup_scene_popup_setting_form.h>
#include <form\popup\hahaha_popup_view_popup_setting_form.h>
//---------------------------------------------------------------------------
#include <function\bitmap\hahaha_function_bitmap_bmp.h>
#include <function\bitmap\hahaha_function_bitmap_jpeg.h>
#include <function\bitmap\hahaha_function_bitmap_png.h>
#include <function\bitmap\hahaha_function_bitmap_gif.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <option\hahaha_option.h>
#include <setting\hahaha_setting.h>
//---------------------------------------------------------------------------
#include <dll\hahaha_load_dll.h>
//---------------------------------------------------------------------------
#include <painter\hahaha_painter_information.h>
#include <painter\hahaha_painter_view.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 注意 : 與dll共用變數，必須放在class內，exe & dll指標是分開的
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_structure_main::hahaha_structure_main()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_structure_main::~hahaha_structure_main()
{

}
//---------------------------------------------------------------------------
hahaha_structure_main::hahaha_structure_main(const hahaha_structure_main& hsm)
{
    Reset();
	Copy(hsm);
}
//---------------------------------------------------------------------------
hahaha_structure_main::hahaha_structure_main(hahaha_structure_main&& hsm) noexcept
{
    Move(std::move(hsm));

}
//---------------------------------------------------------------------------
hahaha_structure_main& hahaha_structure_main::operator=(const hahaha_structure_main& hsm)
{
	Copy(hsm);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_structure_main& hahaha_structure_main::operator=(hahaha_structure_main&& hsm) noexcept
{
	if (this != &hsm)
    {
        Move(std::move(hsm));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_structure_main::Copy(const hahaha_structure_main& hsm)
{

}
//---------------------------------------------------------------------------
void hahaha_structure_main::Move(hahaha_structure_main&& hsm) noexcept
{
    //---------------------------------------------------------------------------
    // 變數
    //---------------------------------------------------------------------------
    Image_View_ = std::move(hsm.Image_View_);
    Form_Image_View_ = std::move(hsm.Form_Image_View_);
    // painter
    Painter_Information_ = std::move(hsm.Painter_Information_);
    Painter_View_ = std::move(hsm.Painter_View_);
    //---------------------------------------------------------------------------
    // 主要
    //---------------------------------------------------------------------------

    Form_Edit_ = std::move(hsm.Form_Edit_);
    Form_Option_ = std::move(hsm.Form_Option_);
    Form_Popup_ = std::move(hsm.Form_Popup_);
    Form_System_Setting_ = std::move(hsm.Form_System_Setting_);
    Form_View_ = std::move(hsm.Form_View_);
    //---------------------------------------------------------------------------
    // 次要
    //---------------------------------------------------------------------------
    Form_Popup_Scene_Popup_ = std::move(hsm.Form_Popup_Scene_Popup_);
    Form_Popup_View_Popup_ = std::move(hsm.Form_Popup_View_Popup_);
    Form_Popup_Scene_Popup_Setting_ = std::move(hsm.Form_Popup_Scene_Popup_Setting_);
    Form_Popup_View_Popup_Setting_ = std::move(hsm.Form_Popup_View_Popup_Setting_);

    //---------------------------------------------------------------------------
    Bitmap_Argb_ = std::move(hsm.Bitmap_Argb_);
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // Dll
    //----------------------------------------
    Dlls_ = std::move(hsm.Dlls_);
    //---------------------------------------------------------------------------
    Factory_Processing_Unit_Bases_ = std::move(hsm.Factory_Processing_Unit_Bases_);
    Factory_Processing_Unit_Regions_ = std::move(hsm.Factory_Processing_Unit_Regions_);
    Factory_Processing_Unit_Strategys_ = std::move(hsm.Factory_Processing_Unit_Strategys_);
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
    Structure_Main_ = hsm.Structure_Main_;
    Structure_Sub_ = hsm.Structure_Sub_;
    Pointer_Main_ = hsm.Pointer_Main_;
    Pointer_Sub_ = hsm.Pointer_Sub_;


	//---------------------------------------------------------------------------

    hsm.Reset();

}
//---------------------------------------------------------------------------
int hahaha_structure_main::Reset()
{


	//---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
    if(Image_View_.get() == NULL)
	{
		Image_View_.reset(new hahaha::hahaha_image_view_base);
	}
	if(Form_Image_View_.get() == NULL)
	{
		Form_Image_View_.reset(new Thahaha_image_view_form(NULL));
	}

    if(Painter_Information_.get() == NULL)
	{
		Painter_Information_.reset(new hahaha::hahaha_painter_information());
	}
    if(Painter_View_.get() == NULL)
	{
		Painter_View_.reset(new hahaha::hahaha_painter_view());
	}

	//---------------------------------------------------------------------------
    if(Bitmap_Argb_.get() == NULL)
	{
		Bitmap_Argb_.reset(new halib::bitmap_alloc_argb);
	}
	//---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // 主要
    //---------------------------------------------------------------------------
	if(Form_System_Setting_.get() == NULL)
	{
		Form_System_Setting_.reset(new Thahaha_form_system_setting(NULL));

	}

	if(Form_Option_.get() == NULL)
	{
		Form_Option_.reset(new Thahaha_form_option(NULL));

	}

	if(Form_Popup_.get() == NULL)
	{
		Form_Popup_.reset(new Thahaha_form_popup(NULL));

	}

    if(Form_Edit_.get() == NULL)
	{
		Form_Edit_.reset(new Thahaha_form_edit(NULL));
        Form_Edit_->ShowInTaskBar = false;

	}

	if(Form_View_.get() == NULL)
	{
		Form_View_.reset(new Thahaha_form_view(NULL));

	}
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // 次要
    //---------------------------------------------------------------------------
    if(Form_Popup_Scene_Popup_.get() == NULL)
	{
		Form_Popup_Scene_Popup_.reset(new Thahaha_form_popup_scene_popup(NULL));

	}
    if(Form_Popup_View_Popup_.get() == NULL)
	{
		Form_Popup_View_Popup_.reset(new Thahaha_form_popup_view_popup(NULL));

	}
    if(Form_Popup_Scene_Popup_Setting_.get() == NULL)
	{
		Form_Popup_Scene_Popup_Setting_.reset(new Thahaha_form_popup_scene_popup_setting(NULL));

	}
    if(Form_Popup_View_Popup_Setting_.get() == NULL)
	{
		Form_Popup_View_Popup_Setting_.reset(new Thahaha_form_popup_view_popup_setting(NULL));

	}
    //---------------------------------------------------------------------------



	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------


	return 0;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_structure_main::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    Image_View_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Painter_Information_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Painter_View_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Form_Edit_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Form_Option_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Form_Popup_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Form_System_Setting_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );


    Form_View_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Form_Popup_Scene_Popup_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    Form_Popup_View_Popup_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_structure_main::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    Image_View_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Painter_Information_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Painter_View_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_Edit_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_Option_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_Popup_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_System_Setting_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_View_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_Popup_Scene_Popup_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_Popup_View_Popup_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_Popup_Scene_Popup_Setting_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Form_Popup_View_Popup_Setting_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------