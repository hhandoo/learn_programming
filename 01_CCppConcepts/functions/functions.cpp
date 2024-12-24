#include <iostream>

using namespace std;


int add(int a, int b){
    return a + b;
}

// lines 6 to 8 is function definition
// parameters defined in function definition are called formal parameters



int main(){
    int x,y,z;

    x = 1;
    y = 2;

    z = add(x,y); // function call with actual parameters

    cout << z << endl;
    return 0;
}