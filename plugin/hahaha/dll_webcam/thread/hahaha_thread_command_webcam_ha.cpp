//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <functional>
//---------------------------------------------------------------------------
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
#include <thread\base\hahaha_thread_command_command.h>

#include <lock\hahaha_mutex.h>
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
#include <capture\webcam\hahaha_capture_webcam_direct_show.h>
#include <image_view\hahaha_image_view_base.h>
#include <image_view\hahaha_form_image_view.h>
#include <mutex>
#include <form\hahaha_main_form.h>
#include <thread\hahaha_thread_command_ui.h>
#include <ui\hahaha_ui_message.h>
//---------------------------------------------------------------------------
#include "hahaha_thread_command_webcam_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::hahaha_thread_command_webcam_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::~hahaha_thread_command_webcam_ha()
{

}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::hahaha_thread_command_webcam_ha(const hahaha_thread_command_webcam_ha& htcwh)
{
    Reset();
	Copy(htcwh);
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::hahaha_thread_command_webcam_ha(hahaha_thread_command_webcam_ha&& htcwh) noexcept
{
    Move(std::move(htcwh));
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha& hahaha_thread_command_webcam_ha::operator=(const hahaha_thread_command_webcam_ha& htcwh)
{
	Copy(htcwh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha& hahaha_thread_command_webcam_ha::operator=(hahaha_thread_command_webcam_ha&& htcwh) noexcept
{
	if (this != &htcwh)
    {
        Move(std::move(htcwh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_command_webcam_ha::Copy(const hahaha_thread_command_webcam_ha& htcwh)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_command_webcam_ha::Move(hahaha_thread_command_webcam_ha&& htcwh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_thread_command_webcam_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int hahaha_thread_command_webcam_ha::Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command)
{
	if(command->Command_ == (int)hahaha_thread_command_command_command::ADD_GRAB)
	{
        hahaha::hahaha_thread_command_parameter_webcam* p_ = (hahaha::hahaha_thread_command_parameter_webcam*)command->Parameter_;
		On_Grab(p_->Webcam_);
        delete p_;
	}

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_command_webcam_ha::On_Grab(hahahalib::hahaha_capture_webcam_direct_show* webcam)
{
    // 建立暫存 Bitmap
    std::unique_ptr<halib::bitmap_alloc_argb> bitmap_argb_ha_temp_;
    if(bitmap_argb_ha_temp_.get() == NULL)
    {
        bitmap_argb_ha_temp_.reset(new halib::bitmap_alloc_argb);
    }

    int result_ = bitmap_argb_ha_temp_->Resize(ha::Bitmap_Argb_Ha_->Width_, ha::Bitmap_Argb_Ha_->Height_);

    // 抓圖
    webcam->Grab(*bitmap_argb_ha_temp_);

    if(result_ == 0)
    {
        // 將暫存 Bitmap 移動到 queue（thread-safe）
        {
            std::lock_guard<std::mutex> lock(Bitmap_Buffer_Mutex_);
            Bitmap_Buffer_.push(std::move(bitmap_argb_ha_temp_));
        }

//		hahahalib::hahaha_ui_message ui_;
//		ui_.Handle_ = ha::Pointer_Main_->Form_Main_->Handle;
//        ui_.Send_Message(MESSAGE_UI, 0,
		ha::Pointer_Main_->Command_UI_->Add_Sync(
            new std::function<void()>(
                [this]()
                {
                    std::unique_ptr<halib::bitmap_alloc_argb> bitmap_;

                    {
                        std::lock_guard<std::mutex> lock(Bitmap_Buffer_Mutex_);
                        if (!Bitmap_Buffer_.empty())
						{
							bitmap_ = std::move(Bitmap_Buffer_.front());
                            Bitmap_Buffer_.pop();
                        }
					}

					Bitmap_Old_.reset();   // ✔ 正確：會 delete

					if (bitmap_)
					{
						ha::Image_View_Ha_->Bitmap_ = bitmap_.get();
					}

                    if (bitmap_)
					{
						ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
						ha::Image_View_Ha_->Is_Repaint_ = true;
						ha::Image_View_Ha_->Is_Invalidate_View_Image_ = true;
						ha::Image_View_Ha_->Repaint();

					}


					Bitmap_Old_ = std::move(bitmap_);
				}
            )

        );

    }




    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_command_webcam_ha::Add_Grab(hahahalib::hahaha_capture_webcam_direct_show* webcam)
{
	Mutex_->Lock();

    std::unique_ptr<hahahalib::hahaha_thread_command_command> command_;
    command_.reset(new hahahalib::hahaha_thread_command_command);

    hahaha::hahaha_thread_command_parameter_webcam* p_ = new hahaha::hahaha_thread_command_parameter_webcam;
    p_->Webcam_ = webcam;

//
	command_->Command_ = (int)hahaha_thread_command_command_command::ADD_GRAB;
    command_->Parameter_ = p_;
//
	Queue_Command_.push(std::move(command_));
    SetEvent(Event_Run_);

	Mutex_->Un_Lock();
	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------