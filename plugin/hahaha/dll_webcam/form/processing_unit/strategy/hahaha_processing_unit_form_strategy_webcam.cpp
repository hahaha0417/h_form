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
#include <capture\webcam\hahaha_capture_webcam_direct_show_origin_ha.h>
#include <image_view\hahaha_image_view_base.h>
#include <thread\hahaha_thread_command_webcam_ha.h>
#include <thread_pool\hahaha_thread_pool_time_set_event_timer_webcam_ha.h>
#include <image_process\color\hahaha_image_process_color.h>
#include <image_process_composite\color\hahaha_image_process_composite_color.h>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
#include <lock\hahaha_mutex.h>
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
	flip_vertical_box->Color = (TColor)RGB(210,255,210);

    BodyBox->BorderStyle = bsNone;

    main_box->BorderStyle = bsNone;

    
    camera_box->BorderStyle = bsNone;
    enabled_box->BorderStyle = bsNone;
    resolution_box->BorderStyle = bsNone;
    fps_box->BorderStyle = bsNone;
	direction_box->BorderStyle = bsNone;
	flip_vertical_box->BorderStyle = bsNone;

	view_box->BorderStyle = bsNone;


    if(Webcam_Direct_Show_Origin_.get() == NULL)
	{
		Webcam_Direct_Show_Origin_.reset(new hahaha::hahaha_capture_webcam_direct_show_origin_ha());
	}
    Webcam_Direct_Show_Origin_->Mutex_->Create();

    Is_Update_ = false;

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
    if(Is_Update_)
    {
        return;
    }
    if(open_dialog_image->Execute())
    {
        // 硂璶玡
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
	if(Is_Update_)
	{
        return;
    }

	ha::Pointer_Main_->Select_View_->Get_Parameter();

	ha::Image_View_Ha_->View_Direction_ = (halib_def::image_view_view_direction)(combo_box_direction->ItemIndex + 1);
    ha::Image_View_Ha_->Is_View_Bitmap_Full_ = true;
	// 硂柑琌琌本更Bitmap本更紇钩
	ha::Image_View_Ha_->Bitmap_ = ha::Bitmap_Argb_Ha_.get();
	ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
	ha::Image_View_Ha_->Is_Repaint_ = true;
	ha::Image_View_Ha_->Is_Invalidate_View_Image_ = true;
	ha::Image_View_Ha_->Repaint();
}
//---------------------------------------------------------------------------


void __fastcall Thahaha_form_processing_unit_strategy_webcam::button_camera_refreshClick(TObject *Sender)

{
	Is_Update_ = true;

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
		// ----------------------------------------------------------
        std::vector<hahahalib::hahaha_capture_webcam_direct_show_item> format_temp_;
		strategy_->Format_.clear();

		hahahalib::hahaha_capture_webcam_direct_show_origin direct_show_;
		direct_show_.Open(combo_box_camera->ItemIndex, 1280, 720);
		direct_show_.List_Format(format_temp_);

        std::copy_if(format_temp_.begin(), format_temp_.end(), std::back_inserter(strategy_->Format_),
            [](auto& x){
                return x.Sub_Type_ == MEDIASUBTYPE_YUY2;
            }
        );

		std::sort(strategy_->Format_.begin(), strategy_->Format_.end(),
            [](const auto& a, const auto& b)
            {
                // 1) 秆猂钩计
                int pixels_a = a.Width_ * a.Height_;
                int pixels_b = b.Width_ * b.Height_;
                if (pixels_a != pixels_b)
                    return pixels_a > pixels_b;

                // 2) FPS
                if (a.Fps_ != b.Fps_)
                    return a.Fps_ > b.Fps_;

                // 3) Α纔抖
                auto score = [](const GUID& g)
                {
                    if (g == MEDIASUBTYPE_YUY2) return 3;
                    if (g == MEDIASUBTYPE_MJPG) return 2;
                    if (g == MEDIASUBTYPE_RGB24) return 1;
                    return 0;
                };

                return score(a.Sub_Type_) > score(b.Sub_Type_);
            }
        );
        // ----------------------------------------------------------

		int m = strategy_->Format_.size();

		combo_box_resolution->Items->BeginUpdate();
		combo_box_resolution->Clear();
		for(int i = 0; i < m; i++)
		{

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

	Is_Update_ = false;

	combo_box_enabled->ItemIndex = 1;


}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_enabledChange(TObject *Sender)

{
	if(Is_Update_)
	{
		return;
	}
    Is_Update_ = true;

    Webcam_Direct_Show_Origin_->Mutex_->Lock();

    ha::Pointer_Main_->Select_View_->Get_Parameter();

    hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;




	if(combo_box_enabled->ItemIndex == 0)
	{

		if(Webcam_Direct_Show_Origin_->Is_Open_)
		{
		}
		else
		{
			int period_ = (int)(1000.0 / combo_box_fps->Text.ToInt());

			Webcam_Direct_Show_Origin_->Open(combo_box_camera->ItemIndex,
				strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
				strategy_->Format_[combo_box_resolution->ItemIndex].Height_,
				strategy_->Format_[combo_box_resolution->ItemIndex].Fps_
			);

			if(Webcam_Direct_Show_Origin_->Is_Open_)
			{
            	ha::Bitmap_Yuy2_Ha_->Resize(strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
					strategy_->Format_[combo_box_resolution->ItemIndex].Height_
				);
				ha::Bitmap_Argb_Ha_->Resize(strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
					strategy_->Format_[combo_box_resolution->ItemIndex].Height_
				);
				Webcam_Direct_Show_Origin_->Flip_ = combo_box_flip_vertical->ItemIndex == 0 ? false : true;

				ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Webcam_ = Webcam_Direct_Show_Origin_.get();

	

				ha::Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));
                ha::Structure_Main_->Image_View_->Bitmap_ = ha::Bitmap_Argb_Ha_.get();
                ha::Structure_Main_->Image_View_->Is_View_Scroll_ = true;
                ha::Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
                ha::Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
                ha::Structure_Main_->Image_View_->Is_Repaint_ = true;
                ha::Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;
                ha::Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(ha::Bitmap_Argb_Ha_->Width_ - 1 ) / 2,
                    (double)(ha::Bitmap_Argb_Ha_->Height_ - 1 ) / 2
                );

                ha::Structure_Main_->Image_View_->Repaint();

                Webcam_Direct_Show_Origin_->Start();

				ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Create(0, period_);

			}





		}
	}
	else if(combo_box_enabled->ItemIndex == 1)
	{
		if(Webcam_Direct_Show_Origin_->Is_Open_)
		{
            ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Close();
            ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Webcam_ = NULL;
            
			Webcam_Direct_Show_Origin_->Stop();
			Webcam_Direct_Show_Origin_->Close();

		}
		else
		{
		}
	}
    Webcam_Direct_Show_Origin_->Mutex_->Un_Lock();

    Is_Update_ = false;
	
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_cameraChange(TObject *Sender)

{
	if(Is_Update_)
	{
		return;
	}
    Is_Update_ = true;
    Webcam_Direct_Show_Origin_->Mutex_->Lock();

	ha::Pointer_Main_->Select_View_->Get_Parameter();

	if(combo_box_camera->ItemIndex >= 0 )
	{
		hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;
        // ----------------------------------------------------------
        std::vector<hahahalib::hahaha_capture_webcam_direct_show_item> format_temp_;
		strategy_->Format_.clear();

		hahahalib::hahaha_capture_webcam_direct_show_origin direct_show_;
		direct_show_.Open(combo_box_camera->ItemIndex, 1280, 720);
		direct_show_.List_Format(format_temp_);

        std::copy_if(format_temp_.begin(), format_temp_.end(), std::back_inserter(strategy_->Format_),
            [](auto& x){
                return x.Sub_Type_ == MEDIASUBTYPE_YUY2;
            }
        );

		std::sort(strategy_->Format_.begin(), strategy_->Format_.end(),
            [](const auto& a, const auto& b)
            {
                // 1) 秆猂钩计
                int pixels_a = a.Width_ * a.Height_;
                int pixels_b = b.Width_ * b.Height_;
                if (pixels_a != pixels_b)
                    return pixels_a > pixels_b;

                // 2) FPS
                if (a.Fps_ != b.Fps_)
                    return a.Fps_ > b.Fps_;

                // 3) Α纔抖
                auto score = [](const GUID& g)
                {
                    if (g == MEDIASUBTYPE_YUY2) return 3;
                    if (g == MEDIASUBTYPE_MJPG) return 2;
                    if (g == MEDIASUBTYPE_RGB24) return 1;
                    return 0;
                };

                return score(a.Sub_Type_) > score(b.Sub_Type_);
            }
        );
        // ----------------------------------------------------------

		int m = strategy_->Format_.size();

		combo_box_resolution->Items->BeginUpdate();
		combo_box_resolution->Clear();
		for(int i = 0; i < m; i++)
		{

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

    Webcam_Direct_Show_Origin_->Mutex_->Lock();

    Is_Update_ = false;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::button_testClick(TObject *Sender)

{
    Webcam_Direct_Show_Origin_->Mutex_->Lock();
	if(Webcam_Direct_Show_Origin_->Is_Open_)
	{
		Webcam_Direct_Show_Origin_->Grab(*ha::Bitmap_Yuy2_Ha_);



        hahahalib::bitmap_alloc_yvyu bitmap_temp_yvyu_;
        bitmap_temp_yvyu_.Resize(ha::Bitmap_Yuy2_Ha_->Width_, ha::Bitmap_Yuy2_Ha_->Height_);

        halib_image::color::YUY2_To_YVYU(
            *ha::Bitmap_Yuy2_Ha_,
            halib::roi(0, 0, ha::Bitmap_Yuy2_Ha_->Width_ - 1, ha::Bitmap_Yuy2_Ha_->Height_ - 1),
            bitmap_temp_yvyu_,
            halib::roi(0, 0, bitmap_temp_yvyu_.Width_ - 1, bitmap_temp_yvyu_.Height_ - 1)
        );

        halib_image::color::YUV422_To_ARGB(
            bitmap_temp_yvyu_,
            halib::roi(0, 0, bitmap_temp_yvyu_.Width_ - 1, bitmap_temp_yvyu_.Height_ - 1),
            *ha::Bitmap_Argb_Ha_,
            halib::roi(0, 0, ha::Bitmap_Argb_Ha_->Width_ - 1, ha::Bitmap_Argb_Ha_->Height_ - 1)
        );



        // 硂柑琌琌本更Bitmap本更紇钩
		ha::Image_View_Ha_->Bitmap_ = ha::Bitmap_Argb_Ha_.get();
		ha::Image_View_Ha_->Image_Center_ = halib::point_double((double)(ha::Bitmap_Argb_Ha_->Width_ - 1 ) / 2,
			(double)(ha::Bitmap_Argb_Ha_->Height_ - 1 ) / 2
		);

		ha::Image_View_Ha_->Background_Color_ = TColor(RGB(60, 60, 60));

		ha::Image_View_Ha_->Is_View_Bitmap_Full_ = true;
		ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
		ha::Image_View_Ha_->Is_Repaint_ = true;
		ha::Image_View_Ha_->Is_Repaint_View_Image_ = true;
        ha::Image_View_Ha_->Is_View_Bitmap_Full_ = true;

		ha::Image_View_Ha_->Repaint();


	}
    Webcam_Direct_Show_Origin_->Mutex_->Un_Lock();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_resolutionChange(TObject *Sender)

{
    if(Is_Update_)
	{
		return;
	}
    Is_Update_ = true;

    Webcam_Direct_Show_Origin_->Mutex_->Lock();

    {
        hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;

        combo_box_fps->Items->BeginUpdate();
        combo_box_fps->Clear();
        for(int i = strategy_->Format_[combo_box_resolution->ItemIndex].Fps_; i > 0; i--)
        {
            combo_box_fps->Items->Add(std::to_wstring(i).c_str());
        }
        combo_box_fps->Items->EndUpdate();

        combo_box_fps->ItemIndex = 0;
    }

	ha::Pointer_Main_->Select_View_->Get_Parameter();

    if(Webcam_Direct_Show_Origin_->Is_Open_)
	{
        hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;

		int period_ = (int)(1000.0 / combo_box_fps->Text.ToInt());
		ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Close();

		Webcam_Direct_Show_Origin_->Stop();
		Webcam_Direct_Show_Origin_->Close();


		Webcam_Direct_Show_Origin_->Open(combo_box_camera->ItemIndex,
			strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
			strategy_->Format_[combo_box_resolution->ItemIndex].Height_,
            strategy_->Format_[combo_box_resolution->ItemIndex].Fps_
		);



		if(Webcam_Direct_Show_Origin_->Is_Open_)
		{
        int rrr = combo_box_resolution->ItemIndex;
			ha::Bitmap_Yuy2_Ha_->Resize(strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
                strategy_->Format_[combo_box_resolution->ItemIndex].Height_
            );
            ha::Bitmap_Argb_Ha_->Resize(strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
                strategy_->Format_[combo_box_resolution->ItemIndex].Height_
            );
			Webcam_Direct_Show_Origin_->Flip_ = combo_box_flip_vertical->ItemIndex == 0 ? false : true;

			ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Webcam_ = Webcam_Direct_Show_Origin_.get();

			// 硂柑琌琌本更Bitmap本更紇钩


			ha::Structure_Main_->Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));
            ha::Structure_Main_->Image_View_->Bitmap_ = ha::Bitmap_Argb_Ha_.get();
			ha::Structure_Main_->Image_View_->Is_View_Scroll_ = true;
			ha::Structure_Main_->Image_View_->Is_View_Bitmap_Full_ = true;
			ha::Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
			ha::Structure_Main_->Image_View_->Is_Repaint_ = true;
			ha::Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;
            ha::Structure_Main_->Image_View_->Image_Center_ = halib::point_double((double)(ha::Bitmap_Argb_Ha_->Width_ - 1 ) / 2,
                (double)(ha::Bitmap_Argb_Ha_->Height_ - 1 ) / 2
            );

			ha::Structure_Main_->Image_View_->Repaint();

			ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Create(0, period_);
            Webcam_Direct_Show_Origin_->Start();
		}


	}

    Webcam_Direct_Show_Origin_->Mutex_->Un_Lock();

    Is_Update_ = false;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_fpsChange(TObject *Sender)

{
	if(Is_Update_)
	{
		return;
	}
    Is_Update_ = true;

    Webcam_Direct_Show_Origin_->Mutex_->Lock();


	ha::Pointer_Main_->Select_View_->Get_Parameter();

    if(Webcam_Direct_Show_Origin_->Is_Open_)
	{
        hahaha::hahaha_processing_unit_strategy_webcam* strategy_ = (hahaha::hahaha_processing_unit_strategy_webcam*)ha::Pointer_Main_->Select_View_->Processing_Unit_->Processing_Unit_Strategy_;

		int period_ = (int)(1000.0 / combo_box_fps->Text.ToInt());
		ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Close();

		Webcam_Direct_Show_Origin_->Stop();
		Webcam_Direct_Show_Origin_->Close();


		Webcam_Direct_Show_Origin_->Open(combo_box_camera->ItemIndex,
			strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
			strategy_->Format_[combo_box_resolution->ItemIndex].Height_,
            strategy_->Format_[combo_box_resolution->ItemIndex].Fps_
		);

		if(Webcam_Direct_Show_Origin_->Is_Open_)
		{
			ha::Bitmap_Yuy2_Ha_->Resize(strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
                strategy_->Format_[combo_box_resolution->ItemIndex].Height_
            );
            ha::Bitmap_Argb_Ha_->Resize(strategy_->Format_[combo_box_resolution->ItemIndex].Width_,
                strategy_->Format_[combo_box_resolution->ItemIndex].Height_
            );
			Webcam_Direct_Show_Origin_->Flip_ = combo_box_flip_vertical->ItemIndex == 0 ? false : true;

			ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Webcam_ = Webcam_Direct_Show_Origin_.get();

			// 硂柑琌琌本更Bitmap本更紇钩
			ha::Image_View_Ha_->Image_Center_ = halib::point_double((double)(ha::Bitmap_Argb_Ha_->Width_ - 1 ) / 2,
				(double)(ha::Bitmap_Argb_Ha_->Height_ - 1 ) / 2
			);

			ha::Image_View_Ha_->Background_Color_ = TColor(RGB(60, 60, 60));

			ha::Image_View_Ha_->Is_View_Bitmap_Full_ = true;
			ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
			ha::Image_View_Ha_->Is_Repaint_ = true;
			ha::Image_View_Ha_->Is_Invalidate_View_Image_ = true;
            ha::Image_View_Ha_->Image_Center_ = halib::point_double((double)(ha::Bitmap_Argb_Ha_->Width_ - 1 ) / 2,
                (double)(ha::Bitmap_Argb_Ha_->Height_ - 1 ) / 2
            );
			ha::Image_View_Ha_->Repaint();

			ha::Thread_Pool_Time_Set_Event_Timer_Webcam_Ha_->Create(0, period_);
            Webcam_Direct_Show_Origin_->Start();
		}


	}

    Webcam_Direct_Show_Origin_->Mutex_->Un_Lock();

    Is_Update_ = false;
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_form_processing_unit_strategy_webcam::combo_box_flip_verticalChange(TObject *Sender)

{
	if(Is_Update_)
	{
		return;
	}
    Is_Update_ = true;

    Webcam_Direct_Show_Origin_->Mutex_->Lock();

	ha::Pointer_Main_->Select_View_->Get_Parameter();

	if(Webcam_Direct_Show_Origin_->Is_Open_)
	{

		Webcam_Direct_Show_Origin_->Flip_ = combo_box_flip_vertical->ItemIndex == 0 ? false : true;


		ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
		ha::Image_View_Ha_->Is_Repaint_ = true;
		ha::Image_View_Ha_->Is_Invalidate_View_Image_ = true;
        ha::Image_View_Ha_->Image_Center_ = halib::point_double((double)(ha::Bitmap_Argb_Ha_->Width_ - 1 ) / 2,
            (double)(ha::Bitmap_Argb_Ha_->Height_ - 1 ) / 2
        );
		ha::Image_View_Ha_->Repaint();
	}
    Is_Update_ = false;

    Webcam_Direct_Show_Origin_->Mutex_->Un_Lock();
}
//---------------------------------------------------------------------------

