//---------------------------------------------------------------------------

#ifndef hahaha_popup_view_popup_form_itemH
#define hahaha_popup_view_popup_form_itemH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.TitleBarCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Skia.hpp>

//---------------------------------------------------------------------------
class Thahaha_form_popup_view_popup_item : public TForm
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
	TScrollBox *box_item;
	TButton *button_add_rect_form;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TScrollBox *ScrollBox1;
	TScrollBox *ScrollBox2;
	TScrollBox *item_rect_form_box;
	TImage *pic_processing_unit_icon_rect_form;
	TImage *pic_processing_unit_sketch_rect_form;
	TMemo *processing_unit_content_rect_form;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
	void __fastcall button_add_rect_formClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_popup_view_popup_item(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_popup_view_popup_item *hahaha_form_popup_view_popup_item;
//---------------------------------------------------------------------------
#endif
