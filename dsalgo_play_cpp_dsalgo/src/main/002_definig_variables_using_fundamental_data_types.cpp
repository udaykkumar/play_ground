#include <iostream>

#define STRING_OF(x) (#x)
#define PRINT_SIZE_OF(x)  do { std::cout << STRING_OF(x) << sizeof(x) << std::endl; } while ( 0 );

int main(int argc, char const *argv[])
{
	/// Classic definition
	{
		int iVar;
		char32_t cVar;
		long long llVar;
		bool bVar;

		iVar = 100;
	    cVar = 'a';
	    llVar = 9223372036854775805;
	    bVar = true;

	    
	    (void)iVar;
  		(void)cVar;
  		(void)llVar;
  		(void)bVar;
	}

	/// Classic declaration 
	{
		int iVar = 100;
	    char32_t cVar = 'a';
	    long long llVar = 9223372036854775805;
	    bool bVar = true;
	    (void)iVar;
  		(void)cVar;
  		(void)llVar;
  		(void)bVar;
	}

	/// bit modern way
	{
		int iVar(100);
	    char32_t cVar('a');
	    long long llVar(9223372036854775805);
	    bool bVar(true);
	    (void)iVar;
  		(void)cVar;
  		(void)llVar;
  		(void)bVar;
	}

	/// more modern way
	{
		int iVar{100};
	    char32_t cVar{'a'};
	    long long llVar{9223372036854775805};
	    bool bVar{true};
	    (void)iVar;
  		(void)cVar;
  		(void)llVar;
  		(void)bVar;
	}

	/// corresponding size chart
	PRINT_SIZE_OF(int);
	PRINT_SIZE_OF(char32_t);
	PRINT_SIZE_OF(long long);
	PRINT_SIZE_OF(bool);

	return 0;
}