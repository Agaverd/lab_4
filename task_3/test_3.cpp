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

int main() {
	//Test cases
	TestDefaultConstructor();

	// indev
	//TestSizeConstructor();
	//TestCopyConstructor();
	//TestAssignmentOperator();
	//TestAccessOperator();

	return 0;
}