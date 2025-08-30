//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <parameter_deal_system_setting\hahaha_parameter_deal_system_setting.h>
#include <parameter_deal_option\hahaha_parameter_deal_option.h>
#include <parameter_deal_setting\hahaha_parameter_deal_setting.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <view\hahaha_view_scene.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_setting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_setting::hahaha_setting()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_setting::~hahaha_setting()
{

}
//---------------------------------------------------------------------------
hahaha_setting::hahaha_setting(const hahaha_setting& hs)
{
    Reset();
	Copy(hs);
}
//---------------------------------------------------------------------------
hahaha_setting::hahaha_setting(hahaha_setting&& hs) noexcept
{
    Move(std::move(hs));
}
//---------------------------------------------------------------------------
hahaha_setting& hahaha_setting::operator=(const hahaha_setting& hs)
{
	Copy(hs);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_setting& hahaha_setting::operator=(hahaha_setting&& hs) noexcept
{
	if (this != &hs)
    {
        Move(std::move(hs));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_setting::Copy(const hahaha_setting& hs)
{


}
//---------------------------------------------------------------------------
void hahaha_setting::Move(hahaha_setting&& hs) noexcept
{
    File_Name_ = std::move(hs.File_Name_);

    Scenes_.swap(hs.Scenes_);


    Structure_Main_ = hs.Structure_Main_;
    Structure_Sub_ = hs.Structure_Sub_;
    Pointer_Main_ = hs.Pointer_Main_;
    Pointer_Sub_ = hs.Pointer_Sub_;

    hs.Reset();

}
//---------------------------------------------------------------------------
int hahaha_setting::Reset()
{
    std::vector<std::unique_ptr<hahaha::hahaha_view_scene>> temp_;
    temp_.swap(Scenes_);

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_setting::Load(
    const std::wstring& dir_name
)
{
    halib_def::result result_ = halib_def::result::SUCCESS;

    return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_setting::Save(
    const std::wstring& dir_name
)
{
    halib_def::result result_ = halib_def::result::SUCCESS;

    return result_;
}
//---------------------------------------------------------------------------
int hahaha_setting::Add_Scene(const std::wstring& name)
{
    Scenes_.emplace_back(std::unique_ptr<hahaha::hahaha_view_scene>(new hahaha::hahaha_view_scene()));

    hahaha::hahaha_view_scene* scene_ = Scenes_.back().get();
    scene_->Name_ = name;

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_setting::Delete_Scene(const int& index)
{
    std::vector<std::unique_ptr<hahaha::hahaha_view_scene>> temp_;

    int n = Scenes_.size();

    temp_.reserve(n);

    for(int i = 0; i < n; i++)
    {
        if(i == index)
        {
            continue;
        }
        temp_.emplace_back(std::unique_ptr<hahaha::hahaha_view_scene>());
        temp_.back().swap(Scenes_[i]);

    }

    temp_.swap(Scenes_);


    return 0;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_setting::Set_Structure(
    hahaha::hahaha_structure_main* structure_main,
    hahaha::hahaha_structure_sub* structure_sub
)
{
    Structure_Main_ = structure_main;
    Structure_Sub_ = structure_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::result hahaha_setting::Set_Pointer(
    hahaha::hahaha_pointer_main* pointer_main,
    hahaha::hahaha_pointer_sub* pointer_sub
)
{
    Pointer_Main_ = pointer_main;
    Pointer_Sub_ = pointer_sub;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_setting::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_setting::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_setting::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_setting::On_Paint_Design(halib::image_view& image_view)
{
    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_setting::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_setting::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    
    return result;
}
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------