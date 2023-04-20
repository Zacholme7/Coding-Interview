// https://leetcode.com/problems/merge-strings-alternately/
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            string res;
            for(int i = 0; i < max(word1.size(), word2.size()); i++) {
                if(i < word1.size()) {
                    res += word1[i];
                }
                if(i < word2.size()) {
                    res += word2[i];
                }
            }
            return res;
        }
};


int main() {
    Solution sol;
    cout << sol.mergeAlternately("foo", "barhello") << endl;
    return 0;

}

