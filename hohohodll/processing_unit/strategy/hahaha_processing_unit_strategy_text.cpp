//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <define\processing_unit\hahaha_define_processing_unit_region.h>
#include <form\processing_unit\strategy\hahaha_processing_unit_form_strategy_text.h>
#include <define\hahaha_define_ho.h>

#include <define\processing_unit\hahaha_define_processing_unit_region.h>
//---------------------------------------------------------------------------
#include <image_process\set\hahaha_image_process_set.h>
#include <image_process\copy\hahaha_image_process_copy.h>
#include <image_process\resize\hahaha_image_process_resize.h>
#include <image_process\alpha\hahaha_image_process_alpha_comp.h>

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

//---------------------------------------------------------------------------
#include <bitmap\function\base\hahaha_bitmap_function_bitmap.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
//---------------------------------------------------------------------------

#include "hahaha_processing_unit_strategy_text.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_text::hahaha_processing_unit_strategy_text()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_text::~hahaha_processing_unit_strategy_text()
{

}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_text::hahaha_processing_unit_strategy_text(const hahaha_processing_unit_strategy_text& hpust)
{
    Reset();
    hahaha::hahaha_processing_unit_strategy::Copy(hpust);
	Copy(hpust);
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_text::hahaha_processing_unit_strategy_text(hahaha_processing_unit_strategy_text&& hpust) noexcept
{
    hahaha::hahaha_processing_unit_strategy::Move(std::move(hpust));
	Move(std::move(hpust));
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_text& hahaha_processing_unit_strategy_text::operator=(const hahaha_processing_unit_strategy_text& hpust)
{
    hahaha::hahaha_processing_unit_strategy::Copy(hpust);
	Copy(hpust);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_processing_unit_strategy_text& hahaha_processing_unit_strategy_text::operator=(hahaha_processing_unit_strategy_text&& hpust) noexcept
{
    hahaha::hahaha_processing_unit_strategy::Move(std::move(hpust));
	Move(std::move(hpust));

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_processing_unit_strategy_text::Copy(const hahaha_processing_unit_strategy_text& hpust)
{

}
//---------------------------------------------------------------------------
void hahaha_processing_unit_strategy_text::Move(hahaha_processing_unit_strategy_text&& hpust) noexcept
{
    Font_Type_ = std::move(hpust.Font_Type_);
    Content_ = std::move(hpust.Content_);
    Font_Color_ = Font_Color_;
    Font_Size_ = Font_Size_;

    Message_Create_ = std::move(hpust.Message_Create_);

    Bitmap_Text_ = std::move(hpust.Bitmap_Text_);
}
//---------------------------------------------------------------------------
int hahaha_processing_unit_strategy_text::Reset()
{
    Type_Strategy_ = ha_def::processing_unit_strategy::TEXT;
    Name_Strategy_ = L"text";

    std::vector<std::wstring>().swap(Content_);
    Font_Color_ = (unsigned int)(RGB(255, 0, 0));
    Font_Size_ = 12;

    if(Bitmap_Text_.get() == NULL)
    {
        Bitmap_Text_.reset(new TBitmap());
    }


    Message_Create_ = L"建立文字框";
    Is_Deal_ = false;

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_text::Set_Parameter()
{
    ha::Form_Processing_Unit_Strategy_Text_->Is_Update = true;
    int index_ = ha::Form_Processing_Unit_Strategy_Text_->combo_box_font->Items->IndexOf(Font_Type_.c_str());
    if(index_ != -1)
    {
        ha::Form_Processing_Unit_Strategy_Text_->combo_box_font->ItemIndex = index_;
    }
    else
    {
        ha::Form_Processing_Unit_Strategy_Text_->combo_box_font->ItemIndex = 0;
    }

    int n = Content_.size();
    ha::Form_Processing_Unit_Strategy_Text_->memo_text->Lines->BeginUpdate();
    ha::Form_Processing_Unit_Strategy_Text_->memo_text->Lines->Clear();
    for(int i = 0; i < n; i++)
    {
        ha::Form_Processing_Unit_Strategy_Text_->memo_text->Lines->Add(Content_[i].c_str());
    }
    ha::Form_Processing_Unit_Strategy_Text_->memo_text->Lines->EndUpdate();

    ha::Form_Processing_Unit_Strategy_Text_->panel_color->Color = (TColor)Font_Color_;
    ha::Form_Processing_Unit_Strategy_Text_->text_size->Text = UnicodeString(Font_Size_);

    ha::Form_Processing_Unit_Strategy_Text_->Is_Update = false;
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_text::Get_Parameter()
{
    ha::Form_Processing_Unit_Strategy_Text_->Is_Update = true;

    Font_Type_ = ha::Form_Processing_Unit_Strategy_Text_->combo_box_font->Text;

    std::vector<std::wstring>().swap(Content_);
    int n = ha::Form_Processing_Unit_Strategy_Text_->memo_text->Lines->Count;
    Content_.resize(n);
    for(int i = 0; i < n; i++)
    {
        Content_[i] = ha::Form_Processing_Unit_Strategy_Text_->memo_text->Lines->Strings[i].c_str();
    }

    Font_Color_ = (unsigned int)ha::Form_Processing_Unit_Strategy_Text_->panel_color->Color;
    if(ha::Form_Processing_Unit_Strategy_Text_->text_size->Text.Trim() != L"")
    {
        Font_Size_ = ha::Form_Processing_Unit_Strategy_Text_->text_size->Text.ToInt();
    }


    ha::Form_Processing_Unit_Strategy_Text_->Is_Update = false;
    Is_Deal_ = false;

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_text::On_Mouse_Down_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
	halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {

    }

    return result_;

}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_text::On_Mouse_Move_Design(halib::image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {

    }

    return result_;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_text::On_Mouse_Up_Design(halib::image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {

    }

    return result_;
}
//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_text::On_Paint_Begin(halib::image_view& image_view)
{
	halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)image_view.Form_Image_View_;

    if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::NONE)
    {

    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::CREATE)
    {


    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::EDIT)
    {





        if(Content_.size() != 0)
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

                if(!Is_Deal_ || !image_view.Is_View_Thumbnail_)
                {
                    // 设置字体
                    image_view.Canvas_->Font->Name = Font_Type_.c_str();
                    image_view.Canvas_->Font->Color = (TColor)Font_Color_;   // 字体颜色
                    image_view.Canvas_->Font->Size = Font_Size_ * image_view.View_Ratio_;        // 字体大小
                    image_view.Canvas_->Font->Style = TFontStyles() << fsBold; // 粗体

                    // 让背景透明
                    image_view.Canvas_->Brush->Style = bsClear;

                    Bitmap_Text_->PixelFormat = pf32bit; // 32 位颜色

                    int width_ = 0;
                    int height_ = 0;
                    int n = Content_.size();

                    for(int i = 0; i < n; i++)
                    {
                        if(i == 0)
                        {
                            height_ = image_view.Canvas_->TextHeight(Content_[i].c_str());
                        }
                        int w_ = image_view.Canvas_->TextWidth(Content_[i].c_str()) + Font_Size_ * 2;
                        if(w_ > width_)
                        {
                            width_ = w_;
                        }
                    }


                    if(width_ > 0 && height_ > 0)
                    {
                        Bitmap_Text_->Width = width_;
                        Bitmap_Text_->Height = -(height_ * n + 10);

                        // 設為透明
                        halib::bitmap_ptr_argb temp_((unsigned char*)Bitmap_Text_->ScanLine[0]);
                        temp_.Resize(Bitmap_Text_->Width, std::abs(Bitmap_Text_->Height));

                        if(Font_Color_ == RGB(0, 0, 0))
                        {
                            halib_image::set::Set(
                                temp_,
                                halib::roi(0,0, Bitmap_Text_->Width - 1, Bitmap_Text_->Height - 1),
                                255, 255, 255, 0
                            );
                        }
                        else
                        {
                            halib_image::set::Set(
                                temp_,
                                halib::roi(0,0, Bitmap_Text_->Width - 1, Bitmap_Text_->Height - 1),
                                0, 0, 0, 0
                            );
                        }


                        Bitmap_Text_->Canvas->Pen->Style = psSolid;
                        Bitmap_Text_->Canvas->Brush->Style = bsClear; // 设置背景为透明
                        Bitmap_Text_->Canvas->Font = image_view.Canvas_->Font;    // 继承字体


                        int offset_x = 10;
                        int offset_y = 5;


                        for(int i = 0; i < n; i++)
                        {
                            Bitmap_Text_->Canvas->TextOut(offset_x, offset_y, Content_[i].c_str());    // 绘制文字
                            offset_y += height_;
                        }

                        if(Font_Color_ == RGB(0, 0, 0))
                        {
                            halib::bitmap_ptr_argb temp_((unsigned char*)Bitmap_Text_->ScanLine[0]);
                            temp_.Resize(Bitmap_Text_->Width, Bitmap_Text_->Height);
                            for(int j = 0; j < temp_.Height_; j++)
                            {
                                unsigned char* ptr_ = temp_[j];
                                for(int i = 0; i < temp_.Width_; i++)
                                {
                                    if(ptr_[4 * i] == 255 &&
                                        ptr_[4 * i + 1] == 255 &&
                                        ptr_[4 * i + 2] == 255 &&
                                        ptr_[4 * i + 3] == 0
                                    )
                                    {

                                    }
                                    else
                                    {
                                        ptr_[4 * i + 3] = 255;
                                    }
                                }
                            }
                        }
                        else
                        {
                            halib::bitmap_ptr_argb temp_((unsigned char*)Bitmap_Text_->ScanLine[0]);
                            temp_.Resize(Bitmap_Text_->Width, Bitmap_Text_->Height);
                            for(int j = 0; j < temp_.Height_; j++)
                            {
                                unsigned char* ptr_ = temp_[j];
                                for(int i = 0; i < temp_.Width_; i++)
                                {
                                    if(ptr_[4 * i] == 0 &&
                                        ptr_[4 * i + 1] == 0 &&
                                        ptr_[4 * i + 2] == 0 &&
                                        ptr_[4 * i + 3] == 0
                                    )
                                    {

                                    }
                                    else
                                    {
                                        ptr_[4 * i + 3] = 255;
                                    }
                                }
                            }
                        }
                    }




                    Is_Deal_ = true;

                }



            }

        }



    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {

    }

    return result_;

}

//---------------------------------------------------------------------------

halib_def::image_view_result hahaha_processing_unit_strategy_text::On_Paint_Design(halib::image_view& image_view)
{
	halib_def::image_view_result result_ = halib_def::image_view_result::SUCCESS;

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





        if(Content_.size() != 0)
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
                    int w_ = form_->view_image->Picture->Bitmap->Width;
                    int h_ = form_->view_image->Picture->Bitmap->Height;

                    if(h_ > 0 && Bitmap_Text_->Width > 0 && Bitmap_Text_->Height > 0)
                    {
                        halib::bitmap_ptr_argb src_((unsigned char*)Bitmap_Text_->ScanLine[0]);
                        src_.Resize(Bitmap_Text_->Width, Bitmap_Text_->Height);

                        halib::bitmap_ptr_argb temp_((unsigned char*)form_->view_image->Picture->Bitmap->ScanLine[0]);
                        temp_.Resize(w_, h_);

                        halib::roi roi_dst_ = halib::roi(
                            roi_.X1_, roi_.Y1_, roi_.X1_ + Bitmap_Text_->Width - 1, roi_.Y1_ + Bitmap_Text_->Height - 1
                        );



                        halib_bitmap::bitmap::Fix_Roi(roi_dst_, temp_, true);

                        if(roi_dst_.Width() > 0 && roi_dst_.Height() > 0)
                        {
                            halib_image::alpha_comp::Alpha_Comp(
                                src_,
                                halib::roi(roi_dst_.X1_ - roi_.X1_, roi_dst_.Y1_ - roi_.Y1_, roi_dst_.X1_ - roi_.X1_ + roi_dst_.Width() - 1, roi_dst_.Y1_ - roi_.Y1_ + roi_dst_.Height() - 1),
                                temp_,
                                roi_dst_,
                                halib_def_image::alpha_type::ALPHA_OVER_PREMUL
                            );
                        }


                        //---------------------------------------------------------------------------
                        //
                        //---------------------------------------------------------------------------

                    }


                }

            }

        }



    }
    else if(Processing_Unit_Region_->State_Region_ == ha_def::processing_unit_region_state::SHOW)
    {

    }

    return result_;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_text::Prepare_Node(
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

    if(type == halib_def::type_variable::VECTOR)
    {
        node_names_target.emplace_back(L"Content");
        if(value == &Content_ && node_names_target == node_names)
        {
            int count_ = 0;
            xmlNodePtr xml_node_cur_;
            for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
            {
                if (xml_node_cur_->type == XML_ELEMENT_NODE)
                {
                    count_++;

                }
            }

            Content_.resize(count_);

        }
        node_names_target.pop_back();

        // 裡面有Views了
        Mapping(xml, node_names_target, root);

    }




    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_text::Prepare_Attribute(
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
halib_def::result hahaha_processing_unit_strategy_text::Prepare_Value(
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
halib_def::result hahaha_processing_unit_strategy_text::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& root
)
{
    halib_def::result result = halib_def::result::SUCCESS;

    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_text::Mapping(
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
        {{},
			L"Font_Type", halib_def::xml_type::VALUE, halib_def::type_variable::WSTRING, &Font_Type_},
        {{},
			L"Font_Color", halib_def::xml_type::VALUE, halib_def::type_variable::UNSIGNED_INT, &Font_Color_},
        {{},
			L"Font_Size", halib_def::xml_type::VALUE, halib_def::type_variable::INT, &Font_Size_},
        //
	};

    node_names_.emplace_back(L"Content");

    items_.emplace_back(
        node_names_,
			L"", halib_def::xml_type::NODE, halib_def::type_variable::VECTOR, (void*)&Content_
    );

    int n = Content_.size();

    for(int i = 0; i < n; i++)
    {
        std::wstring str_ = L"Content" + std::to_wstring(i + 1);

        items_.emplace_back(
            node_names_,
			str_, halib_def::xml_type::VALUE, halib_def::type_variable::WSTRING, (void*)&Content_[i]
        );


    }

    node_names_.pop_back();



    root.Add(items_);




    return result;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_text::Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;
    return result;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_processing_unit_strategy_text::Load_Initial()
{
    halib_def::result result = halib_def::result::SUCCESS;


    return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------