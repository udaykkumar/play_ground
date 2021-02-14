/*
Hi, here's your problem today. This problem was recently asked by AirBNB:

Given two strings, determine the edit distance between them. The edit distance
is defined as the minimum number of edits (insertion, deletion, or
substitution) needed to change one string to the other.

For example, "biting" and "sitting" have an edit distance of 2 (substitute b
for s, and insert a t).

Here's the signature:


def distance(s1, s2):
  # Fill this in.

print distance('biting', 'sitting')
# 2

*/

#include <26_07_2019.hpp>
#include <iostream>

namespace daily_interview
{
	int distance( std::string s1, std::string s2, int l1, int l2 )
	{
		
		if( l1 == 0 )
			return l2;
		
		if( l2 == 0 )
			return l1;

		if( s1[l1-1] == s2[l2-1] )
			return distance( s1, s2, l1-1, l2-1 );

		return 1 + std::min(
						std::min(
								distance(s1, s2, l1,   l2-1 ), //Insert
								distance(s1, s2, l1-1, l2   ) //Remove
							) ,
						distance(s1, s2, l1-1, l2-1 )  //Replace
					);
	}
}

