// source: https://leetcode.com/problems/factorial-trailing-zeroes/

/**
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 **/

#include<iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int count5 = 0;
		while(n >= 5)
		{
			n = n/5;
			count5 += n;
		}
		return count5;
	}
};

int main()
{
	Solution* so = new Solution();
	for (int i = 0; i < 20; i++)
	{
		cout << "input: " << i << ", output: " << so->trailingZeroes(i) << endl;
	}
}
