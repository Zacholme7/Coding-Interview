// Link: https://leetcode.com/problems/flood-fill/
// Difficulty: Easy
// Date: June 17, 2023
// Space: O(n) the stack must store at most the number of frames corresponding to the number of elements in the image
// Time:  O(n) need to visited all spots at most once
/*
Solution
This is just a simple bfs traversal on a graph. We have a starting spot and we just do a traversal from that 
spot to all nodes of the same value and then just change their color. Verify that the row and coll are in bounds
and that our color is the original color, change the color, adn then traverse horizontally and vertically
*/

#include <vector>

using namespace std;
class Solution {
public:

    void floodFillHelper(vector<vector<int>> &image, int row, int col, int color, int origColor) {
        if(row >= 0 && col >= 0 && row < image.size() && col < image[0].size() && image[row][col] == origColor) {
            image[row][col] = color;
            floodFillHelper(image, row + 1, col, color, origColor);
            floodFillHelper(image, row - 1, col, color, origColor);
            floodFillHelper(image, row, col - 1, color, origColor);
            floodFillHelper(image, row, col + 1, color, origColor);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) {
            return image;
        }

        floodFillHelper(image, sr, sc, color, image[sr][sc]);
        return image;
    }
   
};


int main() {
    Solution sol;
    return 0;
}