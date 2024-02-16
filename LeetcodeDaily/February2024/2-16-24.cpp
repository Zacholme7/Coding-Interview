// link:
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16
// difficulty: medium
// date solved: february 16, 2024
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> mp;
    for (auto a : arr)
      mp[a]++;

    vector<int> v;
    int cnt = 0;
    for (auto a : mp) {
      v.push_back(a.second);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      if (k > v[i]) {
        k -= v[i];
        v[i] = 0;
      } else {
        v[i] -= k;
        k = 0;
      }
      if (v[i] != 0)
        cnt++;
    }

    return cnt;
  }
};

int main() {}
