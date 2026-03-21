//---------------------------------------------------------------------------

#ifndef hahaha_thread_pool_time_set_event_timer_webcam_haH
#define hahaha_thread_pool_time_set_event_timer_webcam_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <thread_pool\hahaha_thread_pool_time_set_event_timer.h>
//---------------------------------------------------------------------------
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
namespace hahaha
{
//---------------------------------------------------------------------------

class hahaha_thread_pool_time_set_event_timer_webcam_ha : public hahahalib::hahaha_thread_pool_time_set_event_timer
{
public:
	hahaha_thread_pool_time_set_event_timer_webcam_ha();
	~hahaha_thread_pool_time_set_event_timer_webcam_ha();

	hahaha_thread_pool_time_set_event_timer_webcam_ha(const hahaha_thread_pool_time_set_event_timer_webcam_ha& htptsetwh);
    hahaha_thread_pool_time_set_event_timer_webcam_ha(hahaha_thread_pool_time_set_event_timer_webcam_ha&& htptsetwh) noexcept;
	hahaha_thread_pool_time_set_event_timer_webcam_ha& operator=(const hahaha_thread_pool_time_set_event_timer_webcam_ha& htptsetwh);
	hahaha_thread_pool_time_set_event_timer_webcam_ha& operator=(hahaha_thread_pool_time_set_event_timer_webcam_ha&& htptsetwh) noexcept;
	void Copy(const hahaha_thread_pool_time_set_event_timer_webcam_ha& htptsetwh);
    void Move(hahaha_thread_pool_time_set_event_timer_webcam_ha&& htptsetwh) noexcept;
public:
	int Reset();
public:
	virtual int Handle();
public:
    hahahalib::hahaha_capture_webcam_direct_show_origin* Webcam_;
public:

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
