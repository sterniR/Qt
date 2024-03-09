#include <iostream>

int main()
{
    int value1 = 1;                     //non-const value
    const int value2 = 2;               //const     value
    int value3 = 3;                     //non-const value
    const int value4 = 4;               //const     value

    int *ptr1 = &value1;                //pointer und referenz kann man verändern.
    const int *ptr2 = &value2;          //pointer aber NICHT DIE REFERENZ darf man verändern.
    int *const ptr3 = &value3;          //referenz aber NICHT DEN POINTER darf man verändern.
    const int *const ptr4 = &value4;    //referenz und pointer darf man NICHT verändern.

    *ptr1 = 777;

    //*ptr2 = 777; main.cpp:22:11: Read-only variable is not assignable

    *ptr3 = 777;

    //*ptr4 = 777; main.cpp:22:11: Read-only variable is not assignable

    std::cout << "Value (*ptr): " << *ptr1 << '\n' << "Adresse (ptr): " << ptr1 << '\n';
    std::cout << '\n';
    std::cout << "Value (*ptr): " << *ptr2 << '\n' << "Adresse (ptr): " << ptr2 << '\n';
    std::cout << '\n';
    std::cout << "Value (*ptr): " << *ptr3 << '\n' << "Adresse (ptr): " << ptr3 << '\n';
    std::cout << '\n';
    std::cout << "Value (*ptr): " << *ptr4 << '\n' << "Adresse (ptr): " << ptr4 << '\n';}


/*
    1. int value = 5;         // non-const value

    2. const int *ptr_1 = &value;      // ptr_1 points to a “const int” value, so this is a pointer to a const value.

    3. int *const ptr_2 = &value;        // ptr_2 points to an “int”, so this is a const pointer to a non-const value.

    4. const int *const ptr_3 = &value;   // ptr_3 points to a “const int” value, so this is a const pointer to a const value.
*/
