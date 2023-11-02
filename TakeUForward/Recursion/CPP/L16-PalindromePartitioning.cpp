// Link: https://leetcode.com/problems/palindrome-partitioning/
// Difficulty: Medium
// Date solved: May 26, 2023
/*
Solution:
This problem follows the same recursive structure that we have seen previously, but it does have a few little tricky parts to it. 
In a way its just taking all the subsets but instread of adding a single element to a list we are adding a substring to a list.
this logic is simple, the substring is just index to length i - index + 1. The key here is that when we do our recusrive call, we dont
want to start one elemetn past where we started previoulsy, we want to start at the ITH index. we do not care what we have seen previoulsy if 
we have a palindrome, we want something completely new. So in our loop we start at idx which starts off at 0, take the palinfromfor that position,
and if it is a palinfrome, we add it to the list, and recurse on the ith + 1 index. In this way, we are only adding palindromes to our list
and we dont have to check for validity in the base case. 
*/
#include <vector>
#include <string>
#include <iostream>
#include <ctype.h>
#include "../../../Util.cpp"
using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void partitionHelper(int idx, vector<string> &tracker, vector<vector<string>> &res, string &s) {
        if(idx == s.size()) {
            res.push_back(tracker);
            return;
        }

        for(int i = idx; i < s.size(); ++i) {
            if(isPalindrome(s, idx, i)) {
                tracker.push_back(s.substr(idx, i - idx + 1));
                partitionHelper(i + 1, tracker, res, s);
                tracker.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) {
            return res;
        }
        vector<string> tracker;
        partitionHelper(0, tracker, res, s);
        return res;
    }
};

int main() {
    Solution sol;
    string test = "aab";
    cout << sol.partition(test) << endl;

    return 0;
}