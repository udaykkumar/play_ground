#include <iostream>


void print( const char *s )
{
    std::cout << "the char * is : " << s << std::endl;
}

/* Obviously this is as good as above so 
 * this will throw a redifinition error
 */
// Error unless we fo #if 0 .. #endif
//
#if 0
void print( string s )
{
    std::cout << "the string is : " << s << std::endl;
}
#endif

int main()
{
    const char *s = "String"; 
    print(s);

    return (0);
}
