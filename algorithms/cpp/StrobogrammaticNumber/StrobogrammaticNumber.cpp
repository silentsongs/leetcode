// source: https://leetcode.com/problems/strobogrammatic-number/

/**
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 *
 * Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 *
 * For example, the numbers "69", "88", and "818" are all strobogrammatic.
 *
 **/

class Solution {
public:
	bool isStrobogrammatic(string num) {
		int length = num.length();
		for (int i = 0; i < length/2; i++)
		{
			if (num[i] == '9' && num[length-1-i] == '6') continue;
			else if (num[i] == '6' && num[length-1-i] == '9') continue;
			else if ((num[i] == '8' || num[i] == '0' || num[i] == '1') && num[length-1-i] == num[i]) continue;
			else 
				return false;
		}
		if (length % 2 != 0)
		{
			int mid = length/2;
			if (!(num[mid] == '1' || num[mid] == '8' || num[mid] == '0')) return false;
		}
		return true;
	}
};
