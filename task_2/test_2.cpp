#include "MySwap.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>


int main() {
    // integer swap
    int x = 56, y = 78;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    mySwap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    //string swap
    std::string s1 = "NUST", s2 = "MISIS";
    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    mySwap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;

    // double swap
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Before swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
    mySwap(d1, d2);
    std::cout << "After swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;

    // vector swap
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7 };
    std::cout << "Vector: " << containerToString(vec) << std::endl;

    // list swap
    std::list<std::string> zoo = { "lion", "zebra", "hippo", "penguin" };
    std::cout << "List: " << containerToString(zoo) << std::endl;

    // set swap
    std::set<double> st = { 1.0, 1.41, 1.73 };
    std::cout << "Set: " << containerToString(st) << std::endl;

    // map swap
    std::map<int, std::string> numbers = { {1, "one"}, {2, "two"}, {3, "three"} };
    std::cout << "Map: " << containerToString(numbers) << std::endl;

    return 0;
}