#ifndef __14_07_2019_HPP_INCLUDED__
#define __14_07_2019_HPP_INCLUDED__

#include <iostream>
#include <vector>

struct bracket_sequence
{

private:
	std::string sequence;
	std::vector<char> stack;

public:
	bracket_sequence(std::string s) :
			sequence(s)
	{
	}
	bool is_valid();

private:
	bool is_open_bracket(const char c);

	bool is_stack_empty();

	bool is_matching_pair(const char current);
};

#endif
