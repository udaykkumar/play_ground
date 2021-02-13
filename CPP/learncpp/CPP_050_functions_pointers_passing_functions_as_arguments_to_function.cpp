#include <iostream>

void callbackOne()
{
    std::cout << std::endl << "Called Back 1" << std::endl;
}
void callbackTwo()
{
    std::cout << std::endl << "Called Back 2" << std::endl;
}
int return5( void (*callBack)() )
{
    (*callBack)();
    return 5;
}

int return10( void (*callBack)() )
{
    callBack();
    return 10;
}


int main()
{
   
    std::cout << "return 5 with CallBack 1 " << return5( callbackOne ) << std::endl;
    std::cout << "return 10 with CallBack 1 " << return10( callbackOne ) << std::endl;

    std::cout << "return 5 with CallBack 2 " << return5( callbackTwo ) << std::endl;
    std::cout << "return 10 with CallBack 2 " << return10( callbackTwo ) << std::endl;

    return (0);
}
