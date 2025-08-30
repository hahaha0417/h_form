//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_main_form.h"
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view.h>
//---------------------------------------------------------------------------
#include <form\hahaha_option_form.h>
#include <form\hahaha_popup_form.h>
#include <form\hahaha_system_setting_form.h>
#include <form\hahaha_edit_form.h>
#include <form\hahaha_view_form.h>
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
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"

Thahaha_form_main *hahaha_form_main;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_main::Thahaha_form_main(TComponent* Owner)
	: TForm(Owner)
{
    RegisterClass(__classid(Thahaha_form_main));
	CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_main::button_minClick(TObject *Sender)
{
	PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_main::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_main::button_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_main::FormShow(TObject *Sender)
{
	// ha::Form_Image_View_->MainBox->Parent = ha::Form_Main_->BodyBox;



    //---------------------------------------------------------------------------

    // 避免title bar 異常
    Width++;
    Width--;



    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    {
        std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
        dir_name_ += L"setting\\" + Pointer_Main_->Option_->File_Name_Setting_ + L"\\";
        if(Pointer_Main_->Setting_->Load(dir_name_) == halib_def::result::FAILURE)
        {
            Pointer_Main_->Setting_->Save(dir_name_);
        }
        // 載入初始化
        Pointer_Main_->Setting_->Load_Initial();

        if(Pointer_Main_->Setting_->Scenes_.size() != 0)
        {
            Pointer_Main_->Setting_->Scenes_[0]->Select();
            if(Pointer_Main_->Setting_->Scenes_[0]->Views_.size() != 0)
            {
                Pointer_Main_->Setting_->Scenes_[0]->Views_[0]->Select();
            }
        }

    }
    //---------------------------------------------------------------------------
    Structure_Main_->Form_Popup_->Initial_UI();
    //---------------------------------------------------------------------------
    PostMessage(Handle, MESSAGE_EDIT_FORM_SHOW, 0, 0);
    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_main::popup_menuPopup(TObject *Sender)
{
    Structure_Main_->Form_Popup_->Update_UI();
    Structure_Main_->Form_Popup_->Show();
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_main::FormCloseQuery(TObject *Sender, bool &CanClose)

{
    int result = MessageDlg(L"確定要關閉應用程式嗎？", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);

    if (result == mrYes)
    {
        CanClose = true;  // 允許關閉
    }
    else
    {
        CanClose = false; // 取消關閉
    }

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_main::FormClose(TObject *Sender, TCloseAction &Action)

{
    //---------------------------------------------------------------------------
	{
        std::wstring dir_name = ExtractFilePath(Application->ExeName).c_str();
		dir_name += L"setting\\" + Pointer_Main_->Option_->File_Name_Setting_ + L"\\";
		Pointer_Main_->Setting_->Save(dir_name);
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    {
        std::wstring dir_name = ExtractFilePath(Application->ExeName).c_str();
        dir_name += L"option\\";
        Pointer_Main_->Option_->Save(dir_name);
    }
    //---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
    {
        std::wstring dir_name = ExtractFilePath(Application->ExeName).c_str();
        dir_name += L"system_setting\\";
        Pointer_Main_->System_Setting_->Save(dir_name);
    }
	//---------------------------------------------------------------------------

	std::vector<std::unique_ptr<hahaha::hahaha_view_scene>>().swap(Pointer_Main_->Setting_->Scenes_);


}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_main::On_Message(TMessage& message)
{
    switch (message.Msg) {
        case MESSAGE_EDIT_FORM_SHOW:
		{
            Structure_Main_->Form_Edit_->Show();

			break;
        }
        default:
        {
            TForm::WndProc(message);  // Default handling
        }

    }
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_main::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
	Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_main::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------




