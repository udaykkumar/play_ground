
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
#include <cstring>

int main(int argc, char const *argv[])
{
	std::cout << "Hello " << argv[0] << "\n";
	int socfd = socket( AF_INET, SOCK_STREAM, 0 );
	if( socfd <= 0 )
	{
		std::cerr << "ERROR : We have problem creating socket \n";
		std::exit(socfd);
	}

	struct sockaddr_in saddr;
		saddr.sin_family 		= AF_INET;
		saddr.sin_port   		= htons(1231);
		saddr.sin_addr.s_addr	= INADDR_ANY;


	if (bind(socfd, (struct sockaddr *) &saddr,
                   sizeof(struct sockaddr_in)) == -1)
	{
		std::cerr << "ERROR : we have a bind failure here\n";
		std::exit(-1);
	}

	if (listen(socfd, 5) == -1 )
	{
		std::cerr << "ERROR : we have a listen failure here\n";
		std::exit(-1);
	}

	size_t served = 0;
	for ( ;; )
	{
		//std::cout << "DEBUG  : we do the thing ..\n";
		struct sockaddr_in raddr;
		socklen_t          raddrlen;
		int cfd = accept( socfd, (struct sockaddr*)&raddr, &raddrlen);
		if( cfd <= 0 )
		{
			std::cerr << "ERROR : we have a accept failure here\n";
			continue;
		}
		served ++;
		//std::cout << "DEBUG  : we handle " << cfd << "\n";
		size_t totalRead = 0;
		for(char buf[1024]; ;) 
		{
			std::memset(buf, 0, 1024);
			size_t nbytes = recv(cfd, buf, sizeof buf, 0);
			if ( nbytes <= 0 )
			{
				std::cerr << "ERROR : [" << cfd << "] we have a recv failure here ( client exit ? )\n";
				break;
			}
			totalRead += nbytes;
			//std::cout << "DEBUG  : ["<< cfd << "] we got " << nbytes << " bytes \n";
		}
		std::cout << "INFO  : ["<< cfd << "] we got total " << totalRead << " bytes " << "served " << served << " connections" << "\n";
	}
	
	return 0;
}