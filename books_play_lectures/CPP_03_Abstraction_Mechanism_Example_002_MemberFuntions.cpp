#include <iostream>

struct Date { // representation
  int d, m, y;
};

// initialize d
void init_date(Date& d, int, int, int);

// add n years to d
void add_year(Date& d, int n);

// add n months to d
void add_month(Date& d, int n);

// add n days to d
void add_day(Date& d, int n);

int main(int argc, char const *argv[]) {
  Date d;
  return 0;
}
