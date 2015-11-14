// source: https://leetcode.com/problems/longest-common-prefix/

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		string str0 = strs[0];
		string prefix = "";
		for(int i = 0; i < str0.length(); i++)
		{
			for(int j = 1; j < strs.size(); j++)
			{
				if (strs[j].length() <= i || (strs[j].length() > i && strs[j][i] != str0[i]))
					return prefix;
			}
			prefix += str0[i];
		}
		return prefix;
	}

};

