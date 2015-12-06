// source: https://leetcode.com/problems/ugly-number/

/**
 *
 * Write a program to check whether a given number is an ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) return false;
		while(num % 2 == 0)
		{
			num = num/2;
		}
		while(num % 3 == 0)
		{
			num = num/3;
		}
		while (num % 5 == 0)
		{
			num = num/5;
		}
		if (num == 1) return true;
		return false;
	}
};

int main()
{
	Solution* so = new Solution();
	for (int i = 1; i < 30; i++)
		cout << "input: " << i << ", output: " << so->isUgly(i) << endl;
}
