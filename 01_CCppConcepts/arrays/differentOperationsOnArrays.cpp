#include<iostream>
#include<stdio.h> // by including this we can use c features in cpp like printf etc

using namespace std;

int main(){
    // initialize an array
    int arr1[5];

    // initialize and declare
    int arr2[5] = {1, 2, 3,};

    // by default array is initialized with garbage values

    int arr2size = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Array size: " << arr2size << endl;

    for(int x: arr2){
        cout << x << endl;
    }

    cout << "------------" << endl;
    // empty array of size n
    int arr3[5] = {0};

    for(int x: arr3){
        cout << x << endl;
    }


    // undeclared array of size n with garbage values

    cout << "------------" << endl;


    int arr4[5];

    for(int x: arr4){
        cout << x << endl;
    }





    return 0;
}