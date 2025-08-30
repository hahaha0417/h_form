//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_load_dll.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_load_dll::hahaha_load_dll()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_load_dll::~hahaha_load_dll()
{

}
//---------------------------------------------------------------------------
hahaha_load_dll::hahaha_load_dll(const hahaha_load_dll& hld)
{
    Reset();
	Copy(hld);
}
//---------------------------------------------------------------------------
hahaha_load_dll::hahaha_load_dll(hahaha_load_dll&& hld) noexcept
{
    Move(std::move(hld));

}
//---------------------------------------------------------------------------
hahaha_load_dll& hahaha_load_dll::operator=(const hahaha_load_dll& hld)
{
	Copy(hld);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_load_dll& hahaha_load_dll::operator=(hahaha_load_dll&& hld) noexcept
{
	if (this != &hld)
    {
        Move(std::move(hld));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_load_dll::Copy(const hahaha_load_dll& hld)
{

}
//---------------------------------------------------------------------------
void hahaha_load_dll::Move(hahaha_load_dll&& hld) noexcept
{
    Dll_ = hld.Dll_;
    Hahaha_ = hld.Hahaha_;
    Hahaha_Post_ = hld.Hahaha_Post_;

    hld.Reset();

}
//---------------------------------------------------------------------------
int hahaha_load_dll::Reset()
{
    Dll_ = nullptr;
    Hahaha_ = nullptr;
    Hahaha_Post_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_load_dll::Load(const std::wstring& file_name)
{
	Dll_ = LoadLibraryW(file_name.c_str());

    if (Dll_ == nullptr)
	{
        return -1;

	}
#if defined(__WIN64_MODERN)
	Hahaha_ = (Hahaha)GetProcAddress(Dll_, "_Z6HahahaRNSt3__112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEE");
	Hahaha_Post_ = (Hahaha_Post)GetProcAddress(Dll_, "_Z11Hahaha_PostRN6hahaha19hahaha_post_packageES1_S1_");

#elif defined(__WIN64)
	Hahaha_ = (Hahaha)GetProcAddress(Dll_, "_Z6HahahaRSbIwSt11char_traitsIwESaIwEE");
	Hahaha_Post_ = (Hahaha_Post)GetProcAddress(Dll_, "_Z11Hahaha_PostRN6hahaha19hahaha_post_packageES1_S1_");
#elif defined(__WIN32)
	Hahaha_ = (Hahaha)GetProcAddress(Dll_, "@Hahaha$qr60std@%basic_string$b19std@%char_traits$b%17std@%allocator$b%%");
	Hahaha_Post_ = (Hahaha_Post)GetProcAddress(Dll_, "@Hahaha_Post$qr26hahaha@hahaha_post_packaget1t1");
#endif
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_load_dll::Close()
{
    if(Dll_ != nullptr)
    {
        FreeLibrary(Dll_);
        Dll_ = NULL;
    }


    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------