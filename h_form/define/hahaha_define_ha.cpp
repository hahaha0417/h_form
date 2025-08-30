//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_define_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <iostream>
#include <filesystem>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
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
#include <parameter_deal_system_setting\hahaha_parameter_deal_system_setting_ha.h>
#include <parameter_deal_option\hahaha_parameter_deal_option_ha.h>
#include <parameter_deal_setting\hahaha_parameter_deal_setting_ha.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting_ha.h>
#include <option\hahaha_option_ha.h>
#include <setting\hahaha_setting_ha.h>
//
#include <command\hahaha_command_main_ha.h>
#include <command\hahaha_command_sub_ha.h>
//---------------------------------------------------------------------------
#include <dll\hahaha_load_dll.h>
#include <post\hahaha_post_package.h>
//---------------------------------------------------------------------------
#include <define\parameter_mapping\hahaha_define_parameter_mapping_type.h>
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_region.h>
#include <define\processing_unit\hahaha_define_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <painter\hahaha_painter_information.h>
#include <painter\hahaha_painter_view.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace ha
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 變數
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_parameter_deal_system_setting_ha> Parameter_Deal_System_Setting_Ha_;
std::unique_ptr<hahaha::hahaha_parameter_deal_option_ha> Parameter_Deal_Option_Ha_;
std::unique_ptr<hahaha::hahaha_parameter_deal_setting_ha> Parameter_Deal_Setting_Ha_;
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_system_setting_ha> System_Setting_Ha_;
std::unique_ptr<hahaha::hahaha_option_ha> Option_Ha_;
std::unique_ptr<hahaha::hahaha_setting_ha> Setting_Ha_;
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_structure_main>  Structure_Main_Ha_;
std::unique_ptr<hahaha::hahaha_structure_sub>  Structure_Sub_Ha_;
std::unique_ptr<hahaha::hahaha_pointer_main>  Pointer_Main_Ha_;
std::unique_ptr<hahaha::hahaha_pointer_sub>  Pointer_Sub_Ha_;
//---------------------------------------------------------------------------
std::unique_ptr<hahaha::hahaha_command_main_ha> Command_Main_Ha_;
std::unique_ptr<hahaha::hahaha_command_sub_ha> Command_Sub_Ha_;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 指標
//---------------------------------------------------------------------------
hahaha::hahaha_structure_main* Structure_Main_;
hahaha::hahaha_structure_sub* Structure_Sub_;
hahaha::hahaha_pointer_main* Pointer_Main_;
hahaha::hahaha_pointer_sub* Pointer_Sub_;
//

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 功能
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int Initial(Thahaha_form_main* form_main)
{

	//---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // 變數
    //---------------------------------------------------------------------------
    if(Parameter_Deal_System_Setting_Ha_.get() == NULL)
    {
        Parameter_Deal_System_Setting_Ha_.reset(new hahaha::hahaha_parameter_deal_system_setting_ha);

    }

    if(Parameter_Deal_Option_Ha_.get() == NULL)
    {
        Parameter_Deal_Option_Ha_.reset(new hahaha::hahaha_parameter_deal_option_ha);
    }

    if(Parameter_Deal_Setting_Ha_.get() == NULL)
    {
        Parameter_Deal_Setting_Ha_.reset(new hahaha::hahaha_parameter_deal_setting_ha);
    }
    //---------------------------------------------------------------------------
    if(System_Setting_Ha_.get() == NULL)
	{
		System_Setting_Ha_.reset(new hahaha::hahaha_system_setting_ha);
	}

    if(Option_Ha_.get() == NULL)
	{
		Option_Ha_.reset(new hahaha::hahaha_option_ha);
	}

    if(Setting_Ha_.get() == NULL)
	{
		Setting_Ha_.reset(new hahaha::hahaha_setting_ha);
	}
    //---------------------------------------------------------------------------
    if(Structure_Main_Ha_.get() == NULL)
	{
		Structure_Main_Ha_.reset(new hahaha::hahaha_structure_main);

	}

    if(Structure_Sub_Ha_.get() == NULL)
	{
		Structure_Sub_Ha_.reset(new hahaha::hahaha_structure_sub);
	}

    if(Pointer_Main_Ha_.get() == NULL)
	{
		Pointer_Main_Ha_.reset(new hahaha::hahaha_pointer_main);
	}

    if(Pointer_Sub_Ha_.get() == NULL)
	{
		Pointer_Sub_Ha_.reset(new hahaha::hahaha_pointer_sub);
	}
    //---------------------------------------------------------------------------
    if(Command_Main_Ha_.get() == NULL)
    {
        Command_Main_Ha_.reset(new hahaha::hahaha_command_main_ha);
    }

    if(Command_Sub_Ha_.get() == NULL)
    {
        Command_Sub_Ha_.reset(new hahaha::hahaha_command_sub_ha);
    }
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    // 指標
    //---------------------------------------------------------------------------


    //---------------------------------------------------------------------------
    // 功能
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // 設定
    //---------------------------------------------------------------------------
    ha::Structure_Main_ = Structure_Main_Ha_.get();
    ha::Structure_Sub_ = Structure_Sub_Ha_.get();
    ha::Pointer_Main_ = Pointer_Main_Ha_.get();
    ha::Pointer_Sub_ = Pointer_Sub_Ha_.get();
    //
    ha::Pointer_Main_->Form_Main_ = form_main;
    //
    ha::Pointer_Main_->System_Setting_ = System_Setting_Ha_.get();
    ha::Pointer_Main_->Option_ = Option_Ha_.get();
    ha::Pointer_Main_->Setting_ = Setting_Ha_.get();
    //
    ha::Pointer_Main_->Command_Main_ = Command_Main_Ha_.get();
    ha::Pointer_Main_->Command_Sub_ = Command_Sub_Ha_.get();
    //-------------------------------------
    // form
    //-------------------------------------
    ha::Structure_Main_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Structure_Main_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Pointer_Main_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Pointer_Main_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Structure_Sub_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Structure_Sub_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Pointer_Sub_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Pointer_Sub_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );




    
    //-------------------------------------
    //
    //-------------------------------------
    ha::System_Setting_Ha_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::System_Setting_Ha_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Option_Ha_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Option_Ha_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Setting_Ha_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Setting_Ha_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Parameter_Deal_System_Setting_Ha_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Parameter_Deal_System_Setting_Ha_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Parameter_Deal_Option_Ha_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Parameter_Deal_Option_Ha_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    ha::Parameter_Deal_Setting_Ha_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );
    ha::Parameter_Deal_Setting_Ha_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

	//---------------------------------------------------------------------------
    // Image_View
	//---------------------------------------------------------------------------
	ha::Structure_Main_->Form_Image_View_->Set_Image_View((hahaha::hahaha_image_view_base*)ha::Structure_Main_->Image_View_.get());

	ha::Structure_Main_->Image_View_->View_Thumbnail_Interpolation_ = halib_def::image_view_view_thumbnail_interpolation::NEAREST;
	ha::Structure_Main_->Image_View_->View_Direction_ = halib_def::image_view_view_direction::NORMAL;
	ha::Structure_Main_->Image_View_->View_Ratio_ = 1.0;
	ha::Structure_Main_->Image_View_->Is_View_Scroll_ = true;
	//
	// ha::Bitmap_Argb_->Resize(1920, 1080);
	f_lib::png::Load(L"C:\\Users\\hahaha\\Desktop\\ttt\\4K.png", *ha::Structure_Main_->Bitmap_Argb_);

	ha::Structure_Main_->Image_View_->Bitmap_ = ha::Structure_Main_->Bitmap_Argb_.get();
	ha::Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
	ha::Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(ha::Structure_Main_->Bitmap_Argb_->Width_ - 1 ) / 2,
		(double)(ha::Structure_Main_->Bitmap_Argb_->Height_ - 1 ) / 2
	);

	ha::Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));

	ha::Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
	//ha::Structure_Main_->Form_Image_View_->Show();

    ha::Structure_Main_->Image_View_->Add_Painter(ha::Structure_Main_->Painter_Information_.get());
    ha::Structure_Main_->Image_View_->Add_Painter(ha::Structure_Main_->Painter_View_.get());

	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------





	return 0;

}
//---------------------------------------------------------------------------
int Initial_Plugin()
{
    for (const auto& entry : std::filesystem::recursive_directory_iterator(ha::Pointer_Main_->System_Setting_->Folder_Plugin_)) {
        if (std::filesystem::is_regular_file(entry) && entry.path().extension() == ".dll") {
            std::unique_ptr<hahaha::hahaha_load_dll> dll_;
            dll_.reset(new hahaha::hahaha_load_dll());

            std::wstring eee = entry.path().filename();
            std::wstring eeer = entry.path();

            dll_->Load(entry.path());
            std::wstring str_;
            dll_->Hahaha_(str_);

            if(str_ == L"hahaha")
            {
                ha::Structure_Main_->Dlls_.emplace(entry.path().filename(), std::move(dll_));
            }

        }
    }

    ha::Pointer_Main_->Command_Main_->Initial_Environment();

    ha::Pointer_Main_->Command_Main_->Initial();







    return 0;
}
//---------------------------------------------------------------------------
int Close()
{


	return 0;

}

//---------------------------------------------------------------------------
int Close_Plugin()
{
    ha::Pointer_Main_->Command_Main_->Close();

   	

    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // ha
//---------------------------------------------------------------------------
