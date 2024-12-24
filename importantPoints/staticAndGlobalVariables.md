# Static and Global Variables
In C++, **static** and **global** variables are special types of variables that have specific properties regarding their **lifetime** and **scope**. Let’s dive deeper into each:

---

### **1. Global Variables**
A **global variable** is a variable that is declared outside of all functions or classes. 

#### **Key Characteristics**:
- **Scope**: Accessible throughout the program, in all functions or files (if `extern` is used in multiple files).
- **Lifetime**: Exists for the entire duration of the program (created when the program starts and destroyed when it ends).
- **Storage**: Stored in the **data segment** of memory (initialized or uninitialized sections).
- **Default Value**: Automatically initialized to `0` (for integers) or `nullptr` (for pointers) if not explicitly initialized.

#### **Example**:
```cpp
#include <iostream>

int globalVar = 42; // Global variable

void displayGlobal() {
    std::cout << "Global Variable: " << globalVar << std::endl;
}

int main() {
    displayGlobal();
    globalVar += 10; // Modify global variable
    displayGlobal();
    return 0;
}
```

#### **Output**:
```
Global Variable: 42
Global Variable: 52
```

---

### **2. Static Variables**
A **static variable** is a variable that retains its value across multiple function calls or program executions.

#### **Key Characteristics**:
- **Scope**:
  - If declared inside a function, its scope is **local** to that function.
  - If declared outside any function, it behaves like a **global variable** but is only accessible within the file (file-level scope).
- **Lifetime**: Exists for the entire program duration, even if declared in a function.
- **Storage**: Stored in the **data segment** of memory.
- **Default Value**: Automatically initialized to `0` if not explicitly initialized.
- **Keyword**: Declared using the `static` keyword.

#### **Static in Functions (Preserves State)**:
```cpp
#include <iostream>

void counter() {
    static int count = 0; // Static variable
    count++;
    std::cout << "Count: " << count << std::endl;
}

int main() {
    counter(); // Count: 1
    counter(); // Count: 2
    counter(); // Count: 3
    return 0;
}
```

#### **Static Outside Functions (File Scope)**:
```cpp
#include <iostream>

// File-level static variable
static int fileStaticVar = 100;

void showStatic() {
    std::cout << "File Static Variable: " << fileStaticVar << std::endl;
}

int main() {
    showStatic(); // File Static Variable: 100
    return 0;
}
```

---

### **Key Differences Between Global and Static Variables**:

| **Feature**           | **Global Variable**                     | **Static Variable**                                 |
|------------------------|------------------------------------------|----------------------------------------------------|
| **Scope**             | Accessible throughout the program        | - Inside a function: Local to the function         |
|                        |                                          | - Outside functions: Local to the file             |
| **Lifetime**          | Exists for the entire program duration   | Exists for the entire program duration             |
| **Initialization**    | Default value: `0` or `nullptr`          | Default value: `0` or `nullptr`                   |
| **Storage**           | Data segment                             | Data segment                                       |
| **Keyword**           | No special keyword required              | Declared using the `static` keyword               |

---

### **When to Use**:
- **Global Variables**:
  - Use when a variable needs to be shared across multiple functions or files.
  - Avoid overusing, as they can lead to code that is difficult to debug and maintain.
  
- **Static Variables**:
  - Use when you need to preserve a variable's state across multiple function calls.
  - Use static file-level variables to restrict access to variables in the current file only (for encapsulation).