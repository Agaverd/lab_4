#pragma once
#include <cstddef>
#include <memory>
#include <stdexcept>

template<class T>
class ArrayT {
public:
    ArrayT() = default;
    ArrayT(const ArrayT&);

    ArrayT(const std::ptrdiff_t size);

    ~ArrayT() = default;

private:

};
