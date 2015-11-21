// source: https://leetcode.com/problems/house-robber/

/**
 *
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police * .
 *
 * Credits:
 * Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
 *
 **/

class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) return 0;
		if (size == 1) return nums[0];
		if (size == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
		int current_step = nums[2] + nums[0];
		int one_step_before = nums[1];
		int two_step_before = nums[0];
		for (int i = 3; i < size; i++)
		{
			int n = one_step_before > two_step_before ? one_step_before + nums[i] : two_step_before + nums[i];
			two_step_before = one_step_before;
			one_step_before = current_step;
			current_step = n;
		}
		return current_step > one_step_before ? current_step : one_step_before;
	}

};
