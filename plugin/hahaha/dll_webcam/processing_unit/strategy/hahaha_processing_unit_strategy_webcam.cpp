//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <filesystem>

#include <define\processing_unit\hahaha_define_processing_unit_strategy.h>
#include <form\processing_unit\strategy\hahaha_processing_unit_form_strategy_webcam.h>
#include <define\hahaha_define_ho.h>
//---------------------------------------------------------------------------
#include <function\bitmap\hahaha_function_bitmap_bmp.h>
#include <function\bitmap\hahaha_function_bitmap_jpeg.h>
#include <function\bitmap\hahaha_function_bitmap_png.h>
//---------------------------------------------------------------------------
#include <bitmap\function\base\hahaha_bitmap_function_bitmap.h>
//---------------------------------------------------------------------------
#include <image_process\set\hahaha_image_process_set.h>
#include <image_process\copy\hahaha_image_process_copy.h>
#include <image_process\resize\hahaha_image_process_resize.h>
#include <image_process\alpha\hahaha_image_process_alpha_comp.h>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
#include <shape\function\hahaha_shape_function_roi.h>
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_base.h>
//---------------------------------------------------------------------------
#include <function\hahaha_function_vector.h>
//---------------------------------------------------------------------------
#include <parameter_mapping\hahaha_parameter_mapping.h>
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>

//---------------------------------------------------------------------------
#include <define\hahaha_define_ho.h>
#include <ippi.h>

#include "hahaha_processing_unit_strategy_webcam.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_webcam::hahaha_processing_unit_strategy_webcam()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_webcam::~hahaha_processing_unit_strategy_webcam()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_webcam::hahaha_processing_unit_strategy_webcam(const hahaha_processing_unit_strategy_webcam& hpusw)
{
    Reset();
    hahaha::hahaha_processing_unit_strategy_webcam::Copy(hpusw);
	Copy(hpusw);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_webcam::hahaha_processing_unit_strategy_webcam(hahaha_processing_unit_strategy_webcam&& hpusw) noexcept
{
    hahaha::hahaha_processing_unit_strategy_webcam::Move(std::move(hpusw));
    Move(std::move(hpusw));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_webcam& hahaha_processing_unit_strategy_webcam::operator=(const hahaha_processing_unit_strategy_webcam& hpusw)
{
    hahaha::hahaha_processing_unit_strategy_webcam::Copy(hpusw);
	Copy(hpusw);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_webcam& hahaha_processing_unit_strategy_webcam::operator=(hahaha_processing_unit_strategy_webcam&& hpusw) noexcept
{
    hahaha::hahaha_processing_unit_strategy_webcam::Move(std::move(hpusw));
    Move(std::move(hpusw));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_strategy_webcam::Copy(const hahaha_processing_unit_strategy_webcam& hpusw)
{

}
//---------------------------------------------------------------------------
void hahaha_processing_unit_strategy_webcam::Move(hahaha_processing_unit_strategy_webcam&& hpusw) noexcept
{

    Message_Create_ = std::move(hpusw.Message_Create_);

    Camera_ = hpusw.Camera_;
    Enabled_ = hpusw.Enabled_;
    Resolution_ = hpusw.Resolution_;
    Fps_ = hpusw.Fps_;
    Direction_ = hpusw.Direction_;

    Width_ = hpusw.Width_;
    Height_ = hpusw.Height_;

    Bitmap_Load_ = std::move(hpusw.Bitmap_Load_);
    Bitmap_ = std::move(hpusw.Bitmap_);
	Bitmap_Thumbnail_ = std::move(hpusw.Bitmap_Thumbnail_);

	Format_ = std::move(Format_);

}
//---------------------------------------------------------------------------
int hahaha_processing_unit_strategy_webcam::Reset()
{
    Type_Strategy_ = ha_def::processing_unit_strategy::PLUGIN_HAHAHA_WEBCAM;
    Name_Strategy_ = L"webcam";


    Message_Create_ = L"建立網路攝影機";

    Camera_ = 0;
    Enabled_ = 0;
    Resolution_ = 0;
    Fps_ = 0;
    Direction_ = ha_def::processing_unit_strategy_direction::NORMAL;

    Width_ = 0;
    Height_ = 0;

    Is_Deal_ = false;


    if(Bitmap_Load_.get() == NULL)
    {
        Bitmap_Load_.reset(new halib::bitmap_alloc_argb());
    }

    if(Bitmap_.get() == NULL)
    {
        Bitmap_.reset(new halib::bitmap_alloc_argb());
    }

    if(Bitmap_Thumbnail_.get() == NULL)
    {
        Bitmap_Thumbnail_.reset(new halib::bitmap_alloc_argb());
    }




	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Set_Parameter()
{
    ha::Form_Processing_Unit_Strategy_Webcam_->Is_Update = true;

    ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_camera->ItemIndex = Camera_;
    ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_enabled->ItemIndex = Enabled_;
    ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_resolution->ItemIndex = Resolution_;
    ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_fps->ItemIndex = Fps_;
    ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_direction->ItemIndex = (int)Direction_;

    Width_ = 0;
    Height_ = 0;

    ha::Form_Processing_Unit_Strategy_Webcam_->Is_Update = false;
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Get_Parameter()
{
    ha::Form_Processing_Unit_Strategy_Webcam_->Is_Update = true;


    Camera_ = ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_camera->ItemIndex;
    Enabled_ = ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_enabled->ItemIndex;
    Resolution_ = ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_resolution->ItemIndex;
    Fps_ = ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_fps->ItemIndex;
    Direction_ = (ha_def::processing_unit_strategy_direction)ha::Form_Processing_Unit_Strategy_Webcam_->combo_box_direction->ItemIndex;

	Width_ = 0;
    Height_ = 0;


    ha::Structure_Main_->Image_View_->Is_Invalidate_View_Image_ = true;
    ha::Form_Processing_Unit_Strategy_Webcam_->Is_Update = false;
    Is_Deal_ = false;



    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_webcam::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;


    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
		if(Processing_Unit_Region_->Type_Region_ == ha_def::processing_unit_region::RECTANGLE)
        {
            halib::point_double pt_start_;
            halib::point_double pt_end_;

            if(Processing_Unit_Region_->Down_Mouse_)
            {

                if(Processing_Unit_Region_->Choose_)
                {
                    //---------------------------------------------------------------------------
                    // 點
                    //---------------------------------------------------------------------------
                    //----------------------------
                    // 左上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }


                    //----------------------------
                    // 中上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::MIDDLE_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                    	Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;

                    }

                    //----------------------------
                    // 左中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_MIDDLE);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_MIDDLE);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 左下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 中下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::MIDDLE_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    // 線
                    //---------------------------------------------------------------------------

                    //----------------------------
                    // 上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
                    {


                    }

                    //----------------------------
                    // 下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
                    {


                    }

                    //----------------------------
                    // 左
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
                    {



                    }

                    //----------------------------
                    // 右
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
                    {


                    }

                    //----------------------------
                    //
                    //----------------------------

                    //---------------------------------------------------------------------------
                    // 面
                    //---------------------------------------------------------------------------
                    //----------------------------
                    //
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
                    {


                    }
                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    //
                    //---------------------------------------------------------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
                    {

                    }
                }
                else
                {

                }
            }
            else
            {

            }





        }
    }
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_webcam::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
		if(Processing_Unit_Region_->Type_Region_ == ha_def::processing_unit_region::RECTANGLE)
        {
            halib::point_double pt_start_;
            halib::point_double pt_end_;

            if(Processing_Unit_Region_->Down_Mouse_)
            {

                if(Processing_Unit_Region_->Choose_)
                {
                    //---------------------------------------------------------------------------
                    // 點
                    //---------------------------------------------------------------------------
                    //----------------------------
                    // 左上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }


                    //----------------------------
                    // 中上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::MIDDLE_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                    	Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;

                    }

                    //----------------------------
                    // 左中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_MIDDLE);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_MIDDLE);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 左下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 中下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::MIDDLE_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    // 線
                    //---------------------------------------------------------------------------

                    //----------------------------
                    // 上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
                    {


                    }

                    //----------------------------
                    // 下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
                    {


                    }

                    //----------------------------
                    // 左
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
                    {



                    }

                    //----------------------------
                    // 右
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
                    {


                    }

                    //----------------------------
                    //
                    //----------------------------

                    //---------------------------------------------------------------------------
                    // 面
                    //---------------------------------------------------------------------------
                    //----------------------------
                    //
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
                    {


                    }
                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    //
                    //---------------------------------------------------------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
                    {

                    }
                }
                else
                {

                }
            }
            else
            {

            }





        }
    }
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_webcam::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
		if(Processing_Unit_Region_->Type_Region_ == ha_def::processing_unit_region::RECTANGLE)
        {
            halib::point_double pt_start_;
            halib::point_double pt_end_;

            if(Processing_Unit_Region_->Down_Mouse_)
            {

                if(Processing_Unit_Region_->Choose_)
                {
                    //---------------------------------------------------------------------------
                    // 點
                    //---------------------------------------------------------------------------
                    //----------------------------
                    // 左上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
                    {
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }


                    //----------------------------
                    // 中上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
                    {
                    	Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
                    {
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;

                    }

                    //----------------------------
                    // 左中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
                    {
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
                    {
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 左下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
                    {
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 中下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
                    {
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
                    {
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    // 線
                    //---------------------------------------------------------------------------

                    //----------------------------
                    // 上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
                    {


                    }

                    //----------------------------
                    // 下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
                    {


                    }

                    //----------------------------
                    // 左
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
                    {



                    }

                    //----------------------------
                    // 右
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
                    {


                    }

                    //----------------------------
                    //
                    //----------------------------

                    //---------------------------------------------------------------------------
                    // 面
                    //---------------------------------------------------------------------------
                    //----------------------------
                    //
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
                    {


                    }
                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    //
                    //---------------------------------------------------------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
                    {

                    }
                }
                else
                {

                }
            }
            else
            {
                if(Processing_Unit_Region_->Choose_)
                {
                    //---------------------------------------------------------------------------
                    // 點
                    //---------------------------------------------------------------------------
                    //----------------------------
                    // 左上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }


                    //----------------------------
                    // 中上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::MIDDLE_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                    	Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_TOP);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y1_ = roi_temp_.Y1_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;

                    }

                    //----------------------------
                    // 左中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_MIDDLE);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_MIDDLE);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 左下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::LEFT_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X1_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X1_ = roi_temp_.X1_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 中下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::MIDDLE_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    // 右下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
                    {
                        if(bool Ratio_Fix_ = true && Bitmap_->Width_ != 0 && Bitmap_->Height_ != 0)
                        {

                            halib::roi_double roi_temp_ = halib::roi_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_,
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            );

                            double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                            double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;

                            halib_shape::roi_double::Fix_Roi_Fix_Bitmap_Ratio(roi_temp_, *Bitmap_, dx_, dy_, halib_def::shape_rectangle_control_point::RIGHT_BOTTOM);

                            // 其中一個會修改
                            Processing_Unit_Region_->Point_Choose_Move_->Y_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Point_Choose_Move_->X_ = roi_temp_.X2_;

                            Processing_Unit_Region_->Roi_->Y2_ = roi_temp_.Y2_;
                            Processing_Unit_Region_->Roi_->X2_ = roi_temp_.X2_;

                        }
                        Is_Deal_ = false;
                        image_view.Is_Repaint_ = true;
                    }

                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    // 線
                    //---------------------------------------------------------------------------

                    //----------------------------
                    // 上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
                    {


                    }

                    //----------------------------
                    // 下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
                    {


                    }

                    //----------------------------
                    // 左
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
                    {



                    }

                    //----------------------------
                    // 右
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
                    {


                    }

                    //----------------------------
                    //
                    //----------------------------

                    //---------------------------------------------------------------------------
                    // 面
                    //---------------------------------------------------------------------------
                    //----------------------------
                    //
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
                    {


                    }
                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    //
                    //---------------------------------------------------------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
                    {

                    }
                }
                else
                {

                }
            }





        }
    }
    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_webcam::On_Paint_Begin(halib::image_view& image_view)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
		if(Processing_Unit_Region_->Type_Region_ == ha_def::processing_unit_region::RECTANGLE)
        {
            halib::point_double pt_start_;
            halib::point_double pt_end_;

            if(Processing_Unit_Region_->Down_Mouse_)
            {

                if(Processing_Unit_Region_->Choose_)
                {
                    //---------------------------------------------------------------------------
                    // 點
                    //---------------------------------------------------------------------------
                    //----------------------------
                    // 左上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }


                    //----------------------------
                    // 中上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
                    {
                         image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 右上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 左中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 右中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 左下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 中下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 右下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    // 線
                    //---------------------------------------------------------------------------

                    //----------------------------
                    // 上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
                    {
                        double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_ + dy_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_ + dy_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
                    {
                        double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_ + dy_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_ + dy_
                            ),
                            pt_end_
                        );


                    }

                    //----------------------------
                    // 左
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
                    {
                        double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_ + dx_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_ + dx_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );


                    }

                    //----------------------------
                    // 右
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
                    {
                        double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_ + dx_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_ + dx_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );


                    }

                    //----------------------------
                    //
                    //----------------------------

                    //---------------------------------------------------------------------------
                    // 面
                    //---------------------------------------------------------------------------
                    //----------------------------
                    //
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
                    {
                        double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                        double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_ + dx_,
                                Processing_Unit_Region_->Roi_->Y1_ + dy_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_ + dx_,
                                Processing_Unit_Region_->Roi_->Y2_ + dy_
                            ),
                            pt_end_
                        );



                    }
                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    //
                    //---------------------------------------------------------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );
                    }
                }
                else
                {
                    image_view.Image_To_View(
                        halib::point_double(
                            Processing_Unit_Region_->Roi_->X1_,
                            Processing_Unit_Region_->Roi_->Y1_
                        ),
                        pt_start_
                    );

                    image_view.Image_To_View(
                        halib::point_double(
                            Processing_Unit_Region_->Roi_->X2_,
                            Processing_Unit_Region_->Roi_->Y2_
                        ),
                        pt_end_
                    );
                }
            }
            else
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Processing_Unit_Region_->Roi_->X1_,
                        Processing_Unit_Region_->Roi_->Y1_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Processing_Unit_Region_->Roi_->X2_,
                        Processing_Unit_Region_->Roi_->Y2_
                    ),
                    pt_end_
                );
            }

            halib::roi roi_ = halib::roi(
                pt_start_.X_,
                pt_start_.Y_,
                pt_end_.X_,
                pt_end_.Y_,
                true
            );

//            if(Is_Load_Bitmap_)
//            {
//                if(!Is_Deal_ || !image_view.Is_View_Thumbnail_)
//                {
//
//
//                    Bitmap_Thumbnail_->Resize(roi_.Width(), roi_.Height());
//                    halib_image::resize::Resize_Nearest(
//                        *Bitmap_,
//                        halib::roi(0, 0, Bitmap_->Width_ - 1, Bitmap_->Height_ - 1),
//                        *Bitmap_Thumbnail_,
//                        halib::roi(0, 0, roi_.Width() - 1, roi_.Height() - 1)
//                    );
//                    Is_Deal_ = true;
//
//                }
//            }



        }
    }



    return halib_def::image_view_result::SUCCESS;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_webcam::On_Paint_Design(halib::image_view& image_view)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {
        if(image_view.Is_Repaint_)
        {
            // 设置字体
            image_view.Canvas_->Font->Color = clRed;   // 字体颜色
            image_view.Canvas_->Font->Size = 16;        // 字体大小
            image_view.Canvas_->Font->Style = TFontStyles() << fsBold; // 粗体
            image_view.Canvas_->Font->Name = L"新細明體";

            // 让背景透明
            image_view.Canvas_->Brush->Style = bsClear;


            int text_width_ = image_view.Canvas_->TextWidth(Message_Create_.c_str());
        //    int text_height_ = image_view.Canvas_->TextHeight(Message_Create_.c_str());

            // 计算居中位置（假设窗口宽度 400，高度 300）
            int text_center_x = (image_view.View_Width_ - text_width_) / 2;




            // 在 (50, 50) 位置绘制 "Hello, C++ Builder!"
            image_view.Canvas_->TextOut(text_center_x, 50, Message_Create_.c_str());
        }

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {
		if(Processing_Unit_Region_->Type_Region_ == ha_def::processing_unit_region::RECTANGLE)
        {
            halib::point_double pt_start_;
            halib::point_double pt_end_;

            if(Processing_Unit_Region_->Down_Mouse_)
            {

                if(Processing_Unit_Region_->Choose_)
                {
                    //---------------------------------------------------------------------------
                    // 點
                    //---------------------------------------------------------------------------
                    //----------------------------
                    // 左上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }


                    //----------------------------
                    // 中上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
                    {
                         image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 右上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 左中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 右中
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 左下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 中下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 右下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Point_Choose_Move_->X_,
                                Processing_Unit_Region_->Point_Choose_Move_->Y_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    // 線
                    //---------------------------------------------------------------------------

                    //----------------------------
                    // 上
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
                    {
                        double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_ + dy_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_ + dy_
                            ),
                            pt_end_
                        );

                    }

                    //----------------------------
                    // 下
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
                    {
                        double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_ + dy_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_ + dy_
                            ),
                            pt_end_
                        );


                    }

                    //----------------------------
                    // 左
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
                    {
                        double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_ + dx_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_ + dx_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );


                    }

                    //----------------------------
                    // 右
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
                    {
                        double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_ + dx_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_ + dx_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );


                    }

                    //----------------------------
                    //
                    //----------------------------

                    //---------------------------------------------------------------------------
                    // 面
                    //---------------------------------------------------------------------------
                    //----------------------------
                    //
                    //----------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
                    {
                        double dx_ = Processing_Unit_Region_->Point_Choose_Move_->X_ - Processing_Unit_Region_->Point_Choose_Down_->X_;
                        double dy_ = Processing_Unit_Region_->Point_Choose_Move_->Y_ - Processing_Unit_Region_->Point_Choose_Down_->Y_;
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_ + dx_,
                                Processing_Unit_Region_->Roi_->Y1_ + dy_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_ + dx_,
                                Processing_Unit_Region_->Roi_->Y2_ + dy_
                            ),
                            pt_end_
                        );



                    }
                    //----------------------------
                    //
                    //----------------------------
                    //---------------------------------------------------------------------------
                    //
                    //---------------------------------------------------------------------------
                    if(Processing_Unit_Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
                    {
                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X1_,
                                Processing_Unit_Region_->Roi_->Y1_
                            ),
                            pt_start_
                        );

                        image_view.Image_To_View(
                            halib::point_double(
                                Processing_Unit_Region_->Roi_->X2_,
                                Processing_Unit_Region_->Roi_->Y2_
                            ),
                            pt_end_
                        );
                    }
                }
                else
                {
                    image_view.Image_To_View(
                        halib::point_double(
                            Processing_Unit_Region_->Roi_->X1_,
                            Processing_Unit_Region_->Roi_->Y1_
                        ),
                        pt_start_
                    );

                    image_view.Image_To_View(
                        halib::point_double(
                            Processing_Unit_Region_->Roi_->X2_,
                            Processing_Unit_Region_->Roi_->Y2_
                        ),
                        pt_end_
                    );
                }
            }
            else
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Processing_Unit_Region_->Roi_->X1_,
                        Processing_Unit_Region_->Roi_->Y1_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Processing_Unit_Region_->Roi_->X2_,
                        Processing_Unit_Region_->Roi_->Y2_
                    ),
                    pt_end_
                );
            }

            halib::roi roi_ = halib::roi(
                pt_start_.X_,
                pt_start_.Y_,
                pt_end_.X_,
                pt_end_.Y_,
                true
            );


            if(image_view.Is_Repaint_)
            {
//                if(Is_Load_Bitmap_)
//                {
//                    int w_ = form_->view_image->Picture->Bitmap->Width;
//                    int h_ = form_->view_image->Picture->Bitmap->Height;
//
//                    if(h_ > 0 && Bitmap_Thumbnail_->Width_ > 0 && Bitmap_Thumbnail_->Height_)
//                    {
//
//                        halib::bitmap_ptr_argb temp_((unsigned char*)form_->view_image->Picture->Bitmap->ScanLine[0]);
//
//                        temp_.Resize(w_, h_);
//
//
//                        halib::roi roi_dst_ = roi_;
//
//                        halib_bitmap::bitmap::Fix_Roi(roi_dst_, temp_, true);
//
//                        if(roi_dst_.Width() > 0 && roi_dst_.Height() > 0)
//                        {
//                            halib_image::alpha_comp::Alpha_Comp(
//                                *Bitmap_Thumbnail_,
//                                halib::roi(roi_dst_.X1_ - roi_.X1_, roi_dst_.Y1_ - roi_.Y1_,
//                                    roi_dst_.X1_ - roi_.X1_ + roi_dst_.Width() - 1,
//                                    roi_dst_.Y1_ - roi_.Y1_ + roi_dst_.Height() - 1),
//                                temp_,
//                                roi_dst_,
//                                halib_def_image::alpha_type::ALPHA_OVER_PREMUL
//                            );
//                        }
//
//
//
//
//                        //---------------------------------------------------------------------------
//                        //
//                        //---------------------------------------------------------------------------
//
//                    }
//                }



                if(!Processing_Unit_Region_->Is_Paint_Frame_ && !Processing_Unit_Region_->Choose_)
                {
                    // 在這裡才paint frame
                    Processing_Unit_Region_->Paint_Frame(image_view);
                }
            }




        }
    }



    return halib_def::image_view_result::SUCCESS;

}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Prepare_Node(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    std::vector<std::wstring>& node_names_target,
    hahahalib::hahaha_parameter_deal_xml_node& root,
    hahahalib::hahaha_parameter_deal_xml_node& node,
    hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
    xmlDocPtr xml_doc,
    xmlNodePtr xml_node_root,
    xmlNodePtr xml_node_cur,
    std::wstring & xml_wstring,
    const halib_def::type_variable& type,
    void* value
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Prepare_Attribute(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    std::vector<std::wstring>& node_names_target,
    hahahalib::hahaha_parameter_deal_xml_node& root,
    hahahalib::hahaha_parameter_deal_xml_node& node,
    hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
    xmlDocPtr xml_doc,
    xmlNodePtr xml_node_root,
    xmlNodePtr xml_node_cur,
    std::wstring & xml_wstring,
    const halib_def::type_variable& type,
    void* value
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Prepare_Value(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    std::vector<std::wstring>& node_names_target,
    hahahalib::hahaha_parameter_deal_xml_node& root,
    hahahalib::hahaha_parameter_deal_xml_node& node,
    hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
    xmlDocPtr xml_doc,
    xmlNodePtr xml_node_root,
    xmlNodePtr xml_node_cur,
    std::wstring & xml_wstring,
    const halib_def::type_variable& type,
    void* value
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Mapping(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    std::vector<std::wstring> node_names_;
    hahahalib::Vector_Copy(node_names, node_names_);


    std::vector<hahahalib::hahaha_parameter_deal_xml_item> items_ = {
        {node_names_,
			L"", halib_def::xml_type::NODE, halib_def::type_variable::NONE, (void*)NULL},
        {{},
			L"Type_Strategy", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Type_Strategy_},
        {{},
			L"Type_Factory_Strategy", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Type_Factory_Strategy_},

        {node_names_,
			L"Camera", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Camera_},
        {node_names_,
			L"Enabled", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Enabled_},
        {node_names_,
			L"Resolution", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Resolution_},
        {node_names_,
			L"Fps", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Fps_},
        {node_names_,
			L"Direction", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Direction_},
        //
	};




    root.Add(items_);




    return result;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    Processing_Unit_Region_->Is_Paint_Frame_ = false;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_webcam::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;

    ha::Form_Processing_Unit_Strategy_Webcam_->Is_Update = true;

    bool Ratio_Fix_ = true;

    if(Ratio_Fix_)
    {
        halib_bitmap::bitmap_double::Fix_Roi_Bitmap_Ratio(*Processing_Unit_Region_->Roi_, *Bitmap_);

    }


	Structure_Main_->Image_View_->Is_Invalidate_View_Image_ = true;
    ha::Form_Processing_Unit_Strategy_Webcam_->Is_Update = false;
    Is_Deal_ = false;

    return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------
