#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array *arr)
{
    cout << "[";
    for (int i = 0; i < arr->size; i++)
    {

        if (i == arr->size - 1)
        {
            cout << arr->A[i];
        }
        else
        {
            cout << arr->A[i] << ", ";
        }
    }

    cout << "]" << endl;

    cout << "Size: " << arr->size << " Length: " << arr->length << endl;
}

void insert(int elem, int index, struct Array *arr)
{
    cout << "Insert Operation: ";
    if ((index >= arr->size) || (index >= arr->length))
    {
        cout << "Operation Not Possible" << endl;
    }
    else
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = elem;
        arr->length++;
        cout << "Successful!!!" << endl;

        Display(arr);
    }
}

void deleteElem(int index, struct Array *arr)
{

    cout << "Delete Operation: ";
    if ((index >= arr->size) || (index >= arr->length))
    {
        cout << "Operation Not Possible" << endl;
    }
    else
    {
        for (int i = index; i <= arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        cout << "Successful!!!" << endl;
    }

    Display(arr);
}

int main()
{
    struct Array arr;

    cout << "Enter size of an array : ";
    cin >> arr.size;

    cout << "Enter length of elemets: ";
    cin >> arr.length;

    arr.A = (int *)malloc(arr.size * sizeof(int));
    cout << "Enter  elements: " << endl;

    for (int i = 0; i < arr.length; i++)
    {
        cin >> arr.A[i];
    }

    Display(&arr);

    insert(233, 2, &arr);

    deleteElem(2, &arr);
    deleteElem(2, &arr);

    return 0;
}