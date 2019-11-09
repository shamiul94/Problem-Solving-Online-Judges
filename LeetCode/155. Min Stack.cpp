#include <bits/stdc++.h>

using namespace std;

// with 2 stacks
class MinStack2Stacks {
public:
    /** initialize your data structure here. */
    stack<int> numStack;
    stack<int> minStack;

    int min = INT_MAX;

    MinStack2Stacks() {

    }

    void push(int x) {

        // we need the equal sign because, if -2 is inserted 10 times, once the minStack is popped, it will
        // be lost.
        numStack.push(x);

        if (minStack.empty()) {
            minStack.push(x);
        } else {
            if (minStack.top() >= x) {
                minStack.push(x);
            }
        }
    }

    void pop() {
        if (!numStack.empty()) {
            if (numStack.top() == minStack.top()) {
                minStack.pop();
            }
            numStack.pop();
        }
    }

    int top() {
        return numStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};


// with 1 stacks = better. time - 92%, space - 90%
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> numStack;
    int min = INT_MAX;

    MinStack() {

    }

    void push(int x) {
        if (min >= x) {
            numStack.push(min);
            min = x;
        }
        numStack.push(x);
    }

    void pop() {
        if (numStack.top() == min) {
            numStack.pop();
            min = numStack.top();
            numStack.pop();
        } else {
            numStack.pop();
        }
    }

    int top() {
        return numStack.top();
    }

    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */