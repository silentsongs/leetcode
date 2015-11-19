// source: https://leetcode.com/problems/majority-element/

/**
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 **/

 // Solution uses algorithm here: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 1;
		int major = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (count == 0)
			{
				major = nums[i];
				count++;
			}
			else if (major == nums[i])
				count++;
			else
				count--;
		}
		return major;
	}
};
