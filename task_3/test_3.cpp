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

void TestAssignmentOperator() {
	ArrayT<std::string> arr1(2);
	arr1[0] = "NUST"; arr1[1] = "MISIS";
	ArrayT<std::string> arr2;
	arr2 = arr1;

	assert(arr2.Size() == 2);
	assert(arr2[0] == "NUST" && arr2[1] == "MISIS");

	std::cout << "TestAssignmentOperator passed\n";
}

void TestAccessOperator() {
	ArrayT<double> arr(3);
	arr[0] = 1.0; arr[1] = 1.41; arr[2] = 1.73;

	assert(arr[0] == 1.0 && arr[1] == 1.41 && arr[2] == 1.73);

	try {
		double val = arr[-1];
		assert(false && "Expected exception weren't thrown");
	}
	catch (const std::invalid_argument&) {}

	try {
		double val = arr[3];
		assert(false && "Expected exception weren't thrown");
	}
	catch (const std::invalid_argument&) {
		std::cout << "TestAccessOperator passed" << std::endl;
	}
}

void TestResize() {
	ArrayT<int> arr(2);
	arr[0] = 1; arr[1] = 2;

	try{
		// resize to smaller
		arr.Resize(1);
		assert(arr.Size() == 1 && arr[0] == 1);

		// resize to larger
		arr.Resize(3);
		assert(arr.Size() == 3 && arr[0] == 1);
	}
	catch (const std::invalid_argument&) {
		assert(false && "Expected exception weren't thrown");
	}

	std::cout << "TestResize passed" << std::endl;
}

int main() {
	//Test cases
	TestDefaultConstructor();
	TestSizeConstructor();
	TestCopyConstructor();
	TestAssignmentOperator();
	TestAccessOperator();
	TestResize();

	// indev

	std::cout << "________________\n\nAll tests passed!" << std::endl;

	return 0;
}