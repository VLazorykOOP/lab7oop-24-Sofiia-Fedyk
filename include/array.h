#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* data;          // Pointer to dynamic array
    size_t size;      // Current size of array

public:
    // Default constructor
    Array() : data(nullptr), size(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // Constructor with size parameter
    explicit Array(size_t size) : size(size) {
        std::cout << "Parameterized constructor called" << std::endl;
        if (size > 0) {
            data = new T[size]();  // Allocate memory and initialize with default values
        } else {
            data = nullptr;
        }
    }

    // Copy constructor
    Array(const Array& other) : size(other.size) {
        std::cout << "Copy constructor called" << std::endl;
        if (size > 0) {
            data = new T[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    // Destructor
    ~Array() {
        std::cout << "Destructor called" << std::endl;
        delete[] data;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        std::cout << "Assignment operator called" << std::endl;
        if (this != &other) {
            // Free existing resources
            delete[] data;
            
            // Copy from other
            size = other.size;
            if (size > 0) {
                data = new T[size];
                for (size_t i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Addition operator
    Array operator+(const Array& other) const {
        std::cout << "Addition operator called" << std::endl;
        // Ensure arrays have the same size
        if (size != other.size) {
            throw std::runtime_error("Cannot add arrays of different sizes");
        }

        Array result(size);
        for (size_t i = 0; i < size; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Addition assignment operator
    Array& operator+=(const Array& other) {
        std::cout << "Addition assignment operator called" << std::endl;
        // Ensure arrays have the same size
        if (size != other.size) {
            throw std::runtime_error("Cannot add arrays of different sizes");
        }

        for (size_t i = 0; i < size; i++) {
            data[i] += other.data[i];
        }
        return *this;
    }

    // Subtraction operator
    Array operator-(const Array& other) const {
        std::cout << "Subtraction operator called" << std::endl;
        // Ensure arrays have the same size
        if (size != other.size) {
            throw std::runtime_error("Cannot subtract arrays of different sizes");
        }

        Array result(size);
        for (size_t i = 0; i < size; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Subtraction assignment operator
    Array& operator-=(const Array& other) {
        std::cout << "Subtraction assignment operator called" << std::endl;
        // Ensure arrays have the same size
        if (size != other.size) {
            throw std::runtime_error("Cannot subtract arrays of different sizes");
        }

        for (size_t i = 0; i < size; i++) {
            data[i] -= other.data[i];
        }
        return *this;
    }

    // Subscript operator (read/write)
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Array index out of range");
        }
        return data[index];
    }

    // Subscript operator (read-only)
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Array index out of range");
        }
        return data[index];
    }

    // Get size of array
    size_t getSize() const {
        return size;
    }

    // Display array elements
    void display() const {
        std::cout << "Array contents: ";
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // ARRAY_H