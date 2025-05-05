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

	//getters
    [[nodiscard]] std::ptrdiff_t Size() const noexcept {return size_;} 
    [[nodiscard]] std::ptrdiff_t Capacity() const noexcept { return capacity_; }
    [[nodiscard]] std::ptrdiff_t IsEmpty() const noexcept { return size_ == 0 }

	//accessors
    [[nodiscard]] T& operator[](const std::ptrdiff_t idx);
    [[nodiscard]] const T& operator[](const std::ptrdiff_t idx) const;

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t size_ = 0;
    std::unique_ptr<T[]> data
};
