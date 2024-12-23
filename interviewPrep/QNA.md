### Basic C/C++ Interview Questions with Answers

---

#### **General Concepts**
1. **What is the difference between C and C++?**  
   - **C** is a procedural programming language, whereas **C++** is an object-oriented programming language that supports OOP features like classes, objects, inheritance, and polymorphism.

2. **What are the main features of object-oriented programming in C++?**  
   - Encapsulation, Inheritance, Polymorphism, Abstraction.

3. **Explain the concept of a compiler and an interpreter. How are they different?**  
   - A **compiler** translates the entire source code into machine code before execution.  
   - An **interpreter** translates code line-by-line during execution.  

4. **What is the use of a preprocessor directive? Give examples.**  
   - Preprocessor directives are instructions that are processed before compilation, e.g., `#include`, `#define`.

5. **What is the difference between a `macro` and a `const` in C/C++?**  
   - A **macro** is a preprocessor directive and is replaced during preprocessing (`#define PI 3.14`).  
   - A **const** variable is type-checked and part of the compiled code (`const float PI = 3.14;`).

6. **What are header files, and why are they used?**  
   - Header files (`*.h`) contain declarations of functions and macros, allowing code reuse, e.g., `#include <iostream>`.

---

#### **Data Types and Variables**
7. **What are the different types of data types in C/C++?**  
   - Primitive (`int`, `char`, `float`, `double`), Derived (`array`, `pointer`), and User-defined (`struct`, `class`).

8. **Explain the difference between `int`, `short`, `long`, and `long long`.**  
   - These differ in size and range:
     - `int`: Typically 4 bytes.
     - `short`: At least 2 bytes.
     - `long`: At least 4 bytes, larger range than `int`.
     - `long long`: At least 8 bytes.

9. **What is the scope of a variable in C/C++?**  
   - Scope defines where a variable can be accessed.  
     - **Global**: Accessible throughout the program.  
     - **Local**: Accessible only within the block/function.

10. **What is the difference between a `static` and `extern` variable?**  
    - **Static**: Retains value between function calls, limited scope.  
    - **Extern**: Declares a global variable in another file.

11. **How is a `volatile` variable different from a normal variable?**  
    - A `volatile` variable tells the compiler not to optimize it as its value can change outside the program (e.g., by hardware).

---

#### **Control Structures**
12. **What is the difference between `if` and `switch` statements?**  
    - **`if`** evaluates conditions and can handle ranges or complex expressions.  
    - **`switch`** checks a variable against fixed values (case labels).

13. **How does a `while` loop differ from a `do-while` loop?**  
    - **`while`** checks the condition before executing.  
    - **`do-while`** executes the block at least once before checking the condition.

14. **What is a nested loop? Provide an example.**  
    - A loop inside another loop.  
    ```cpp
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << i << ", " << j << endl;
        }
    }
    ```

15. **Explain the use of the `break` and `continue` statements in loops.**  
    - `break`: Exits the loop prematurely.  
    - `continue`: Skips the current iteration and moves to the next.

---

#### **Functions**
16. **What are the different ways to pass arguments to a function in C++?**  
    - **By Value**: Passes a copy of the variable.  
    - **By Reference**: Passes the actual variable.  
    - **By Pointer**: Passes the address of the variable.

17. **What is the difference between a function declaration and a function definition?**  
    - **Declaration**: Specifies the function signature (prototype).  
    - **Definition**: Includes the function body.

18. **Explain recursion with an example.**  
    - A function calling itself.  
    ```cpp
    int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
    ```

19. **What is a friend function, and how is it used in C++?**  
    - A friend function has access to the private and protected members of a class.  
    ```cpp
    class MyClass {
        private:
            int data;
        public:
            MyClass(int val) : data(val) {}
            friend void showData(MyClass obj);
    };
    void showData(MyClass obj) {
        cout << obj.data;
    }
    ```

20. **Can you overload a function in C++? How does it work?**  
    - Yes, functions with the same name but different parameter lists (type/number) can coexist.  
    ```cpp
    void print(int x) { cout << x; }
    void print(string s) { cout << s; }
    ```

---

#### **Pointers and References**
21. **What is a pointer? How is it different from a reference?**  
    - A pointer stores the address of a variable.  
    - A reference is an alias for an existing variable.  
    - Pointers can be reassigned; references cannot.

22. **Explain the concept of pointer arithmetic.**  
    - Operations like `p++` move the pointer to the next memory location based on the data type size.

23. **What is a dangling pointer? How can it be avoided?**  
    - A dangling pointer points to a memory location that has been deallocated. Avoid by setting it to `nullptr` after deletion.

24. **What is a null pointer? How is it different from a dangling pointer?**  
    - A null pointer explicitly points to `nullptr` (nothing).  
    - A dangling pointer points to invalid or freed memory.