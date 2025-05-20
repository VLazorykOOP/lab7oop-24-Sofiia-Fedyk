// quicksort.cpp
#include "quicksort.h"
#include <cstring>
#include <iostream>
#include <algorithm>  // For std::swap

/**
 * @brief Implementation of partition function for quicksort
 * 
 * This function takes the last element as pivot, places the pivot at its correct
 * position in the sorted array, and places all smaller elements to the left of
 * the pivot and all greater elements to the right of the pivot.
 */
template <typename T>
int partition(T arr[], int low, int high) {
    // Pivot is the last element
    T pivot = arr[high];
    
    // Index of smaller element
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;    // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * @brief Implementation of quicksort algorithm
 * 
 * This is the main function that implements quicksort.
 */
template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);
        
        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * @brief Specialization of partition function for char* type
 * 
 * Uses strcmp to compare strings instead of the < operator
 */
template <>
int partition<char*>(char* arr[], int low, int high) {
    // Pivot is the last element
    char* pivot = arr[high];
    
    // Index of smaller element
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot using strcmp
        if (arr[j] != nullptr && pivot != nullptr && strcmp(arr[j], pivot) < 0) {
            i++;    // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
        // Handle null strings (considered smaller than non-null)
        else if (arr[j] == nullptr && pivot != nullptr) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * @brief Specialization of quicksort function for char* type
 * 
 * This is identical to the generic version but calls the specialized partition
 * function which handles string comparisons correctly.
 */
template <>
void quickSort<char*>(char* arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition<char*>(arr, low, high);
        
        // Separately sort elements before and after partition
        quickSort<char*>(arr, low, pi - 1);
        quickSort<char*>(arr, pi + 1, high);
    }
}

// Explicit instantiation of the template for common types
template int partition<int>(int[], int, int);
template void quickSort<int>(int[], int, int);

template int partition<double>(double[], int, int);
template void quickSort<double>(double[], int, int);

template int partition<char>(char[], int, int);
template void quickSort<char>(char[], int, int);