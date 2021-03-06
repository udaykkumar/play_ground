
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
#include "client_common.hpp"


int main(int argc, char const *argv[])
{
    for ( int nc = 1 ; nc ; nc = nc << 1 )
    {
        auto start = std::chrono::steady_clock::now();
        for ( int i = 0 ; i < nc ; ++ i )
        {
            int socfd = make_connection();
            do_push(socfd);
            close(socfd);
        }
        auto end = std::chrono::steady_clock::now();
        auto es = end - start;
        std::cout << "INFO  : benchmarking no of clientes " 
        	<< nc 
        	<< " took " << es.count() << "\n";
    }


    return 0;
}