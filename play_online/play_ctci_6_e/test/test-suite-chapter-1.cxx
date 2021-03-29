#include "chapter_1.hxx"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( chapter_1_suite);

BOOST_AUTO_TEST_CASE( chapter_1_1_1_is_uniq_simple_case )
{
	std::string s("AL_Uniq_Chrs");
	BOOST_CHECK( is_unique(s) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_1_is_uniq_string_with_repeating_characters_returns_false )
{
	std::string s("Hello_World_is_False");
	BOOST_CHECK( is_unique(s) == false );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_1_is_uniq_string_empty_string_is_true )
{
	std::string s("");
	BOOST_CHECK( is_unique(s) == true );
}

BOOST_AUTO_TEST_CASE( chapter_1_1_1_is_uniq_string_is_case_sensitive_so_returns_true_for_AaBbCc )
{
	std::string s("AbBbCc");
	BOOST_CHECK( is_unique(s) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_1_is_uniq_string_with_single_character_is_true )
{
	std::string s("A");
	BOOST_CHECK( is_unique(s) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_2_is_one_permutation_of_other_v1_simple_case )
{
	std::string s1("abcs");
	std::string s2("csba");
	BOOST_CHECK( is_one_permutation_of_other_v1(s1,s2) == true );	
	
}


BOOST_AUTO_TEST_CASE( chapter_1_1_2_is_one_permutation_of_other_v1_simple_for_false )
{
	std::string s1("abcs");
	std::string s2("ccba");
	BOOST_CHECK( is_one_permutation_of_other_v1(s1,s2) == false );	
	
}


BOOST_AUTO_TEST_CASE( chapter_1_1_2_is_one_permutation_of_other_v2_simple_case )
{
	std::string s1("abcs");
	std::string s2("csba");
	BOOST_CHECK( is_one_permutation_of_other_v2(s1,s2) == true );	
	
}


BOOST_AUTO_TEST_CASE( chapter_1_1_2_is_one_permutation_of_other_v2_simple_for_false )
{
	std::string s1("abcs");
	std::string s2("ccba");
	BOOST_CHECK( is_one_permutation_of_other_v2(s1,s2) == false );	
	
}


BOOST_AUTO_TEST_CASE( chapter_1_1_3_urlify_simple_case )
{
	std::string urlified_url = "Mr%20John%20Smith";
	char url[] = "Mr John Smith    ";
	BOOST_CHECK( urlify( url, 13 ) == 0 );
	BOOST_CHECK( std::string(url) == urlified_url );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_3_urlify_a_little_bitter_case )
{
	std::string urlified_url = "A%20B%20C%20D%20E%20F";
	char url[] 				 = "A B C D E F          ";
	
	BOOST_CHECK(urlify( url, 11 ) == 0 );
	BOOST_CHECK( std::string(url) == urlified_url );
}



BOOST_AUTO_TEST_CASE( chapter_1_1_3_urlify_a_url_with_so_many_adjacent_spaces )
{
	std::string urlified_url = "A%20%20%20%20%20%20%20%20%20x";
	char url[] 				 = "A         x                  ";

	BOOST_CHECK( urlify( url, 11 ) == 0 );
	BOOST_CHECK( std::string(url) == urlified_url );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_3_urlify_buffer_with_not_enough_space_returns_minus_1 )
{
	std::string urlified_url = "A%20%20%20%20%20%20%20%20%20x";
	char url[] 				 = "A         x                 ";
	
	BOOST_CHECK( urlify( url, 11 ) == -1 );
}

BOOST_AUTO_TEST_CASE( chapter_1_1_4_is_Pallindrom_permutation_simple_case )
{
	std::string str = "malayalam";
	BOOST_CHECK( is_Pallindrom_permutation(str) == true );
}

BOOST_AUTO_TEST_CASE( chapter_1_1_4_is_Pallindrom_permutation_simple_case_2 )
{
	std::string str = "Tact Coa";
	BOOST_CHECK( is_Pallindrom_permutation(str) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_4_is_Pallindrom_permutation_simple_case_3 )
{
	std::string str = "Hello olleH";
	BOOST_CHECK( is_Pallindrom_permutation(str) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_4_is_Pallindrom_permutation_simple_case_4 )
{
	std::string str = "Malayanam";
	BOOST_CHECK( is_Pallindrom_permutation(str) == false );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_4_is_Pallindrom_permutation_simple_case_5 )
{
	std::string str = "MalayaLam";
	BOOST_CHECK( is_Pallindrom_permutation(str) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_4_is_Pallindrom_permutation_simple_case_6 )
{
	std::string str = "OutuuO";
	BOOST_CHECK( is_Pallindrom_permutation(str) == false );
}



BOOST_AUTO_TEST_CASE( chapter_1_1_5_is_one_edit_away_simple_case )
{
	std::string str1 = "pale";
	std::string str2 = "pal";
	BOOST_CHECK( is_one_edit_away(str1, str2) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_5_is_one_edit_away_simple_case_2 )
{
	std::string str1 = "pale";
	std::string str2 = "palp";
	BOOST_CHECK( is_one_edit_away(str1, str2) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_5_is_one_edit_away_simple_case_3 )
{
	std::string str1 = "pal";
	std::string str2 = "pale";
	BOOST_CHECK( is_one_edit_away(str1, str2) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_5_is_one_edit_away_simple_case_4 )
{
	std::string str1 = "pale";
	std::string str2 = "naje";
	BOOST_CHECK( is_one_edit_away(str1, str2) == false );
}



BOOST_AUTO_TEST_CASE( chapter_1_1_6_compress_simple_case_1 )
{
	char a[] = "AAAABBBBCCCCDDDD";
	std::string compressed = "A4B4C4D4";
	BOOST_CHECK( std::string(compress(a)) == compressed );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_6_compress_simple_case_2 )
{
	char a[] = "AABBCCCCCCD";
	std::string compressed = "A2B2C6D1";
	BOOST_CHECK( std::string(compress(a)) == compressed );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_6_compress_simple_case_3 )
{
	char a[] = "AA";
	std::string compressed = "A2";
	BOOST_CHECK( std::string(compress(a)) != compressed );
	BOOST_CHECK( std::string(compress(a)) == std::string(a) );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_6_compress_simple_case_4 )
{
	char a[] = "ABCDEFGHIJ";
	std::string compressed = "A1B1C1D1G1H1I1J1K1";
	BOOST_CHECK( std::string(compress(a)) != compressed );
	BOOST_CHECK( std::string(compress(a)) == std::string(a) );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_7_martix_rotate_todo )
{
	//TODO Week point is matrix and multi dimensional arrays
	int **foo = NULL;
	BOOST_CHECK( rotate(foo, 0 , 0)  == 0);
}



BOOST_AUTO_TEST_CASE( chapter_1_1_8_zero_matrix_simple_case_1_todo )
{
	//TODO Week point is matrix and multi dimensional arrays
}

BOOST_AUTO_TEST_CASE( chapter_1_1_9_is_a_rotation_simple_case_1 )
{
	std::string s1 = "waterbottle";
	std::string s2 = "erbottlewat";

	BOOST_CHECK( is_a_rotation( s1, s2) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_9_is_a_rotation_simple_case_2 )
{
	std::string s1 = "helloworld";
	std::string s2 = "orldhellow";

	BOOST_CHECK( is_a_rotation( s1, s2) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_9_is_a_rotation_simple_case_3 )
{
	std::string s1 = "helloworld";
	std::string s2 = "helloworld";

	BOOST_CHECK( is_a_rotation( s1, s2) == true );
}


BOOST_AUTO_TEST_CASE( chapter_1_1_9_is_a_rotation_simple_case_4 )
{
	std::string s1 = "helloworld";
	std::string s2 = "Yes";

	BOOST_CHECK( is_a_rotation( s1, s2) == false );
}
BOOST_AUTO_TEST_SUITE_END();
