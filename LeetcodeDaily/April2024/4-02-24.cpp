// link: https://leetcode.com/problems/isomorphic-strings/?envType=daily-question&envId=2024-04-02
// difficulty: easy
// date solved: april 2, 2024
// writeup: this is a tally based approach where we keep track of the last index of the char. If the 
// index of the two current chars do not match, that means we saw it somewhere else previously and the 
// strings are not isomorphic 
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    vector<int> indexS(200, 0);
    vector<int> indexT(200, 0);

    for(int i = 0; i < s.length(); i++) {
      if (indexS[s[i]] != indexT[t[i]]) {
        return false;
      }

      indexS[s[i]] = i + 1;
      indexT[t[i]] = i + 1;
    }
    return true;
  }
};
