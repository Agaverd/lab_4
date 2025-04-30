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

	MyVector(MyVector&& other) noexcept
		: data(other.data), size(other.size) { 
		other.data = nullptr;
		other.size = 0;
	}
};