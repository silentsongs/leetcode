// source: https://leetcode.com/problems/isomorphic-strings/

/**
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 *
 **/

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, char> char_maps;
		map<char, char> reverse_maps;
		for (int i = 0; i < s.length(); i++)
		{
			if (char_maps.find(s[i]) != char_maps.end())
			{
				if (char_maps[s[i]] != t[i]) return false;
			}
			else
			{
				if (reverse_maps.find(t[i]) != reverse_maps.end()) return false;
				char_maps[s[i]] = t[i];
				reverse_maps[t[i]] = s[i];
			}
		}
		return true;
	}
};

int main()
{
	Solution* so = new Solution();
	string srcs[] =  {"egg", "foo", "paper", "paperss"};
	string dests[] = {"add", "bar", "title", "titlett"};
	for (int i = 0; i < 4; i++)
	{
		cout << "input: source = " << srcs[i] << " dest = " << dests[i] << ", output: " << so->isIsomorphic(srcs[i], dests[i]) << endl;
	}
}
