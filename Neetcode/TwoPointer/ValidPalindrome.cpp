// Link: https://leetcode.com/problems/valid-palindrome/
// Difficulty: Easy
// Date solved: April 27, 2023
/*
Solution
This is a pretty easy problem. We want to check is a string is a palindrom while ignoring all non alphanumeric characters
and convering them all to lowercase. We know this must read the same forwards and backwards, so thats what we can check. We have a 
pointer at the left and right ends of the string. If the left or the right is a non alphanumberic character, we just move the pointerb
because we want to ignore those. Otherwise, we compare if the characters are the same and if they arent we return false, otherwise we
move both of the pointers. At the end we just return true if we made it through
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if(!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << " should be true" << endl;
    cout << sol.isPalindrome("this is a random sentence") << " should be false" << endl;
    return 0;
}