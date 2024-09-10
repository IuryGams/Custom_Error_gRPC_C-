#include "utils.hpp"
#include <map>
#include "enums.hpp"

namespace ees
{
    auto map_exception_to_error(const exceptions::CustomException &error) -> grpc::Status
    {
        std::map<ErrorType, grpc::Status> error_map = {
            {ErrorType::INVALID_ADDRESS, grpc::Status(grpc::StatusCode::INVALID_ARGUMENT, "Error 1 INVALID_ADDRESS")},
            {ErrorType::FRAME_IS_TOO_SHORT, grpc::Status(grpc::StatusCode::INVALID_ARGUMENT, "Error 2 FRAME_IS_TOO_SHORT")},
            {ErrorType::CHECKSUM_DOES_NOT_MATCH, grpc::Status(grpc::StatusCode::INVALID_ARGUMENT, "Error 3 CHECKSUM_DOES_NOT_MATCH")},
        };

        auto it = error_map.find(error.code());
        if (it != error_map.end())
            return it->second;

        return grpc::Status(grpc::StatusCode::UNKNOWN, "An unknown error ocurred");
    }
}