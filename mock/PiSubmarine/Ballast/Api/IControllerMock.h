#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Ballast/Api/IController.h"

namespace PiSubmarine::Ballast::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetTargetPosition, (BallastFillFraction position), (override));
        MOCK_METHOD((Error::Api::Result<BallastFillFraction>), GetTargetPosition, (), (const, override));
    };
}
