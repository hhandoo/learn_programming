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


## Polymorphism

Polymorphism allows functions to behave differently based on the object that calls them.

### Compile-Time Polymorphism (Function Overloading) (static Polymorphism):

Compile-time polymorphism, also known as static polymorphism, occurs when the decision about which function to invoke is made during the program's compilation. Function overloading is a key example of compile-time polymorphism in C++.

In function overloading, multiple functions can have the same name but must differ in one or more of the following ways:

- Number of parameters
- Types of parameters
- Order of parameters

The compiler determines the appropriate function to call based on the arguments provided during the function call. This allows for flexibility and code readability.
#### Example 1
```cpp
#include <iostream>
using namespace std;

// Function with one integer parameter
void display(int num) {
    cout << "Integer: " << num << endl;
}

// Function with one double parameter
void display(double num) {
    cout << "Double: " << num << endl;
}

// Function with two integer parameters
void display(int num1, int num2) {
    cout << "Two integers: " << num1 << " and " << num2 << endl;
}

int main() {
    display(10);          // Calls the first function
    display(3.14);        // Calls the second function
    display(20, 30);      // Calls the third function
    return 0;
}

```
#### Example 2
```cpp
#include <iostream>
using namespace std;

class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    MathOperations math;
    cout << "Integer addition: " << math.add(2, 3) << endl;
    cout << "Double addition: " << math.add(2.5, 3.1) << endl;

    return 0;
}

```


### Run-Time Polymorphism (Virtual Functions) (dynamic polymorphism):

Run-time polymorphism, also known as dynamic polymorphism, occurs when the decision about which function to invoke is made during the program's execution. Virtual functions in C++ are a primary example of achieving run-time polymorphism.

A virtual function is a member function in a base class that you expect to be overridden in derived classes. By declaring a function as virtual in the base class, you allow the derived class's function to be invoked, even if the call is made through a pointer or reference to the base class.

#### Example 1

```cpp
#include <iostream>
using namespace std;

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

int main() {
    Shape* shape;
    Circle circle;
    shape = &circle;

    shape->draw();  // Calls Circle's draw()

    return 0;
}
```


### Run-time Polymorphism vs Compile-time polymorphism


| **Aspect**                  | **Compile-Time Polymorphism**                                              | **Run-Time Polymorphism**                                                |
|-----------------------------|---------------------------------------------------------------------------|---------------------------------------------------------------------------|
| **Definition**              | Polymorphism where the method to be invoked is determined during compilation. | Polymorphism where the method to be invoked is determined at runtime.    |
| **Mechanism**               | Achieved through **function overloading** or **operator overloading**.     | Achieved through **function overriding** and **virtual functions**.      |
| **Binding Type**            | **Static Binding:** The method call is bound to the method body at compile time. | **Dynamic Binding:** The method call is bound to the method body at runtime. |
| **Flexibility**             | Less flexible, as decisions are made during compilation.                   | More flexible, as decisions are made dynamically at runtime.             |
| **Performance**             | Faster execution since decisions are made during compilation.              | Slightly slower due to runtime decision-making (dynamic dispatch).       |
| **Scope**                   | Occurs within the same class.                                              | Occurs across a base and derived class relationship.                     |
| **Implementation**          | Uses **function overloading** (same name, different parameter lists).       | Uses **function overriding** (same name, same parameters).               |
| **Keyword Requirement**     | No special keyword is needed.                                              | Requires the `virtual` keyword in the base class and possibly `override` in the derived class. |
| **Usage Context**           | Used when methods perform similar operations with varying inputs or implementations. | Used in situations requiring **dynamic behavior** like abstract classes or polymorphic interfaces. |
| **Code Maintenance**        | Simplifies function naming but less adaptable to changes in object hierarchy. | Facilitates extensibility in object-oriented designs.                    |
| **Polymorphism Type**       | **Static Polymorphism**                                                    | **Dynamic Polymorphism**                                                 |
| **Inheritance**             | Not required.                                                              | Requires inheritance.                                                    |



### **Advantages and Disadvantages**

| **Aspect**                 | **Compile-Time Polymorphism**                                          | **Run-Time Polymorphism**                                                |
|----------------------------|----------------------------------------------------------------------|---------------------------------------------------------------------------|
| **Advantages**             | - Improves performance due to compile-time binding.                  | - Increases flexibility by allowing dynamic behavior.                    |
|                            | - Simplifies function naming by overloading.                         | - Facilitates polymorphic designs and reduces coupling.                  |
| **Disadvantages**          | - Cannot adapt to changes in object hierarchy dynamically.            | - Introduces slight overhead due to dynamic dispatch.                    |
|                            | - Less flexible for certain use cases requiring runtime decisions.    | - Requires careful use of inheritance to avoid complexity.               |

---

### **When to Use Each**

| **Scenario**                               | **Polymorphism Type**          | **Reason**                                                              |
|-------------------------------------------|--------------------------------|--------------------------------------------------------------------------|
| You want multiple versions of a function differing in input types or counts. | Compile-Time Polymorphism     | Overloading provides a clear and efficient way to achieve this.          |
| You need dynamic behavior based on the type of object at runtime.             | Run-Time Polymorphism         | Overriding with virtual functions allows flexibility and extensibility.   |
| Performance is critical, and you know the function details at compile time.   | Compile-Time Polymorphism     | Eliminates the need for dynamic dispatch, improving execution speed.      |
| You’re designing a polymorphic interface or using abstract base classes.      | Run-Time Polymorphism         | Supports dynamic behavior for diverse object hierarchies.                |


## Abstraction
Abstraction is an object-oriented programming concept where only essential details of an object are exposed to the user, hiding the implementation details. It helps in reducing complexity and increases the ease of use.

In C++, abstraction is typically achieved through:

- Abstract classes (classes with at least one pure virtual function).
- Interfaces (a form of abstract class where all member functions are pure virtual).


```cpp
#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw();  // Calls Circle's draw()
    shape2->draw();  // Calls Rectangle's draw()

    delete shape1;
    delete shape2;

    return 0;
}
```


## Understanding Virtual Functions and Pure Virtual Functions

### Virtual Functions
A **virtual function** is a member function in a base class that can be overridden in a derived class. It allows for **runtime polymorphism**, enabling the program to decide at runtime which function to call based on the type of the object pointed to, rather than the type of the pointer.

- Declared using the `virtual` keyword in the base class.
- The function in the derived class must have the same signature (name, parameters, and return type).
- Accessed using a base class pointer or reference pointing to a derived class object.

---

**Example: Virtual Functions**
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {  // Virtual function
        cout << "Display from Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {  // Overriding the base class function
        cout << "Display from Derived class" << endl;
    }
};

int main() {
    Base* basePtr;   // Pointer to Base class
    Derived derivedObj;

    basePtr = &derivedObj;  // Pointing to Derived class object
    basePtr->display();     // Calls Derived class's display() function

    return 0;
}
```

**Output**:
```
Display from Derived class
```

---

### Pure Virtual Functions
A **pure virtual function** is a virtual function in a base class that is declared by assigning it to `0`. It does not have an implementation in the base class and must be overridden by derived classes. 

- Declared using the syntax:  
  ```cpp
  virtual void function_name() = 0;
  ```
- Makes the base class an **abstract class**, meaning it cannot be instantiated directly.
- Forces derived classes to provide an implementation for the function.

---

**Example: Pure Virtual Functions**
```cpp
#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw();  // Calls Circle's draw()
    shape2->draw();  // Calls Rectangle's draw()

    delete shape1;
    delete shape2;

    return 0;
}
```

**Output**:
```
Drawing a Circle
Drawing a Rectangle
```

---

### **Key Differences**

| **Aspect**               | **Virtual Functions**                          | **Pure Virtual Functions**                      |
|--------------------------|-----------------------------------------------|------------------------------------------------|
| **Definition**           | Functions declared with the `virtual` keyword. | Functions declared as `virtual` and set to `= 0`. |
| **Implementation**       | May have an implementation in the base class. | No implementation in the base class. Must be overridden in derived classes. |
| **Abstract Class**        | Not required for base class to be abstract.   | Declaring a pure virtual function makes the class abstract. |
| **Usage**                | Provides runtime polymorphism and optional overriding. | Enforces derived classes to implement the function, ensuring behavior. |
| **Instantiation**        | The base class can still be instantiated.      | The base class cannot be instantiated.         |

### **Use Cases**
- **Virtual Functions**: When a base class provides a default implementation that derived classes can override if needed.
- **Pure Virtual Functions**: When you want to define an interface or enforce that derived classes provide specific behavior.


## Constructors

In C++, **constructors** are special member functions that are automatically called when an object of a class is created. They are used to initialize objects of the class. Constructors can be categorized based on their behavior, arguments, and initialization methods. Here are the **types of constructors** in C++:

### Default Constructor
A **default constructor** is a constructor that takes no arguments or has all its arguments with default values.

- **Syntax**: 
  ```cpp
  class ClassName {
  public:
      ClassName() {
          // initialization code
      }
  };
  ```

- **Example**:
  ```cpp
  class MyClass {
  public:
      MyClass() {
          cout << "Default constructor called" << endl;
      }
  };
  
  int main() {
      MyClass obj;  // Calls the default constructor
  }
  ```

- **Output**:
  ```
  Default constructor called
  ```

---

### 2. **Parameterized Constructor**
A **parameterized constructor** is a constructor that takes arguments to initialize an object with specific values.

- **Syntax**: 
  ```cpp
  class ClassName {
  public:
      ClassName(Type arg1, Type arg2) {
          // initialization using arguments
      }
  };
  ```

- **Example**:
  ```cpp
  class MyClass {
  private:
      int x, y;
  public:
      MyClass(int a, int b) {
          x = a;
          y = b;
      }
      void display() {
          cout << "x: " << x << ", y: " << y << endl;
      }
  };
  
  int main() {
      MyClass obj(10, 20);  // Calls the parameterized constructor
      obj.display();
  }
  ```

- **Output**:
  ```
  x: 10, y: 20
  ```

---

### 3. **Copy Constructor**
A **copy constructor** is a constructor that initializes an object using another object of the same class. It is typically used when an object is passed by value or returned by value.

- **Syntax**:
  ```cpp
  class ClassName {
  public:
      ClassName(const ClassName& other) {
          // copy initialization
      }
  };
  ```

- **Example**:
  ```cpp
  class MyClass {
  private:
      int x;
  public:
      MyClass(int a) : x(a) {}
      
      // Copy constructor
      MyClass(const MyClass& obj) {
          x = obj.x;
          cout << "Copy constructor called" << endl;
      }
      
      void display() {
          cout << "x: " << x << endl;
      }
  };
  
  int main() {
      MyClass obj1(10);
      MyClass obj2 = obj1;  // Calls the copy constructor
      obj2.display();
  }
  ```

- **Output**:
  ```
  Copy constructor called
  x: 10
  ```

---

### 4. **Move Constructor (C++11 and later)**
A **move constructor** is used to transfer resources from one object to another. It is typically used when objects are returned by value or passed by value, to avoid unnecessary copies and improve performance. The move constructor "steals" the resources of a temporary object.

- **Syntax**:
  ```cpp
  class ClassName {
  public:
      ClassName(ClassName&& other) {
          // move initialization
      }
  };
  ```

- **Example**:
  ```cpp
  class MyClass {
  private:
      int* data;
  public:
      MyClass(int value) {
          data = new int(value);
      }

      // Move constructor
      MyClass(MyClass&& other) noexcept {
          data = other.data;
          other.data = nullptr;  // Null out the source's pointer
          cout << "Move constructor called" << endl;
      }

      void display() {
          if (data) cout << "data: " << *data << endl;
          else cout << "data is null" << endl;
      }
  };
  
  int main() {
      MyClass obj1(10);
      MyClass obj2 = std::move(obj1);  // Calls the move constructor
      obj2.display();
      obj1.display();  // obj1 is now empty
  }
  ```

- **Output**:
  ```
  Move constructor called
  data: 10
  data is null
  ```

---

### 5. **Implicit Constructor**
An **implicit constructor** is a constructor that can be called without explicitly passing arguments (implicitly called by the compiler). This includes the default constructor, copy constructor, and others that can be called implicitly.

- **Example**: The following constructor can be called implicitly:
  ```cpp
  class MyClass {
  public:
      MyClass(int x) {
          cout << "Constructor called with value: " << x << endl;
      }
  };

  int main() {
      MyClass obj = 5;  // Implicitly calls the constructor with argument 5
  }
  ```

- **Output**:
  ```
  Constructor called with value: 5
  ```

---

### 6. **Explicit Constructor**
An **explicit constructor** is a constructor that cannot be used implicitly for type conversion. It is declared with the `explicit` keyword to prevent automatic type conversions or copy initialization that might lead to undesired behavior.

- **Syntax**:
  ```cpp
  class ClassName {
  public:
      explicit ClassName(int x) {
          // initialization
      }
  };
  ```

- **Example**:
  ```cpp
  class MyClass {
  public:
      explicit MyClass(int x) {
          cout << "Constructor called with value: " << x << endl;
      }
  };

  int main() {
      MyClass obj1 = 5;   // Error: Explicit constructor prevents implicit conversion
      MyClass obj2(10);    // Correct: Explicit constructor called with argument 10
  }
  ```

- **Output**:
  ```
  Constructor called with value: 10
  ```

---

### 7. **Conversion Constructor**
A **conversion constructor** is a constructor that can convert an object of one type to another type. It is typically used to convert one class type to another.

- **Syntax**:
  ```cpp
  class ClassName {
  public:
      ClassName(OtherType arg) {
          // conversion logic
      }
  };
  ```

- **Example**:
  ```cpp
  class MyClass {
  private:
      int x;
  public:
      MyClass(int value) : x(value) {}
      
      // Conversion constructor
      MyClass(double value) {
          x = static_cast<int>(value);
      }
      
      void display() {
          cout << "x: " << x << endl;
      }
  };
  
  int main() {
      MyClass obj1(10);      // Calls int constructor
      MyClass obj2(10.5);     // Calls double constructor (conversion constructor)
      obj1.display();
      obj2.display();
  }
  ```

- **Output**:
  ```
  x: 10
  x: 10
  ```

---

### **Summary of Constructors in C++**

| **Type of Constructor**      | **Purpose**                                                                                  | **Syntax Example**                      |
|------------------------------|----------------------------------------------------------------------------------------------|-----------------------------------------|
| **Default Constructor**       | Initializes an object with no arguments or default values.                                   | `MyClass() {}`                          |
| **Parameterized Constructor** | Initializes an object with user-provided arguments.                                           | `MyClass(int a, int b) {}`              |
| **Copy Constructor**          | Initializes an object using another object of the same class.                                | `MyClass(const MyClass& obj) {}`        |
| **Move Constructor**          | Transfers resources from a temporary object to a new object (C++11 and later).                | `MyClass(MyClass&& obj) {}`             |
| **Implicit Constructor**      | Can be called implicitly by the compiler for conversions.                                   | `MyClass(int x) {}`                     |
| **Explicit Constructor**      | Prevents implicit conversion to avoid errors or undesired behavior.                          | `explicit MyClass(int x) {}`            |
| **Conversion Constructor**    | Converts an object of one type to another.                                                   | `MyClass(double x) {}`                  |

These constructors help in creating objects, initializing data, and managing resources in C++ programs effectively.



## Destructors

In C++, a **destructor** is a special member function that is called automatically when an object of a class goes out of scope or is explicitly deleted. The purpose of a destructor is to clean up resources acquired during the object's lifetime, such as memory allocation or file handles, ensuring that no memory leaks or other issues occur.

### **Key Characteristics of Destructors:**

1. **Name:** A destructor has the same name as the class, preceded by a tilde (`~`). 
   
2. **No Return Type:** Destructors do not return any value, not even `void`.
   
3. **No Parameters:** Destructors cannot have parameters. Since they are called automatically, no arguments are needed.

4. **Automatically Called:** Destructors are called automatically when an object goes out of scope, or when `delete` is called on a dynamically allocated object.

5. **Called Once:** A destructor is called only once when the object is destroyed, either automatically or manually.

6. **Cannot Be Overloaded:** Unlike constructors, **destructors cannot be overloaded**. Each class can only have one destructor.

7. **Virtual Destructors (For Inheritance):** If you have a class hierarchy, it's important to define a **virtual destructor** in the base class to ensure proper cleanup of derived class objects when deleted via base class pointers.

---

### **Syntax of a Destructor:**

```cpp
class ClassName {
public:
    ~ClassName() {
        // Cleanup code (e.g., free memory, close file handles)
    }
};
```

### **Example:**

```cpp
#include <iostream>
using namespace std;

class MyClass {
public:
    int* ptr;

    // Constructor to allocate memory
    MyClass(int value) {
        ptr = new int;  // Dynamically allocate memory
        *ptr = value;
        cout << "Constructor: Memory allocated for ptr." << endl;
    }

    // Destructor to release memory
    ~MyClass() {
        delete ptr;  // Release the allocated memory
        cout << "Destructor: Memory released for ptr." << endl;
    }
};

int main() {
    MyClass obj(10);  // Constructor is called
    // Destructor will be automatically called when 'obj' goes out of scope
    return 0;
}
```

**Output:**
```
Constructor: Memory allocated for ptr.
Destructor: Memory released for ptr.
```

In this example:
- The constructor allocates memory dynamically for `ptr`.
- The destructor is called automatically when the object `obj` goes out of scope (at the end of the `main` function), releasing the memory using `delete`.

---

### **Virtual Destructors:**
When dealing with inheritance, it's important to declare a destructor as **virtual** in the base class if you intend to delete objects of derived classes through base class pointers. This ensures that the derived class's destructor is called, preventing memory leaks.

#### **Example with Virtual Destructor:**

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {  // Virtual destructor
        cout << "Base class destructor called." << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived class destructor called." << endl;
    }
};

int main() {
    Base* basePtr = new Derived();  // Base pointer pointing to Derived object
    delete basePtr;  // Destructor of Derived class is called first, then Base class
    return 0;
}
```

**Output:**
```
Derived class destructor called.
Base class destructor called.
```

If the destructor in the base class was **not virtual**, only the base class destructor would be called, potentially leading to resource leaks in the derived class.

---

### **Summary of Destructors:**

| **Feature**                | **Details**                                     |
|----------------------------|-------------------------------------------------|
| **Name**                   | Same as the class name, preceded by `~`         |
| **Return Type**            | None (void is not allowed)                     |
| **Parameters**             | Cannot have parameters                         |
| **Called Automatically**   | When an object goes out of scope or is deleted |
| **Usage**                  | Cleanup resources (memory, file handles, etc.) |
| **Overloading**            | Cannot be overloaded                           |
| **Virtual Destructor**     | Required for proper cleanup in inheritance     |

Destructors are essential for managing dynamic memory and resources in C++ to ensure proper cleanup and prevent memory leaks.




# Templates in CPP

In C++, **templates** are a powerful feature that allows you to define generic classes, functions, and data structures. Templates enable the writing of code that can work with any data type without knowing the type in advance. This allows for more flexible, reusable, and type-safe code.

There are two main types of templates in C++:

### 1. **Function Templates**
Function templates allow you to write a single function definition that works with any data type.

#### **Syntax of a Function Template:**
```cpp
template <typename T>
T function_name(T arg1, T arg2) {
    return arg1 + arg2;
}
```

- **`typename T`** is a placeholder for the data type.
- You can use this function with any data type by specifying the type when calling the function.

#### **Example of a Function Template:**

```cpp
#include <iostream>
using namespace std;

// Function template to add two values of any type
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(5, 3) << endl;        // Calls add<int>
    cout << add(3.5, 2.1) << endl;    // Calls add<double>
    cout << add('A', 1) << endl;      // Calls add<char>
    return 0;
}
```

**Output:**
```
8
5.6
66
```

In this example, the `add` function works with integers, doubles, and characters, without needing to write separate versions of the function for each type.

---

### 2. **Class Templates**
Class templates allow you to define a class that works with any data type.

#### **Syntax of a Class Template:**
```cpp
template <typename T>
class ClassName {
public:
    T value;
    ClassName(T v) : value(v) {}
    T getValue() {
        return value;
    }
};
```

- The **`typename T`** is the placeholder for the type used by the class.

#### **Example of a Class Template:**

```cpp
#include <iostream>
using namespace std;

// Class template to hold a value of any type
template <typename T>
class Box {
public:
    T value;
    Box(T v) : value(v) {}

    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);      // Creates an instance of Box with int type
    Box<double> doubleBox(3.14); // Creates an instance of Box with double type
    Box<string> stringBox("Hello, Templates!"); // Creates an instance of Box with string type

    cout << "Integer value: " << intBox.getValue() << endl;
    cout << "Double value: " << doubleBox.getValue() << endl;
    cout << "String value: " << stringBox.getValue() << endl;

    return 0;
}
```

**Output:**
```
Integer value: 10
Double value: 3.14
String value: Hello, Templates!
```

Here, `Box` is a template class that can store a value of any data type (`int`, `double`, `string`, etc.).

---

### 3. **Template Specialization**
Template specialization allows you to define a specific implementation for a particular data type. This is useful when the general template does not work well for certain types.

#### **Syntax of Template Specialization:**
```cpp
template <>
class ClassName<SpecificType> {
public:
    // Specialized version of the class
};
```

#### **Example of Template Specialization:**

```cpp
#include <iostream>
using namespace std;

// General template
template <typename T>
class Box {
public:
    T value;
    Box(T v) : value(v) {}
    void print() {
        cout << "General template: " << value << endl;
    }
};

// Specialization for the type 'char'
template <>
class Box<char> {
public:
    char value;
    Box(char v) : value(v) {}
    void print() {
        cout << "Specialized template for char: " << value << endl;
    }
};

int main() {
    Box<int> intBox(10);      // Calls general template
    Box<double> doubleBox(3.14); // Calls general template
    Box<char> charBox('A');   // Calls specialized template

    intBox.print();
    doubleBox.print();
    charBox.print();

    return 0;
}
```

**Output:**
```
General template: 10
General template: 3.14
Specialized template for char: A
```

In this example:
- The `Box<int>` and `Box<double>` objects use the general template.
- The `Box<char>` object uses the specialized template that is tailored for the `char` type.

---

### 4. **Template Non-Type Parameters**
Templates can also accept non-type parameters. These are parameters that are not types but values like integers or pointers.

#### **Syntax of a Template with Non-Type Parameters:**
```cpp
template <typename T, int size>
class Array {
public:
    T arr[size];
    void print() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
```

#### **Example of Template with Non-Type Parameter:**

```cpp
#include <iostream>
using namespace std;

// Template with a non-type parameter (size)
template <typename T, int size>
class Array {
public:
    T arr[size];
    void fill() {
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1;
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int, 5> intArr;  // Array of 5 integers
    intArr.fill();
    intArr.print();

    Array<double, 3> doubleArr;  // Array of 3 doubles
    doubleArr.fill();
    doubleArr.print();

    return 0;
}
```

**Output:**
```
1 2 3 4 5 
1 2 3 
```

In this example, `Array` is a template that accepts a data type (`T`) and a non-type parameter (`size`), allowing you to create arrays of different types and sizes.

---

### **Advantages of Using Templates:**
1. **Code Reusability:** Write a single function or class to handle multiple data types.
2. **Type Safety:** Templates are type-safe, meaning that type mismatches are caught at compile-time.
3. **Performance:** Templates are generally expanded at compile-time, which means that there is no performance overhead during runtime.

---

### **Summary of Templates in C++:**

- **Function Templates:** Enable writing generic functions that can work with any data type.
- **Class Templates:** Enable writing generic classes that can hold or operate on any type.
- **Template Specialization:** Allows creating specific versions of a template for particular types.
- **Non-Type Parameters:** Templates can accept constant values as parameters, like array sizes.

Templates are a key feature of C++ that make the language more powerful, flexible, and efficient, especially in creating generic libraries and data structures.
