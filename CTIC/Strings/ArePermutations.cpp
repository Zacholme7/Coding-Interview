// Given two strings, write a method to decide if one is a permutation of the other
// Date Solved: June 15, 2023
// Time complexity: 
// Space complexity: 
/*
Solution:
*/

#include <unordered_map>
#include <string>
#include <iostream>
#include <set>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPermutation(string str1, string str2) {
        if(str1.length() != str2.length()) {
            return false;
        }
        unordered_map<char, int> charMp;
        for(int i = 0; i < str1.length(); i++) {
            charMp[str1[i]]++;
            charMp[str2[i]]--;
        }

        for(auto it: charMp) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    cout << (sol.isPermutation("abc", "cba") ? "PASS" : "FAIL") << endl;
    cout << (sol.isPermutation("abc", "abc") ? "PASS" : "FAIL") << endl;
    cout << (!sol.isPermutation("abc", "def") ? "PASS" : "FAIL") << endl;
    cout << (!sol.isPermutation("aab", "abc") ? "PASS" : "FAIL") << endl;
    cout << (!sol.isPermutation("abcd", "abc") ? "PASS" : "FAIL") << endl;
    cout << (sol.isPermutation("", "") ? "PASS" : "FAIL") << endl;
    cout << (!sol.isPermutation("", "abc") ? "PASS" : "FAIL") << endl;
    cout << (!sol.isPermutation("abc", "ABC") ? "PASS" : "FAIL") << endl;
    cout << (sol.isPermutation("abc!", "!bca") ? "PASS" : "FAIL") << endl;
    return 0;
}
