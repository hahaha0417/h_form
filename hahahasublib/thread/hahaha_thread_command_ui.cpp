//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <ui\hahaha_ui_message.h>
//---------------------------------------------------------------------------
#include "hahaha_thread_command_ui.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_command_ui::hahaha_thread_command_ui()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui::~hahaha_thread_command_ui()
{

}
//---------------------------------------------------------------------------
hahaha_thread_command_ui::hahaha_thread_command_ui(const hahaha_thread_command_ui& htcu)
{
    Reset();
	Copy(htcu);
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui::hahaha_thread_command_ui(hahaha_thread_command_ui&& htcu) noexcept
{
    Move(std::move(htcu));
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui& hahaha_thread_command_ui::operator=(const hahaha_thread_command_ui& htcu)
{
	Copy(htcu);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_command_ui& hahaha_thread_command_ui::operator=(hahaha_thread_command_ui&& htcu) noexcept
{
	if (this != &htcu)
    {
        Move(std::move(htcu));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_command_ui::Copy(const hahaha_thread_command_ui& htcu)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_command_ui::Move(hahaha_thread_command_ui&& htcu) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_thread_command_ui::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int hahaha_thread_command_ui::Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command)
{


	return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_command_ui::On_Sync(std::function<void()>* callback)
{

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_command_ui::Add_Sync(std::function<void()>* callback)
{

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------