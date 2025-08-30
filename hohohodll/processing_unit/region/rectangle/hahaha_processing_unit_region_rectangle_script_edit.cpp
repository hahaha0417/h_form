//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_processing_unit_region_rectangle_script_edit.h"
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <processing_unit\region\hahaha_processing_unit_region_rectangle.h>
#include <image_view\hahaha_form_image_view.h>

#include <define\hahaha_define_ho.h>

#include <shape\hahaha_line.h>
#include <shape\hahaha_line_segment.h>
#include <shape\function\hahaha_shape_function_line_segment.h>
#include <shape\function\hahaha_shape_function_point.h>
#include <shape\function\hahaha_shape_function_roi.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_edit::hahaha_processing_unit_region_rectangle_script_edit()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_edit::~hahaha_processing_unit_region_rectangle_script_edit()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_edit::hahaha_processing_unit_region_rectangle_script_edit(const hahaha_processing_unit_region_rectangle_script_edit& hpurrse)
{
    Reset();
	Copy(hpurrse);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_edit::hahaha_processing_unit_region_rectangle_script_edit(hahaha_processing_unit_region_rectangle_script_edit&& hpurrse) noexcept
{
     Move(std::move(hpurrse));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_edit& hahaha_processing_unit_region_rectangle_script_edit::operator=(const hahaha_processing_unit_region_rectangle_script_edit& hpurrse)
{
	Copy(hpurrse);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_region_rectangle_script_edit& hahaha_processing_unit_region_rectangle_script_edit::operator=(hahaha_processing_unit_region_rectangle_script_edit&& hpurrse) noexcept
{
    Move(std::move(hpurrse));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle_script_edit::Copy(const hahaha_processing_unit_region_rectangle_script_edit& hpurrse)
{
    Region_ = hpurrse.Region_;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_region_rectangle_script_edit::Move(hahaha_processing_unit_region_rectangle_script_edit&& hpurrse) noexcept
{
    Region_ = hpurrse.Region_;
}
//---------------------------------------------------------------------------
int hahaha_processing_unit_region_rectangle_script_edit::Reset()
{
    Region_ = NULL;

	return 0;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_edit::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    Region_->Down_Mouse_ = true;

    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------
    if(Region_->Choose_)
    {
        //
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



        halib::roi roi_ = halib::roi(
            pt_start_.X_,
            pt_start_.Y_,
            pt_end_.X_,
            pt_end_.Y_,
            true
        );
        //---------------------------------------------------------------------------
        // 點
        //---------------------------------------------------------------------------
        //----------------------------
        // 左上
        //----------------------------
        {

            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_LEFT_TOP;

                return halib_def::image_view_result::BREAK;
            }
        }


        //----------------------------
        // 中上
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右上
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_RIGHT_TOP;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左中
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, (roi_.Y1_ + roi_.Y2_) >> 1), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右中
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, (roi_.Y1_ + roi_.Y2_) >> 1), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左下
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 中下
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右下
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        //
        //----------------------------

        //---------------------------------------------------------------------------
        // 線
        //---------------------------------------------------------------------------
        int distance_ = Region_->Paint_Line_Size_ * 500;
        //----------------------------
        // 上
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y1_),
                halib::point(roi_.X2_, roi_.Y1_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::LINE_TOP;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 下
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y2_),
                halib::point(roi_.X2_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::LINE_BOTTOM;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y1_),
                halib::point(roi_.X1_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::LINE_LEFT;

                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X2_, roi_.Y1_),
                halib::point(roi_.X2_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::LINE_RIGHT;

                return halib_def::image_view_result::BREAK;
            }
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
        {
            if(halib_shape::roi::Is_Point_In(roi_, halib::point(X, Y))
            )
            {
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Down_
                );
                image_view.View_To_Image(
                    halib::point_double(
                        X,
                        Y
                    ),
                    *Region_->Point_Choose_Move_
                );



                Region_->Choose_Region_ = ha_def::processing_unit_region_choose::PLANE;

                return halib_def::image_view_result::BREAK;
            }
        }
        //----------------------------
        //
        //----------------------------
        //---------------------------------------------------------------------------
        //
        //---------------------------------------------------------------------------
        Region_->Choose_Region_ = ha_def::processing_unit_region_choose::NONE;
    }


    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_edit::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;






    //---------------------------------------------------------------------------
    if(Region_->Down_Mouse_)
    {
        //---------------------------------------------------------------------------
        //
        //---------------------------------------------------------------------------
        Region_->Candidate_ = false;
        //
        if(Region_->Choose_Region_ != ha_def::processing_unit_region_choose::NONE)
        {
            image_view.View_To_Image(
                halib::point_double(
                    X,
                    Y
                ),
                *Region_->Point_Choose_Move_
            );



            image_view.Is_Repaint_ = true;
        }
        else
        {
            image_view.Is_Repaint_ = false;
        }

        //---------------------------------------------------------------------------
        //
        //---------------------------------------------------------------------------
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



        halib::roi roi_ = halib::roi(
            pt_start_.X_,
            pt_start_.Y_,
            pt_end_.X_,
            pt_end_.Y_,
            true
        );


        //---------------------------------------------------------------------------
        // 點
        //---------------------------------------------------------------------------
        //----------------------------
        // 左上
        //----------------------------
        if(Region_->Choose_)
        {

            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeNWSE;

                return halib_def::image_view_result::BREAK;
            }
        }


        //----------------------------
        // 中上
        //----------------------------
        if(Region_->Choose_)
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeNS;


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右上
        //----------------------------
        if(Region_->Choose_)
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeNESW;


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左中
        //----------------------------
        if(Region_->Choose_)
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, (roi_.Y1_ + roi_.Y2_) >> 1), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeWE;


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右中
        //----------------------------
        if(Region_->Choose_)
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, (roi_.Y1_ + roi_.Y2_) >> 1), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeWE;


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左下
        //----------------------------
        if(Region_->Choose_)
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeNESW;


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 中下
        //----------------------------
        if(Region_->Choose_)
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeNS;


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右下
        //----------------------------
        if(Region_->Choose_)
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {
                form_->view_image->Cursor = crSizeNWSE;


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        //
        //----------------------------

        //---------------------------------------------------------------------------
        // 線
        //---------------------------------------------------------------------------
        int distance_ = Region_->Paint_Line_Size_ * 500;
        //----------------------------
        // 上
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y1_),
                halib::point(roi_.X2_, roi_.Y1_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                if(Region_->Choose_)
                {
                    form_->view_image->Cursor = crHandPoint;
                }
                else
                {
                    form_->view_image->Cursor = crHandPoint;
                }


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 下
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y2_),
                halib::point(roi_.X2_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                if(Region_->Choose_)
                {
                    form_->view_image->Cursor = crHandPoint;
                }
                else
                {
                    form_->view_image->Cursor = crHandPoint;
                }


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y1_),
                halib::point(roi_.X1_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                if(Region_->Choose_)
                {
                    form_->view_image->Cursor = crHandPoint;
                }
                else
                {
                    form_->view_image->Cursor = crHandPoint;
                }


                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X2_, roi_.Y1_),
                halib::point(roi_.X2_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {
                if(Region_->Choose_)
                {
                    form_->view_image->Cursor = crHandPoint;
                }
                else
                {
                    form_->view_image->Cursor = crHandPoint;
                }


                return halib_def::image_view_result::BREAK;
            }
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
        {
            if(halib_shape::roi::Is_Point_In(roi_, halib::point(X, Y))
            )
            {
                if(Region_->Choose_)
                {
                    form_->view_image->Cursor = crHandPoint;
                    return halib_def::image_view_result::BREAK;
                }
                else
                {
                    form_->view_image->Cursor = crHandPoint;
                    if(!Region_->Candidate_)
                    {
                        if(ha::Pointer_Main_->Candidate_Processing_Unit_ == nullptr)
                        {
                            ha::Pointer_Main_->Candidate_Processing_Unit_ = Region_->Processing_Unit_Base_;
                            Region_->Candidate_ = true;
                            image_view.Is_Repaint_ = true;
                            image_view.Is_Invalidate_View_Image_ = true;
                        }

                    }
                    else
                    {
                        if(ha::Pointer_Main_->Candidate_Processing_Unit_ != nullptr)
                        {
                        	if(ha::Pointer_Main_->Candidate_Processing_Unit_ != Region_->Processing_Unit_Base_)
                            {
                                // 選中其他框
                                Region_->Candidate_ = false;
                                image_view.Is_Repaint_ = true;
                                image_view.Is_Invalidate_View_Image_ = true;
                            }
                            else
                            {

                            }

                        }
                        else
                        {
                            // 是自己
                            ha::Pointer_Main_->Candidate_Processing_Unit_ = Region_->Processing_Unit_Base_;
                        }
                    }


                }



            }
            else
            {
                if(Region_->Candidate_)
                {
                    // 選中其他框
                    Region_->Candidate_ = false;
                    image_view.Is_Repaint_ = true;
                    image_view.Is_Invalidate_View_Image_ = true;
                }
            }
        }
        //----------------------------
        //
        //----------------------------
        //---------------------------------------------------------------------------
        //
        //---------------------------------------------------------------------------

    }





    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    form_->view_image->Cursor = crArrow;

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_edit::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    Region_->Down_Mouse_ = false;

    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------
    if(Region_->Choose_Region_ != ha_def::processing_unit_region_choose::NONE)
    {
        image_view.Is_Repaint_ = true;
        image_view.View_To_Image(
            halib::point_double(
                X,
                Y
            ),
            *Region_->Point_Choose_Move_
        );
    }



    //
    if(Region_->Choose_)
    {
        //---------------------------------------------------------------------------
        // 點
        //---------------------------------------------------------------------------
        //----------------------------
        // 左上
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
        {

            *Region_->Roi_ = halib::roi_double(
                Region_->Point_Choose_Move_->X_,
                Region_->Point_Choose_Move_->Y_,
                Region_->Roi_->X2_,
                Region_->Roi_->Y2_,
                true
            );

        }


        //----------------------------
        // 中上
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_,
                Region_->Point_Choose_Move_->Y_,
                Region_->Roi_->X2_,
                Region_->Roi_->Y2_,
                true
            );


        }

        //----------------------------
        // 右上
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_,
                Region_->Point_Choose_Move_->Y_,
                Region_->Point_Choose_Move_->X_,
                Region_->Roi_->Y2_,
                true
            );


        }

        //----------------------------
        // 左中
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Point_Choose_Move_->X_,
                Region_->Roi_->Y1_,
                Region_->Roi_->X2_,
                Region_->Roi_->Y2_,
                true
            );


        }

        //----------------------------
        // 右中
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_,
                Region_->Roi_->Y1_,
                Region_->Point_Choose_Move_->X_,
                Region_->Roi_->Y2_,
                true
            );


        }

        //----------------------------
        // 左下
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Point_Choose_Move_->X_,
                Region_->Roi_->Y1_,
                Region_->Roi_->X2_,
                Region_->Point_Choose_Move_->Y_,
                true
            );


        }

        //----------------------------
        // 中下
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_,
                Region_->Roi_->Y1_,
                Region_->Roi_->X2_,
                Region_->Point_Choose_Move_->Y_,
                true
            );


        }

        //----------------------------
        // 右下
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
        {
            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_,
                Region_->Roi_->Y1_,
                Region_->Point_Choose_Move_->X_,
                    Region_->Point_Choose_Move_->Y_,
                true
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
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
        {
            double dy_ = Region_->Point_Choose_Move_->Y_ - Region_->Point_Choose_Down_->Y_;

            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_,
                Region_->Roi_->Y1_ + dy_,
                Region_->Roi_->X2_,
                Region_->Roi_->Y2_ + dy_,
                true
            );


        }

        //----------------------------
        // 下
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
        {
            double dy_ = Region_->Point_Choose_Move_->Y_ - Region_->Point_Choose_Down_->Y_;

            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_,
                Region_->Roi_->Y1_ + dy_,
                Region_->Roi_->X2_,
                Region_->Roi_->Y2_ + dy_,
                true
            );


        }

        //----------------------------
        // 左
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
        {
            double dx_ = Region_->Point_Choose_Move_->X_ - Region_->Point_Choose_Down_->X_;

            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_ + dx_,
                Region_->Roi_->Y1_,
                Region_->Roi_->X2_ + dx_,
                Region_->Roi_->Y2_,
                true
            );


        }

        //----------------------------
        // 右
        //----------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
        {
            double dx_ = Region_->Point_Choose_Move_->X_ - Region_->Point_Choose_Down_->X_;

            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_ + dx_,
                Region_->Roi_->Y1_,
                Region_->Roi_->X2_ + dx_,
                Region_->Roi_->Y2_,
                true
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
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
        {
            double dx_ = Region_->Point_Choose_Move_->X_ - Region_->Point_Choose_Down_->X_;
            double dy_ = Region_->Point_Choose_Move_->Y_ - Region_->Point_Choose_Down_->Y_;

            *Region_->Roi_ = halib::roi_double(
                Region_->Roi_->X1_ + dx_,
                Region_->Roi_->Y1_ + dy_,
                Region_->Roi_->X2_ + dx_,
                    Region_->Roi_->Y2_ + dy_,
                true
            );

            ha::Pointer_Main_->Choose_Processing_Unit_ = Region_->Processing_Unit_Base_;
        }
        //----------------------------
        //
        //----------------------------
        //---------------------------------------------------------------------------
        //
        //---------------------------------------------------------------------------
        if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
        {
            Region_->Choose_ = false;

        }
        image_view.Is_Repaint_ = true;
    }
    else
    {
        //
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



        halib::roi roi_ = halib::roi(
            pt_start_.X_,
            pt_start_.Y_,
            pt_end_.X_,
            pt_end_.Y_,
            true
        );
        //---------------------------------------------------------------------------
        // 點
        //---------------------------------------------------------------------------
        //----------------------------
        // 左上
        //----------------------------
        {

            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }


        //----------------------------
        // 中上
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右上
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, roi_.Y1_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左中
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, (roi_.Y1_ + roi_.Y2_) >> 1), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右中
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, (roi_.Y1_ + roi_.Y2_) >> 1), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左下
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X1_, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 中下
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右下
        //----------------------------
        {
            halib::roi r_ = halib_shape::point::Center_Roi(halib::point(roi_.X2_, roi_.Y2_), Region_->Paint_Point_Size_);
            if(halib_shape::roi::Is_Point_In(r_, halib::point(X, Y))
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        //
        //----------------------------

        //---------------------------------------------------------------------------
        // 線
        //---------------------------------------------------------------------------
        int distance_ = Region_->Paint_Line_Size_ * 500;
        //----------------------------
        // 上
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y1_),
                halib::point(roi_.X2_, roi_.Y1_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 下
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y2_),
                halib::point(roi_.X2_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 左
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X1_, roi_.Y1_),
                halib::point(roi_.X1_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }

        //----------------------------
        // 右
        //----------------------------
        {
            halib::line_segment line_segment_ = halib::line_segment(halib::point(roi_.X2_, roi_.Y1_),
                halib::point(roi_.X2_, roi_.Y2_)
            );
            if(halib_shape::line_segment::Is_On_Line_Segment_With_Tolerance(line_segment_, halib::point(X, Y), distance_)
            )
            {

                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                return halib_def::image_view_result::BREAK;
            }
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
        {
            if(halib_shape::roi::Is_Point_In(roi_, halib::point(X, Y))
            )
            {
                
                Region_->Choose_ = true;
                image_view.Is_Repaint_ = true;
                image_view.Is_Invalidate_View_Image_ = true;
                return halib_def::image_view_result::BREAK;
            }
        }
        //----------------------------
        //
        //----------------------------
        //---------------------------------------------------------------------------
        //
        //---------------------------------------------------------------------------


        Region_->Choose_ = false;
        image_view.Is_Repaint_ = true;
    }

    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_edit::On_Paint_Design(halib::image_view& image_view)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;

    if(image_view.Is_Repaint_)
    {
        if(Region_->Is_Paint_Frame_ && !Region_->Choose_)
        {
            Region_->Paint_Frame(image_view);
        }
    }




    //---------------------------
    //
    //---------------------------

    //---------------------------------------------------------------------------

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_region_rectangle_script_edit::Paint_Frame(halib::image_view& image_view)
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    halib::point_double pt_start_;
    halib::point_double pt_end_;



    if(Region_->Down_Mouse_)
    {
        if(Region_->Choose_)
        {
            //---------------------------------------------------------------------------
            // 點
            //---------------------------------------------------------------------------
            //----------------------------
            // 左上
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_TOP)
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Point_Choose_Move_->X_,
                        Region_->Point_Choose_Move_->Y_
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

            }


            //----------------------------
            // 中上
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_TOP)
            {
                 image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_,
                        Region_->Point_Choose_Move_->Y_
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

            }

            //----------------------------
            // 右上
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_TOP)
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_,
                        Region_->Point_Choose_Move_->Y_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Point_Choose_Move_->X_,
                        Region_->Roi_->Y2_
                    ),
                    pt_end_
                );

            }

            //----------------------------
            // 左中
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_MIDDLE)
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Point_Choose_Move_->X_,
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

            }

            //----------------------------
            // 右中
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_MIDDLE)
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_,
                        Region_->Roi_->Y1_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Point_Choose_Move_->X_,
                        Region_->Roi_->Y2_
                    ),
                    pt_end_
                );

            }

            //----------------------------
            // 左下
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_LEFT_BOTTOM)
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Point_Choose_Move_->X_,
                        Region_->Roi_->Y1_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X2_,
                        Region_->Point_Choose_Move_->Y_
                    ),
                    pt_end_
                );

            }

            //----------------------------
            // 中下
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_MIDDLE_BOTTOM)
            {
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
                        Region_->Point_Choose_Move_->Y_
                    ),
                    pt_end_
                );

            }

            //----------------------------
            // 右下
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::POINT_RIGHT_BOTTOM)
            {
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_,
                        Region_->Roi_->Y1_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Point_Choose_Move_->X_,
                        Region_->Point_Choose_Move_->Y_
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
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_TOP)
            {
                double dy_ = Region_->Point_Choose_Move_->Y_ - Region_->Point_Choose_Down_->Y_;
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_,
                        Region_->Roi_->Y1_ + dy_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X2_,
                        Region_->Roi_->Y2_ + dy_
                    ),
                    pt_end_
                );

            }

            //----------------------------
            // 下
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_BOTTOM)
            {
                double dy_ = Region_->Point_Choose_Move_->Y_ - Region_->Point_Choose_Down_->Y_;
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_,
                        Region_->Roi_->Y1_ + dy_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X2_,
                        Region_->Roi_->Y2_ + dy_
                    ),
                    pt_end_
                );


            }

            //----------------------------
            // 左
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_LEFT)
            {
                double dx_ = Region_->Point_Choose_Move_->X_ - Region_->Point_Choose_Down_->X_;
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_ + dx_,
                        Region_->Roi_->Y1_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X2_ + dx_,
                        Region_->Roi_->Y2_
                    ),
                    pt_end_
                );


            }

            //----------------------------
            // 右
            //----------------------------
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::LINE_RIGHT)
            {
                double dx_ = Region_->Point_Choose_Move_->X_ - Region_->Point_Choose_Down_->X_;
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_ + dx_,
                        Region_->Roi_->Y1_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X2_ + dx_,
                        Region_->Roi_->Y2_
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
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::PLANE)
            {
                double dx_ = Region_->Point_Choose_Move_->X_ - Region_->Point_Choose_Down_->X_;
                double dy_ = Region_->Point_Choose_Move_->Y_ - Region_->Point_Choose_Down_->Y_;
                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X1_ + dx_,
                        Region_->Roi_->Y1_ + dy_
                    ),
                    pt_start_
                );

                image_view.Image_To_View(
                    halib::point_double(
                        Region_->Roi_->X2_ + dx_,
                        Region_->Roi_->Y2_ + dy_
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
            if(Region_->Choose_Region_ == ha_def::processing_unit_region_choose::NONE)
            {
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
            }
        }
        else
        {
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
        }

    }
    else
    {
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
    }


    halib::roi roi_ = halib::roi(
        pt_start_.X_,
        pt_start_.Y_,
        pt_end_.X_,
        pt_end_.Y_,
        true
    );

    // 设置字体
    if(Region_->Choose_)
    {
        image_view.Canvas_->Pen->Color = clRed;   // 字体颜色

        image_view.Canvas_->Pen->Width = Region_->Paint_Line_Size_ * 2 + 1;   // 字体颜色

        // 让背景透明
        image_view.Canvas_->Brush->Style = bsClear;



        // 画矩形框 (左上角 x, y, 右下角 x, y)
        image_view.Canvas_->Rectangle(roi_.X1_,
            roi_.Y1_,
            roi_.X2_,
            roi_.Y2_
        );
    }
    else if(Region_->Candidate_)
    {
        image_view.Canvas_->Pen->Color = clBlue;   // 字体颜色

        image_view.Canvas_->Pen->Width = Region_->Paint_Line_Size_ * 2 + 1;   // 字体颜色

        // 让背景透明
        image_view.Canvas_->Brush->Style = bsClear;



        // 画矩形框 (左上角 x, y, 右下角 x, y)
        image_view.Canvas_->Rectangle(roi_.X1_,
            roi_.Y1_,
            roi_.X2_,
            roi_.Y2_
        );
    }
    else
    {
        image_view.Canvas_->Pen->Width = Region_->Paint_Line_Size_ * 2 + 1;   // 字体颜色

        // 让背景透明
        image_view.Canvas_->Brush->Style = bsClear;
    }










    //---------------------------------------------------------------------------
    image_view.Canvas_->Pen->Color = clRed;   // 字体颜色
    image_view.Canvas_->Pen->Width = 2;   // 字体颜色

    // 让背景透明
    image_view.Canvas_->Brush->Color = clRed;   // 字体颜色
    image_view.Canvas_->Brush->Style = bsSolid;

    if(Region_->Choose_)
    {
        {
            //---------------------------
            // 左上
            //---------------------------
            halib::point pt_ = halib::point(roi_.X1_, roi_.Y1_);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }

        {
            //---------------------------
            // 中上
            //---------------------------
            halib::point pt_ = halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y1_);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }

        {
            //---------------------------
            // 右上
            //---------------------------
            halib::point pt_ = halib::point(roi_.X2_, roi_.Y1_);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }

        {
            //---------------------------
            // 左中
            //---------------------------
            halib::point pt_ = halib::point(roi_.X1_, (roi_.Y1_ + roi_.Y2_) >> 1);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }

        {
            //---------------------------
            // 右中
            //---------------------------
            halib::point pt_ = halib::point(roi_.X2_, (roi_.Y1_ + roi_.Y2_) >> 1);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }

        {
            //---------------------------
            // 左下
            //---------------------------
            halib::point pt_ = halib::point(roi_.X1_, roi_.Y2_);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }

        {
            //---------------------------
            // 中下
            //---------------------------
            halib::point pt_ = halib::point((roi_.X1_ + roi_.X2_) >> 1, roi_.Y2_);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }

        {
            //---------------------------
            // 右下
            //---------------------------
            halib::point pt_ = halib::point(roi_.X2_, roi_.Y2_);
            image_view.Canvas_->Rectangle(pt_.X_ - Region_->Paint_Point_Size_,
                pt_.Y_ - Region_->Paint_Point_Size_,
                pt_.X_ + Region_->Paint_Point_Size_,
                pt_.Y_ + Region_->Paint_Point_Size_
            );

        }
    }


    //---------------------------
    //
    //---------------------------

    //---------------------------------------------------------------------------

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------