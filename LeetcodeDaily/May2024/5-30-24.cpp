// link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30
// difficulty: medium
// date solved: may 30, 2024
#include <vector>
using namespace std;

class Solution {
public:
  int countTriplets(vector<int> &arr) {
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int a = 0;
        for (int k = i; k < j; k++) {
          a ^= arr[k];
        }

        int b = 0;
        for (int k = j; k < n; k++) {
          b ^= arr[k];
          if (a == b) {
            count++;
          }
        }
      }
    }

    return count;
  }
};
