#include <iostream>

using namespace std;

class myClass {
private:
    int* _ptr;
public:
    myClass();
    myClass(int val);
    myClass(const myClass &obj);
    ~myClass();
    void print() { cout << "Ptr value = " << *_ptr << endl; }
    int getVal() { return *_ptr;  }

};

myClass::myClass()
{
    _ptr = new int;
    *_ptr = 1;
}

myClass::myClass(int val) {
    cout << "This destructor call" << endl;

    _ptr = new int;
    *_ptr = val;
}

myClass::~myClass()
{
    cout << "This is destructor call" << endl;
    delete(_ptr);
}

myClass::myClass(const myClass &obj) {
    _ptr = new int;
    *_ptr = *obj._ptr;
    cout << "This is copy constuctor call" << endl;
}

void display(myClass &obj) {
    cout << "Display" << obj.getVal() << endl;
}

int main() {
    myClass b(20);
    b.print();
    display(b);
    return 0;
}

