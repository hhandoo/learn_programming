#include<iostream>
using namespace std;

void swap_passByValue(int a, int b){
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void swap_passByAddress(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_passByReference(int &a, int &b){
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a, b;

    a = 10;
    b = 20;

    swap_passByValue(a, b);
    cout<< "a: " << a <<" b: " << b << endl;
    swap_passByAddress(&a, &b);
    cout<< "a: " << a <<" b: " << b << endl;
    swap_passByReference(a, b);
    cout<< "a: " << a <<" b: " << b << endl;
    return 0;
}