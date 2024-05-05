// link: https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04
// difficulty: medium
// date solved: may 04
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());

    int i = 0, boats = 0;
    int j = people.size() - 1;

    while (i <= j) {
      if (people[i] + people[j] <= limit) {
        i++;
        j--;
        boats++;
      } else {
        boats++;
        j--;
      }
    }

    return boats;
  }
};
