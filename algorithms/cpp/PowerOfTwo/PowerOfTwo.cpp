// source: https://leetcode.com/problems/power-of-two/

/**
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n < 1) return false;
		while(n > 1)
		{
			if ((n & 0x01) > 0) return false;
			n = n >> 1;
		}
		return true;
	}
};

int main()
{
	Solution* so = new Solution();
	for (int i = 0; i < 33; i++)
	{
		cout << "input: " << i << ", output: " << so->isPowerOfTwo(i) << endl;
	}
}
