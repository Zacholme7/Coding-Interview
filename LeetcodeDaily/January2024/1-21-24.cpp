// link: https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21
// difficulty: medium
// date solved: january 20, 2024

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& A) {
        int prev2 = 0, prev = 0, cur = 0;
        for(auto i : A) {
            cur = max(prev, i + prev2);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};


int main() {
  return 0;
}


