//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
#include <shape\function\hahaha_shape_function_roi.h>
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_base.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <form\hahaha_main_form.h>
#include <thread\hahaha_thread_command_ui.h>
#include <ui\hahaha_ui_message.h>
#include <image_process\color\hahaha_image_process_color.h>
#include <image_process\color\hahaha_image_process_color.h>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
//---------------------------------------------------------------------------
#include <define\hahaha_define_ho.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <bitmap\hahaha_c_bitmap_alloc.h>
#include <bitmap\hahaha_c_bitmap_ptr.h>
//---------------------------------------------------------------------------
#include <lock\hahaha_mutex.h>
#include "hahaha_capture_webcam_direct_show_origin_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin_ha::hahaha_capture_webcam_direct_show_origin_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin_ha::~hahaha_capture_webcam_direct_show_origin_ha()
{

}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin_ha::hahaha_capture_webcam_direct_show_origin_ha(const hahaha_capture_webcam_direct_show_origin_ha& hcwdsoh)
{
    Reset();
	Copy(hcwdsoh);
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin_ha::hahaha_capture_webcam_direct_show_origin_ha(hahaha_capture_webcam_direct_show_origin_ha&& hcwdsoh) noexcept
{
    Move(std::move(hcwdsoh));
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin_ha& hahaha_capture_webcam_direct_show_origin_ha::operator=(const hahaha_capture_webcam_direct_show_origin_ha& hcwdsoh)
{
	Copy(hcwdsoh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin_ha& hahaha_capture_webcam_direct_show_origin_ha::operator=(hahaha_capture_webcam_direct_show_origin_ha&& hcwdsoh) noexcept
{
	if (this != &hcwdsoh)
    {
        Move(std::move(hcwdsoh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_origin_ha::Copy(const hahaha_capture_webcam_direct_show_origin_ha& hcwdsoh)
{

}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_origin_ha::Move(hahaha_capture_webcam_direct_show_origin_ha&& hcwdsoh) noexcept
{
    Mutex_ = std::move(hcwdsoh.Mutex_);
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show_origin_ha::Reset()
{
    if(Mutex_.get() == nullptr)
    {
        Mutex_.reset(new hahahalib::hahaha_mutex());
    }

	return 0;
}
//---------------------------------------------------------------------------

void hahaha_capture_webcam_direct_show_origin_ha::Callback_Grabber(double time, BYTE* buffer, long len)
{
    Mutex_->Lock();

    // 建立暫存 Bitmap
    halib::bitmap_ptr_yuy2 bitmap_yuy2_ha_temp_(buffer);

    bitmap_yuy2_ha_temp_.Resize(ha::Bitmap_Argb_Ha_->Width_, ha::Bitmap_Argb_Ha_->Height_);


    std::unique_ptr<halib::bitmap_alloc_argb> bitmap_argb_ha_temp_;
    if(bitmap_argb_ha_temp_.get() == NULL)
    {
        bitmap_argb_ha_temp_.reset(new halib::bitmap_alloc_argb);
    }

    bitmap_argb_ha_temp_->Resize(ha::Bitmap_Argb_Ha_->Width_, ha::Bitmap_Argb_Ha_->Height_);

    halib_image::color::YUV422_To_ARGB(
        bitmap_yuy2_ha_temp_,
        halib::roi(0, 0, bitmap_yuy2_ha_temp_.Width_ - 1, bitmap_yuy2_ha_temp_.Height_ - 1),
        *bitmap_argb_ha_temp_,
        halib::roi(0, 0, bitmap_argb_ha_temp_->Width_ - 1, bitmap_argb_ha_temp_->Height_ - 1)
    );



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

//                    if (bitmap_)
//					{
//						ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
//						ha::Image_View_Ha_->Is_Repaint_ = true;
//						ha::Image_View_Ha_->Is_Repaint_View_Image_ = true;
//						ha::Image_View_Ha_->Repaint();
//
//					}

                if (bitmap_)
                {
                    ha::Structure_Main_->Image_View_->Bitmap_ = bitmap_.get();
                }

                if (bitmap_)
                {
                    ha::Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
                    ha::Structure_Main_->Image_View_->Is_Repaint_ = true;
                    ha::Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;
                    ha::Structure_Main_->Image_View_->Repaint();
//
                }



                Bitmap_Old_ = std::move(bitmap_);
            }
        )

    );


    Mutex_->Un_Lock();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------