// link:
// https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10
// difficulty: medium
// date solved: february 10, 2024
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        int ans = 0;

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                if (s[i] == s[i + len - 1] && (len <= 2 || palindrome[i + 1][i + len - 2])) {
                    palindrome[i][i + len - 1] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {}
