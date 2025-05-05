#include <algorithm>

class MyVector {
private:
	int* data;
	size_t size;

public:
	MyVector(size_t s = 0) :
		size(s), data(s > 0 ? new int[s] : nullptr) {
	}

	~MyVector() {
		delete[] data;
	}

	MyVector(const MyVector& vector) :
		size(vector.size), data(vector.size > 0 ? new int[vector.size] : nullptr) {
		if (size > 0) {
			std::copy(vector.data, vector.data + size, data);
		}
	}

	MyVector& operator=(const MyVector& vector) {
		if (this != &vector) { 
			delete[] data; 

			size = vector.size;
			data = (size > 0 ? new int[size] : nullptr);

			if (size > 0) {
				std::copy(vector.data, vector.data + size, data); 
			}
		}
		return *this;
	}

	MyVector(MyVector&& vector) noexcept
		: data(vector.data), size(vector.size) { 
		vector.data = nullptr;
		vector.size = 0;
	}

	MyVector&  operator=(MyVector&& vector ) noexcept {
		delete[] data;

		size = vector.size;
		data = (size > 0 ? new int[size] : nullptr);

		vector.data = nullptr;
		vector.size = 0;
		return *this;
	}

	size_t getSize() const{
		return size;
	}

};