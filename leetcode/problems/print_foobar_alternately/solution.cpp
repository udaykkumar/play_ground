class FooBar {
private:
    int n;
    int print;
    
public:
    FooBar(int n) {
        this->n = n;
        print = 1;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            while( print == 2 );
        	printFoo();
            print = 2;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            while( print == 1 );
        	printBar();
            print= 1;
        }
    }
};