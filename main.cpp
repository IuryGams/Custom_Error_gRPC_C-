#include <locale.h>
#include "server.hpp"

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");

	cloud::GRPCServer server;

	server.StartServer();

	return 0;
}