#include "client_common.hpp"

void do_push(int socfd)
{
    const std::string hi("Hello There");
    for ( int i = 0 ; i < 100000; ++i )
    {
        std::size_t nbytes = send(socfd, hi.c_str(), hi.size(), 0);
        if ( nbytes <= 0 )
        {
            std::cerr << "ERROR : We have problem in sending to socket [ " 
                << socfd << " ] returned [ " << nbytes << " ]\n";
        }
    }   

}

int make_connection( )
{
    short port = 1231;
    std::string ip("127.0.0.1");

    int socfd = socket(AF_INET, SOCK_STREAM, 0);
    if( socfd <= 0 )
    {
        perror("ERROR : We have problem creating socket : ");
        std::cerr << "Done\n";
        return -1;
    }

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port   = htons(port);
    saddr.sin_addr.s_addr = inet_addr(ip.c_str());

    if( connect(socfd, (struct sockaddr *) &saddr, sizeof(saddr)) != 0 )
    {
        perror("ERROR : we have a connect failure here :");
        std::cerr << "Done\n";
        return -1;
    }

    return socfd;
}
