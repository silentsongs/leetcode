// source: https://leetcode.com/problems/excel-sheet-column-title/

/**
 *
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 *
 * Credits:
 * Special thanks to @ifanchu for adding this problem and creating all test cases.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string output = "";
		if (n == 0) return output;
		n--;
		while(n/26 > 0)
		{
			int x = n % 26;
			output = string(1, 'A' + x) + output;
			n = n/26 - 1;
		}
		if (n >= 0) output = string(1, 'A' + n) + output;
		return output;
	}
};

int main()
{
	Solution* so = new Solution();
	int cases[] = {1, 26, 27, 52, 26 * 26 + 1, 26 * 27, 26 * (26+1) + 1, 26 * 27 + 26 + 1};
	int size = sizeof(cases)/sizeof(int);
	for (int i = 0; i < size; i++)
		cout << "input: " << cases[i] << ", output: " << so->convertToTitle(cases[i]) << endl;
}
