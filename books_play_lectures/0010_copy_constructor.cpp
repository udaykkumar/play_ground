// Example for copy constructor,

#include <iostream>
using namespace std;

class mobile {

    char* model;
    char* display;
    int pixel;
    int cost;

public:
    mobile(char* m, char* d, int p, int c)
    {
        model = new (nothrow) char[100];
        display = new (nothrow) char[100];
        strcpy(model, m);
        strcpy(display, d);
        pixel = p;
        cost = c;
    }

    mobile(const mobile& obj)
    {
        model = new (nothrow) char[strlen(obj.model) + 1];
        display = new (nothrow) char[strlen(obj.display) + 1];
        strcpy(model, obj.model);
        strcpy(display, obj.display);
        pixel = obj.pixel;
        cost=obj.cost;

        //Note: If there is no copy constructor
        //copy constructor and will make a shallow copy.
    }

    void show()
    {
        cout << model << endl
             << display << endl
             << pixel << endl
             << cost << endl;
    }
};

int main()
{
    mobile o("1100", "White", 1000, 1000);
    o.show();

    mobile o1(o);
    o1.show();

    return 0;
}
