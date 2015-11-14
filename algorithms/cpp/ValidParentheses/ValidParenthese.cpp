// source: https://leetcode.com/problems/valid-parentheses/

/**
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 **/

 #include <iostream>
 #include <vector>

 using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> pars;
		for(int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				pars.push_back(s[i]);
			else if (s[i] == ')')
			{
				if (pars.size() == 0) return false;
				if (pars.back() != '(') return false;
				pars.pop_back();
			}
			else if (s[i] == ']')
			{
				if (pars.size() == 0) return false;
				if (pars.back() != '[') return false;
				pars.pop_back();
			}
			else if (s[i] == '}')
			{
				if (pars.size() == 0) return false;
				if (pars.back() != '{') return false;
				pars.pop_back();
			}
		}
		if (pars.size() > 0) return false;
		return true;
	}
};

int main()
{
	Solution* so = new Solution();
	string cases[] = {"{}[]", "}{}", "{{()}}", "12345", "", "{{{{}"};
	int size = sizeof(cases)/sizeof(string);
	for(int i = 0; i < size; i++)
	{
		cout << "input: " << cases[i] << ", output: " << so->isValid(cases[i]) << endl;
	}
}
