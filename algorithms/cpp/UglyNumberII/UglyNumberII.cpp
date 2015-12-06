// source: https://leetcode.com/problems/ugly-number-ii/

/**
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;
		vector<int> v(n);
		v[0] = 1;
		int pos2 = 0, pos3 = 0, pos5 = 0;
		for (int i = 1; i < n; i++)
		{
			v[i] = min(v[pos2]*2, min(v[pos3]*3, v[pos5]*5));
			if (v[i] == v[pos2]*2) pos2++;
			if (v[i] == v[pos3]*3) pos3++;
			if (v[i] == v[pos5]*5) pos5++;
		}
		return v[n-1];
	}
};

int main()
{
	Solution* so = new Solution();
	for (int i = 1; i < 16; i++)
		cout << "input: " << i << ", output: " << so->nthUglyNumber(i) << endl;
}
