#include "MyArray.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

void TestDefaultConstructor() {
	ArrayT<int> arr;
	assert(arr.Size() == 0);
	assert(arr.Capacity() == 0);
	assert(arr.IsEmpty() == true);
	std::cout << "TestDefaultConstructor passed" << std::endl;
}

void TestSizeConstructor() {
	ArrayT<int> arr(5);
	assert(arr.Size() == 5);
	assert(arr.Capacity() == 5);
	assert(arr.IsEmpty() == false);

	try {
		ArrayT<int> invalid(-1);
		assert(false && "Expected exception weren't thrown"); //mghtmt smart case
	}
	catch (const std::invalid_argument&) {
		std::cout << "TestSizeConstructor passed" << std::endl;
	}
}

void TestCopyConstructor() {
	ArrayT<int> src(5);
	src[0] = 1; src[1] = 2; src[2] = 3 ; src[3] = 4; src[4] = 5;

	ArrayT<int> copy(src);
	assert(copy.Size() == 5);
	assert(copy[0] == 1 && copy[1] == 2 && copy[2] == 3 && copy[3] == 4 && copy[4] == 5);

	std::cout << "TestCopyConstructor passed" << std::endl;
}


int main() {
	//Test cases
	TestDefaultConstructor();
	TestSizeConstructor();
	TestCopyConstructor();

	// indev
	//TestAssignmentOperator();
	//TestAccessOperator();
	std::cout << "________________\n\nAll tests passed!" << std::endl;

	return 0;
}