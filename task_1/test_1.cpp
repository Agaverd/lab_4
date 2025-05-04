#include "MyVector.hpp"
#include <chrono>
#include <iostream>

template<typename function>
double measureTime(function f) {

    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> diff = end - start;
    return diff.count();
}

int main() {
    const size_t BIG_NUM = 9999999;

    double copyTime = measureTime([&]() {
        MyVector original(BIG_NUM);
        MyVector copy = original;
    });

    std::cout << "Copy constructor: " << copyTime << std::endl;

    double moveTime = measureTime([&]() {
        MyVector original(BIG_NUM);
        MyVector move = std::move(original);
    });

    std::cout << "Move constructor: " << moveTime << std::endl;

    double copyAssignTime = measureTime([&]() {
        MyVector original(BIG_NUM);
        MyVector copyAssigned;
        copyAssigned = original;
    });

    std::cout << "Copy assignment: " << copyAssignTime << std::endl;

    double moveAssignTime = measureTime([&]() {
        MyVector original(BIG_NUM);
        MyVector moveAssigned;
        moveAssigned = std::move(original);
    });

    std::cout << "Move assignment: " << moveAssignTime << std::endl;

    return 0;
}