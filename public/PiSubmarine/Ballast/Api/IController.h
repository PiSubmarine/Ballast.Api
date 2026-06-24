#pragma once

#include "PiSubmarine/Ballast/BallastFillFraction.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Ballast::Api
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual Error::Api::Result<void> SetTargetPosition(BallastFillFraction position) = 0;
        [[nodiscard]] virtual Error::Api::Result<BallastFillFraction> GetTargetPosition() const = 0;
    };
}
