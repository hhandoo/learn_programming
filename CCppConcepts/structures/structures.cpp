#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    struct department {
        char name[10];
        char desc[50];
    }; // total mem in main functions stack frame: 60 bytes

    struct employee {
        int id;
        char employeeName[10];
        char gender[5];
        struct department dept;
    };

    // distribute 4 employees in 2 departments

    // Create departments
    department d1 = {"HR", "Handles recruitment and employee welfare"};
    department d2 = {"IT", "Maintains IT infrastructure"};

    struct employee emp[4] = {
        {1, "Alice", "F", d1},
        {2, "Bob", "M", d1},
        {3, "Charlie", "M", d2},
        {4, "Diana", "F", d2}
    };


    // Display employee details
    for (int i = 0; i < 4; i++) {
        cout << "Employee ID: " << emp[i].id << endl;
        cout << "Name: " << emp[i].employeeName << endl;
        cout << "Gender: " << emp[i].gender << endl;
        cout << "Department: " << emp[i].dept.name << endl;
        cout << "Description: " << emp[i].dept.desc << endl;
        cout << "-----------------------------" << endl;
    }
    return 0;
}