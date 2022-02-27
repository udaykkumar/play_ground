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
	int socfd = make_connection();
	do_push(socfd);
	close(socfd);

	return 0;
}
