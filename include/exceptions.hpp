#pragma once

#include <string>
#include <unordered_map>
#include <grpcpp/grpcpp.h>
#include "hello.grpc.pb.h"

namespace ees::exceptions
{

    enum class Language
    {
        PT_BR,
        EN_US,
        ZH_CN
    };

    enum class ErrorType
    {
        CANCELLED,
        INVALID_ARGUMENT,
        DEADLINE_EXCEEDED,
        NOT_FOUND,
        ALREADY_EXISTS,
        PERMISSION_DENIED,
        RESOURCE_EXHAUSTED,
        FAILED_PRECONDITION,
        ABORTED,
        OUT_OF_RANGE,
        UNIMPLEMENTED,
        INTERNAL,
        UNAVAILABLE,
        DATA_LOSS,
        UNAUTHENTICATED,
        UNKNOWN,
    };

    enum class EnergyMeterType
    {
        PANTHEON_NG,
        CRONOS,
        BULK_METER,
        CRONOS_NG_PLUS,
        MONOPHASE_RECLOSER,
        PANTHEON,
        GATEWAY,
        ZEUS,
        ZEUS_NG,
        ZEUS_THS,
        RESIDENCIAL_WATER_METER
    };

    // Class Abstract
    template <typename REASON_ERROR_ENUM>
    class EnergyMeterExceptions : public std::exception
    {
        using Mapping = std::unordered_map<REASON_ERROR_ENUM, std::string>;

    private:
        EnergyMeterType meter_type;
        ErrorType type_error;
        REASON_ERROR_ENUM reason;
        const Mapping *error_map;
        mutable std::string cached_message;

    public:
        EnergyMeterExceptions(const EnergyMeterType &meter_type, const ErrorType &error_type, REASON_ERROR_ENUM reason, const Mapping *map)
            : meter_type(meter_type), type_error(error_type), reason(reason), error_map(map)
        {
            cached_message = error_reason_to_string(*error_map, reason);
        };

        auto what() const noexcept -> const char * override { return cached_message.c_str(); }

    private:
        auto error_reason_to_string(const Mapping &error_map, const REASON_ERROR_ENUM &reason) const -> std::string
        {
            auto it = error_map.find(reason);
            return (it != error_map.end()) ? it->second : "MISSING_EXCEPTION_ON_ELETRA_SDK";
        }
    };
}