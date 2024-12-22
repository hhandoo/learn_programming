#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct rectangle {
    int length;
    int breadth;
};

int main(){

    // pointer takes 2 bytes of memory.

    // this pointer is in stack frame of the main function.
    struct rectangle r;
    r = {10, 5};

    struct rectangle *p = &r;

    // c's way of doing it
    (*p).length = 15;
    (*p).breadth = 15;

    // cpp's way of doing the same thing
    p -> length = 20;
    p -> breadth = 25;


    printf("Dims are %d x %d.\n",(*p).length, (*p).breadth);


    // create this in the heap memory

    struct rectangle *p2;

    // malloc function returns void pointer
    p2 = (struct rectangle *) malloc(sizeof(struct rectangle));

    p2 -> length = 10;
    p2 ->breadth = 15;


    printf("Dims are %d x %d.\n",(*p2).length, (*p2).breadth);

    return 0;
}