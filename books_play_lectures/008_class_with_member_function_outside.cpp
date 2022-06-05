/* class with member functionc defined outside */

#include <iostream>
using namespace std;

class test {
private:
    int rollno;
    char name[10];

public:
    int count;
    void getdata();
    void setdata(int r, char* n);
    void display();
};

void test::getdata()
{
    cout << "\nEnter the Rollno";
    cin >> rollno;
    cout << "\nEnter name";
    cin >> name;
}

void test::setdata(int t, char* n)
{
    rollno = t;
    strcpy(name, n);
}

void test::display()
{
    cout << "\n Roll no =" << rollno;
    cout << "\n Name  =" << name;
}
int main()
{
    test obj1;
    obj1.getdata();
    obj1.display();

    test obj2;
    obj2.setdata(1, "vanitha");

    obj2.display();
}
