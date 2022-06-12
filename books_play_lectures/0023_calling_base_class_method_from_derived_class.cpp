#include <iostream>

class Base{
  public:
    void foo(){ std::cout<<"base";}
};

class Derived : public Base { 
  public:
    void foo(){ 
      Base::foo(); 
    }        
};



class DerivedAgain : public Base { 
  public:
    void foo(int i){ 
      if ( i == 0 )
        Base::foo(); 
      else {
        std::cout << "recurse\n";
        foo(--i);
      }
    }        
};

int main(){
  Derived bar;
  bar.foo(); // calls Base::foo()
  DerivedAgain da;
  da.foo(5);
  return 0;
}