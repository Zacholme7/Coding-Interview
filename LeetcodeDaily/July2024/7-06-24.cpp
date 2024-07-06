// link: https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06
// difficulty: easy
// date solved: july 6, 2024
#include <cmath>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        return n - abs(n - 1 - time % (n * 2 - 2));   
    }
};