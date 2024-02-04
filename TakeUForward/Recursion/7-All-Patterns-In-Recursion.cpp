// link:
// https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7

// all possible patterns from subsequence. pick then not pick
// 1) print all of the subsequences
// 2) print all sq which sums to k
// 3) print 1 sq which sums to 5
// 4) print count of sq which sums to k
#include <iostream>
#include <vector>

class Solution {
public:
  void subsequenceSumHelper(std::vector<int> &arr, std::vector<int> &curr,
                            int k, int idx, int currSum) {
    // if we are past the arr or our sum is more than the target
    if (idx > arr.size() || currSum > k) {
      return;
    }

    // if our sum is the target
    if (currSum == k) {
      std::cout << "[ ";
      for (int val : curr) {
        std::cout << val << ", ";
      }
      std::cout << "]\n";
      return;
    }

    // pick
    curr.push_back(arr[idx]);
    subsequenceSumHelper(arr, curr, k, idx + 1, currSum + arr[idx]);

    // remove
    curr.pop_back();
    subsequenceSumHelper(arr, curr, k, idx + 1, currSum);
  }

  void printSubsequenceWithSumK(std::vector<int> &arr, int k) {
    std::vector<int> tracker;
    subsequenceSumHelper(arr, tracker, k, 0, 0);
  }


  int countSubsequenceHelper(std::vector<int> &arr, int currSum, int k, int idx) {
    if (idx == arr.size()) {
      if (currSum == k) return 1;
      else return 0;
    }
    return countSubsequenceHelper(arr, currSum + arr[idx], k, idx + 1) + countSubsequenceHelper(arr, currSum, k, idx + 1);
  }

  int countSubsequencesWithSumK(std::vector<int> &arr, int k) {
    return countSubsequenceHelper(arr, 0, k, 0);
  }
};

int main() {
  Solution sol;
  std::vector<int> test{1, 2, 1};
  sol.printSubsequenceWithSumK(test, 2);
  std::cout << sol.countSubsequencesWithSumK(test, 2) << std::endl;
  return 0;
}
