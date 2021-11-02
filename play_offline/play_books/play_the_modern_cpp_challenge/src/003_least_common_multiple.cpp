#include <iostream>
#include <numeric>
#include <vector>

int gcd(int const a, int const b)
{
   return b == 0 ? a : gcd(b, a % b);
}


int main()
{
   std::vector<int> numbers{ 1,2,3,4,5,6};

   /// accumulate -  
   ////     is special it sends each element from vector to 
   ///   tha lambda function with 
   ///      a as init value and this keeps getting updated with return of lambda
   ///      b as the element in vector starting from 1 through to 6
   ///   for the first iteration its 1, 1 
   ///   for the second iteration    1, 2
   ///   for the third iterator      2, 3
   ///  so on ..

   std::cout << "lcm  " << std::accumulate(
                              numbers.begin(), // Input Iterator Start
                              numbers.end(),   // Input Iterator End
                              1,               // Starting value init
                              [](int const a, int const b){    // Our very own LCM evaluator
                                    int h = gcd(a, b);
                                 return h ? (a * (b / h)) : 0;
                              }
                           ) << std::endl;
   return 0;
}
