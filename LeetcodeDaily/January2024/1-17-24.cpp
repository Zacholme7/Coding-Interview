// link:
// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17
// difficulty: easy
// date solved: january 17, 2024

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> numFreq;
    set<int> uniqueFreq;

    for (const int &num : arr) {
      numFreq[num]++;
    }

    for (const auto &freq : numFreq) {
      uniqueFreq.insert(freq.second);
    }

    return numFreq.size() == uniqueFreq.size();
  }
};

int main() {
  Solution sol;
  vector<int> t1{1, 2, 2, 1, 1, 3};
  vector<int> t2{1, 2};
  vector<int> t3{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  cout << sol.uniqueOccurrences(t1) << endl;
  cout << sol.uniqueOccurrences(t2) << endl;
  cout << sol.uniqueOccurrences(t3) << endl;
}
