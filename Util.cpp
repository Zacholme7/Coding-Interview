// UTILITY FUNCTIONS I TEND TO USE A LOT
#pragma once
#include <iostream>
#include <vector>
using namespace std;

// print a vector
template <typename T>
std::ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[ ";
    for (const auto& elem : v) {
        os << elem << " ";
    }
    os << "]";
    return os;
}