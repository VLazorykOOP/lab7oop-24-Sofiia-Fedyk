#ifndef QUICKSORT_H
#define QUICKSORT_H

/**
 * @brief Template function for quick sort algorithm
 * 
 * @tparam T Type of array elements
 * @param arr Array to be sorted
 * @param low Starting index of the array (usually 0)
 * @param high Ending index of the array (usually size-1)
 */
template <typename T>
void quickSort(T arr[], int low, int high);

/**
 * @brief Helper function to partition the array for quicksort
 * 
 * @tparam T Type of array elements
 * @param arr Array to be partitioned
 * @param low Starting index of the partition
 * @param high Ending index of the partition
 * @return int The partition index
 */
template <typename T>
int partition(T arr[], int low, int high);

/**
 * @brief Specialization of quickSort function for char* type
 * 
 * @param arr Array of strings to be sorted
 * @param low Starting index of the array
 * @param high Ending index of the array
 */
template <>
void quickSort<char*>(char* arr[], int low, int high);

/**
 * @brief Specialization of partition function for char* type
 * 
 * @param arr Array of strings to be partitioned
 * @param low Starting index of the partition
 * @param high Ending index of the partition
 * @return int The partition index
 */
template <>
int partition<char*>(char* arr[], int low, int high);

#endif // QUICKSORT_H