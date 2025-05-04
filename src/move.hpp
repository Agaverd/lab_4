#include <iostream>
#include <algorithm> 
#include <utility>   

class MyVector {
private:
    int* data;
    size_t size;

public:

    MyVector(size_t s = 0);

    ~MyVector();

    MyVector(const MyVector& other);

    MyVector& operator=(const MyVector& other);

    MyVector(MyVector&& other) noexcept;

    MyVector& operator=(MyVector&& other) noexcept;

    size_t getSize() const;
};

MyVector createMyVector(size_t s);

