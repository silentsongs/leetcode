// source: https://leetcode.com/problems/contains-duplicate-iii/

/**
 *
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 *
 **/

class Solution {
public:
	// Use the thought here: https://leetcode.com/discuss/45120/c-using-set-less-10-lines-with-simple-explanation
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k <= 0) return false;
		set<int> elements;

		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k)
			{
				elements.erase(nums[i-k-1]);
			}
			set<int>::iterator it = elements.lower_bound(nums[i] - t);
			if (it != elements.end() && *it - t <= nums[i]) return true; // it has to be *it - t <= nums[i] instead of *it <= nums[i] + t, to avoid overflow case.
			else elements.insert(nums[i]);
		}
		return false;
	}
};
