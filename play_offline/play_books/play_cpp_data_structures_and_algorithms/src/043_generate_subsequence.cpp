#include <iostream>
#include "043_generate_subsequence.hpp"
#include "instrumentation.hpp"

int main(int argc, char const *argv[])
{
	std::vector < std::string > inputs = 
		{
		 	"abcdef",
		 	"donut"
		};

	for ( auto s : inputs ) 
	{
		for ( auto ss : ds::generate_subsequence(s) ) 
		{
			std::cout << ss << std::endl;
		}
	}

	for ( auto s : inputs ) 
	{
		for ( auto ss : ds::generate_subsequence_by_powerset(s) ) 
		{
			std::cout << ss << std::endl;
		}
	}


	for ( int i = 0 ; i < 10; ++i )
	{
		std::string s = "";
		for ( int j = 0 ; j < i; j ++ )
			s += 'a' + (j%26) ;
		
		{
			ds::instrumentation::task_time t("time            generate_subsequence");
			auto v = ds::generate_subsequence(s) ;
		}

		

		{
			ds::instrumentation::task_time t("time generate_subsequence_by_powerset");
			auto v = ds::generate_subsequence_by_powerset(s) ;
		}
	}
	


	
	
	return 0;
}