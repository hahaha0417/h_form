//---------------------------------------------------------------------------

#pragma hdrstop

#include <function\hahaha_function_vector.h>

#include "hahaha_post_package.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_post_package::hahaha_post_package()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_post_package::hahaha_post_package(
    const std::wstring& name,
    const std::wstring& type,
    const void* object,
    const std::vector<void*>& objects,
    const std::vector<std::wstring>& commands,
    const std::vector<std::wstring>& describes,
    const std::vector<hahaha_post_package>& packages
)
{
    Name_ = name;
    Type_ = type;
    Object_ = (void*)object;

    hahahalib::Vector_Copy(objects, Objects_);
    hahahalib::Vector_Copy(commands, Commands_);
    hahahalib::Vector_Copy(describes, Describes_);
    hahahalib::Vector_Copy(packages, Packages_);

}
//---------------------------------------------------------------------------
hahaha_post_package::~hahaha_post_package()
{

}
//---------------------------------------------------------------------------
hahaha_post_package::hahaha_post_package(const hahaha_post_package& hpp)
{
    Reset();
	Copy(hpp);
}
//---------------------------------------------------------------------------
hahaha_post_package::hahaha_post_package(hahaha_post_package&& hpp) noexcept
{
    Move(std::move(hpp));

}
//---------------------------------------------------------------------------
hahaha_post_package& hahaha_post_package::operator=(const hahaha_post_package& hpp)
{
	Copy(hpp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_post_package& hahaha_post_package::operator=(hahaha_post_package&& hpp) noexcept
{
	if (this != &hpp)
    {
        Move(std::move(hpp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_post_package::Copy(const hahaha_post_package& hpp)
{
    Name_ = hpp.Name_;
    Type_ = hpp.Type_;
    Object_ = hpp.Object_;

    hahahalib::Vector_Copy(hpp.Objects_, Objects_);
    hahahalib::Vector_Copy(hpp.Commands_, Commands_);
    hahahalib::Vector_Copy(hpp.Describes_, Describes_);
    hahahalib::Vector_Copy(hpp.Packages_, Packages_);
}
//---------------------------------------------------------------------------
void hahaha_post_package::Move(hahaha_post_package&& hpp) noexcept
{
    Name_.swap(hpp.Name_);
    Type_.swap(hpp.Type_);
    Object_ = hpp.Object_;

    Objects_.swap(hpp.Objects_);
    Commands_.swap(hpp.Commands_);
    Describes_.swap(hpp.Describes_);
    Packages_.swap(hpp.Packages_);

    hpp.Reset();

}
//---------------------------------------------------------------------------
int hahaha_post_package::Reset()
{
    Name_ = L"";;
    Type_ = L"";
    Object_ = NULL;
    std::vector<void*>().swap(Objects_);
    std::vector<std::wstring>().swap(Commands_);
    std::vector<std::wstring>().swap(Describes_);
    //
	std::vector<hahaha_post_package>().swap(Packages_);

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------