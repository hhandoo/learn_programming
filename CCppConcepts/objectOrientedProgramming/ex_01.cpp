#include <iostream>
using namespace std;

class Car
{
public:
    string brand;
    int year;

    void displayDetails()
    {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main()
{
    Car myCar; // Create an object of Car
    myCar.brand = "Toyota";
    myCar.year = 2021;

    myCar.displayDetails(); // Access the class method

    return 0;
}
