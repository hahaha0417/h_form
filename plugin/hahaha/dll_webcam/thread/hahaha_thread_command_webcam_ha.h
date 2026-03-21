//---------------------------------------------------------------------------

#ifndef hahaha_thread_command_webcam_haH
#define hahaha_thread_command_webcam_haH
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
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_thread_command_command;
class hahaha_capture_webcam_direct_show_origin;


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
enum class hahaha_thread_command_command_command
{
    ADD_GRAB = 0,
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
struct hahaha_thread_command_parameter_webcam
{
    hahahalib::hahaha_capture_webcam_direct_show_origin* Webcam_ = NULL;
};
//---------------------------------------------------------------------------
class hahaha_thread_command_webcam_ha : public hahahalib::hahaha_thread_command
{
public:
	hahaha_thread_command_webcam_ha();
	~hahaha_thread_command_webcam_ha();

	hahaha_thread_command_webcam_ha(const hahaha_thread_command_webcam_ha& he);
    hahaha_thread_command_webcam_ha(hahaha_thread_command_webcam_ha&& he) noexcept;
	hahaha_thread_command_webcam_ha& operator=(const hahaha_thread_command_webcam_ha& he);
	hahaha_thread_command_webcam_ha& operator=(hahaha_thread_command_webcam_ha&& he) noexcept;
	void Copy(const hahaha_thread_command_webcam_ha& he);
    void Move(hahaha_thread_command_webcam_ha&& he) noexcept;
public:
	int Reset();
public:
	virtual int Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command);

public:
	int On_Grab(hahahalib::hahaha_capture_webcam_direct_show_origin* webcam);
	int Add_Grab(hahahalib::hahaha_capture_webcam_direct_show_origin* webcam);
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
