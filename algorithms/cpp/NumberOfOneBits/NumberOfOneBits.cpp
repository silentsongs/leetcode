// source: https://leetcode.com/problems/number-of-1-bits/

/**
 *
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int num = 0;
		for (int i = 0; i < 32; i++)
		{
			if ((n & (1 << i)) > 0) num++;
		}
		return num;
	}

	// see this in the Discuss area
	int hammingWeight2(uint32_t n)
	{
		int num = 0;
		while(n > 0)
		{
			n &= (n-1);
			num++;
		}
		return num;
	}
};

int main()
{
	Solution* so = new Solution();
	int cases[] = {0, 1, 2, 3, 11};
	int size = sizeof(cases)/sizeof(int);
	for (int i = 0; i < size; i++)
	{
		cout << "input: " << cases[i] << ", output: " << so->hammingWeight(cases[i]) << endl;
	}
}
