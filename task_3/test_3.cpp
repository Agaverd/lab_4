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

int main() {
	//Test cases
	TestDefaultConstructor();
	TestSizeConstructor();

	// indev
	//TestCopyConstructor();
	//TestAssignmentOperator();
	//TestAccessOperator();

	return 0;
}