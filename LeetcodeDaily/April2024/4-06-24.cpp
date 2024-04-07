// link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/?envType=daily-question&envId=2024-04-06
// difficulty: medium
// date solved: april 6, 2024
// writeup: a pretty simple approach. Mark all of extra parens and just dont add them at the end. On the first pass we go through
// and mark all the closing. If the openParenCount is 0 and we are at a closing, that means it is an extra one and we can mark it.
// Otherwise we have a pair and decrement the count. On the other way through we work backwards and we know we have openParenCount extra
// openings so we can just go through and mark them as extra in reverse order. then just make the string at the end
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int openParenCount = 0;
    vector<char> sVec(s.begin(), s.end());

    // mark all extra closing
    for(int i = 0; i < s.size(); i++) {
      if (sVec[i] == '(') {
        openParenCount++;
      } else if (sVec[i] == ')') {
        if (openParenCount == 0) {
          sVec[i] = '*';
        } else{
          openParenCount--;
        }
      }
    }

    // mark all extra opening, doesnt matter which
    for(int i = s.size() - 1; i >= 0; i--) {
      if (openParenCount > 0 and sVec[i] == '(') {
        sVec[i] = '*';
        openParenCount--;
      }
    }

    string res = "";
    for(auto &c: sVec) {
      if (c != '*') {
        res += c;
      }
    }

    return res;
  }
};
