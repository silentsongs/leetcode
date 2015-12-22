// source: https://leetcode.com/problems/permutations/

/**
 *
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int>& nums) {
		vector<vector<int> > result;
		dfs(nums, result);
		return result;
	}

	void dfs(vector<int>& nums, vector<vector<int> >& result)
	{
		if (nums.size() == 1)
		{
			result.push_back(nums);
			return;
		}

		vector<int> nums1(nums.begin()+1, nums.end());
		dfs(nums1, result);
		vector<vector<int> > vec1;
		for (int i = 0; i < result.size(); i++)
		{
			for(int j = 0; j <= result[i].size(); j++)
			{
				vector<int> tmp =  result[i];
				tmp.insert(tmp.begin()+j, nums[0]);
				vec1.push_back(tmp);
			}
		}
		result = vec1;
	}
};
