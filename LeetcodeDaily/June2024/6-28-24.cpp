// link: https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28
// difficulty: medium
// date solved: june 28, 2024
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<int> degree(n, 0); // Array to store the degree of each city

    // Calculate the degree of each city
    for (const auto &road : roads) {
      degree[road[0]]++;
      degree[road[1]]++;
    }

    // Create a list of cities and sort by degree
    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
      cities[i] = i;
    }
    sort(cities.begin(), cities.end(),
         [&](int a, int b) { return degree[a] > degree[b]; });

    // Assign values to cities starting from the highest degree
    long long totalImportance = 0;
    for (int i = 0; i < n; i++) {
      totalImportance += (long long)(n - i) * degree[cities[i]];
    }

    return totalImportance;
  }
};
