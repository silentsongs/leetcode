// source: https://leetcode.com/problems/happy-number/

/**
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, 
 * and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
 * Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1*1 + 9*9 = 82
 * 8*8 + 2*2 = 68
 * 6*6 + 8*8 = 100
 * 1*1 + 0*0 + 0*0 = 1
 *
 * Credits:
 * Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 *
 **/

class Solution {
public:
	bool isHappy(int n) {
		map<int, int> showed_nums;
		std::map<int,int>::iterator it;
		while(showed_nums.find(n) == showed_nums.end())
		{
			showed_nums[n] = 1;
			n = squareSum(n); 
		}
		return n == 1 ? true : false;
	}

	int squareSum(int n)
	{
		int num = 0;
		while(n > 0)
		{
			int x = n % 10;
			num += (x * x);
			n = n/10;
		}
		return num;
	}

	// Using Floyd cycle detection algorithm 
	bool isHappy(int n) 
	{
		int fast = squareSum(squareSum(n));
		int slow = squareSum(n);
		while(fast != slow)
		{
			fast = squareSum(squareSum(fast));
			slow = squareSum(slow);
		}
		return slow == 1 ? true : false;
	}
};
