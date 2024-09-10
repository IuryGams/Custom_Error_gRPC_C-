#pragma once
#include "custom_errors.hpp"
#include <grpcpp/grpcpp.h>

namespace ees
{
    auto map_exception_to_error(const exceptions::CustomException &error ) -> grpc::Status;
}