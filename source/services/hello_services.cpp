#include "hello_services.hpp"
#include "pantheon_ng.hpp"
#include <iostream>

grpc::Status HelloServiceImpl::HelloWorld(grpc::ServerContext *context, const HelloRequest *request, HelloResponse *response)
{
    using namespace ees::exceptions;
    using namespace ees::pantheon_ng;
    try
    {

        response->set_text("Hello " + request->name());
        if (response->text() == "Hello Eletra2")
        {
            throw PantheonNgExceptions(ErrorType::INTERNAL, PantheonNgExceptionReason::ADSUP_COULD_NOT_BE_LESS_THEN_ADINF);
        }

        return grpc::Status::OK;
    }
    catch (const PantheonNgExceptions &error)
    {
        PantheonNgExceptionsProto *error_proto = response->mutable_error_response();
        error_proto->set_meter_type("PANTHEON_NG");

        ErrorDetails *error_details = error_proto->mutable_error();
        error_details->set_error_code("INTERNAL");                                     // Código do erro
        error_details->set_message(error.what());                                      // Mensagem descritiva do erro
        error_details->set_technical_message("Technical details: ADSUP < ADINF");      // Mensagem técnica
        error_details->set_solution("Ensure ADSUP is greater than or equal to ADINF"); // Solução sugerida

        return grpc::Status(grpc::StatusCode::INTERNAL, "Internal error occurred");
    }
}