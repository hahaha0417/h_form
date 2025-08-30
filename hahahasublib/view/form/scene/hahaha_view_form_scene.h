//---------------------------------------------------------------------------

#ifndef hahaha_view_form_sceneH
#define hahaha_view_form_sceneH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.TitleBarCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
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
//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------
class hahaha_view_scene;
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 因為TForm不能多重繼承 + 簡化new，由hahaha_processing_unit_base_base生成處理
//---------------------------------------------------------------------------
class Thahaha_form_view_scene : public TForm
{
__published:	// IDE-managed Components
	TTitleBarPanel *title_bar;
	TImage *image_background;
	TImage *image_itw;
	TImage *Image1;
	TLabel *title_name;
	TScrollBox *ButtonSystemBox;
	TButton *button_close;
	TButton *button_max;
	TButton *button_min;
	TScrollBox *BodyBox;
	TPageControl *PageControl1;
	TTabSheet *tab_sheet_main;
	TTabSheet *tab_sheet_sub;
	TScrollBox *ScrollBox1;
	TScrollBox *ScrollBox3;
	TScrollBox *ScrollBox4;
	TTabSheet *TabSheet1;
	TScrollBox *ScrollBox5;
	TScrollBox *ScrollBox6;
	TMemo *Memo1;
	TScrollBox *item_box;
	TLabel *label_name;
	TImage *image_logo;
	TImage *image_icon_on;
	TImage *image_icon_off;
	TScrollBox *main_box;
	TScrollBox *sub_box;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
	void __fastcall ItemEnter(TObject *Sender);
	void __fastcall ItemLeave(TObject *Sender);
	void __fastcall ItemDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ItemUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_view_scene(TComponent* Owner);
public:
public:
	//---------------------------------------------------------------------------
	int Set_Structure(
        hahaha::hahaha_structure_main* structure_main,
    	hahaha::hahaha_structure_sub* structure_sub
    );
    int Set_Pointer(
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
public:
    hahaha::hahaha_view_scene* Scene_;
public:
    bool Down_Item_;
};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_view_scene *hahaha_form_view_scene;
//---------------------------------------------------------------------------
#endif
