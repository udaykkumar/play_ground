#include <iostream>

class Date { // representation
    int d, m, y;

public:
    // initialize d
    void init(int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    }

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
    Date d;
    d.init(1,1,1990);
    do_something(d);
    return 0;
}
