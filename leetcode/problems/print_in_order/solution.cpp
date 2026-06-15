class Foo {
    
    int to_print;
public:
    Foo() {
        to_print = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        while( to_print != 1);
        printFirst();
        to_print ++;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while( to_print != 2);
        printSecond();
        to_print ++;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while( to_print != 3);
        printThird();
        to_print ++;
    }
};