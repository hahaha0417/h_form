//---------------------------------------------------------------------------

#ifndef hahaha_processing_unit_form_strategy_formH
#define hahaha_processing_unit_form_strategy_formH
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
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// 因為TForm不能多重繼承 + 簡化new，由hahaha_processing_unit_strategy_text生成處理
//---------------------------------------------------------------------------
class Thahaha_form_processing_unit_strategy_form : public TForm
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
	TScrollBox *main_box;
	TScrollBox *ScrollBox3;
	TScrollBox *ScrollBox4;
	TTabSheet *TabSheet1;
	TScrollBox *ScrollBox5;
	TScrollBox *ScrollBox6;
	TMemo *Memo1;
	TScrollBox *image_box;
	TLabel *label_image_path;
	TEdit *text_image_path;
	TImage *image_icon_on;
	TImage *image_icon_off;
	TOpenDialog *open_dialog_image;
	TScrollBox *ratio_box;
	TLabel *Label1;
	TScrollBox *direction_box;
	TLabel *Label2;
	TCheckBox *check_fix_ratio;
	TComboBox *combo_box_direction;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
	void __fastcall text_image_pathDblClick(TObject *Sender);
	void __fastcall check_fix_ratioClick(TObject *Sender);
	void __fastcall combo_box_directionChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_processing_unit_strategy_form(TComponent* Owner);

public:
public:
public:
public:
    bool Is_Update;
};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_processing_unit_strategy_form *hahaha_form_processing_unit_strategy_form;
//---------------------------------------------------------------------------
#endif
