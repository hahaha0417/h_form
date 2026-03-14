//---------------------------------------------------------------------------

#ifndef hahaha_thread_command_ui_haH
#define hahaha_thread_command_ui_haH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <thread\hahaha_thread_command_ui.h>
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
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_thread_command_command;


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class hahaha_thread_command_ui_ha : public hahaha::hahaha_thread_command_ui
{
public:
	hahaha_thread_command_ui_ha();
	~hahaha_thread_command_ui_ha();

	hahaha_thread_command_ui_ha(const hahaha_thread_command_ui_ha& htcuh);
    hahaha_thread_command_ui_ha(hahaha_thread_command_ui_ha&& htcuh) noexcept;
	hahaha_thread_command_ui_ha& operator=(const hahaha_thread_command_ui_ha& htcuh);
	hahaha_thread_command_ui_ha& operator=(hahaha_thread_command_ui_ha&& htcuh) noexcept;
	void Copy(const hahaha_thread_command_ui_ha& htcuh);
    void Move(hahaha_thread_command_ui_ha&& htcuh) noexcept;
public:
	virtual int Reset();
public:
	virtual int Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command);

public:
	virtual int On_Sync(std::function<void()>* callback);
	virtual int Add_Sync(std::function<void()>* callback);
public:
public:

};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
