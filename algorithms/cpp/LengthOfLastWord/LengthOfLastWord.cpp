// source: https://leetcode.com/problems/length-of-last-word/

/**
 *
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 *
 **/

#include<iostream>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if (validChar(s[i])) length++;
			if (s[i] == ' ' && i < (s.length() - 1) && validChar(s[i+1])) length = 0;
		}
		return length;
	}

	bool validChar(char c)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
		return false;
	}
};

int main()
{
	Solution* so = new Solution();
	string cases[] = {"  ", "", " Hello World  ", "Normal Case"};
	int size = sizeof(cases)/sizeof(string);
	for(int i = 0; i < size; i++)
	{
		cout << "input: \"" << cases[i] << "\", output: " << so->lengthOfLastWord(cases[i]) << endl;
	}
}
