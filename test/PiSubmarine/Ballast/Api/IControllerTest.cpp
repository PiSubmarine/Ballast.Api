#include <gtest/gtest.h>

#include <type_traits>

#include "PiSubmarine/Ballast/Api/IController.h"

namespace PiSubmarine::Ballast::Api
{
    TEST(IControllerTest, HasVirtualDestructor)
    {
        static_assert(std::has_virtual_destructor_v<IController>);
        SUCCEED();
    }
}
