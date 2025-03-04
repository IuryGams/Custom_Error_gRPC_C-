#pragma once

#include "./exceptions.hpp"
#include "./reason.hpp"

namespace ees::pantheon_ng
{
    class PantheonNgExceptions : public ees::exceptions::EnergyMeterExceptions<PantheonNgExceptionReason>
    {
        using Reason = PantheonNgExceptionReason;

    private:
        static const std::unordered_map<Reason, std::string> error_messages;

    public:
        explicit PantheonNgExceptions(const ees::exceptions::ErrorType &error_type, const Reason &error_reason);
    };
}