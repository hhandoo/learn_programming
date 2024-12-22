#include<stdio.h>

int main(){
    // integers
    int a = -122;
    printf("%d\n", a);
    printf("%i\n", a);

    // float
    float b = 1.22;
    printf("%.4f\n", b);

    // char
    char c = 'a';
    printf("%c\n", c);

    // string
    // a string is an array of characters terminated by a special character called the null character ('\0')
    // Strings are arrays of characters, so you can manipulate them using array indexing.

    char d[] = "hello";
    printf("%s\n", d);

    // unsigned integer
    int e = 122;
    printf("%u\n", e);


    // octal number
    int f = 012;  // Octal 12 (Decimal 10)
    printf("Octal: %o, Decimal: %d\n", f, f);

    // hexa
    int g = 0x1A;  // Hexadecimal 1A (Decimal 26)
    printf("Hexadecimal: %x, Decimal: %d\n", g, g);

    // pointer
    int *h = &a;
    printf("Address of a: %p\n", &a);  // Print the address of 'num'
    printf("Address stored in h: %p\n", h);  // Print the value of the pointer
    printf("Value at ptr: %d\n", *h);    // Dereference the pointer


    // G
    float i = 12345.32;
    printf("%G\n", i);
    return 0;
}