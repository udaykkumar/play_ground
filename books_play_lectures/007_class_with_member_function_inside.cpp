/* class with member functions defined inside */
#include <iostream>
#include <string>
using namespace std;

class test {
private:
    int rollno;
    char name[10];

public:
    int count;
    void getdata()
    {
        cout << "\nEnter the Rolino ";
        cin >> rollno;
        cout << "\nEnter name";
        cin >> name;
    }

    void display()
    {
        cout << "\n Roll no = " << rollno;
        cout << "\n Name = " << name;
    }
};

int main()
{
    test obj;
    // obj.rollno=10; // cannot access directly the private data member
    obj.count = 1; // can be accessed since it is a public data member
    obj.getdata(); // invoking the member function
    obj.display(); // invoking the member function

    return 0;
}
