
// UTILITY FUNCTIONS I TEND TO USE A LOT

#pragma once
#include <iostream>
using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    for (const auto& elem : v) {
        os << elem << " ";
    }
    os << "]";
    return os;
}