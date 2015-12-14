// source: https://leetcode.com/problems/two-sum-iii-data-structure-design/

/**
 *
 * Design and implement a TwoSum class. It should support the following operations: add and find.
 *
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the value.
 *
 * For example,
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 *
 **/

class TwoSum {
private:
	unordered_map<int, int> nums_;
public:

	// Add the number to an internal data structure.
	void add(int number) {
		nums_[number]++;
	}
	
	// Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
		for (unordered_map<int, int>::iterator it = nums_.begin(); it != nums_.end(); it++)
		{
			int target = value - it->first;
			if (target == it->first)
			{
				if (it->second > 1) return true;
				else continue;
			}
			if (nums_.find(target) != nums_.end()) return true;
		}
		return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
