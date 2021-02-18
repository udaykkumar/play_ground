/*
https://practice.geeksforgeeks.org/problems/minimum-platforms/0

Given arrival and departure times of all trains that reach a railway station. 
Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. 
Also, arrival and departure times must not be same for a train.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int to_minutes( int timeIn24Fmt )
{
	return ( timeIn24Fmt % 100 ) + ( timeIn24Fmt / 100 ) * 60 ;
}

int minimum_platforms(std::vector< int > &arrivals, std::vector<int> &departures )
{
	std::sort( arrivals.begin(), arrivals.end() );
	std::sort( departures.begin(), departures.end() );

	int min_platforms = 0;
	int platforms = 0;
	auto it_arrive_iterator { arrivals.begin()   } ;
	auto it_depart_iterator { departures.begin() } ;

	for( ; it_arrive_iterator != arrivals.end() && it_depart_iterator != departures.end();	)
	{
		if( *it_arrive_iterator < *it_depart_iterator) {
			platforms ++;
			it_arrive_iterator ++;
			min_platforms = std::max( min_platforms, platforms );
		}
		else {
			it_depart_iterator ++;
			platforms --;
		}
	}

	for( ; it_arrive_iterator != arrivals.end(); ++it_arrive_iterator )
		platforms ++;

	min_platforms = std::max( min_platforms, platforms );

	for( ; it_depart_iterator != departures.end(); ++it_depart_iterator )
		platforms --;

	return min_platforms;

}


void exec_test(int index)
{
	std::vector< int > arrivals; 
	std::vector< int > departures; 
	int trains;
		std::cin >> trains;

	for( int i = 0 ; i < trains; i ++ ) 
	{
		int time;
		std::cin >> time;
		arrivals.push_back( to_minutes(time) );
	}

	for( int i = 0 ; i < trains; i ++ ) 
	{
		int time;
		std::cin >> time;
		departures.push_back( to_minutes(time) );
	}

	//std::cout << " " << minimum_platforms( arrivals, departures ) << std::endl;
}

int main( int ac, char **av )
{
	int t;
		std::cin >> t;

	for( int i = 0 ; i < t; i ++ )
		exec_test(i);

	return 0;
}