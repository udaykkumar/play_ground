

/**
 * This symbol here may never be seen by the compiler 
 * and may be removed by the preprocessor before 
 * the source code ever gets to the compiler
 */
#define ASPECT_RATIO 1.653


/**
 * Definitely Seen by the compiler and will certainly enter into
 * the symbols database 
 */
const double AspectRatio = 1.653;

/**
 * 	Note - 
 *	 There is a blind substitution that happens when using a preprocessor
 *	use of const may field a smaller code
 */

/**
 *
 * There are two special cases, when one tries to replace the #defines with const 
 *  	1.	definign const pointers
 *  			because constant definitios are usually put in hpp, important that 
 *  		pointer be declared as const in addition to what pointer points to
 *
 * 		like below
 * 	
 */
const char * const someString = "Hello There";

/**
 * a better c++ way is to use std::string ; ofcourse
 */

const std::string someCppString("Hello There");

/**
 * 	Now the second case
 * 		2.	make sure to limit the scope of these constants to a class
 *
 * 	example ..
 */

class fooClass
{
public:
	fooClass();
	~fooClass();

private:
	static const int numFooInstances = 5;
	int foos[numFooInstances];
	
};

/**
 *	Note :
 *		the numFooInstances above is a declaration and not a definition..
 *
 * 		Okay **Important**
 * 			Usually C++, requires that you provide definition for anything you use.
 * 			however class-specific constants that are static and of integral type are exception
 *
 * 			As long as you dont take the address of those you can declare them and use them
 *
 * 		There is NO WAY to create a class specific constant using #define because #define doesn't 
 * 		respect the concept of scoping they live as long as they are not encountered with #undef
 *
 * 		and there is no encapsulation as there is no "private" for #defines
 */

class loggerClass
{
public:
	loggerClass();
	~loggerClass();
	
	private:
		static const int log_level;	// This declaration of static class constant goes in header
};

// somehere is the impl for this

const int loggerClass::log_level = 5; // you see its accessible even with a private scope..


