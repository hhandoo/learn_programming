#include<iostream>
#include<stdio.h>

using namespace std;

struct rectangle {
    int l;
    int b;
};

struct test {
    int arr[5];
    int l;
};
int fun1_callByValue(struct rectangle r){
    return r.l * r.b;
}

int fun2_callByAddress(struct rectangle *r){
    return r->l * r->b;
}

int fun3_callByReference(struct rectangle &r){
    return r.l * r.b;
}


void pass_array(struct test t){
    t.arr[0] = 122;
    t.arr[1] = 2222;

    for(int x: t.arr){
        cout << x << endl;
    }
}





int main(){

    // init structure 
    struct rectangle r1 = {5, 6};

    int opt = fun1_callByValue(r1);
    printf("%d\n", opt);

    int opt2 = fun2_callByAddress(&r1);
    printf("%d\n", opt2);


    int opt3 = fun3_callByReference(r1);
    printf("%d\n", opt3);


    // how to pass an array ?

    struct test t = {{1,2,4,5,6},1};


    pass_array(t);




    return 0;
}