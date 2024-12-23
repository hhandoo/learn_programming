| Feature              | Pointer                                                | Reference                                                |
|----------------------|-------------------------------------------------------|---------------------------------------------------------|
| **Definition**        | Holds the memory address of another variable.         | Acts as an alias for an existing variable.              |
| **Declaration**       | Requires `*` for declaration (e.g., `int *p = &a;`).  | Requires `&` for declaration (e.g., `int &ref = a;`).   |
| **Initialization**    | Can be uninitialized or null.                         | Must be initialized during declaration.                |
| **Reassignment**      | Can be reassigned to point to another variable.       | Cannot be reassigned to another variable.              |
| **Nullability**       | Can be null (`nullptr`) or uninitialized.             | Cannot be null or uninitialized.                       |
| **Dereferencing**     | Requires `*` operator to access the value.            | Automatically dereferences, no operator required.       |
| **Address Access**    | Requires `&` operator to get the address of a variable.| Not needed; directly references the variable.          |
| **Arithmetic**        | Supports pointer arithmetic (e.g., `p + 1`).          | Arithmetic operations are not allowed.                 |
| **Dynamic Memory**    | Used for dynamic memory allocation (`new`, `delete`). | Cannot manage dynamic memory directly.                 |
| **Memory Access**     | Can point to arrays, use arithmetic for iteration.    | Always tied to the specific variable it aliases.        |
| **Use Cases**         | Dynamic memory, data structures, function pointers.   | Passing variables to functions, simplifying syntax.     |
