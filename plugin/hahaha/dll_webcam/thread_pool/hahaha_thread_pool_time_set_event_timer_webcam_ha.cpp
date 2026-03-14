//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <thread\hahaha_thread_command_webcam_ha.h>
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
//---------------------------------------------------------------------------
#include "hahaha_thread_pool_time_set_event_timer_webcam_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer_webcam_ha::hahaha_thread_pool_time_set_event_timer_webcam_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer_webcam_ha::~hahaha_thread_pool_time_set_event_timer_webcam_ha()
{

}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer_webcam_ha::hahaha_thread_pool_time_set_event_timer_webcam_ha(const hahaha_thread_pool_time_set_event_timer_webcam_ha& htptsetwh)
{
    Reset();
	Copy(htptsetwh);
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer_webcam_ha::hahaha_thread_pool_time_set_event_timer_webcam_ha(hahaha_thread_pool_time_set_event_timer_webcam_ha&& htptsetwh) noexcept
{
    Move(std::move(htptsetwh));
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer_webcam_ha& hahaha_thread_pool_time_set_event_timer_webcam_ha::operator=(const hahaha_thread_pool_time_set_event_timer_webcam_ha& htptsetwh)
{
	Copy(htptsetwh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer_webcam_ha& hahaha_thread_pool_time_set_event_timer_webcam_ha::operator=(hahaha_thread_pool_time_set_event_timer_webcam_ha&& htptsetwh) noexcept
{
	if (this != &htptsetwh)
    {
        Move(std::move(htptsetwh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_pool_time_set_event_timer_webcam_ha::Copy(const hahaha_thread_pool_time_set_event_timer_webcam_ha& htptsetwh)
{
    Webcam_ = htptsetwh.Webcam_;
}
//---------------------------------------------------------------------------
void hahaha_thread_pool_time_set_event_timer_webcam_ha::Move(hahaha_thread_pool_time_set_event_timer_webcam_ha&& htptsetwh) noexcept
{
    Webcam_ = htptsetwh.Webcam_;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_time_set_event_timer_webcam_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_time_set_event_timer_webcam_ha::Handle()
{
    if(Webcam_ != NULL)
    {
        ha::Thread_Command_Webcam_Ha_->Add_Grab(Webcam_);
    }


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------