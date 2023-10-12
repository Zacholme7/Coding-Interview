// Link: https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium
// Date solved: April 22, 2023
/*
Solution:
This problem has to do with just understanding that all anagrams of a word will have the same sorted version.
I have a map that will use the sorted word as a key and maintain a vector of the words that are anagrams.
I loop over the strings and sort them, I use the sorted version as a key and add the word to the vector
in the map. At the end I add all of the groups to a vector to be returnes.
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../../../Util.cpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map to track the anagrams
        unordered_map<string, vector<string>> wordMap;

        // loop through the strings
        for(int i = 0; i < strs.size(); i++) {
            // sort the string, set it as a key and add the string to the vector
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            wordMap[sortedStr].push_back(strs[i]);
        }

        // add all the groups of anagrams to a vector to be returned
        vector<vector<string>> res;
        for(auto words: wordMap) {
            res.push_back(words.second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> test1 = {"eat", "tea", "tan", "nat", "ate", "bat"};
    vector<string> test2 = {""};
    vector<string> test3 = {"a"};
    cout << sol.groupAnagrams(test1) << endl;
    cout << sol.groupAnagrams(test2) << endl;
    cout << sol.groupAnagrams(test3) << endl;
    return 0;
}
