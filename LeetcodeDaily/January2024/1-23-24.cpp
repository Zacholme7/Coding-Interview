// link:
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23
// difficulty: medium
// date solved: january 23, 2024

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool hasNoDuplicates(const string& word) {
    unordered_set<char> charSet;
    for (char ch : word) {
      if (charSet.find(ch) != charSet.end()) {
        return false;  // Duplicate character found
      }
      charSet.insert(ch);
    }
    return true;
  }

  void addLetters(const string &word, vector<int> &letterCnt) {
    for (char ch : word) {
      int idx = ch - 'a';
      letterCnt[idx]++;
    }
  }

  void subtractLetters(const string &word, vector<int> &letterCnt) {
    for (char ch : word) {
      int idx = ch - 'a';
      letterCnt[idx]--;
    }
  }

  bool canUseWord(const string &word, const vector<int> &letterCnt) {
    for (char ch : word) {
      int charIdx = ch - 'a';
      if (letterCnt[charIdx] != 0) {
        return false;
      }
    }
    return true;
  }

  void helper(int &currMax, int currLength, int idx, const vector<string> &arr, vector<int> &letterCnt) {
    currMax = max(currMax, currLength);

    for (int i = idx; i < arr.size(); i++) {
      if (canUseWord(arr[i], letterCnt)) {
        addLetters(arr[i], letterCnt);
        helper(currMax, currLength + arr[i].size(), i + 1, arr, letterCnt);
        subtractLetters(arr[i], letterCnt);
      }
    }
  }

  int maxLength(vector<string> &arr) {
    vector<string> filteredArr;
    for (const string& word : arr) {
      if (hasNoDuplicates(word)) {
        filteredArr.push_back(word);
      }
    }

    int res = 0;
    vector<int> letterCnt(26, 0);
    helper(res, 0, 0, filteredArr, letterCnt);
    return res;
  }
};


int main() {
  Solution sol;
  vector<std::string> t1{"un", "iq", "ue"};
  vector<std::string> t2{"char", "r", "act", "ers"};
  cout << sol.maxLength(t1) << endl;
  cout << sol.maxLength(t2) << endl;
  return 0;
}
