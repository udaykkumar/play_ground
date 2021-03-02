#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <algorithm>
#include <memory>
#include <vector>

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

struct player {
	
	player(std::string n) :
		name_(n),
		score_(0)
		{ }

	player(const char *n) :
		name_(n),
		score_(0)
		{ }

	// Copy constructor
    player(const player &p) {
    	name_  = p.name(); 
    	score_ = p.score(); 
    }

    // move constructor
    player (player && p){
    	name_  = std::move(p.name()); 
    	score_ = std::move(p.score()); 
  	}

  	void operator ++()
  	{
  		++score_;
  	}

	friend std::ostream& operator<<( std::ostream &os , const player p )
	{
		os << " " << p.name() << " " << p.score() << "\n";
		return os;
	} 

	std::string name() const { return name_; }
	size_t 	    score() const{ return score_;}

private:
	std::string name_;
	size_t 		score_;
};

static std::string make_name(int i)
{
	return "Player "+ std::to_string(i);
}

void play(std::shared_ptr<player> &&p)
{
	while ( running )
	{	
		if( get_the_ball() )
		{
			++(*p);
			put_the_ball();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(rand()%23));
	}
}


 
int main(int argc, char const *argv[])
{
	const size_t max_players = 10;
	std::vector< std::shared_ptr<player> > players(max_players);

	int i = 0;
	std::generate(players.begin(), players.end(), [&i]() {
		return std::make_shared<player>(make_name(i++));
	});

	for ( auto p : players ) {
		std::thread t( play, std::move(p) );
		t.detach();
	}

	for ( i = 0 ; i < 120 ; i ++ )
	{
		for ( auto p : players )
			std::cout << i << " " << *p;
		std::this_thread::sleep_for( std::chrono::seconds(1));
	}
	return 0;
}