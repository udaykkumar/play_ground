#include <iostream>

int main(int argc, char const *argv[])
{
	char greeting[] = "hello";

	/**
	 * non-const pointer and non-const data
	 */
	char *p1 = greeting;

	p1[0] = '4'; // allowed 
	//p1 	  = "Another String"; // Allowed, with a warning
	std::cout << p1 << "\n";

	/**
	 * non-const pointer, const data
	 */
	const char *p2 = greeting;

	//p2[0] = 'f';  // Not allowed,'read only ' 
	p2 =	"Another String"; // Allowed, no warning
	std::cout << p2 << "\n";
	/**
	 * const pointer, non-const data
	 */
	char * const p3 = greeting;
	p3[0] = '4'; // Allowed
	//p3 = "Another String"; // Not allowed at all

	/**
	 * const pointer, const data;
	 */
	const char * const p4 = greeting;
	//p4[0] = 'x'; // Not Allowed
	//p4    = "Hyoasd"; // Not Allowed
	std::cout << p4 << "\n";

	// same effect const data - non const pointer
	const char *p5 = greeting;
	char const *p6 = greeting;

	// Below Works
	p5 = "Hyy";
	p6 = "yhh";
	std::cout << p5 << "\n";
	std::cout << p6 << "\n";
	//p5[0] = 'i'; // err
	//p6[0] = 'o'; // err
	return 0;
}