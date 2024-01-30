// link:
// https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29
// difficulty: easy
// date solved: january 29, 2024
#include <stack>

class MyQueue {
public:
  int size;
  std::stack<int> q1;
  std::stack<int> q2;

  MyQueue() 
    : size(0), q1(), q2() {}

  void push(int x) {
    q1.push(x);
    size++;
  }

  int pop() {
    if (empty()) {
      return -1;
    }

    if (q2.size() == 0) {
      int qSz = q1.size();
      for(int i = 0; i < qSz; i++) {
        auto ele = q1.top(); q1.pop();
        q2.push(ele);
      }
    }

    size--;
    auto ele = q2.top(); q2.pop();
    return ele;
  }

  int peek() {
    if(empty()) {
      return -1;
    }
    if (q2.size() == 0) {
      int qSz = q1.size();
      for(int i = 0; i < qSz; i++) {
        auto ele = q1.top(); q1.pop();
        q2.push(ele);
      }
    }

    auto ele = q2.top();
    return ele;
  }

  bool empty() { return size == 0; }
};
