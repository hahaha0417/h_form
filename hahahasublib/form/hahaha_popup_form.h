//---------------------------------------------------------------------------

#ifndef hahaha_popup_formH
#define hahaha_popup_formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.TitleBarCtrls.hpp>
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <define\parameter_mapping\hahaha_define_parameter_mapping_type.h>
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Thahaha_form_popup : public TForm
{
__published:	// IDE-managed Components
	TTitleBarPanel *title_bar;
	TImage *image_background;
	TImage *image_itw;
	TImage *Image1;
	TScrollBox *ButtonSystemBox;
	TButton *button_close;
	TButton *button_max;
	TButton *button_min;
	TScrollBox *BodyBox;
	TLabel *title_name;
	TScrollBox *top_box;
	TScrollBox *MainBox;
	TScrollBox *scene_box;
	TScrollBox *view_box;
	TPanel *panel_scene;
	TPanel *panel_view;
	TScrollBox *scene_list;
	TScrollBox *view_list;
	TScrollBox *ScrollBox6;
	TLabel *Label2;
	TImage *Image4;
	TScrollBox *ScrollBox7;
	TLabel *Label3;
	TImage *Image7;
	TScrollBox *LeftBox;
	TScrollBox *form_box;
	TButton *button_full_screen_1;
	TButton *button_scroll_show;
	TButton *button_scroll_hide;
	TButton *button_full_screen_2;
	TButton *button_normal_screen;
	TScrollBox *model_box;
	TLabel *label_model_name;
	TComboBox *setting_name;
	TButton *button_setting_add;
	TButton *button_setting_delete;
	TButton *button_setting_rename;
	TButton *button_setting_reset;
	TScrollBox *mode_box;
	TButton *button_option;
	TButton *button_load_image;
	TButton *button_setting;
	TButton *button_view;
	TScrollBox *scene_bottom_box;
	TScrollBox *view_bottom_box;
	TButton *button_scene_add;
	TButton *button_scene_delete;
	TButton *button_view_add;
	TButton *button_view_delete;
	TButton *button_scene_setting;
	TButton *button_scene_up;
	TButton *button_scene_down;
	TButton *button_view_setting;
	TButton *button_view_up;
	TButton *button_view_down;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
	void __fastcall button_full_screen_1Click(TObject *Sender);
	void __fastcall button_normal_screenClick(TObject *Sender);
	void __fastcall button_full_screen_2Click(TObject *Sender);
	void __fastcall button_scroll_showClick(TObject *Sender);
	void __fastcall button_scroll_hideClick(TObject *Sender);
	void __fastcall button_load_imageClick(TObject *Sender);
	void __fastcall button_optionClick(TObject *Sender);
	void __fastcall button_settingClick(TObject *Sender);
	void __fastcall button_viewClick(TObject *Sender);
	void __fastcall button_setting_addClick(TObject *Sender);
	void __fastcall setting_nameDropDown(TObject *Sender);
	void __fastcall setting_nameChange(TObject *Sender);
	void __fastcall button_setting_deleteClick(TObject *Sender);
	void __fastcall button_setting_renameClick(TObject *Sender);
	void __fastcall button_setting_resetClick(TObject *Sender);
	void __fastcall button_scene_addClick(TObject *Sender);
	void __fastcall button_view_addClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall button_scene_deleteClick(TObject *Sender);
	void __fastcall button_scene_settingClick(TObject *Sender);
	void __fastcall button_scene_upClick(TObject *Sender);
	void __fastcall button_scene_downClick(TObject *Sender);
	void __fastcall button_view_deleteClick(TObject *Sender);
	void __fastcall button_view_settingClick(TObject *Sender);
	void __fastcall button_view_upClick(TObject *Sender);
	void __fastcall button_view_downClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_popup(TComponent* Owner);
public:
    halib_def::result Parameter_Mapping(halib_def::parameter_mapping_type type);
public:
    int Initial_UI();
    int Update_UI();
public:
public:
public:
    bool Is_Update_;
public:
	//---------------------------------------------------------------------------
	halib_def::result Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    halib_def::result Set_Pointer(
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

public:

};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_popup *hahaha_form_popup;
//---------------------------------------------------------------------------
#endif
