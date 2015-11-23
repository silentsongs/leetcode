// source: https://leetcode.com/problems/contains-duplicate-ii/

/**
 *
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 *
 **/

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k <= 0) return false;
		int size = nums.size();
		map<int, int> show_nums;
		for (int i = 0; i < size; i++)
		{
			map<int, int>::iterator it = show_nums.find(nums[i]);
			if (it == show_nums.end()) 
				show_nums[nums[i]] = i;
			else
			{
				int pos = it->second;
				if (pos + k >= i) return true;
				else show_nums[nums[i]] = i;
			}
		}
		return false;
	}
};
