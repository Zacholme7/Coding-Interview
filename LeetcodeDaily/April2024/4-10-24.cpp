// link: https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10
// difficulty: medium
// date solved: april 10, 2024
// writeup: this is kindof tricky. We want to work backwards in this problem so we sort the deck, have a result to modify, and 
// setup a deque for the indicies that we populate. For each card, we assign the first index on the deque and then we skip the next
// one, we do this for each card which will make it so that we use each index. 
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    sort(deck.begin(), deck.end());
    vector<int> res(deck.size());
    deque<int> q;
    for(int i = 0; i < deck.size(); i++) {
      q.push_back(i);
    }


    for(auto &card : deck) {
      int idx = q.front(); q.pop_front();
      res[idx] = card;
      if (!q.empty())  {
        q.push_back(q.front()); q.pop_front();
      }
    }

    return res;
  }
};
