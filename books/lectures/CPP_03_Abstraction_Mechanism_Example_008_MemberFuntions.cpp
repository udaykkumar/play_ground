#include <iostream>


int getTodaysDay()
{
    return 0;
}

int getTodaysMonth()
{
    return 0;
}

int getTodaysYear()
{
    return 0;
}

class Date { // representation
    int d, m, y;

public:
    // initialize d
    // day, month, year
    explicit Date(int dd = 0, int mm = 0, int yy = 0)
    {
        d = dd ? dd : getTodaysDay();
        m = mm ? mm : getTodaysMonth();
        y = yy ? yy : getTodaysYear();
    }

    // day, month, today’s year
    explicit Date(int, int);

    // date in string representation
    explicit Date(const char*);

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

Date today;
void do_something(Date d) {
  //d.d ; /// this is error
}

int main(int argc, char const* argv[])
{
    Date d(1,1,1990);
    d.peek("d");
    return 0;
}
