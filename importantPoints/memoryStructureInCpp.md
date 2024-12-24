# Memory Structure


The **memory structure** of a program in a system is divided into several distinct segments, each serving a specific purpose. Here’s a detailed breakdown of the typical memory layout:

## Code Segment (Text Segment) 
**Purpose**: Stores the program's compiled machine code (instructions).  
- **Characteristics**:
  - Read-only to prevent accidental overwriting of program instructions.
  - Shared among processes running the same program to save memory.
- **Content**:
  - Function definitions.
  - Executable statements of the program.

## Data Segment 
**Purpose**: Stores global and static variables. This is further divided into two sections:  
- **Initialized Data Segment**:
  - Stores initialized global and static variables (e.g., `int x = 10;`).
  - Retains values across the program's lifetime.
- **BSS Segment (Block Started by Symbol)**:
  - Stores uninitialized global and static variables (e.g., `int y;`).
  - Variables here are automatically initialized to `0`.

## Stack
**Purpose**: Used for **local variables** and **function call management**.  
- **Characteristics**:
  - Grows downward (toward lower memory addresses).
  - Automatically managed by the compiler.
  - Stores:
    - Local variables.
    - Function parameters.
    - Return addresses.
    - Stack frames for each function call.
- **Lifetime**:
  - Variables in the stack exist only during the function's execution.
  - Deallocated automatically when the function ends.

## Heap
**Purpose**: Used for **dynamic memory allocation** (`malloc`, `new`).  
- **Characteristics**:
  - Grows upward (toward higher memory addresses).
  - Memory must be explicitly allocated and deallocated by the programmer.
  - Suitable for data that needs to persist beyond the lifetime of a function.
- **Potential Issues**:
  - Memory leaks (if not deallocated properly).
  - Fragmentation.

## Reserved and Other Segments
- **Command-Line Arguments and Environment Variables**:
  - Stored in a separate segment in memory, typically above the stack.
- **Kernel Space**:
  - Reserved for the operating system's use.


## Memory Layout Visualization
```plaintext
+---------------------------+ Higher Memory Addresses
| Kernel Space              | Reserved for OS
+---------------------------+
| Stack                     | Function calls and local variables
| (grows downward)          |
+---------------------------+
| Heap                      | Dynamically allocated memory
| (grows upward)            |
+---------------------------+
| BSS Segment               | Uninitialized global/static variables
+---------------------------+
| Initialized Data Segment  | Initialized global/static variables
+---------------------------+
| Code Segment (Text)       | Program instructions
+---------------------------+ Lower Memory Addresses
```

### **Examples for Each Segment**

#### **Code Segment**
```cpp
int globalVar; // Stored in BSS
int globalInitializedVar = 42; // Initialized data segment

void func() {
    static int staticVar = 10; // Initialized data segment
    int localVar = 5; // Stored in stack
    int* ptr = new int(20); // Dynamically allocated, stored in heap
}
```

#### **Stack**
- `localVar` is allocated on the stack.
- Stack frames are created for each function call, holding:
  - Local variables.
  - Return address.
  - Function parameters.

#### **Heap**
```cpp
int* arr = new int[10]; // Dynamically allocated array
```
- The array is stored in the heap, and the pointer `arr` is stored in the stack.

### **Dynamic Memory (Heap) Example**
```cpp
#include <iostream>

void dynamicMemoryExample() {
    int* ptr = new int(10); // Allocate memory in the heap
    std::cout << "Value: " << *ptr << std::endl;
    delete ptr; // Deallocate memory to avoid memory leaks
}

int main() {
    dynamicMemoryExample();
    return 0;
}
```

## Key Concepts
1. **Memory Segments Are Managed Separately**:
   - **Code Segment** is loaded once when the program starts.
   - **Data Segment** is pre-allocated based on global/static variable needs.
   - **Stack** and **Heap** grow dynamically during runtime.

2. **Segmentation Fault**:
   - Occurs when the program accesses a restricted or non-existent memory segment.

3. **Optimization and Debugging**:
   - Use tools like `valgrind` to detect memory leaks in the heap.
   - Stack overflow errors occur if the stack exceeds its allocated size (e.g., infinite recursion).

This detailed structure provides a comprehensive understanding of how memory is organized for program execution, enabling efficient use and debugging of resources.