
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <algorithm>
#include <memory>
#include <vector>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	short port = 1231;
	std::string ip("127.0.0.1");

	int socfd = socket(AF_INET, SOCK_STREAM, 0);
	if( socfd <= 0 )
	{
		std::cerr << "ERROR : We have problem creating socket \n";
		std::exit(socfd);
	}

	struct sockaddr_in saddr;
		saddr.sin_family = AF_INET;
		saddr.sin_port   = htons(port);
		saddr.sin_addr.s_addr = inet_addr(ip.c_str());

	if( connect(socfd, (struct sockaddr *) &saddr, sizeof(saddr)) != 0 )
	{
		std::cerr << "ERROR : we have a connect failure here\n";
		std::exit(-1);
	}
	
	const std::string hi("Hello There");
	for ( int i = 0 ; i < 10000; ++i )
	send(socfd, hi.c_str(), hi.size(), 0);

	close(socfd);

	return 0;
}