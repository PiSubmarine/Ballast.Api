#include <gtest/gtest.h>

#include "PiSubmarine/Ballast/Api/IControllerMock.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Ballast::Api
{
    TEST(IControllerMockTest, SupportsSettingTargetPosition)
    {
        IControllerMock controller;
        const auto targetPosition = BallastFillFraction{NormalizedFraction{0.65}};

        EXPECT_CALL(controller, SetTargetPosition(targetPosition))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        EXPECT_TRUE(controller.SetTargetPosition(targetPosition).has_value());
    }

    TEST(IControllerMockTest, SupportsGettingTargetPosition)
    {
        IControllerMock controller;
        const auto targetPosition = BallastFillFraction{NormalizedFraction{0.35}};

        EXPECT_CALL(controller, GetTargetPosition())
            .WillOnce(testing::Return(Error::Api::Result<BallastFillFraction>{targetPosition}));

        const auto result = controller.GetTargetPosition();

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(static_cast<double>(*result), 0.35);
    }
}
