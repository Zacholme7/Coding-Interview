// UTILITY FUNCTIONS I TEND TO USE A LOT
#pragma once
#include <iostream>
#include <vector>
using namespace std;

// print a 1D vector
template <typename T>
std::ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[ ";
    for (const auto& elem : v) {
        os << elem << " ";
    }
    os << "]";
    return os;
}


// print a 2D vector
template <typename T>
std::ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    os << "[ ";
    for (const auto& elem : v) {
        os << elem << " ";
    }
    os << "]";
    return os;
}