//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_processing_unit_region_rectangle_script_create.h"
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
#include <shape\hahaha_roi.h>

#include <windows.h>
//---------------------------------------------------------------------------
#include <processing_unit\region\hahaha_processing_unit_region_rectangle.h>
#include <image_view\hahaha_form_image_view.h>
#include <view\hahaha_view_scene.h>
#include <view\hahaha_view_view.h>

#include <define\hahaha_define_ho.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_create::hahaha_processing_unit_region_rectangle_script_create()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_create::~hahaha_processing_unit_region_rectangle_script_create()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_create::hahaha_processing_unit_region_rectangle_script_create(const hahaha_processing_unit_region_rectangle_script_create& hpurrsc)
{
    Reset();
	Copy(hpurrsc);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_create::hahaha_processing_unit_region_rectangle_script_create(hahaha_processing_unit_region_rectangle_script_create&& hpurrsc) noexcept
{
    Move(std::move(hpurrsc));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_create& hahaha_processing_unit_region_rectangle_script_create::operator=(const hahaha_processing_unit_region_rectangle_script_create& hpurrsc)
{
	Copy(hpurrsc);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_create& hahaha_processing_unit_region_rectangle_script_create::operator=(hahaha_processing_unit_region_rectangle_script_create&& hpurrsc) noexcept
{
    Move(std::move(hpurrsc));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle_script_create::Copy(const hahaha_processing_unit_region_rectangle_script_create& hpurrsc)
{
    Region_ = hpurrsc.Region_;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle_script_create::Move(hahaha_processing_unit_region_rectangle_script_create&& hpurrsc) noexcept
{
    Region_ = hpurrsc.Region_;
}
//---------------------------------------------------------------------------
int hahaha_processing_unit_region_rectangle_script_create::Reset()
{
    Region_ = NULL;

	return 0;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_create::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    Region_->Down_Mouse_ = true;

	image_view.View_To_Image(
		halib::point_double(
			X,
			Y
		),
		*Region_->Point_Start_
	);

    image_view.Is_Repaint_ = true;

    return halib_def::image_view_result::BREAK;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_create::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
	if(Region_->Candidate_)
    {
        Region_->Candidate_ = false;
        image_view.Is_Repaint_ = true;
    }


	if(Region_->Down_Mouse_)
    {
        image_view.View_To_Image(
            halib::point_double(
                X,
                Y
            ),
            *Region_->Point_End_
        );


        image_view.Is_Repaint_ = true;

        return halib_def::image_view_result::BREAK;
    }


    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_create::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(Region_->Down_Mouse_)
    {
        Region_->Down_Mouse_ = false;
        Region_->Processing_Unit_Strategy_->Is_Deal_ = false;
        image_view.Is_Repaint_ = true;

        //---------------------------------------------------------------------------
        //
        //---------------------------------------------------------------------------
        image_view.View_To_Image(
            halib::point_double(
                X,
                Y
            ),
            *Region_->Point_End_
        );

        if(std::abs(Region_->Point_End_->X_ - Region_->Point_Start_->X_) >= 5 &&
            std::abs(Region_->Point_End_->Y_ - Region_->Point_Start_->Y_) >= 5
        )
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Point_Start_->X_,
                Region_->Point_Start_->Y_,
                Region_->Point_End_->X_,
                Region_->Point_End_->Y_,
                true
            );
            //---------------------------------------------------------------------------
            //
            Region_->State_Region_ = ha_def::processing_unit_region_state::EDIT;
            Region_->Is_Create_ = true;
            // 先簡單做，拉完直接變換
            ha::Pointer_Main_->Select_View_->Get_Parameter();
            image_view.Repaint();


            return halib_def::image_view_result::BREAK;
        }
        else
        {
            *Region_->Roi_ = halib::roi_double();
        }

        *Region_->Point_Start_ = halib::point_double();
        *Region_->Point_End_ = halib::point_double();
    }


    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_create::On_Paint_Design(halib::image_view& image_view)
{
	if(Region_->Down_Mouse_)
    {
        if(*Region_->Point_Start_ != halib::point_double() &&
            *Region_->Point_End_ != halib::point_double()
        )
        {
            halib::point_double pt_start_;
            halib::point_double pt_end_;

            image_view.Image_To_View(
                *Region_->Point_Start_,
                pt_start_
            );

            image_view.Image_To_View(
                *Region_->Point_End_,
                pt_end_
            );

            // 设置字体
            image_view.Canvas_->Pen->Color = clRed;   // 字体颜色
            image_view.Canvas_->Pen->Width = Region_->Paint_Line_Size_ * 2 + 1;   // 字体颜色

            // 让背景透明
            image_view.Canvas_->Brush->Style = bsClear;

            halib::roi roi_ = halib::roi(
                pt_start_.X_,
                pt_start_.Y_,
                pt_end_.X_,
                pt_end_.Y_,
                true
            );

            // 画矩形框 (左上角 x, y, 右下角 x, y)
    		image_view.Canvas_->Rectangle(roi_.X1_,
                roi_.Y1_,
                roi_.X2_,
                roi_.Y2_
            );


        }

    }
    else
    {
        halib::point_double pt_start_;
        halib::point_double pt_end_;

        image_view.Image_To_View(
            halib::point_double(
                Region_->Roi_->X1_,
                Region_->Roi_->Y1_
            ),
            pt_start_
        );

        image_view.Image_To_View(
            halib::point_double(
                Region_->Roi_->X2_,
                Region_->Roi_->Y2_
            ),
            pt_end_
        );

        // 设置字体
        image_view.Canvas_->Pen->Color = clRed;   // 字体颜色
        image_view.Canvas_->Pen->Width = Region_->Paint_Line_Size_ * 2 + 1;   // 字体颜色

        // 让背景透明
        image_view.Canvas_->Brush->Style = bsClear;

        halib::roi roi_ = halib::roi(
            pt_start_.X_,
            pt_start_.Y_,
            pt_end_.X_,
            pt_end_.Y_,
            true
        );

        // 画矩形框 (左上角 x, y, 右下角 x, y)
        image_view.Canvas_->Rectangle(roi_.X1_,
            roi_.Y1_,
            roi_.X2_,
            roi_.Y2_
        );




    }

    if(*Region_->Roi_ == halib::roi_double())
    {




        return halib_def::image_view_result::SUCCESS;
    }

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------