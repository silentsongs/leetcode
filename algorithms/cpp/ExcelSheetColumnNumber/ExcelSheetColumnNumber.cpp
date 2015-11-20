// source: https://leetcode.com/problems/excel-sheet-column-number/

/**
 *
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *      ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int num = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int x = (s[i] - 'A') + 1;
			num = num * 26 + x;
		}
		return num;
	}
};

int main()
{
	Solution* so = new Solution();
	string cases[] = {"A", "Z", "AA", "AZ", "ZZ", "AAA", "AAZ", "AZA", "ZZA", "ZZZ"};
	int size = sizeof(cases)/sizeof(string);
	for (int i = 0; i < size; i++)
	{
		cout << "input: " << cases[i] << ", output: " << so->titleToNumber(cases[i]) << endl;
	}
}
