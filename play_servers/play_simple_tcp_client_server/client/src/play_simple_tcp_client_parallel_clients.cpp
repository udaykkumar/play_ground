
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
#include <future>
#include "client_common.hpp"


int main(int argc, char const *argv[])
{
    auto push_client = [](){
        if ( int socfd = make_connection() )
        {
            do_push(socfd);
            close(socfd);
            return true;
        }
        return false;
    };


    for ( int nc = 1 ; nc > 0 ; nc *= 2 )
    {
        std::vector< std::future< bool > > clients;
        
        auto start = std::chrono::steady_clock::now();
        int success = 0, failure = 0;
        for ( int i = 0 ; i < nc ; ++ i )
            clients.push_back( std::async(std::launch::async, push_client) );
        
        for ( auto &c : clients )
        {
            if ( c.get() )
                ++ success;
            else 
                ++ failure; 
        
        } 
            
        auto end = std::chrono::steady_clock::now();
        auto es = end - start;
        std::cout << "INFO  : benchmarking no of clientes " 
        	<< nc 
        	<< " took " << es.count() 
            << " success " << success
            << " failures " << failure
            << "\n";
    }


    return 0;
}