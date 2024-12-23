# Object Oriented Programming (OOP) in C/C++

Object-Oriented Programming (OOP) in C++ is a programming paradigm based on the concept of objects, which can contain data in the form of fields (often referred to as attributes or properties) and code in the form of methods (functions or procedures). OOP in C++ is used to structure software in a way that is modular, reusable, and easier to manage.


## Classes and Objects

A `class` is a blueprint for creating objects. `Objects` are instances of a class.


```cpp
#include <iostream>
using namespace std;
class Car {
public:
    string brand;
    int year;

    void displayDetails() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};
int main() {
    Car myCar;  // Create an object of Car named myCar
    myCar.brand = "Toyota";
    myCar.year = 2021;

    myCar.displayDetails();  // Access the class method

    return 0;
}
```


## Encapsulation
Encapsulation is achieved by bundling data (variables) and methods (functions) that operate on the data into a single unit (class). Use private and public access specifiers.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;  // Private data member

public:
    // Constructor
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Public methods to access private data
    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(1000.0);  // Initial balance
    account.deposit(500.0);  // Deposit money
    cout << "Current Balance: " << account.getBalance() << endl;

    return 0;
}

```

## Inheritance

Inheritance allows a class (child) to inherit properties and behaviors from another class (parent).

```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited method
    myDog.bark(); // Own method

    return 0;
}

```
