//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <define\hahaha_define_ho.h>
//---------------------------------------------------------------------------
#include <view\view\hahaha_view_view_package.h>
#include <view\form\view\hahaha_view_form_view.h>
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>
#include <information\hahaha_information_webcam.h>
#include <information\webcam\hahaha_information_webcam_item.h>
#include "hahaha_processing_unit_form_strategy_webcam.h"
#include <processing_unit\strategy\hahaha_processing_unit_strategy_webcam.h>
#include <capture\webcam\hahaha_capture_webcam_direct_show.h>
//---------------------------------------------------------------------------
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
#include <capture\webcam\hahaha_capture_webcam_direct_show.h>
#include <image_view\hahaha_image_view_base.h>
#include <thread\hahaha_thread_command_webcam_ha.h>
#include <thread_pool\hahaha_thread_pool_time_set_event_timer_webcam_ha.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thahaha_form_processing_unit_strategy_webcam *hahaha_form_processing_unit_strategy_webcam;
//---------------------------------------------------------------------------
__fastcall Thahaha_form_processing_unit_strategy_webcam::Thahaha_form_processing_unit_strategy_webcam(TComponent* Owner)
	: TForm(Owner)
{
    CustomTitleBar->BackgroundColor = (TColor)RGB(210,255,210);
	BodyBox->Color = (TColor)RGB(210,255,210);
    main_box->Color = (TColor)RGB(210,255,210);

    camera_box->Color = (TColor)RGB(210,255,210);
    enabled_box->Color = (TColor)RGB(210,255,210);
    resolution_box->Color = (TColor)RGB(210,255,210);
    fps_box->Color = (TColor)RGB(210,255,210);
	direction_box->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

    main_box->BorderStyle = bsNone;

    
    camera_box->BorderStyle = bsNone;
    enabled_box->BorderStyle = bsNone;
    resolution_box->BorderStyle = bsNone;
    fps_box->BorderStyle = bsNone;
	direction_box->BorderStyle = bsNone;

	view_box->BorderStyle = bsNone;


    if(Webcam_Direct_Show_.get() == NULL)
	{
		Webcam_Direct_Show_.reset(new hahahalib::hahaha_capture_webcam_direct_show());
	}

    Is_Update = false;

}
//---------------------------------------------------------------------------
void __fastcall Thahaha_form_processing_unit_strategy_webcam::button_minClick(TObject *Sender)

{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::button_maxClick(TObject *Sender)

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

void __fastcall Thahaha_form_processing_unit_strategy_webcam::button_closeClick(TObject *Sender)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::text_image_pathDblClick(TObject *Sender)

{
    if(Is_Update)
    {
        return;
    }
    if(open_dialog_image->Execute())
    {
        // 這要在前
//        text_image_path->Text = open_dialog_image->FileName;
		ha::Pointer_Main_->Select_View_->Get_Parameter();
    }
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_processing_unit_strategy_webcam::check_fix_ratioClick(TObject *Sender)

{
    ha::Pointer_Main_->Select_View_->Get_Parameter();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_directionChange(TObject *Sender)

{
    if(Is_Update)
    {
        return;
    }

	ha::Pointer_Main_->Select_View_->Get_Parameter();
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_processing_unit_strategy_webcam::button_camera_refreshClick(TObject *Sender)

{
	Is_Update = true;

	combo_box_camera->Items->BeginUpdate();
	combo_box_camera->Clear();
	int n = ha::Structure_Main_->Information_Webcam_->Webcams_.size();
	for(int i = 0; i < n; i++)
	{
		combo_box_camera->Items->Add(ha::Structure_Main_->Information_Webcam_->Webcams_[i].Name_Device_.c_str());
	}
	combo_box_camera->ItemIndex = 0;

	combo_box_camera->Items->EndUpdate();

	hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;

	if(n > 0)
	{
        strategy_->Format_.clear();
		CoInitializeEx(NULL, COINIT_MULTITHREADED);
		hahahalib::hahaha_capture_webcam_direct_show direct_show_;
		direct_show_.Open(0, 1280, 720);
		direct_show_.List_Format(strategy_->Format_);

		std::sort(strategy_->Format_.begin(), strategy_->Format_.end(),
			[](const hahahalib::hahaha_capture_webcam_direct_show_item& a, const hahahalib::hahaha_capture_webcam_direct_show_item& b)
			{
				return a.Width_ > b.Width_;
			}
		);

		int m = strategy_->Format_.size();

		combo_box_resolution->Items->BeginUpdate();
		combo_box_resolution->Clear();
		for(int i = 0; i < m; i++)
		{
			if(strategy_->Format_[i].Sub_Type_ != MEDIASUBTYPE_YUY2)
			{
				continue;
			}
			combo_box_resolution->Items->Add(strategy_->Format_[i].Description_.c_str());
		}
		combo_box_resolution->Items->EndUpdate();

		combo_box_resolution->ItemIndex = 0;



		combo_box_fps->Items->BeginUpdate();
		combo_box_fps->Clear();
		for(int i = strategy_->Format_[combo_box_resolution->ItemIndex].Fps_; i > 0; i--)
		{
			combo_box_fps->Items->Add(std::to_wstring(i).c_str());
		}
		combo_box_fps->Items->EndUpdate();

		combo_box_fps->ItemIndex = 0;

		direct_show_.Close();
		CoInitializeEx(NULL, COINIT_MULTITHREADED);
	}

	Is_Update = false;

	combo_box_enabled->ItemIndex = 1;


}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_enabledChange(TObject *Sender)

{
	if(Is_Update)
	{
		return;
	}

    hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;




	if(combo_box_enabled->ItemIndex == 0)
	{

		if(Webcam_Direct_Show_->Is_Open_)
		{
		}
		else
		{
            int period_ = (int)(1000.0 / combo_box_fps->Text.ToInt());

			Webcam_Direct_Show_->Open(combo_box_camera->ItemIndex,
                strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
				strategy_->Format_[combo_box_resolution->ItemIndex].Height_
			);

			if(Webcam_Direct_Show_->Is_Open_)
			{
                ha::Bitmap_Argb_Ha_->Resize(strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
					strategy_->Format_[combo_box_resolution->ItemIndex].Height_
				);
                Webcam_Direct_Show_->Flip_ = true;
				Webcam_Direct_Show_->Start();
                ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Webcam_ = Webcam_Direct_Show_.get();

            	ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Create(0, period_);

			}





		}
	}
	else if(combo_box_enabled->ItemIndex == 1)
	{
		if(Webcam_Direct_Show_->Is_Open_)
		{
            ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Close();
            ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Webcam_ = NULL;
            
			Webcam_Direct_Show_->Stop();
			Webcam_Direct_Show_->Close();

		}
		else
		{
		}
	}

	
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_cameraChange(TObject *Sender)

{
    if(Is_Update)
	{
		return;
	}

    if(combo_box_camera->ItemIndex >= 0 )
	{
		hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;

		strategy_->Format_.clear();

		hahahalib::hahaha_capture_webcam_direct_show direct_show_;
		direct_show_.Open(combo_box_camera->ItemIndex, 1280, 720);
		direct_show_.List_Format(strategy_->Format_);

		std::sort(strategy_->Format_.begin(), strategy_->Format_.end(),
			[](const hahahalib::hahaha_capture_webcam_direct_show_item& a, const hahahalib::hahaha_capture_webcam_direct_show_item& b)
			{
				return a.Width_ > b.Width_;
			}
		);


		int m = strategy_->Format_.size();

		combo_box_resolution->Items->BeginUpdate();
		combo_box_resolution->Clear();
		for(int i = 0; i < m; i++)
		{
			if(strategy_->Format_[i].Sub_Type_ != MEDIASUBTYPE_YUY2)
			{
				continue;
			}
			combo_box_resolution->Items->Add(strategy_->Format_[i].Description_.c_str());
		}
		combo_box_resolution->Items->EndUpdate();

		combo_box_resolution->ItemIndex = 0;



		combo_box_fps->Items->BeginUpdate();
		combo_box_fps->Clear();
		for(int i = strategy_->Format_[combo_box_resolution->ItemIndex].Fps_; i > 0; i--)
		{
			combo_box_fps->Items->Add(std::to_wstring(i).c_str());
		}
		combo_box_fps->Items->EndUpdate();

		combo_box_fps->ItemIndex = 0;

		direct_show_.Close();

	}
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::button_testClick(TObject *Sender)

{
	if(Webcam_Direct_Show_->Is_Open_)
	{
		Webcam_Direct_Show_->Grab(*ha::Bitmap_Argb_Ha_);
		ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
		ha::Image_View_Ha_->Is_Repaint_ = true;
		ha::Image_View_Ha_->Is_Invalidate_View_Image_ = true;
		ha::Image_View_Ha_->Repaint();


	}
}
//---------------------------------------------------------------------------

