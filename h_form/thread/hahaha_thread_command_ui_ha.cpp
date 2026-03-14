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
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <define\hahaha_define_ha.h>
//---------------------------------------------------------------------------
#include <thread\base\hahaha_thread_command_command.h>
#include <ui\hahaha_ui_message.h>
#include <lock\hahaha_mutex.h>
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
#include <capture\webcam\hahaha_capture_webcam_direct_show.h>
#include <image_view\hahaha_image_view_base.h>
#include <mutex>
#include <form\hahaha_main_form.h>
//---------------------------------------------------------------------------
#include "hahaha_thread_command_ui_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_command_ui_ha::hahaha_thread_command_ui_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui_ha::~hahaha_thread_command_ui_ha()
{

}
//---------------------------------------------------------------------------
hahaha_thread_command_ui_ha::hahaha_thread_command_ui_ha(const hahaha_thread_command_ui_ha& htcuh)
{
    Reset();
	Copy(htcuh);
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui_ha::hahaha_thread_command_ui_ha(hahaha_thread_command_ui_ha&& htcuh) noexcept
{
    Move(std::move(htcuh));
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui_ha& hahaha_thread_command_ui_ha::operator=(const hahaha_thread_command_ui_ha& htcuh)
{
	Copy(htcuh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui_ha& hahaha_thread_command_ui_ha::operator=(hahaha_thread_command_ui_ha&& htcuh) noexcept
{
	if (this != &htcuh)
    {
        Move(std::move(htcuh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_command_ui_ha::Copy(const hahaha_thread_command_ui_ha& htcuh)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_command_ui_ha::Move(hahaha_thread_command_ui_ha&& htcuh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_thread_command_ui_ha::Reset()
{
    if(UI_.get() == NULL)
    {
        UI_.reset(new hahahalib::hahaha_ui_message());
    }

	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int hahaha_thread_command_ui_ha::Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command)
{
	if(command->Command_ == (int)hahaha::hahaha_thread_command_command_ui::ADD_SYNC)
	{
        hahaha::hahaha_thread_command_parameter_ui* p_ = (hahaha::hahaha_thread_command_parameter_ui*)command->Parameter_;
		On_Sync(p_->Callback_);
        delete p_;
	}

	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int hahaha_thread_command_ui_ha::On_Sync(std::function<void()>* callback)
{
    UI_->Send_Message(MESSAGE_UI, 0, callback);



    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_command_ui_ha::Add_Sync(std::function<void()>* callback)
{
	Mutex_->Lock();

    std::unique_ptr<hahahalib::hahaha_thread_command_command> command_;
    command_.reset(new hahahalib::hahaha_thread_command_command);

    hahaha_thread_command_parameter_ui* p_ = new hahaha_thread_command_parameter_ui;

    p_->Callback_ = callback;
//
	command_->Command_ = (int)hahaha_thread_command_command_ui::ADD_SYNC;
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

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------