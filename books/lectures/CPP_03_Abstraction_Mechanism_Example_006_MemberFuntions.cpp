#include <iostream>

class Date { // representation
    int d, m, y;

public:
    // initialize d
    // day, month, year
    Date(int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    }

    // day, month, today’s year
    Date(int, int);

    // day, today’s month and year
    Date(int);

    // default Date: today
    Date();

    // date in string representation
    Date(const char*);

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


void do_something(Date d) {
  //d.d ; /// this is error
}

int main(int argc, char const* argv[])
{
    Date d(1,1,1990);
    d.peek("d");
    return 0;
}
