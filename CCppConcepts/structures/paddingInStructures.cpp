#include <iostream>
#include <stddef.h>  // For offsetof
using namespace std;

struct MyStruct {
    char a;
    int b;
    char c;
};

struct MyStruct1 {
    char a;
    char c;
};

int main() {
    cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes" << endl;
    cout << "Offset of 'a': " << offsetof(MyStruct, a) << endl;
    cout << "Offset of 'b': " << offsetof(MyStruct, b) << endl;
    cout << "Offset of 'c': " << offsetof(MyStruct, c) << endl;


    cout << "Size of MyStruct: " << sizeof(MyStruct1) << " bytes" << endl;
    cout << "Offset of 'a': " << offsetof(MyStruct1, a) << endl;
    cout << "Offset of 'c': " << offsetof(MyStruct1, c) << endl;
    return 0;
}
