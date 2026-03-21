//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_direct_show_origin_haH
#define hahaha_capture_webcam_direct_show_origin_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <thread\hahaha_thread_command.h>
//---------------------------------------------------------------------------
#include <mutex>
#include <queue>
#include <memory>

#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <bitmap\hahaha_c_bitmap_alloc.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <capture\webcam\hahaha_capture_webcam_direct_show_origin.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
class hahaha_mutex;
}
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_capture_webcam_direct_show_origin_ha : public hahahalib::hahaha_capture_webcam_direct_show_origin
{
public:
	hahaha_capture_webcam_direct_show_origin_ha();
	~hahaha_capture_webcam_direct_show_origin_ha();

	hahaha_capture_webcam_direct_show_origin_ha(const hahaha_capture_webcam_direct_show_origin_ha& hcwdsoh);
    hahaha_capture_webcam_direct_show_origin_ha(hahaha_capture_webcam_direct_show_origin_ha&& hcwdsoh) noexcept;
	hahaha_capture_webcam_direct_show_origin_ha& operator=(const hahaha_capture_webcam_direct_show_origin_ha& hcwdsoh);
	hahaha_capture_webcam_direct_show_origin_ha& operator=(hahaha_capture_webcam_direct_show_origin_ha&& hcwdsoh) noexcept;
	void Copy(const hahaha_capture_webcam_direct_show_origin_ha& hcwdsoh);
    void Move(hahaha_capture_webcam_direct_show_origin_ha&& hcwdsoh) noexcept;
public:
	int Reset();

public:
    virtual void Callback_Grabber(double time, BYTE* buffer, long len);

public:
    std::unique_ptr<hahahalib::hahaha_mutex> Mutex_;
public:
public:
	std::queue<std::unique_ptr<halib::bitmap_alloc_argb>> Bitmap_Buffer_;
	std::mutex Bitmap_Buffer_Mutex_;

	std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_Old_;
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
