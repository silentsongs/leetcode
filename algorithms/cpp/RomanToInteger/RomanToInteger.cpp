// source: https://leetcode.com/problems/roman-to-integer/
/*
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int output = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(i+1 < s.size())
			{
				if (romanCharToInt(s[i]) < romanCharToInt(s[i+1]))
					output -= romanCharToInt(s[i]);
				else
					output += romanCharToInt(s[i]);
			}
			else
				output += romanCharToInt(s[i]);
		}
		return output;
	}

	int romanCharToInt(char c) {
		switch(c)
		{
			case 'I' : return 1;
			case 'V' : return 5;
			case 'X' : return 10;
			case 'L' : return 50;
			case 'C' : return 100;
			case 'D' : return 500;
			case 'M' : return 1000;
			default: return 0;
		}
	}
};

int main()
{
	string cases[] = { 
		"DIV",
		"MMDDCC",
		"MMCDCCXIV"
	};
	Solution* so = new Solution();
	for (int i = 0; i < 3; i++)
	{
		cout<<"input: " << cases[i] << ", output: " << so->romanToInt(cases[i]) << endl;
	}
}


