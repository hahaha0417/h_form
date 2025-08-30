//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hahaha_popup_form.h"
//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_base.h>
//---------------------------------------------------------------------------
#include <system_setting\hahaha_system_setting.h>
#include <setting\hahaha_setting.h>
#include <option\hahaha_option.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>
#include <view\scene\hahaha_view_scene_package.h>
#include <view\view\hahaha_view_view_package.h>
#include <view\form\scene\hahaha_view_form_scene.h>
#include <view\form\view\hahaha_view_form_view.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <iostream>
#include <filesystem>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_popup *hahaha_form_popup;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_popup::Thahaha_form_popup(TComponent* Owner)
	: TForm(Owner)
{
    ShowInTaskBar = true;
    //---------------------------------------------------------------------------
	CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

	top_box->BorderStyle = bsNone;
	form_box->BorderStyle = bsNone;
	mode_box->BorderStyle = bsNone;

    MainBox->BorderStyle = bsNone;
    LeftBox->BorderStyle = bsNone;
    model_box->BorderStyle = bsNone;
    mode_box->BorderStyle = bsNone;
    scene_box->BorderStyle = bsNone;
    view_box->BorderStyle = bsNone;
    scene_list->BorderStyle = bsNone;
    view_list->BorderStyle = bsNone;

	top_box->Color = (TColor)RGB(190,255,190);
	form_box->Color = (TColor)RGB(210,255,210);
	mode_box->Color = (TColor)RGB(210,255,210);
    MainBox->Color = (TColor)RGB(210,255,210);
    LeftBox->Color = (TColor)RGB(210,255,210);

    mode_box->Align = alClient;
    view_box->Align = alClient;
    scene_list->Align = alClient;
    view_list->Align = alClient;

    ScrollBox6->Visible = false;
    ScrollBox7->Visible = false;

    scene_bottom_box->BorderStyle = bsNone;
    view_bottom_box->BorderStyle = bsNone;

    DoubleBuffered = true;


    // model_box->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup::button_minClick(TObject *Sender)
{
	PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_maxClick(TObject *Sender)
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

void __fastcall Thahaha_form_popup::button_closeClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_full_screen_1Click(TObject *Sender)
{
	// 一定會有邊框，等c++ builder改
	Structure_Main_->Form_Edit_->CustomTitleBar->Enabled = false;
	Structure_Main_->Form_Edit_->BorderStyle = bsNone;
	Structure_Main_->Form_Image_View_->BottomBox->Visible = false;
	Structure_Main_->Form_Image_View_->Splitter_Bottom->Visible = false;
//	Structure_Main_->Form_Image_View_->view_bottom_box->Visible = false;
//	Structure_Main_->Form_Image_View_->vertical_box->Visible = false;

	Structure_Main_->Form_Edit_->Left = 0;
	Structure_Main_->Form_Edit_->Top = 0;
	Structure_Main_->Form_Edit_->Width = 1920;
	Structure_Main_->Form_Edit_->Height = 1080;


}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_normal_screenClick(TObject *Sender)
{

	Structure_Main_->Form_Edit_->CustomTitleBar->Enabled = true;
	Structure_Main_->Form_Edit_->BorderStyle = bsSizeable;
	Structure_Main_->Form_Image_View_->Splitter_Bottom->Visible = true;
	Structure_Main_->Form_Image_View_->BottomBox->Visible = true;
//	Structure_Main_->Form_Image_View_->view_bottom_box->Visible = true;
//	Structure_Main_->Form_Image_View_->vertical_box->Visible = true;

	Structure_Main_->Form_Edit_->Left = 200;
	Structure_Main_->Form_Edit_->Top = 100;
	Structure_Main_->Form_Edit_->Width = 800;
	Structure_Main_->Form_Edit_->Height = 600;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_full_screen_2Click(TObject *Sender)
{
    // 一定會有邊框，等c++ builder改
    Structure_Main_->Form_Edit_->CustomTitleBar->Enabled = false;
	Structure_Main_->Form_Edit_->BorderStyle = bsNone;
	Structure_Main_->Form_Image_View_->BottomBox->Visible = false;
	Structure_Main_->Form_Image_View_->Splitter_Bottom->Visible = false;
//	Structure_Main_->Form_Image_View_->view_bottom_box->Visible = false;
//	Structure_Main_->Form_Image_View_->vertical_box->Visible = false;

	Structure_Main_->Form_Edit_->Left = 1920;
	Structure_Main_->Form_Edit_->Top = 0;
	Structure_Main_->Form_Edit_->Width = 1920;
	Structure_Main_->Form_Edit_->Height = 1080;

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_scroll_showClick(TObject *Sender)
{
    Structure_Main_->Form_Image_View_->view_bottom_box->Visible = true;
	Structure_Main_->Form_Image_View_->vertical_box->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_scroll_hideClick(TObject *Sender)
{
    Structure_Main_->Form_Image_View_->view_bottom_box->Visible = false;
	Structure_Main_->Form_Image_View_->vertical_box->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_load_imageClick(TObject *Sender)
{
    int rrr = 0;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_optionClick(TObject *Sender)
{
    Structure_Main_->Form_Option_->Show();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_settingClick(TObject *Sender)
{
    Structure_Main_->Form_System_Setting_->Show();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_viewClick(TObject *Sender)
{
    Structure_Main_->Form_View_->Show();
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_popup::button_setting_addClick(TObject *Sender)
{
    // 使用 InputBox 來顯示輸入對話框
    UnicodeString setting_name_ = InputBox(L"新增設定檔", L"請輸入設定檔名：", L"");
    if(setting_name_ != L"")
    {
        //---------------------------------------------------------------------------
        {
            std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
            dir_name_ += L"setting\\" + setting_name_ + L"\\";

            std::wstring file_name_ = dir_name_ + Pointer_Main_->Setting_->File_Name_;

            if (std::filesystem::exists(file_name_))
            {
                ShowMessage(L"設定檔已存在");
                return;
            }

        }
        //---------------------------------------------------------------------------
        
        //---------------------------------------------------------------------------
        {
        	Pointer_Main_->Setting_->Reset();
        	Pointer_Main_->Option_->File_Name_Setting_ = setting_name_.c_str();
            
            std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
            dir_name_ += L"setting\\" + setting_name_ + L"\\";
            
            Pointer_Main_->Setting_->Save(dir_name_);

            Pointer_Main_->Option_->File_Name_Setting_ = setting_name_;
            

            Structure_Main_->Image_View_->View_Ratio_ = 1.0;
            Structure_Main_->Image_View_->Is_View_Scroll_ = true;
            //
           

            Structure_Main_->Image_View_->Bitmap_ = Structure_Main_->Bitmap_Argb_.get();
            Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
            Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(Structure_Main_->Bitmap_Argb_->Width_ - 1 ) / 2,
                (double)(Structure_Main_->Bitmap_Argb_->Height_ - 1 ) / 2
            );

            Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));

            Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
            Structure_Main_->Image_View_->Is_Repaint_ = true;
            Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;

            Structure_Main_->Image_View_->Repaint();

            Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);

        }
        //---------------------------------------------------------------------------

        
    }
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup::Parameter_Mapping(halib_def::parameter_mapping_type type)
{
    if(Is_Update_)
    {
        return halib_def::result::SUCCESS;
    }
    Is_Update_ = true;

    std::vector<hahahalib::hahaha_parameter_mapping_item> items_ = {
        {setting_name, halib_def::vcl_field::ITEM_INDEX, &Pointer_Main_->Option_->File_Name_Setting_, halib_def::type_variable::WSTRING},
    };

    setting_nameDropDown(NULL);
    hahahalib::hahaha_parameter_mapping parameter_mapping_;
    parameter_mapping_.Deal(items_, type);

    Is_Update_ = false;

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_popup::setting_nameDropDown(TObject *Sender)
{
    std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
    dir_name_ += L"setting\\";

    setting_name->Items->BeginUpdate();
    setting_name->Items->Clear();
    if (std::filesystem::exists(dir_name_) && std::filesystem::is_directory(dir_name_))
    {
        for (const auto& item : std::filesystem::directory_iterator(dir_name_))
        {
            if (std::filesystem::is_directory(item))
            {
                setting_name->Items->Add(item.path().filename().wstring().c_str());
                // std::cout << item.path().filename().wstring() << std::endl;
            }
        }
    }
    setting_name->Items->EndUpdate();

    Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::setting_nameChange(TObject *Sender)
{
	//---------------------------------------------------------------------------
    {
        std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
        dir_name_ += (L"setting\\" + setting_name->Text + L"\\").c_str();

        std::wstring file_name_ = dir_name_ + Pointer_Main_->Setting_->File_Name_;

        if (!std::filesystem::exists(file_name_))
        {
            ShowMessage(L"設定檔不存在");
            return;
        }

    }
    //---------------------------------------------------------------------------
        
    //---------------------------------------------------------------------------
    {
        Pointer_Main_->Setting_->Reset();

        std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
        dir_name_ += (L"setting\\" + setting_name->Text + L"\\").c_str();
        if(Pointer_Main_->Setting_->Load(dir_name_) == halib_def::result::FAILURE)
        {
            ShowMessage(L"設定檔載入失敗");

            std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
        	dir_name_ += (L"setting\\" + Pointer_Main_->Option_->File_Name_Setting_ + L"\\").c_str();

            Pointer_Main_->Setting_->Reset();
            Pointer_Main_->Setting_->Load(dir_name_);
        }
        else
        {
        	Pointer_Main_->Option_->File_Name_Setting_ = setting_name->Text.c_str();
        }

        


        Structure_Main_->Image_View_->View_Ratio_ = 1.0;
        Structure_Main_->Image_View_->Is_View_Scroll_ = true;
        //
           

        Structure_Main_->Image_View_->Bitmap_ = Structure_Main_->Bitmap_Argb_.get();
        Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
        Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(Structure_Main_->Bitmap_Argb_->Width_ - 1 ) / 2,
            (double)(Structure_Main_->Bitmap_Argb_->Height_ - 1 ) / 2
        );

        Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));

        Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
        Structure_Main_->Image_View_->Is_Repaint_ = true;
        Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;

        Structure_Main_->Image_View_->Repaint();

        Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);

    }
    //---------------------------------------------------------------------------
    
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_setting_deleteClick(TObject *Sender)
{
	if(Pointer_Main_->Option_->File_Name_Setting_ != L"")
    {
    	std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
        dir_name_ += (L"setting\\" + Pointer_Main_->Option_->File_Name_Setting_ + L"\\").c_str();

    
        if (std::filesystem::exists(dir_name_) && std::filesystem::is_directory(dir_name_))
        {
        	int result = MessageDlg((L"確認是否刪除設定檔 : " + Pointer_Main_->Option_->File_Name_Setting_).c_str(), mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);

    		if (result == mrYes)
            {
            	std::filesystem::remove_all(dir_name_);
                ShowMessage((L"已刪除設定檔 : " + Pointer_Main_->Option_->File_Name_Setting_).c_str());

                Pointer_Main_->Setting_->Reset();
                //---------------------------------------------------------------------------
                {
                    std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
                    dir_name_ += L"setting\\default\\";
                    if(Pointer_Main_->Setting_->Load(dir_name_) == halib_def::result::FAILURE)
                    {
                        Pointer_Main_->Setting_->Save(dir_name_);
                    }
                    Pointer_Main_->Option_->File_Name_Setting_ = L"default";

                    Structure_Main_->Image_View_->View_Ratio_ = 1.0;
                    Structure_Main_->Image_View_->Is_View_Scroll_ = true;
                    //
           

                    Structure_Main_->Image_View_->Bitmap_ = Structure_Main_->Bitmap_Argb_.get();
                    Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
                    Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(Structure_Main_->Bitmap_Argb_->Width_ - 1 ) / 2,
                        (double)(Structure_Main_->Bitmap_Argb_->Height_ - 1 ) / 2
                    );

                    Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));

                    Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
                    Structure_Main_->Image_View_->Is_Repaint_ = true;
                    Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;

                    Structure_Main_->Image_View_->Repaint();

                    setting_nameDropDown(NULL);
                    Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);

                }
                //---------------------------------------------------------------------------       	
            }

        }
    }
    else 
    {
        ShowMessage(L"沒有設定檔");
    }
	
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_setting_renameClick(TObject *Sender)
{
	// 使用 InputBox 來顯示輸入對話框
    UnicodeString setting_name_ = InputBox(L"更名設定檔", L"請輸入新設定檔名：", L"");
    if(setting_name_ != L"")
    {
        //---------------------------------------------------------------------------
        {
            std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
            dir_name_ += L"setting\\" + setting_name_ + L"\\";

            std::wstring file_name_ = dir_name_ + Pointer_Main_->Setting_->File_Name_;

            if (std::filesystem::exists(file_name_))
            {
                ShowMessage(L"新設定檔已存在");
                return;
            }

            
        }
        //---------------------------------------------------------------------------
        
        //---------------------------------------------------------------------------
        {
        	std::wstring dir_name_ = ExtractFilePath(Application->ExeName).c_str();
            dir_name_ += L"setting\\" + Pointer_Main_->Option_->File_Name_Setting_ + L"\\";

            std::wstring file_name_ = dir_name_ + Pointer_Main_->Setting_->File_Name_;
        	if (std::filesystem::exists(dir_name_) && std::filesystem::is_directory(dir_name_))
            {
                std::wstring dir_name_old_ = ExtractFilePath(Application->ExeName).c_str();
            	dir_name_old_ += L"setting\\" + Pointer_Main_->Option_->File_Name_Setting_ + L"\\";

                std::wstring dir_name_new_ = ExtractFilePath(Application->ExeName).c_str();
            	dir_name_new_ += L"setting\\" + setting_name_ + L"\\";
            
            	std::filesystem::rename(dir_name_old_, dir_name_new_);

                //---------------------------------------------------------------------------
                {
                    
                    if(Pointer_Main_->Setting_->Load(dir_name_new_) == halib_def::result::FAILURE)
                    {
                        Pointer_Main_->Setting_->Save(dir_name_new_);
                    }
                    Pointer_Main_->Option_->File_Name_Setting_ = setting_name_;

                    Structure_Main_->Image_View_->View_Ratio_ = 1.0;
                    Structure_Main_->Image_View_->Is_View_Scroll_ = true;
                    //


                    Structure_Main_->Image_View_->Bitmap_ = Structure_Main_->Bitmap_Argb_.get();
                    Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
                    Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(Structure_Main_->Bitmap_Argb_->Width_ - 1 ) / 2,
                        (double)(Structure_Main_->Bitmap_Argb_->Height_ - 1 ) / 2
                    );

                    Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));

                    Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
                    Structure_Main_->Image_View_->Is_Repaint_ = true;
                    Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;

                    Structure_Main_->Image_View_->Repaint();

                    setting_nameDropDown(NULL);
                    Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);

                }
                //---------------------------------------------------------------------------       	
            }
        }

    }
    
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_setting_resetClick(TObject *Sender)
{
	Pointer_Main_->Setting_->Reset();
    //---------------------------------------------------------------------------
    {
        

        Structure_Main_->Image_View_->View_Ratio_ = 1.0;
        Structure_Main_->Image_View_->Is_View_Scroll_ = true;
        //
           

        Structure_Main_->Image_View_->Bitmap_ = Structure_Main_->Bitmap_Argb_.get();
        Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
        Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(Structure_Main_->Bitmap_Argb_->Width_ - 1 ) / 2,
            (double)(Structure_Main_->Bitmap_Argb_->Height_ - 1 ) / 2
        );

        Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));

        Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
        Structure_Main_->Image_View_->Is_Repaint_ = true;
        Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;

        Structure_Main_->Image_View_->Repaint();

        setting_nameDropDown(NULL);
        Parameter_Mapping(halib_def::parameter_mapping_type::PARAMETER_TO_FIELD);

    }
    //---------------------------------------------------------------------------  
    
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_scene_addClick(TObject *Sender)
{
    // 有空再修
    UnicodeString name_ = L"場景";
    Structure_Main_->Form_Popup_Scene_Popup_->Scene_Name->Text = name_;
    Structure_Main_->Form_Popup_Scene_Popup_->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_view_addClick(TObject *Sender)
{
    Structure_Main_->Form_Popup_View_Popup_->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::FormShow(TObject *Sender)
{
    //---------------------------------------------------------------------------

    // 避免title bar 異常
    Width++;
    Width--;



    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_scene_deleteClick(TObject *Sender)
{
    int index_ = -1;
    {
        int n = Pointer_Main_->Setting_->Scenes_.size();


        for(int i = 0; i < n; i++)
        {
            Pointer_Main_->Setting_->Scenes_[i]->Select_ = false;
            if(Pointer_Main_->Select_Scene_ == Pointer_Main_->Setting_->Scenes_[i].get())
            {
                index_ = i;
                break;
            }

        }
    }

    if(index_ != -1)
    {
        Pointer_Main_->Setting_->Delete_Scene(index_);
    }
    Pointer_Main_->Select_Scene_ = NULL;
    {
        int n = Pointer_Main_->Setting_->Scenes_.size();

        for(int i = 0; i < n; i++)
        {
            if(index_ == i)
            {
                Pointer_Main_->Select_Scene_ = Pointer_Main_->Setting_->Scenes_[i].get();
                break;
            }
			else if(index_ == n)
            {
                Pointer_Main_->Select_Scene_ = Pointer_Main_->Setting_->Scenes_[n - 1].get();
                break;
            }
            else
            {
                Pointer_Main_->Select_Scene_ = Pointer_Main_->Setting_->Scenes_[i].get();
                break;
            }
        }
    }

    if(Pointer_Main_->Select_Scene_ != NULL)
    {
        Pointer_Main_->Select_Scene_->Select();
    }


    Update_UI();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_scene_settingClick(TObject *Sender)
{
    Pointer_Main_->Select_Scene_->Set_Parameter();
    Structure_Main_->Form_Popup_Scene_Popup_Setting_->Update_UI();
    Structure_Main_->Form_Popup_Scene_Popup_Setting_->Show();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_scene_upClick(TObject *Sender)
{
    {
        int n = Pointer_Main_->Setting_->Scenes_.size();

        for(int i = 0; i < n; i++)
        {
            if(Pointer_Main_->Select_Scene_ == Pointer_Main_->Setting_->Scenes_[i].get())
            {
                Pointer_Main_->Setting_->Scenes_[i].swap(Pointer_Main_->Setting_->Scenes_[i - 1]);
                break;
            }

        }
    }

    Update_UI();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_scene_downClick(TObject *Sender)
{
    {
        int n = Pointer_Main_->Setting_->Scenes_.size();

        for(int i = 0; i < n; i++)
        {
            if(Pointer_Main_->Select_Scene_ == Pointer_Main_->Setting_->Scenes_[i].get())
            {
                Pointer_Main_->Setting_->Scenes_[i].swap(Pointer_Main_->Setting_->Scenes_[i + 1]);
                break;
            }

        }
    }

    Update_UI();
}
//---------------------------------------------------------------------------

int Thahaha_form_popup::Initial_UI()
{
    {
        int n = Pointer_Main_->Setting_->Scenes_.size();

        for(int i = 0; i < n; i++)
        {
            hahaha::hahaha_view_scene& scene_ = *Pointer_Main_->Setting_->Scenes_[i];
            // 先移出螢幕
            scene_.Package_->Form_Scene_->item_box->Top = 999999;
            scene_.Package_->Form_Scene_->item_box->Parent = Structure_Main_->Form_Popup_->scene_list;
            scene_.Package_->Form_Scene_->item_box->Align = alTop;
            scene_.Package_->Form_Scene_->item_box->AlignWithMargins = True;
            scene_.Package_->Form_Scene_->label_name->Caption = scene_.Name_.c_str();
            scene_.Package_->Form_Scene_->Scene_ = Pointer_Main_->Setting_->Scenes_[i].get();



        }

        if(n != 0)
        {
            Pointer_Main_->Setting_->Scenes_[0]->Select();
        }
    }


    return 0;
}
//---------------------------------------------------------------------------
int Thahaha_form_popup::Update_UI()
{

    {
        int n = Pointer_Main_->Setting_->Scenes_.size();

        button_scene_delete->Enabled = Pointer_Main_->Select_Scene_ != NULL;
        button_scene_setting->Enabled = Pointer_Main_->Select_Scene_ != NULL;

        if(n == 0)
        {
            button_scene_up->Enabled = false;
            button_scene_down->Enabled = false;
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(Pointer_Main_->Select_Scene_ == Pointer_Main_->Setting_->Scenes_[i].get())
                {
                    button_scene_up->Enabled = i != 0;
                    button_scene_down->Enabled = i != n - 1;
                }

            }
        }
    }

    scene_list->VertScrollBar->Visible = false;
    {
        int n = Pointer_Main_->Setting_->Scenes_.size();

        for(int i = 0; i < n; i++)
        {
            Pointer_Main_->Setting_->Scenes_[i]->Package_->Form_Scene_->item_box->Top = 999999;
            Pointer_Main_->Setting_->Scenes_[i]->Package_->Form_Scene_->item_box->Align = alTop;

        }
    }
    scene_list->VertScrollBar->Visible = true;
    //---------------------------------------------------------------------------
    if(Pointer_Main_->Select_Scene_ != NULL)
    {
        button_view_add->Enabled = Pointer_Main_->Select_Scene_ != NULL;

        {
            int n = Pointer_Main_->Select_Scene_->Views_.size();

            button_view_delete->Enabled = Pointer_Main_->Select_View_ != NULL;
            button_view_setting->Enabled = Pointer_Main_->Select_View_ != NULL;

            if(n == 0)
            {
                button_view_up->Enabled = false;
                button_view_down->Enabled = false;
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    if(Pointer_Main_->Select_View_ == Pointer_Main_->Select_Scene_->Views_[i].get())
                    {
                        button_view_up->Enabled = i != 0;
                        button_view_down->Enabled = i != n - 1;
                    }

                }
            }
        }

        view_list->VertScrollBar->Visible = false;
        {
            int n = Pointer_Main_->Select_Scene_->Views_.size();

            for(int i = 0; i < n; i++)
            {
                ((TScrollBox*)Pointer_Main_->Select_Scene_->Views_[i]->Package_->Form_View_->item_box)->Top = 999999;
                ((TScrollBox*)Pointer_Main_->Select_Scene_->Views_[i]->Package_->Form_View_->item_box)->Align = alTop;

            }
        }
    }
    else
    {
        button_view_add->Enabled = false;
        button_view_delete->Enabled = false;
        button_view_setting->Enabled = false;
        button_view_up->Enabled = false;
    	button_view_down->Enabled = false;
    }



    //---------------------------------------------------------------------------

	return 0;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result Thahaha_form_popup::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------



void __fastcall Thahaha_form_popup::button_view_deleteClick(TObject *Sender)
{
    int index_ = -1;
    {
        int n = Pointer_Main_->Select_Scene_->Views_.size();


        for(int i = 0; i < n; i++)
        {
            Pointer_Main_->Select_Scene_->Views_[i]->Select_ = false;
            if(Pointer_Main_->Select_View_ == Pointer_Main_->Select_Scene_->Views_[i].get())
            {
                index_ = i;
                break;
            }

        }
    }

    if(index_ != -1)
    {
        Pointer_Main_->Select_Scene_->Delete_View(index_);
    }
    Pointer_Main_->Select_View_ = NULL;
    {
        int n = Pointer_Main_->Select_Scene_->Views_.size();

        for(int i = 0; i < n; i++)
        {
            if(index_ == i)
            {
                Pointer_Main_->Select_View_ = Pointer_Main_->Select_Scene_->Views_[i].get();
                break;
            }
			else if(index_ == n)
            {
                Pointer_Main_->Select_View_ = Pointer_Main_->Select_Scene_->Views_[n - 1].get();
                break;
            }
            else
            {
                Pointer_Main_->Select_View_ = Pointer_Main_->Select_Scene_->Views_[i].get();
                break;
            }
        }
    }

    if(Pointer_Main_->Select_View_ != NULL)
    {
        Pointer_Main_->Select_View_->Select();
    }


    Update_UI();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_view_settingClick(TObject *Sender)
{
    Pointer_Main_->Select_View_->Set_Parameter();
    Structure_Main_->Form_Popup_View_Popup_Setting_->Update_UI();
    Structure_Main_->Form_Popup_View_Popup_Setting_->Show();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_view_upClick(TObject *Sender)
{
    {
        int n = Pointer_Main_->Select_Scene_->Views_.size();

        for(int i = 0; i < n; i++)
        {
            if(Pointer_Main_->Select_View_ == Pointer_Main_->Select_Scene_->Views_[i].get())
            {
                Pointer_Main_->Select_Scene_->Views_[i].swap(Pointer_Main_->Select_Scene_->Views_[i - 1]);
                break;
            }

        }
    }

    Update_UI();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_popup::button_view_downClick(TObject *Sender)
{
    {
        int n = Pointer_Main_->Select_Scene_->Views_.size();

        for(int i = 0; i < n; i++)
        {
            if(Pointer_Main_->Select_View_ == Pointer_Main_->Select_Scene_->Views_[i].get())
            {
                Pointer_Main_->Select_Scene_->Views_[i].swap(Pointer_Main_->Select_Scene_->Views_[i + 1]);
                break;
            }

        }
    }

    Update_UI();
}
//---------------------------------------------------------------------------

