// source: https://leetcode.com/problems/range-sum-query-immutable/

/**
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 *
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 **/

class NumArray {
private:
	vector<int> accums_;
public:
	NumArray(vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0) accums_.push_back(nums[i]);
			else
				accums_.push_back(nums[i] + accums_[i-1]);
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) return accums_[j];
		return accums_[j] - accums_[i-1];
	}
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
