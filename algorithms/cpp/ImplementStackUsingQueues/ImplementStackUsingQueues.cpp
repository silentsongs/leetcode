// source: https://leetcode.com/problems/implement-stack-using-queues/

/**
 *
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 * Update (2015-06-11):
 * The class name of the Java function had been updated to MyStack instead of Stack.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and all test cases.
 *
 **/

class Stack {
private:
	queue<int> q1;
	queue<int> q2;
public:
	// Push element x onto stack.
	void push(int x) {
		if (q1.empty()) { 
			q1.push(x);
			while(!q2.empty())
			{
				int i = q2.front();
				q2.pop();
				q1.push(i);
			}
		}
		else
		{
			q2.push(x);
			while(!q1.empty())
			{
				int i = q1.front();
				q1.pop();
				q2.push(i);
			}
		}
	}
	
	// Removes the element on top of the stack.
	void pop() {
		if (!q1.empty()) q1.pop();
		if (!q2.empty()) q2.pop();
	}
	
	// Get the top element.
	int top() {
		if (!q1.empty()) return q1.front();
		if (!q2.empty()) return q2.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty() && q2.empty();
	}
};
