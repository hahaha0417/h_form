//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <form\hahaha_main_form.h>
//---------------------------------------------------------------------------
#include <command\hahaha_command_main.h>
#include <command\hahaha_command_sub.h>
//---------------------------------------------------------------------------
#include "hahaha_pointer_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_pointer_main::hahaha_pointer_main()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_pointer_main::~hahaha_pointer_main()
{

}
//---------------------------------------------------------------------------
hahaha_pointer_main::hahaha_pointer_main(const hahaha_pointer_main& hpm)
{
    Reset();
	Copy(hpm);
}
//---------------------------------------------------------------------------
hahaha_pointer_main::hahaha_pointer_main(hahaha_pointer_main&& hpm) noexcept
{
    Move(std::move(hpm));

}
//---------------------------------------------------------------------------
hahaha_pointer_main& hahaha_pointer_main::operator=(const hahaha_pointer_main& hpm)
{
	Copy(hpm);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_pointer_main& hahaha_pointer_main::operator=(hahaha_pointer_main&& hpm) noexcept
{
	if (this != &hpm)
    {
        Move(std::move(hpm));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_pointer_main::Copy(const hahaha_pointer_main& hpm)
{
    //---------------------------------------------------------------------------
    System_Setting_ = hpm.System_Setting_;
    Option_ = hpm.Option_;
    Setting_ = hpm.Setting_;
    //---------------------------------------------------------------------------
    Select_Scene_ = hpm.Select_Scene_;
    Select_View_ = hpm.Select_View_;
    Choose_Processing_Unit_ = hpm.Choose_Processing_Unit_;
    Candidate_Processing_Unit_ = hpm.Candidate_Processing_Unit_;
    //---------------------------------------------------------------------------
    Form_Main_ = hpm.Form_Main_;
    //---------------------------------------------------------------------------
    Command_Main_ = hpm.Command_Main_;
	Command_Sub_ = hpm.Command_Sub_;


    Structure_Main_ = hpm.Structure_Main_;
    Structure_Sub_ = hpm.Structure_Sub_;
    Pointer_Main_ = hpm.Pointer_Main_;
    Pointer_Sub_ = hpm.Pointer_Sub_;
}
//---------------------------------------------------------------------------
void hahaha_pointer_main::Move(hahaha_pointer_main&& hpm) noexcept
{
    //---------------------------------------------------------------------------
    System_Setting_ = hpm.System_Setting_;
    Option_ = hpm.Option_;
    Setting_ = hpm.Setting_;
    //---------------------------------------------------------------------------
    Select_Scene_ = hpm.Select_Scene_;
    Select_View_ = hpm.Select_View_;
    Choose_Processing_Unit_ = hpm.Choose_Processing_Unit_;
    Candidate_Processing_Unit_ = hpm.Candidate_Processing_Unit_;
    //---------------------------------------------------------------------------
    Form_Main_ = hpm.Form_Main_;
    //---------------------------------------------------------------------------
    Command_Main_ = hpm.Command_Main_;
	Command_Sub_ = hpm.Command_Sub_;


    Structure_Main_ = hpm.Structure_Main_;
    Structure_Sub_ = hpm.Structure_Sub_;
    Pointer_Main_ = hpm.Pointer_Main_;
    Pointer_Sub_ = hpm.Pointer_Sub_;

    hpm.Reset();

}
//---------------------------------------------------------------------------
int hahaha_pointer_main::Reset()
{
    //---------------------------------------------------------------------------
    System_Setting_ = nullptr;
    Option_ = nullptr;
    Setting_ = nullptr;
    //---------------------------------------------------------------------------
    Select_Scene_ = nullptr;
    Select_View_ = nullptr;
    Choose_Processing_Unit_ = nullptr;
    Candidate_Processing_Unit_ = nullptr;
    //---------------------------------------------------------------------------
    Form_Main_ = nullptr;
    //---------------------------------------------------------------------------
    Command_Main_ = nullptr;
	Command_Sub_ = nullptr;


    Structure_Main_ = nullptr;
    Structure_Sub_ = nullptr;
    Pointer_Main_ = nullptr;
    Pointer_Sub_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_pointer_main::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    Form_Main_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );

    Command_Main_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );


    Command_Sub_->Set_Structure(
        Structure_Main_,
        Structure_Sub_
    );


    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_pointer_main::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    Form_Main_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Command_Main_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    Command_Sub_->Set_Pointer(
        Pointer_Main_,
        Pointer_Sub_
    );

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------