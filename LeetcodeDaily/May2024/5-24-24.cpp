// link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/?envType=daily-question&envId=2024-05-24
// difficulty: hard
// date solved: may 24, 2024
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//nested unordered_map for dp
    unordered_map<int, unordered_map<string, int>>dp;
    int helper(vector<string>& words, int curr, vector<char> letters, vector<int>& score, string memory){
        if(curr<0)return 0;
        if(dp[curr][memory]!=0)return dp[curr][memory];
        unordered_map<char, int>curr_dict, curr_word, remaining;
        vector<char>lettersr;
        for(int i=0;i<letters.size();i++){
            curr_dict[letters[i]]++;
        }
        for(int i=0;i<words[curr].size();i++){
            curr_word[words[curr][i]]++;
        }
        remaining=curr_dict;
        int flag=1;
        for(auto temp:curr_word){
            // cout<<temp.first<<" "<<temp.second<<endl;
            if(curr_dict[temp.first]<temp.second){
                flag=0;
                break;
            }
            remaining[temp.first]-=temp.second;
        }
		// generating the string from vectors a is if we pass the current word, b is if we use the current word.
		//Converting to strings and sorting increasing time complexity but will still be better for higher constraints 
		//than recursion(exponential). Converting to strings will help us use the unorered_map to memotise
        string a="", b="";
        for(int i=0;i<letters.size();i++){
            a+=letters[i];
        }
        for(int i=0;i<remaining.size();i++){
            b+=remaining[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(flag==0){
            return helper(words, curr-1, letters, score, a);
        }
        int curr_score=0;
        for(int i=0;i<words[curr].size();i++){
            curr_score+=score[words[curr][i]-'a'];
        }
        for(auto temp:remaining){
            for(int i=0;i<temp.second;i++)
                lettersr.emplace_back(temp.first);
        }
        int ans2=helper(words, curr-1, lettersr, score, b)+curr_score;        
        return max(helper(words, curr-1, letters, score, a), ans2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        string a="";
        for(int i=0;i<letters.size();i++){
            a+=letters[i];
        }
        sort(a.begin(), a.end());
        return helper(words, words.size()-1, letters, score,a);        
    }
};