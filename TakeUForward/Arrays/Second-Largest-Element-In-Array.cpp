// link: https://www.codingninjas.com/studio/problems/second-largest-element-in-the-array_873375
// difficulty: easy
// date solved: january 22, 2023
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findSecondLargest(vector<int> &arr) {
    if (arr.size() < 2) {
      return -1;
    }

    int largest = arr[0];
    int secondLargest = -1;

    for(int i = 1; i < arr.size(); i++) {
      if (arr[i] > largest) {
        secondLargest = largest;
        largest = arr[i];
      } else if (largest > arr[i] && arr[i] > secondLargest) {
        secondLargest = arr[i];
      }
    }
    return secondLargest;
  }
};

void testSecondLargest(std::vector<int> arr, int expected) {
    Solution sol;
    int result = sol.findSecondLargest(arr);
    std::cout << "Test case: ";
    for (int n : arr) std::cout << n << " ";
    std::cout << "\nExpected: " << expected << ", Got: " << result << "\n\n";
}

int main() {
  Solution sol;
  testSecondLargest({4, 5, 1, 3, 2}, 4);
  testSecondLargest({1, 2}, 1);
  testSecondLargest({7, 7, 7, 7}, -1);
  testSecondLargest({5, 4, 3, 2, 1}, 4);
  testSecondLargest({1, 2, 3, 4, 5}, 4);
  testSecondLargest({1000, 500, 300, 200, 100}, 500);
  testSecondLargest({42}, -1);
}
