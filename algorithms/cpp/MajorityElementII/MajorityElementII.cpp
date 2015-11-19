// source: https://leetcode.com/problems/majority-element-ii/

/**
 *
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 *
 * Hint:
 *
 * How many majority elements could it possibly have?
 *
 **/

// Using Boyer-Moore Majority Vote algorithm 
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int count1 = 0, count2 = 0, major1, major2;
		int size = nums.size();
		vector<int> result;
		for(int i = 0; i < size; i++)
		{
			if (count1 == 0)
			{
				major1 = nums[i];
				count1++;
			}
			else if (nums[i] == major1)
			{
				count1++;
			}
			else if (count2 == 0)
			{
				major2 = nums[i];
				count2++;
			}
			else if (nums[i] == major2)
			{
				count2++;
			}
			else
			{
				count1--;
				count2--;
			}
		}
		count1 = 0; count2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (nums[i] == major1) count1++;
			if (nums[i] == major2) count2++;
		}
		if (count1 > size/3) 
			result.push_back(major1);
		if (count2 > size/3 && major2 != major1)
			result.push_back(major2);
		return result;
	}
};
