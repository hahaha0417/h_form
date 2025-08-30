//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <iostream>
#include <filesystem>
//---------------------------------------------------------------------------
#include <include_all.h>
#include <include_all_sub.h>
//---------------------------------------------------------------------------

#include <define\hahaha_define_ha.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <option\hahaha_option.h>
#include <setting\hahaha_setting.h>
//---------------------------------------------------------------------------
#include <form\hahaha_main_form.h>

#include <form\hahaha_option_form.h>
#include <form\hahaha_popup_form.h>
#include <form\hahaha_system_setting_form.h>
#include <form\hahaha_view_form.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <dll\hahaha_load_dll.h>
//---------------------------------------------------------------------------
#include <Vcl.Skia.hpp>
//---------------------------------------------------------------------------


//Application->CreateForm(__classid(Thahaha_form_main), &hahaha_form_main);
//---------------------------------------------------------------------------

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{

	try
	{
		Application->Initialize();

		Application->MainFormOnTaskBar = true;

        Application->CreateForm(__classid(Thahaha_form_main), &hahaha_form_main);




		ha::Initial(hahaha_form_main);
        //---------------------------------------------------------------------------

        //---------------------------------------------------------------------------
        {
            std::wstring dir_name = ExtractFilePath(Application->ExeName).c_str();
            dir_name += L"system_setting\\";
            if(ha::Pointer_Main_->System_Setting_->Load(dir_name) == halib_def::result::FAILURE)
            {
                ha::Pointer_Main_->System_Setting_->Save(dir_name);
            }
        }
		//---------------------------------------------------------------------------

        //---------------------------------------------------------------------------
        {
            std::wstring dir_name = ExtractFilePath(Application->ExeName).c_str();
            dir_name += L"option\\";
            if(ha::Pointer_Main_->Option_->Load(dir_name) == halib_def::result::FAILURE)
            {
                ha::Pointer_Main_->Option_->Save(dir_name);
            }
        }
		//---------------------------------------------------------------------------

        // Dll Plugin
        ha::Pointer_Main_->System_Setting_->Folder_Plugin_ = L"D:\\hahaha\\work\\h_form\\dll";

        ha::Initial_Plugin();



        //---------------------------------------------------------------------------
        ha::Pointer_Main_->Form_Main_ = hahaha_form_main;
        //---------------------------------------------------------------------------
        ha::Structure_Main_->Form_System_Setting_->Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);
        ha::Structure_Main_->Form_Option_->Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);
        ha::Structure_Main_->Form_Popup_->Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);
        //---------------------------------------------------------------------------



		Application->Run();

		ha::Close();
        ha::Close_Plugin();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

