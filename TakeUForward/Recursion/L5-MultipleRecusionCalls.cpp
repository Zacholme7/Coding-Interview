// https://www.youtube.com/watch?v=kvRjNm4rVBE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=5
// Date: May 8, 2023
// This lecture teaches multiple recursion calls using the fibonnaci sequence
// Time complexity: 2 power n, exponential
// Space complexity: 2 power n, exponential

#include <iostream>
using namespace std;

class Solution {
public:
    int calculateFib(int n) {
        if(n <= 1) {
            return n;
        }
        return calculateFib(n - 1) + calculateFib(n - 2);
    }
};


int main() {
    Solution sol;
    cout  << sol.calculateFib(1) << " should be 1" << endl;
    cout << sol.calculateFib(4) <<  " should be 3" << endl;
    return 0;
}