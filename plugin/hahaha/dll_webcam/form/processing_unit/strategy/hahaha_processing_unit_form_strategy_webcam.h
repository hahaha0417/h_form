//---------------------------------------------------------------------------

#ifndef hahaha_processing_unit_form_strategy_webcamH
#define hahaha_processing_unit_form_strategy_webcamH
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
#include <Vcl.Skia.hpp>
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
class hahaha_capture_webcam_direct_show_item;
};

namespace hahaha
{
class hahaha_capture_webcam_direct_show_origin_ha;
};



//---------------------------------------------------------------------------
// 因為TForm不能多重繼承 + 簡化new，由hahaha_processing_unit_strategy_text生成處理
//---------------------------------------------------------------------------
class Thahaha_form_processing_unit_strategy_webcam : public TForm
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
	TScrollBox *camera_box;
	TLabel *label_1;
	TImage *image_icon_on;
	TImage *image_icon_off;
	TOpenDialog *open_dialog_image;
	TScrollBox *direction_box;
	TLabel *Label2;
	TComboBox *combo_box_direction;
	TComboBox *combo_box_camera;
	TScrollBox *enabled_box;
	TComboBox *combo_box_enabled;
	TLabel *Label3;
	TScrollBox *resolution_box;
	TLabel *Label1;
	TComboBox *combo_box_resolution;
	TScrollBox *fps_box;
	TLabel *Label4;
	TComboBox *combo_box_fps;
	TButton *button_camera_refresh;
	TScrollBox *view_box;
	TButton *button_test;
	TScrollBox *flip_vertical_box;
	TLabel *Label5;
	TComboBox *combo_box_flip_vertical;
	void __fastcall button_minClick(TObject *Sender);
	void __fastcall button_maxClick(TObject *Sender);
	void __fastcall button_closeClick(TObject *Sender);
	void __fastcall text_image_pathDblClick(TObject *Sender);
	void __fastcall check_fix_ratioClick(TObject *Sender);
	void __fastcall combo_box_directionChange(TObject *Sender);
	void __fastcall button_camera_refreshClick(TObject *Sender);
	void __fastcall combo_box_enabledChange(TObject *Sender);
	void __fastcall combo_box_cameraChange(TObject *Sender);
	void __fastcall button_testClick(TObject *Sender);
	void __fastcall combo_box_resolutionChange(TObject *Sender);
	void __fastcall combo_box_fpsChange(TObject *Sender);
	void __fastcall combo_box_flip_verticalChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_form_processing_unit_strategy_webcam(TComponent* Owner);

public:
public:
public:
	std::vector<hahahalib::hahaha_capture_webcam_direct_show_item> Format_;

	std::unique_ptr<hahaha::hahaha_capture_webcam_direct_show_origin_ha> Webcam_Direct_Show_Origin_;
public:
    bool Is_Update_;
};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_form_processing_unit_strategy_webcam *hahaha_form_processing_unit_strategy_webcam;
//---------------------------------------------------------------------------
#endif
