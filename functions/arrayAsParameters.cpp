#include <iostream>

using namespace std;

void fun(int *A, int n){
    for (int i = 0; i<n; i++){
        cout << A[i] << endl;
    }
}

void fun1(int *A, int n){
    A[1] = 100;
}

int * fun2(int n){
    int *p;

    p = new int[n];

    for (int i=0; i<n; i++){
        p[i] = i + 1;

    }

    return p;
}

int main(){
    int A[] = {2,4,6,8,10};
    fun(A, 5);
    fun1(A, 5);
    cout << "---------------------" << endl;
    fun(A, 5);

    // creating an array
    cout << "----------create array in heap-----------" << endl;
    int *ptr, sz = 5;

    ptr = fun2(sz);


    for(int i=0; i<sz; i++){
        cout << ptr[i] << endl;
    }

    return 0;
}