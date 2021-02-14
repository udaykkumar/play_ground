#include<iostream>

void function()
{
	int *ptr = new int;
	std::cout << "ptr will not point to heap at " << ptr << std::endl;
	
	*ptr = 5;
	std::cout << "ptr will now have a value " << *ptr << std::endl;

	int *ptrArray = new int[10];
	std::cout << "ptrArray will not point to heap at " << ptrArray << std::endl;
	for( int i = 0 ; i < 10 ; i  ++ )
		ptrArray[i] = i;

	std::cout << "ptrArray will now have a value " ;
	for( int i = 0 ; i < 10; i ++ ) 
		std::cout << ptrArray[i] << " " ;
	std::cout << std::endl;

}
int main()
{
	function();
	return 0;
}