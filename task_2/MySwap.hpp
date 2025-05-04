#include <sstream>

template<typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template<typename Container>
std::string containerToString(const Container& con) {
    std::ostringstream oss;
    oss << "[";
    bool first = true;
    for (const auto& elem : con) {
        if (!first) {
            oss << ", ";
        }
        oss << elem;
        first = false;
    }
    oss << "]";
    return oss.str();
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    return os << "{" << p.first << ": " << p.second << "}";
}