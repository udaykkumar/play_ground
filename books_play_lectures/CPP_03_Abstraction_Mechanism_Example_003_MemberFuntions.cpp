#include <iostream>

struct Date { // representation
    int d, m, y;

    // initialize d
    void init(int, int, int);

    // add n years to d
    void add_year(int n);

    // add n months to d
    void add_month(int n);

    // add n days to d
    void add_day(int n) {
      this->d += 1;
    }

    void peek( std::string o = "Object") {
      std::cout << " class Date : " << o << " "  ;
      std::cout << " members { d : " << d << " , m : " << m << " , y : " << y << " } \n";
    }
};

void Date::init(int dd, int mm, int yy)
{
    d = dd;
    m = mm;
    y = yy;
}


Date my_birthday;
void f()
{
    Date today;
    today.peek("today");
    today.init(16, 10, 1996);
    today.peek("today");
    
    my_birthday.init(30, 12, 1950);
    today.peek("my_birthday");

    Date tomorrow = today;
    tomorrow.add_day(1); // ...
    tomorrow.peek("tomorrow");
}

int main(int argc, char const* argv[])
{
    f();

    my_birthday.peek();

    Date d1 = my_birthday; // initialization by copy
      d1.peek("d1");
    Date d2 { my_birthday }; // initialization by copy
    d2.peek("d2");
    return 0;
}
