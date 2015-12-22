// source: https://leetcode.com/problems/palindrome-permutation/

/**
 *
 * Given a string, determine if a permutation of the string could form a palindrome.
 *
 * For example,
 * "code" -> False, "aab" -> True, "carerac" -> True.
 *
 **/

class Solution {
public:
	bool canPermutePalindrome(string s) {
		int length = s.length();
		if (length == 0) return false;
		unordered_map<char, int> map;
		bool has_odd = false;
		for (int i = 0; i < length; i++)
		{
			map[s[i]]++;
		}
		for (unordered_map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			if (it->second % 2 != 0)
			{
				if (has_odd) return false;
				else 
					has_odd = true;
			}
		}
		return true;
	}
};
