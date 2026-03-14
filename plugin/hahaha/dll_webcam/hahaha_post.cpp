//---------------------------------------------------------------------------

#pragma hdrstop

#include <processing_unit\base\hahaha_processing_unit_base.h>

#include <define\hahaha_define_ho.h>

#include "hahaha_post.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
// 降規格，因為有function會吃編譯時間
// 不做大型post架構
//---------------------------------------------------------------------------
HAHAHA_API int Hahaha_Post(hahaha::hahaha_post_package& input,
	hahaha::hahaha_post_package& output,
    hahaha::hahaha_post_package& setting
)
{
    std::vector<std::wstring>& commands_ = input.Commands_;

    int n = commands_.size();

    if(n >= 1 && commands_[0] == L"initial_environment")
    {
        ha::Initial_Environment(
            input,
            output,
            setting
        );
    }
    else if(n >= 1 && commands_[0] == L"initial")
    {
        ha::Initial();
    }
    else if(n >= 1 && commands_[0] == L"close")
    {
        ha::Close();
    }



    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
