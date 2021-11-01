#include <iostream>
#include <cstdlib>
#include <ctime>

enum CardSuite {  Club, Diamond, Heart, Spade };

enum CardElement  { One, Two, Three, Four,
					Five, Six, Seven, Eight,
					Nine, Ten, Jack, Queen,
					King, Ace };

std::string SuiteString( CardSuite  s )
{
	switch(s) {
		case Club: return "Club";
		case Diamond: return "Diamond";
		case Heart: return "Heart";
		case Spade: return "Spade";
	}
	return "None";
}

std::string ElementString( CardElement  s )
{
	switch(s) {
		case One: return "One";
		case Two: return "Two";
		case Three: return "Three";
		case Four: return "Four";
		case Five: return "Five";
		case Six: return "Six";
		case Seven: return "Seven";
		case Eight: return "Eight";
		case Nine: return "Nine";
		case Ten: return "Ten";
		case Jack: return "Jack";
		case Queen: return "Queen";
		case King: return "King";
		case Ace: return "Ace";
	}
	return "None";
}

int GenerateRandomNumber(int min, int max)
{
    /// static used for efficiency,
    /// so we only calculate this value once
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    /// evenly distribute the random number
    /// across our range
    return min + static_cast<int>(
        (max - min + 1) * (std::rand() * fraction));
}

int main()
{
	// set initial seed value to system clock
    srand(static_cast<unsigned int>(time(0)));

	CardSuite cs = static_cast<CardSuite>(GenerateRandomNumber(0,3));
	CardElement ce = static_cast<CardElement>(GenerateRandomNumber(0,12));

	std::cout << " Chosen Card is " 
			  << ElementString(ce) << " of " 
			  << SuiteString(cs) << std::endl;

	return 0; 
}