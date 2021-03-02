#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

bool running = true;

int is_free = 0;
int is_locked = 1;
std::atomic<int> ball(0);


bool get_the_ball()
{
	return ball.compare_exchange_strong( is_free, is_locked) ;
}

bool put_the_ball()
{
	return ball.compare_exchange_strong( is_locked, is_free );
}

void play(std::string s)
{
	while ( running )
	{
		
		if( get_the_ball() )
		{
			std::cout << s << " I got the ball\n";
			std::this_thread::sleep_for( std::chrono::milliseconds(500));
			put_the_ball();
		}
		else
		{
			std::cout << s << " I am waiting \n";
			std::this_thread::sleep_for( std::chrono::milliseconds(100));
		}
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "Hello Ping Pong .. \n";
	for ( int i = 0 ; i < 10 ; i ++ )
	{
		std::thread t(play, std::string("Thread ")+std::to_string(i) );	
	}
	
	for ( int i = 0 ; i < 120 ; i ++ )
		std::this_thread::sleep_for( std::chrono::seconds(1));
	return 0;
}