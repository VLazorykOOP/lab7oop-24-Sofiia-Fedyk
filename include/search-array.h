#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <cstring>

// Template declaration for findLastOccurrence
template <typename T>
int findLastOccurrenceMain(const T arr[], int size, const T& key) {
    // Start from the end of the array
    for (int i = size - 1; i >= 0; i--) {
        // If the current element equals the key, return its index
        if (arr[i] == key) {
            return i;
        }
    }
    
    // If no element equals the key, return -1
    return -1;
}

// Specialization for char* arrays (string arrays)
template <>
int findLastOccurrenceMain<char*>(char* const arr[], int size, char* const& key) {
    // Start from the end of the array
    for (int i = size - 1; i >= 0; i--) {
        // Use strcmp to compare strings
        if (arr[i] != nullptr && key != nullptr && strcmp(arr[i], key) == 0) {
            return i;
        }
        // Handle null strings (if both are null, consider them equal)
        else if (arr[i] == nullptr && key == nullptr) {
            return i;
        }
    }
    
    // If no string equals the key, return -1
    return -1;
}

// Template declaration for printSearchResult
template <typename T>
void printSearchResultMain(int index, const T& key) {
    if (index != -1) {
        std::cout << "Key '" << key << "' found at index: " << index << std::endl;
    } else {
        std::cout << "Key '" << key << "' not found in the array." << std::endl;
    }
}

// Specialization for char* printing
template <>
void printSearchResultMain<char*>(int index, char* const& key) {
    if (index != -1) {
        std::cout << "String \"" << (key ? key : "NULL") << "\" found at index: " << index << std::endl;
    } else {
        std::cout << "String \"" << (key ? key : "NULL") << "\" not found in the array." << std::endl;
    }
}

#endif // SEARCH_H