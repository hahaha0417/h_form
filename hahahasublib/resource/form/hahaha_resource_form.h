//---------------------------------------------------------------------------

#ifndef hahaha_resource_formH
#define hahaha_resource_formH
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
class Thahaha_form_resource : public TForm
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
	TPageControl *PageControl1;
	TTabSheet *tab_sheet_main;
	TScrollBox *ScrollBox1;
	TImage *image_icon_itw;
	TMemo *Memo1;
	TTabSheet *tab_sheet_sub;
	TScrollBox *ScrollBox3;
	TScrollBox *ScrollBox4;
	TTabSheet *TabSheet1;
	TScrollBox *ScrollBox5;
	TScrollBox *ScrollBox6;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_resource(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_resource *hahaha_form_resource;
//---------------------------------------------------------------------------
#endif
