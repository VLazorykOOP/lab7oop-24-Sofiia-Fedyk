#include "array.h"
#include "binary_tree.h"
#include "quicksort.h"
#include "search-array.h"
#include <iostream>
#include <string>
#include <iomanip>

// Forward declarations for test functions
void testIntArrayMain();
void testDoubleArrayMain();
void testCharArrayMain();
void testErrorHandlingMain();
void testQuickSortIntegers();
void testQuickSortDoubles();
void testQuickSortStrings();
void testSearchIntegers();
void testSearchStrings();
void runQuickSortTests();
void runSearchTests();

// Function to print a separator line
void printSeparator(const std::string& title = "") {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    if (!title.empty()) {
        std::cout << "  " << title << std::endl;
        std::cout << std::string(60, '=') << std::endl;
    }
}

// Array template tests
void testIntArrayMain() {
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

void testDoubleArrayMain() {
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

void testCharArrayMain() {
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

void testErrorHandlingMain() {
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

// QuickSort tests
void testQuickSortIntegers() {
    std::cout << "\n=== Testing QuickSort with Integers ===\n" << std::endl;
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    quickSort(arr, 0, size - 1);
    
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void testQuickSortDoubles() {
    std::cout << "\n=== Testing QuickSort with Doubles ===\n" << std::endl;
    
    double arr[] = {3.14, 2.71, 1.41, 1.73, 2.23, 0.57, 4.47};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << std::fixed << std::setprecision(2) << arr[i] << " ";
    }
    std::cout << std::endl;
    
    quickSort(arr, 0, size - 1);
    
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << std::fixed << std::setprecision(2) << arr[i] << " ";
    }
    std::cout << std::endl;
}

void testQuickSortStrings() {
    std::cout << "\n=== Testing QuickSort with Strings ===\n" << std::endl;
    
    char* arr[] = {
        const_cast<char*>("banana"),
        const_cast<char*>("apple"),
        const_cast<char*>("cherry"),
        const_cast<char*>("date"),
        const_cast<char*>("elderberry"),
        const_cast<char*>("fig")
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    quickSort(arr, 0, size - 1);
    
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Search tests
void testSearchIntegers() {
    std::cout << "\n=== Testing Search with Integers ===\n" << std::endl;
    
    int arr[] = {5, 2, 8, 2, 9, 1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Test finding last occurrence of different values
    int searchKeys[] = {2, 9, 7, 1};
    int numKeys = sizeof(searchKeys) / sizeof(searchKeys[0]);
    
    for (int i = 0; i < numKeys; i++) {
        int result = findLastOccurrenceMain(arr, size, searchKeys[i]);
        printSearchResultMain(result, searchKeys[i]);
    }
}

void testSearchStrings() {
    std::cout << "\n=== Testing Search with Strings ===\n" << std::endl;
    
    char* arr[] = {
        const_cast<char*>("apple"),
        const_cast<char*>("banana"),
        const_cast<char*>("apple"),
        const_cast<char*>("cherry"),
        const_cast<char*>("banana"),
        const_cast<char*>("date")
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Test finding last occurrence of different strings
    char* searchKeys[] = {
        const_cast<char*>("apple"),
        const_cast<char*>("banana"),
        const_cast<char*>("grape"),
        const_cast<char*>("cherry")
    };
    int numKeys = sizeof(searchKeys) / sizeof(searchKeys[0]);
    
    for (int i = 0; i < numKeys; i++) {
        int result = findLastOccurrenceMain(arr, size, searchKeys[i]);
        printSearchResultMain(result, searchKeys[i]);
    }
}

int main() {
    try {
        // Test Search 
        printSeparator("SEARCH ALGORITHM TESTS");
        testSearchIntegers();
        testSearchStrings();

        // Test QuickSort
        printSeparator("QUICKSORT ALGORITHM TESTS");
        testQuickSortIntegers();
        testQuickSortDoubles();
        testQuickSortStrings();
        
        // Test Array template class
        printSeparator("ARRAY TEMPLATE CLASS TESTS");
        testIntArrayMain();
        testDoubleArrayMain();
        testCharArrayMain();
        testErrorHandlingMain();
        
        // Test Binary Tree
        printSeparator("BINARY TREE TESTS");
        runAllTests();  // From binary_tree.h
        std::cout << "\n";
        runAllExamples();  // From binary_tree.cpp - Uncommented this line


        printSeparator("ALL TESTS COMPLETED SUCCESSFULLY");
        std::cout << "Program executed without critical errors!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "\nUnexpected error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "\nUnknown error occurred!" << std::endl;
        return 1;
    }

    return 0;
}