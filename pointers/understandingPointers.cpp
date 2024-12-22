#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main(){
    // data variable
    int a = 10; // created in stack frame of main function

    // address variable(s) are called pointers in c/cpp
    int *p; // declartion

    p = &a; // initialization
    // created in stack frame of main function but consisting of address of previously declared a

    printf("%d\n", a);
    printf("%p\n", p);
    printf("%d\n", *p); // dereferencing


    // how to get memory in heap

    // malloc point to the address at heap memory in the main memory.

    // in c
    int *j;
    j = (int *) malloc(5*sizeof(int));


    // in cpp

    j = new int[5];

    // pointers to an array

    int A[5] = {1,2,3,4,5};

    int *p2;

    // option 1
    p2 = A; // as A itself is an address 
    // pointer can act as a name of an array
    printf("%p\n", p2);


    for(int i=0; i<5; i++){
        cout << p2[i] << endl;
    }

    // option 2
    p2 = &A[0];
    printf("%p\n", p2);



    int *p3;

    p3 = (int *) malloc(5 * sizeof(int)); // c method
    p3 = new int[5];

    p3[0] = 1;
    p3[1] = 2;
    p3[2] = 3;
    p3[3] = 4;
    p3[4] = 5;


    for(int i=0; i<5; i++){
        cout << p3[i] << endl;
    }



    // delete [ ] p3; // good practice to release the memory // C
    free(p3);
    return 0;
}