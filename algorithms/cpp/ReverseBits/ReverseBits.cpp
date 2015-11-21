// source: https://leetcode.com/problems/reverse-bits/

/**
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 **/

#include<iostream>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t num = 0;
		for(int i = 1; i <= 31; i+=2)
		{
			uint32_t x = (n << i) & (1 << (16 + i/2));
			uint32_t y = (n >> i) & (1 << (16 - 1 - i/2));
			num += (x + y);
		}
		return num;
	}
};

int main()
{
	Solution* so = new Solution();
	cout << "input: 43261596, output: " << so->reverseBits(43261596) << endl; 
}
