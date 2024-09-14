#include <iostream>

int main()
{
    // Dynamically allocate memory for an integer
    int *ptr = new int(10); // ptr points to a dynamically allocated memory on the heap

    std::cout << "Value before delete: " << *ptr << std::endl;

    // Deallocate the memory (but ptr still holds the address)
    delete ptr;

    // ptr is now a dangling pointer because the memory has been freed
    // Dereferencing it will lead to undefined behavior
    std::cout << "Value after delete (dangling pointer): " << *ptr << std::endl; // Dangling pointer access

    return 0;
}
