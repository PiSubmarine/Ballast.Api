#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Ballast::Api
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual Error::Api::Result<void> SetTargetPosition(NormalizedFraction position) = 0;
        [[nodiscard]] virtual Error::Api::Result<NormalizedFraction> GetTargetPosition() const = 0;
    };
}
