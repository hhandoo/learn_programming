#include <iostream>

using namespace std;


class Arithmatic{
    public:
        Arithmatic(){
            cout << "Arithmatic has been initialized" << endl; 
        }

        int add(int a, int b){
            cout << "add int" << endl;
            return a + b;
        }

        double add(double a, double b){
            cout << "add double" << endl;

            return a + b;
        }
};




class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};


int main(){

    // function overloading

    Arithmatic myArithmatic;

    cout << myArithmatic.add(1, 2) << endl;

    cout << myArithmatic.add(1.5, 2.55) << endl;
    

    // function overriding

    Shape *myshape;

    Circle myCircle;

    myshape = &myCircle;

    myCircle.draw();


}