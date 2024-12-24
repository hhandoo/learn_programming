#include<iostream>

using namespace std;

class Animal{
    public:
        Animal(){
            cout << "Animal class has been initialized..." << endl;
        }

        void eat(){
            cout << "All animals eat food" << endl;
        }
};

class Dog : public Animal {
    public: 

        void bark(){
            cout << "A dog barks" << endl;
        }
};






int main(){

    Dog myDog; // object of dog class

    myDog.eat();
    myDog.bark();

    return 0;
}