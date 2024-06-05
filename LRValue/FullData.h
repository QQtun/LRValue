#include <iostream>
#include <utility> // for std::move

#pragma once

class FullData {
public:
    int* data;

    // Default constructor
    FullData() : data(new int(0)) {
        std::cout << "Default constructor called\n";
    }

    // Parameterized constructor
    FullData(int value) : data(new int(value)) {
        std::cout << "Parameterized constructor called\n";
    }

    // Copy constructor
    FullData(const FullData& other) : data(new int(*other.data)) {
        std::cout << "Copy constructor called\n";
    }

    // Move constructor
    FullData(FullData&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move constructor called\n";
    }

    // Copy assignment operator
    FullData& operator=(const FullData& other) {
        if (this == &other) return *this; // handle self assignment

        delete data; // clean up existing resource
        data = new int(*other.data); // copy resource
        std::cout << "Copy assignment operator called\n";
        return *this;
    }

    // Move assignment operator
    FullData& operator=(FullData&& other) noexcept {
        if (this == &other) return *this; // handle self assignment

        delete data; // clean up existing resource
        data = other.data; // take ownership of other's resource
        other.data = nullptr; // leave other in a valid state
        std::cout << "Move assignment operator called\n";
        return *this;
    }

    // Destructor
    ~FullData() {
        delete data;
        std::cout << "Destructor called\n";
    }
};