#pragma once
#include <cstddef>
#include <memory>
#include <stdexcept>

template<class T>
class ArrayT {
public:
    ArrayT() = default;

    ~ArrayT() = default;

    ArrayT(const ArrayT&);

    ArrayT(const std::ptrdiff_t size);

    [[nodiscard]] std::ptrdiff_t Size() const noexcept {return size_;} 
    [[nodiscard]] std::ptrdiff_t Capacity() const noexcept { return capacity_; }

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t size_ = 0;
    std::unique_ptr<T[]> data
};
