#include "chapter_1.hxx"

#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

/*
	Problem 1.1: Is Uniq
	============

	The Problem is to implement an algorithm to find 
	if a given string has all unique characters...

	Algorithm:
		is to keep track of the visited characters in the string in an array 
		with character's ascii value as index. and increment as we get along

		if the value is more than 1 we've a collision and is not a unique string

*/
bool is_unique( std::string &string ) {
	std::vector<size_t> track_uniq(255, 0);
	for( auto c: string ) {
		if( track_uniq.at(c) > 1 )
			return false;
		track_uniq.at(c) ++;
	}
	return true;
}


/*
	Problem 1.2: Check Permutation
	============

	The Problem is Given two strings , write a method to decide if one string is a 
	permutation of other

	Algorithm:
		We'll sort both the strings and compare, if the sorted strings are equal its true.

*/
bool is_one_permutation_of_other_v1( std::string &s1, std::string &s2 ) {
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	return ( s1 == s2 ) ;
}
/* This is a continuation of same problems 1.2 
   try not to use sort function */
bool is_one_permutation_of_other_v2( std::string &s1, std::string &s2 ) {

	std::vector<size_t> s1Chars(255,0) ,s2Chars(255,0);
	for(auto c : s1 ) { s1Chars[c] ++; }
	for(auto c : s2 ) { s2Chars[c] ++; }
	for( size_t i = 0 ; i < 255 ; i ++ ) { 
		if ( s1Chars[i] != s2Chars[i] ){
			return false;
		}
	}
	return true;
}

/*
	Problem 1.3: URLify

	Write a function to replace all spaces with %20. one may assume that the string has 
	sufficient space at the end to hold the additional characters, and that you are given the
	true length of the string

	EXAMPLE : 
	input   : "Mr John Smith    ", 13
	output  : "Mr%20John%20Smith"

*/

int urlify( char *url, size_t true_len ) {

	size_t spaces = 0, length = 0 ;
	char *p = url;
	for( size_t i = 0 ; *p  != '\0' ;  ) {
		if( url[i] == ' ' && i  < true_len ) {
			spaces ++;
		}
		i ++, length ++ , p ++;
	}

	/* Final string length will be 
		Current Length + Per space extra 2 chars 2 and 0, considering existing space will be filled with %
		+	a NULL
	*/
	size_t urlified_len = true_len + spaces * 2 + 1;
	if( urlified_len-1 > length ){
		return -1;
	}

	size_t fill_index   = urlified_len -1 ;

	url[ fill_index -- ] = '\0';

	for( int i = true_len-1; i >= 0; i -- ) {
		if( url[i] == ' ') {
			url[ fill_index     ] = '0';
			url[ fill_index - 1 ] = '2';
			url[ fill_index - 2 ] = '%';
			fill_index 			 -=   3;
		} else {
			url[fill_index] = url[i];
			fill_index --;
		}
	}

	return 0;		
}

/*
	Problem 1.4: Pallindrom Permutation

	Given a  string, write a function to check if it is a poermutation of a pallindrome.


	EXAMPLE : 
	input   : Tact Coa
	output  : True ( permutations "taco cat", "atco cta" )

*/

bool is_Pallindrom_permutation( std::string& str ) {
	std::vector<size_t> char_map(255, 0);
	size_t 		   		str_len = 0;
	
	for( auto c : str ) {
		c = tolower(c); 
		char_map[c] ++ ; 
		if( c != ' ')
			str_len ++;
	}

	bool is_str_even = str_len % 2 == 0;
	bool already_exists = false;
	for( size_t i = 0 ; i < 255 ; i ++ ) {
		/* This is not part of given str */
		if( char_map[i] == 0 || i == ' ' ){
			continue;
		}

		bool is_even = char_map [i]%2 == 0 ;
		if( is_str_even ) {
			if( is_even == false )
				return false;
		}

		if( is_str_even == false ) {
			if( is_even == false ) {
				if( already_exists )
					return false;
				already_exists = true;
			}
		}
	}
	return true;
}

/*
	Problem 1.5: One Away

	There are three types of edits that can be performed on a given string;
	insert a character, remove a character, replace a character.

	Given two strings write a function to check if they are one edit( or Zero edits ) away


	EXAMPLE : 
	pale, ple -> true
	pales, pale -> true
	pale, bale -> true
	pale, bake -> false


*/

bool is_one_edit_away( std::string &s1, std::string &s2 )
{
	std::vector<int> charMap(255,0);
	for( auto c : s1 ) { 
		charMap[c] ++ ; 
	}

	for( auto c : s2 ) {
		charMap[c] --;
	}

	size_t operation = 0;
	for( int c = 0; c < 255; c ++ ) {
		if( charMap[c] != 0 ) {
			operation ++;
		}
	}

	switch( operation )  {
		case 0: /* same */
		case 1: /* replace */
		case 2: /* add/remove */
			return true;
	}
	
	return false;
}



/*
	Problem 1.6: String Compression

	Implement a method to perform basic compression using counts of repeated characters

	EXAMPLE : 
	AABBCCCCCCD -> A2B2C6D1
	
*/

char *compress( char *str )
{
	size_t    strsz = strlen(str);
	char   *new_str = new char[strsz];		

		memset( new_str, 0, strsz );
	size_t char_index   = 0;
	size_t repeat_index = 0;

	for( size_t i = 0 ; i < strsz ; i ++ )  {
		if( i == 0 ) {
			new_str[char_index] = str[i];
			repeat_index = char_index + 1;
			new_str[repeat_index] = 1 + '0';
			continue;
		} 

		if( str[i] == new_str[char_index] ) {
			new_str[repeat_index] += 1;
		} else {
			char_index = repeat_index + 1;
			new_str[char_index] = str[i];
			repeat_index = char_index + 1;
			new_str[repeat_index] = 1 + '0';
		}
	}

	repeat_index += 1;
	new_str[ repeat_index ] = '\0';
	
	if( repeat_index >= strsz )
		return str;

	return new_str;
}

/*
	Problem 1.7: Rotate Matrix

	Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
	write a method to rotate the image by 90 degrees

	EXAMPLE : 
	                  90-deg 
	                  Anti-Cloack-wise

	1  2  3  4        4 8 12 16
	5  6  7  8        3 7 11 15
	9  10 11 12   =>  2 6 10 14
	13 14 15 16       1 5 9  13
	
*/

int rotate( int **matrix, const size_t M, const size_t N ) {
	//TODO 
	return 0;
}


/*
	Problem 1.8: Zero Matrix

	Write an algorithm such that if an element of a given M x N matrix is zero, its entire row and column
	are set to 0.

	EXAMPLE : 
	                  

	1 1 0 1    0 0 0 0
	1 1 1 1 => 1 1 0 1
	1 1 1 1    1 1 0 1

	
*/
int zero_matrix( int **matrix, const size_t m, const size_t n){

	std::vector< std::pair<size_t,size_t> > v;
	for( size_t i = 0 ; i < m ; i ++ ){
		for( size_t j = 0 ; j < n; j ++ ) {
			if( matrix[i][j] == 0 ){
				v.push_back( std::make_pair(i,j) );
			}
		}
	}

	for( auto p : v ) {
		size_t row = p.first;
		size_t col = p.second;

		for( size_t i = 0; i < n ; i ++ )
			matrix[row][i] = 0;

		for( size_t j = 0; j < m ; j ++ )
			matrix[j][col] = 0;
			
	}
	return 0;
} 

/*
	Problem 1.9: String Rotation

	Assume you have a function isSubString which checks if one word is a substring of another
	Given two strings s1 and s2 write code to check if s2 is a rotation of s1 using only one call is 
	isSubstring or equivalent

	
*/

bool is_a_rotation( std::string& s1, std::string& s2 )
{
	std::string s = s2 + s2;
	if( s.find(s1) == std::string::npos )
		return false;
	return true;
}
