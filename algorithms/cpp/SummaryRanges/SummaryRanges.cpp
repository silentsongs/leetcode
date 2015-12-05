// source: https://leetcode.com/problems/summary-ranges/

/**
 *
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 **/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		if (nums.size() == 0) return result;
		int rstart = nums[0];
		int rend = nums[0];
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if (nums[i] == rend && i != size - 1) continue;
			if (nums[i] - rend == 1) rend = nums[i];
			else if (nums[i] > rend) // Should consider the overflow scenario
			{
				stringstream range;
				if (rstart == rend) range << rstart;
				else 
					range << rstart <<  "->" << rend;
				result.push_back(range.str());
				rstart = rend = nums[i];
			}
			if (i == size - 1)
			{
				stringstream range;
				if (rstart == rend) range << rstart;
				else
					range << rstart <<  "->" << rend;
				result.push_back(range.str());
			}
		}
		return result;
	}
};
