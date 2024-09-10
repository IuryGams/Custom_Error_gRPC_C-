#pragma once

#include "hello.grpc.pb.h"
#include <grpcpp/grpcpp.h>

class HelloServiceImpl final : public HelloService::Service
{
    public:
    grpc::Status HelloWorld(grpc::ServerContext *context, const HelloRequest *request, HelloResponse *response) override;
};