//---------------------------------------------------------------------------

#ifndef hahaha_settingH
#define hahaha_settingH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
class hahaha_structure_main;
class hahaha_structure_sub;
class hahaha_pointer_main;
class hahaha_pointer_sub;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_view_scene;
//---------------------------------------------------------------------------

class hahaha_setting
{
public:
	hahaha_setting();
	~hahaha_setting();

	hahaha_setting(const hahaha_setting& hs);
    hahaha_setting(hahaha_setting&& hs) noexcept;
	hahaha_setting& operator=(const hahaha_setting& hs);
    hahaha_setting& operator=(hahaha_setting&& hs) noexcept;
	void Copy(const hahaha_setting& hs);
    void Move(hahaha_setting&& hs) noexcept;
public:
	int Reset();

public:

public:
    virtual halib_def::result Load(
		const std::wstring& dir_name
	);
    virtual halib_def::result Save(
		const std::wstring& dir_name
	);
public:
    std::wstring File_Name_;
public:
    std::vector<std::unique_ptr<hahaha::hahaha_view_scene>> Scenes_;
public:
    int Add_Scene(const std::wstring& name);
    int Delete_Scene(const int& index);
public:
public:
public:
	//---------------------------------------------------------------------------
	virtual halib_def::result Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    virtual halib_def::result Set_Pointer(
        hahaha::hahaha_pointer_main* pointer_main,
    	hahaha::hahaha_pointer_sub* pointer_sub
    );
	//---------------------------------------------------------------------------
    hahaha::hahaha_structure_main* Structure_Main_;
    hahaha::hahaha_structure_sub* Structure_Sub_;
    hahaha::hahaha_pointer_main* Pointer_Main_;
    hahaha::hahaha_pointer_sub* Pointer_Sub_;
	//---------------------------------------------------------------------------
public:
public:
	virtual halib_def::image_view_result On_Mouse_Down_Design(halib::image_view& image_view,
		TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
		int Y
	);
	virtual halib_def::image_view_result On_Mouse_Move_Design(halib::image_view& image_view,
		TObject *Sender,
		TShiftState Shift,
		int X,
		int Y
	);
	virtual halib_def::image_view_result On_Mouse_Up_Design(halib::image_view& image_view,
		TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
	);
public:
    virtual halib_def::image_view_result On_Paint_Design(halib::image_view& image_view);
public:
public:
    // 初始化設定
    virtual halib_def::result Initial();
    // 載入初始化
    virtual halib_def::result Load_Initial();
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------



#endif
