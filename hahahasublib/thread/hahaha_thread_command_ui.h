//---------------------------------------------------------------------------

#ifndef hahaha_thread_command_uiH
#define hahaha_thread_command_uiH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <thread\hahaha_thread_command.h>
//---------------------------------------------------------------------------

#include <memory>
#include <functional>
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
class hahaha_ui_message;


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
enum class hahaha_thread_command_command_ui
{
    ADD_SYNC = 0,
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
struct hahaha_thread_command_parameter_ui
{
    std::function<void()>* Callback_;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class hahaha_thread_command_ui : public hahahalib::hahaha_thread_command
{
public:
	hahaha_thread_command_ui();
	~hahaha_thread_command_ui();

	hahaha_thread_command_ui(const hahaha_thread_command_ui& htcu);
    hahaha_thread_command_ui(hahaha_thread_command_ui&& htcu) noexcept;
	hahaha_thread_command_ui& operator=(const hahaha_thread_command_ui& htcu);
	hahaha_thread_command_ui& operator=(hahaha_thread_command_ui&& htcu) noexcept;
	void Copy(const hahaha_thread_command_ui& htcu);
    void Move(hahaha_thread_command_ui&& htcu) noexcept;
public:
	int Reset();
public:
	virtual int Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command);

public:
	virtual int On_Sync(std::function<void()>* callback);
	virtual int Add_Sync(std::function<void()>* callback);
public:
public:
    // UI thread 更新
    std::unique_ptr<hahahalib::hahaha_ui_message> UI_;
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
