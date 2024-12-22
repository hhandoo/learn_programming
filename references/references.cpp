#include<iostream>

using namespace std;

int main(){
    int a = 10; // reference points to the same address in the stack frame of the main function in the main memory of a defined data variable.
    
    int &r = a; // dec + init it has to be initialized when it is declared
    cout << a << endl;
    r++;

    cout << r << endl;
    cout << a << endl;
    return 0;
}