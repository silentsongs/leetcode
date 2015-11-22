// source: https://leetcode.com/problems/contains-duplicate/

/**
 *
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 *
 **/

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> show_times;
		for (int i = 0; i < nums.size(); i++)
		{
			if (show_times.find(nums[i]) != show_times.end()) return true;
			show_times[nums[i]] = 1;
		}
		return false;
	}

};
