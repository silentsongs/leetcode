// source: https://leetcode.com/problems/missing-ranges/

/**
 *
 * Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
 *
 * For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
 *
 **/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
	    int size = nums.size();
	    if (nums.empty())
	    {
	        if (lower == upper)
	            result.push_back(to_string(lower));
	        else
	            result.push_back(to_string(lower) + "->" + to_string(upper));
	        return result;
	    }
        if (nums[0] != lower)
	    {
		    if (nums[0] == lower+1) result.push_back(to_string(lower));
		    else result.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
        for (int i = 1; i < size; i++)
	    {
		    if (nums[i] - 1 == nums[i-1]) continue;
		    else if (nums[i] - 2 == nums[i-1]) result.push_back(to_string(nums[i]-1));
		    else 
			    result.push_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));
	    }
	    if (nums[size-1] == upper-1) result.push_back(to_string(upper));
	    else if (nums[size-1] < upper-1) result.push_back(to_string(nums[size-1]+1) + "->" + to_string(upper));
        return result;

    }
};
