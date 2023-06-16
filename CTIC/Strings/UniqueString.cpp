// Implement an algorithm to determine if a string has all unique characters. 
// What if you cannot use an additional data structure?
// Date Solved: June 15, 2023
// Time complexity: O(n)
// - we are looping through a string of at max n characters
// Space complexity: O(n)
// - dont know what the set of possible charactesr are, if we limited to say the alphabet then it could be constant
/*
Solution:
We just want to check if a character appears more than once. Can just add it to a set
and check if its in there already for each character. If it is we have seen it before and
it is not unique, otherwise its out first time seeing it
*/

#include <unordered_map>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isUnique(string &str) {
        set<char> charSet;
        for(int i = 0; i < str.length(); i++) {
            if(charSet.count(str[i]) != 0) {
                return false;
            }
            charSet.insert(str[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;
    string test1 = "";
    string test2 = "abc";
    string test3 = "aa";
    string test4 = "abcedfee";
    cout << sol.isUnique(test1) << " should be true\n";
    cout << sol.isUnique(test2) << " should be true\n";
    cout << sol.isUnique(test3) << " should be false\n";
    cout << sol.isUnique(test4) << " should be false\n";
    return 0;
}

