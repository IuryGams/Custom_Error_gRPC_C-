#include "catch2.hpp"
#include "custom_errors.hpp"
#include "enums.hpp"
#include "utils.hpp"
#include <map>
#include <string>
#include <grpcpp/grpcpp.h>

TEST_CASE("Testando mapeamento de exceções com loop", "[map_exception_to_error]")
{

    std::map<ErrorType, std::pair<grpc::StatusCode, std::string>> error_test_cases = {
        {ErrorType::INVALID_ADDRESS, {grpc::StatusCode::INVALID_ARGUMENT, "Error 1 INVALID_ADDRESS"}},
        {ErrorType::FRAME_IS_TOO_SHORT, {grpc::StatusCode::INVALID_ARGUMENT, "Error 2 FRAME_IS_TOO_SHORT"}},
        {ErrorType::CHECKSUM_DOES_NOT_MATCH, {grpc::StatusCode::DATA_LOSS, "Error 3 CHECKSUM_DOES_NOT_MATCH"}},
        {ErrorType::UNKNOWN_ERROR, {grpc::StatusCode::UNKNOWN, "An unknown error ocurred"}}};

    for (const auto &[error_type, expected] : error_test_cases)
    {
        grpc::Status status = ees::map_exception_to_error(exceptions::CustomException(error_type));

        REQUIRE(status.error_code() == expected.first);
        REQUIRE(status.error_message() == expected.second);
    };
}