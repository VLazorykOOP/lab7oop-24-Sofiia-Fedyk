#include "array.h"

// Test function to demonstrate integer array operations
void testIntArray() {
    std::cout << "\n=== Testing Integer Array ===\n" << std::endl;
    
    // Create an array of integers
    Array<int> arr1(5);
    for (size_t i = 0; i < arr1.getSize(); i++) {
        arr1[i] = i + 1;  // Set values 1, 2, 3, 4, 5
    }
    std::cout << "arr1: ";
    arr1.display();

    // Copy constructor
    Array<int> arr2 = arr1;
    std::cout << "arr2 (copied from arr1): ";
    arr2.display();

    // Assignment operator
    Array<int> arr3(3);
    arr3 = arr1;
    std::cout << "arr3 (assigned from arr1): ";
    arr3.display();

    // Addition operator
    Array<int> arr4 = arr1 + arr2;
    std::cout << "arr4 (arr1 + arr2): ";
    arr4.display();

    // Addition assignment operator
    arr1 += arr2;
    std::cout << "arr1 after arr1 += arr2: ";
    arr1.display();

    // Subtraction operator
    Array<int> arr5 = arr1 - arr3;
    std::cout << "arr5 (arr1 - arr3): ";
    arr5.display();

    // Subtraction assignment operator
    arr4 -= arr3;
    std::cout << "arr4 after arr4 -= arr3: ";
    arr4.display();
}

// Test function to demonstrate double array operations
void testDoubleArray() {
    std::cout << "\n=== Testing Double Array ===\n" << std::endl;
    
    // Create an array of doubles
    Array<double> dArr1(4);
    for (size_t i = 0; i < dArr1.getSize(); i++) {
        dArr1[i] = (i + 1) * 1.5;  // Set values 1.5, 3.0, 4.5, 6.0
    }
    std::cout << "dArr1: ";
    dArr1.display();
    
    // Copy constructor
    Array<double> dArr2 = dArr1;
    std::cout << "dArr2 (copied from dArr1): ";
    dArr2.display();
    
    // Addition operator
    Array<double> dArr3 = dArr1 + dArr2;
    std::cout << "dArr3 (dArr1 + dArr2): ";
    dArr3.display();
    
    // Subtraction assignment operator
    dArr3 -= dArr1;
    std::cout << "dArr3 after dArr3 -= dArr1: ";
    dArr3.display();
}

// Test function to demonstrate char array operations
void testCharArray() {
    std::cout << "\n=== Testing Char Array ===\n" << std::endl;
    
    // Create an array of characters
    Array<char> cArr1(5);
    cArr1[0] = 'H';
    cArr1[1] = 'e';
    cArr1[2] = 'l';
    cArr1[3] = 'l';
    cArr1[4] = 'o';
    std::cout << "cArr1: ";
    cArr1.display();
    
    // Assignment operator
    Array<char> cArr2(5);
    cArr2 = cArr1;
    std::cout << "cArr2 (assigned from cArr1): ";
    cArr2.display();
    
    // Attempt to access out of bounds (will throw exception)
    try {
        std::cout << "Attempting to access out of bounds element..." << std::endl;
        char c = cArr1[10]; // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

// Test function to demonstrate error handling
void testErrorHandling() {
    std::cout << "\n=== Testing Error Handling ===\n" << std::endl;
    
    Array<int> arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    std::cout << "arr1: ";
    arr1.display();
    
    Array<int> arr2(2);
    arr2[0] = 10;
    arr2[1] = 20;
    std::cout << "arr2: ";
    arr2.display();
    
    try {
        std::cout << "Attempting to add arrays of different sizes..." << std::endl;
        Array<int> arr3 = arr1 + arr2; // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}