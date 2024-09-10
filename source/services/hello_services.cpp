#include "hello_services.hpp"
#include "utils.hpp"
#include "custom_errors.hpp"
#include "enums.hpp"

grpc::Status HelloServiceImpl::HelloWorld(grpc::ServerContext *context, const HelloRequest *request, HelloResponse *response)
{
    try
    {
        response->set_text("Hello " + request->name());
        if (response->text() == "Hello Eletra2")
        {
            throw exceptions::CustomException(ErrorType::FRAME_IS_TOO_SHORT);
        }
        if (response->text() == "Hello Eletra1")
        {
            throw exceptions::CustomException(ErrorType::INVALID_ADDRESS);
        }
        if (response->text() == "Hello Eletra3")
        {
            throw exceptions::CustomException(ErrorType::CHECKSUM_DOES_NOT_MATCH);
        }
        if (response->text() == "Hello Eletra4")
        {
            throw exceptions::CustomException(ErrorType::UNKNOWN_ERROR);
        }

        return grpc::Status::OK;
    }
    catch (const exceptions::CustomException &error)
    {
        return ees::map_exception_to_error(error);
    }
}