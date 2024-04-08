// link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08
// difficulty: easy
// date solved: april 8, 2024
// writeup: this is fairly simple. Make the sandwiches into a stack and the students into a queue. While we have students left
// we check if we can satisfy the studnets sandwich. if we can we remove both. if we cannot we move the student to the back. we 
// have a tracker attempts that will break us out of the loop if there is a cycle
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    deque<int> sandwichDeque(sandwiches.rbegin(), sandwiches.rend());
    stack<int, deque<int>> sandwichStack(sandwichDeque);

    // Create a deque with students in order for the queue
    deque<int> studentDeque(students.begin(), students.end());
    queue<int, deque<int>> studentsQueue(studentDeque);

    int attempts = 0;

    while(!studentsQueue.empty()) {
      if(studentsQueue.front() == sandwichStack.top()) {
        studentsQueue.pop();
        sandwichStack.pop();
        attempts = 0;
      } else {
        studentsQueue.push(studentsQueue.front());
        studentsQueue.pop();
        attempts++;

        if (attempts == studentsQueue.size()) {
          break;
        }
      }

    }

    return studentsQueue.size();
  }
};
