// source: https://leetcode.com/problems/valid-palindrome/

/**
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.length() == 0) return true;
		int i = 0, j = s.length() - 1;
		while(i <= j)
		{
			if (!isValidChar(s[i])) 
			{	
				i++;
				continue;
			}
			if (!isValidChar(s[j])) 
			{	
				j--;
				continue;
			}
			char x = s[i] >= 'A' && s[i] <= 'Z' ? s[i] + 'a' - 'A' : s[i];
			char y = s[j] >= 'A' && s[j] <= 'Z' ? s[j] + 'a' - 'A' : s[j];
			if (x != y) return false;
			else
				i++;j--;
		}
		return true;

	}

	bool isValidChar(char c)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return true;
		return false;
	}
};

int main()
{
	Solution* so = new Solution();
	vector<string> cases;
	cases.push_back("");
	cases.push_back("?");
	cases.push_back("at eta ");
	cases.push_back("1a2");
	for (int i = 0; i < cases.size(); i++)
	{
		cout << "input: " << cases[i] << ", output: " << so->isPalindrome(cases[i]) << endl;
	}
}
