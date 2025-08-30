//---------------------------------------------------------------------------

#ifndef hahaha_popup_view_popup_setting_formH
#define hahaha_popup_view_popup_setting_formH
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
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
#include <map>
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
class Thahaha_form_popup_view_popup_setting : public TForm
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
	TScrollBox *body_body_box;
	TScrollBox *top_box;
	TButton *button_processing_unit_region;
	TButton *button_processing_unit_base;
	TButton *button_processing_unit_strategy;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *tab_sheet_main;
	TScrollBox *ScrollBox1;
	TScrollBox *ScrollBox2;
	TScrollBox *ScrollBox3;
	TScrollBox *ScrollBox4;
	TScrollBox *box_processing_unit_base;
	TScrollBox *box_processing_unit_region;
	TScrollBox *box_processing_unit_strategy;
	TButton *button_main;
	TTabSheet *TabSheet5;
	TScrollBox *ScrollBox5;
	TScrollBox *box_main;
	TEdit *View_Name;
	TLabel *Label_View_Name;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall button_close_sceneClick(TObject *Sender);
	void __fastcall button_ok_sceneClick(TObject *Sender);
	void __fastcall button_processing_unit_baseClick(TObject *Sender);
	void __fastcall button_processing_unit_regionClick(TObject *Sender);
	void __fastcall button_processing_unit_strategyClick(TObject *Sender);
	void __fastcall button_mainClick(TObject *Sender);
	void __fastcall View_NameChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_popup_view_popup_setting(TComponent* Owner);
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
    // 處理參數用
    std::map<ha_def::processing_unit_base, TForm*> Form_Bases_;
    std::map<ha_def::processing_unit_region, TForm*> Form_Regions_;
    std::map<ha_def::processing_unit_strategy, TForm*> Form_Strategys_;
    // 切換顯示用
    std::map<ha_def::processing_unit_base, TScrollBox*> Page_Bases_;
    std::map<ha_def::processing_unit_region, TScrollBox*> Page_Regions_;
    std::map<ha_def::processing_unit_strategy, TScrollBox*> Page_Strategys_;
public:
    int Update_UI();
public:
    bool Is_Update_;
};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_popup_view_popup_setting *hahaha_form_popup_view_popup_setting;
//---------------------------------------------------------------------------
#endif
