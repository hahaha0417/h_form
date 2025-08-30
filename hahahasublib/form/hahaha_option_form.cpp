//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_option_form.h"
//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <option\hahaha_option.h>
#include <setting\hahaha_setting.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_option *hahaha_form_option;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_option::Thahaha_form_option(TComponent* Owner)
	: TForm(Owner)
{
	CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_option::button_minClick(TObject *Sender)
{
	PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_option::button_maxClick(TObject *Sender)
{
    if(WindowState == wsNormal)
	{
		WindowState = wsMaximized;
	}
	else if(WindowState == wsMaximized)
	{
		WindowState = wsNormal;
	}
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_option::button_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_option::Parameter_Mapping(halib_def::parameter_mapping_type type)
{
    if(Is_Update_)
    {
        return halib_def::result::SUCCESS;
    }
    Is_Update_ = true;

    std::vector<hahahalib::hahaha_parameter_mapping_item> items_ = {
        //{folder_plugin, halib_def::vcl_field::TEXT, &ha::System_Setting_->Folder_Plugin_, halib_def::type_variable::WSTRING},
    };

    hahahalib::hahaha_parameter_mapping parameter_mapping_;
    parameter_mapping_.Deal(items_, type);

    Is_Update_ = false;

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_option::FormShow(TObject *Sender)
{
    //---------------------------------------------------------------------------

    // Á×§Ktitle bar ²§±`
    Width++;
    Width--;



    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_option::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_option::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------


