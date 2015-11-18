// source: https://leetcode.com/problems/min-stack/

/**
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 **/

class MinStack {
private:
	stack<int> data;
	stack<int> min;

public:
	void push(int x) {
		if (min.empty() || (!min.empty() && min.top() >= x)) min.push(x);
		data.push(x);
	}	
	
	void pop() {
		int x = data.top();
		if (x == min.top()) min.pop();
		data.pop();
	}
	
	int top() {
		return data.top();
	}
	
	int getMin() {
		return min.top();
	}
};
