//---------------------------------------------------------------------------

#ifndef hahaha_popup_view_popup_formH
#define hahaha_popup_view_popup_formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.TitleBarCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\processing_unit\hahaha_define_processing_unit_base.h>
#include <define\processing_unit\hahaha_define_processing_unit_region.h>
#include <define\processing_unit\hahaha_define_processing_unit_strategy.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_base.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_region.h>
#include <define\factory\processing_unit\hahaha_define_factory_processing_unit_strategy.h>
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
class Thahaha_form_popup_view_popup : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *BodyBox;
	TTitleBarPanel *title_bar;
	TImage *image_background;
	TImage *image_itw;
	TImage *Image1;
	TLabel *title_name;
	TScrollBox *ButtonSystemBox;
	TButton *button_close;
	TButton *button_max;
	TButton *button_min;
	TScrollBox *top_box;
	TButton *button_sub;
	TButton *button_main;
	TButton *button_third_party;
	TButton *button_other;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TScrollBox *ScrollBox1;
	TScrollBox *box_main;
	TTabSheet *TabSheet2;
	TScrollBox *ScrollBox3;
	TScrollBox *box_sub;
	TTabSheet *TabSheet3;
	TScrollBox *ScrollBox5;
	TScrollBox *box_third_party;
	TTabSheet *TabSheet4;
	TScrollBox *ScrollBox7;
	TScrollBox *box_other;
	TTabSheet *TabSheet5;
	TScrollBox *ScrollBox9;
	TScrollBox *ScrollBox10;
	TScrollBox *box_main_list_1;
	TScrollBox *box_main_list_2;
	TScrollBox *bottom_box;
	TScrollBox *bottom_content_box;
	TScrollBox *bottom_confirm_box;
	TButton *button_processing_unit_create;
	TButton *button_processing_unit_cancel;
	TScrollBox *bottom_setting_box;
	TEdit *View_Name;
	TLabel *Label_Type_Base_Label;
	TLabel *Label_Type_Base;
	TLabel *Label_Type_Region;
	TLabel *Label_Type_Region_Label;
	TLabel *Label_Type_Strategy;
	TLabel *Label_Type_Strategy_Label;
	TPopupMenu *Popup_Menu;
	TMenuItem *Popup_Menu_Advance;
	TMenuItem *N1;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
	void __fastcall button_mainClick(TObject *Sender);
	void __fastcall button_subClick(TObject *Sender);
	void __fastcall button_third_partyClick(TObject *Sender);
	void __fastcall button_otherClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall button_processing_unit_createClick(TObject *Sender);
	void __fastcall button_processing_unit_cancelClick(TObject *Sender);
	void __fastcall Popup_Menu_AdvanceClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_popup_view_popup(TComponent* Owner);
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
    ha_def::factory_processing_unit_base Type_Factory_Base_;
    ha_def::factory_processing_unit_region Type_Factory_Region_;
    ha_def::factory_processing_unit_strategy Type_Factory_Strategy_;

    ha_def::processing_unit_base Type_Base_;
    ha_def::processing_unit_region Type_Region_;
    ha_def::processing_unit_strategy Type_Strategy_;
public:

public:

};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_popup_view_popup *hahaha_form_popup_view_popup;
//---------------------------------------------------------------------------
#endif
