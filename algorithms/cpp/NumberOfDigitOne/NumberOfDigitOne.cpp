// source: https://leetcode.com/problems/number-of-digit-one/

/**
 *
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int factor = 1;
		int num = 0;
		int original = n;
		while(n > 0)
		{
			int x = n % 10;
			if (x > 1) num += 1 * factor;
			else if (x == 1) 
				num += (original % factor + 1);
			num += (n/10)*factor;
			n = n/10;
			factor = factor * 10;
		}
		return num;
	}
};

int main()
{
	Solution* so = new Solution();
	for (int i = 0; i < 121; i++)
		cout << "input: " << i << ", output: " << so->countDigitOne(i) << endl;
}
