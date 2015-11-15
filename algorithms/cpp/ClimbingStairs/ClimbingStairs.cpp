// source: https://leetcode.com/problems/climbing-stairs/

/**
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 **/

#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		int one_step_before = 2;
		int two_step_before = 1;
		int all_steps = 0;
		for (int i = 3; i <= n; i++)
		{
			all_steps = one_step_before + two_step_before;
			two_step_before = one_step_before;
			one_step_before = all_steps;
		}
		return all_steps;
	}
};

int main()
{
	Solution* so = new Solution();
	for (int i = 1; i < 11; i++)
	{
		cout<<"input: " << i << ", output: " << so->climbStairs(i) << endl;
	}
}
