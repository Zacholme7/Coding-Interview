// link:
// https://leetcode.com/problems/group-anagrams/?envType=daily-question&envId=2024-02-06
// difficulty: medium
// date solved: february 5, 2024

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> wordMap;
    for (int i = 0; i < strs.size(); i++) {
      string sortedStr = strs[i];
      sort(sortedStr.begin(), sortedStr.end());
      wordMap[sortedStr].push_back(strs[i]);
    }

    vector<vector<string>> res;
    for (auto words : wordMap) {
      res.push_back(words.second);
    }
    return res;
  }
};

int main() { return 0; }
