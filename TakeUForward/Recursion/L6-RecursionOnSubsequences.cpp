// Video: https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6
// Date: May 9, 2023
// This video talks about going through all subsequences which is a huge part of recursive problems

#include <iostream>
#include <vector>
#include "../../Util.cpp"
using namespace std;

class Solution {
public:
    void printSubsequences(int n, vector<int> &vec, vector<int> numbers) {
        if(n >= numbers.size()) {
            cout << vec << endl;
            return;
        }
        vec.push_back(numbers[n]);
        printSubsequences(n + 1, vec, numbers);
        vec.pop_back();
        printSubsequences(n + 1, vec, numbers);
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {3, 1, 2};
    vector<int> vec;
    sol.printSubsequences(0, vec, numbers);
    return 0;

}

