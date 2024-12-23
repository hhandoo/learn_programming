#include<iostream>

using namespace std;

// Abstract Class
class Shape{
    public:
        virtual void draw() = 0; // Pure Virtual Function
        virtual ~Shape() {}; // Virtual Destructor
};


class Circle : public Shape {
    public: 
        void draw() override {
            cout << "Drawing a circle" << endl;
        }
};

class Rectangle : public Shape {
    public:
        void draw() override {
            cout << "drawing a rectangle" << endl;
        }
};



int main(){
    Shape *shape1 = new Circle();
    Shape *shape2 = new Rectangle();

    shape1->draw();  // Calls Circle's draw()
    shape2->draw();  // Calls Rectangle's draw()

    delete shape1;
    delete shape2;

    
    return 0;
}
