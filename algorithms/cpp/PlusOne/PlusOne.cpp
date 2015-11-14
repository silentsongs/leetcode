// source: https://leetcode.com/problems/plus-one/

/**
 *
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 **/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int size = digits.size();
		for (int i = size - 1; i >= 0; i--)
		{
			if (digits[i] < 9)
			{
				digits[i] += 1;
				return digits;
			}
			else
			{
				digits[i] = 0;
				if (i == 0)
				{
					vector<int>::iterator it;
					it = digits.begin();
					it = digits.insert (it, 1);
					return digits;
				}
				continue;
			}
		}
		return digits;
	}
};
