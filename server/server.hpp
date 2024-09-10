#pragma once
#include <grpcpp/grpcpp.h>
#include "hello_services.hpp"

namespace cloud
{
	class GRPCServer
	{
	private:
		const std::string server_address_ = "0.0.0.0:50051";
		std::unique_ptr<grpc::Server> server_;
		HelloServiceImpl services_;
	public:
		void StartServer();
		void StopServer();
	};
}