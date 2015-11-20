// source: https://leetcode.com/problems/rotate-array/

/**
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 *
 * [show hint]
 *
 * Related problem: Reverse Words in a String II
 *
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test cases.
 *
 **/


class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size == 0 || k == 0 || k % size == 0) return;
		int num = nums[0];
		int j = 0, flag = 0;
		for (int i = 0; i < size; i++)
		{
			j = j + k >= size ? (j + k)%size : j + k;
			int x = nums[j];
			nums[j] = num;
			num = x;
			if (j == flag)
			{
				j += 1;
				flag = j;
				num = nums[j];
			}
		}
		return;
	}
};

