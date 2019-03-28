/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (35.38%)
 * Total Accepted:    269.9K
 * Total Submissions: 756.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (x <= min_) {
			s_.push(min_);
			min_ = x;
		}
		s_.push(x);
	}

	void pop() {
		if (s_.top() == min_) {
			s_.pop();
			min_ = s_.top();
			s_.pop();
		}
		else {
			s_.pop();
		}
	}

	int top() {
		return s_.top();
	}

	int getMin() {
		return min_;
	}
private:
	stack<int> s_;
	int min_ = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

