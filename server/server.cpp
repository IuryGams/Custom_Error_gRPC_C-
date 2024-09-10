#include "server.hpp"
#include <grpc++/grpc++.h>

namespace cloud
{
	void GRPCServer::StartServer()
	{
		grpc::ServerBuilder builder;
		builder.AddListeningPort(server_address_, grpc::InsecureServerCredentials());
		builder.RegisterService(&services_);

		server_ = builder.BuildAndStart();
		std::cout << "Server is running on the port: " << server_address_ << std::endl;

		server_->Wait();
	}

	void GRPCServer::StopServer()
	{
		if (server_)
			server_->Shutdown();
	}
}