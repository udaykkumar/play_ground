#include <iostream>

int returnByValue()
{
    return 5;
}

int main()
{
    std::cout << "we call this function returnByValue and assign it to a const reference " << std::endl;
    std::cout << "Now Generally this results in an erro returnByValue assigned to reference " << std::endl;
    std::cout << "In this case however it is Okay , since const references can bound to rvalues ( expressions without address )" << std::endl;
    //Error
    //    int &ref = returnByValue();
    //Okay
        const int &ref = returnByValue();

    return 0;
}
