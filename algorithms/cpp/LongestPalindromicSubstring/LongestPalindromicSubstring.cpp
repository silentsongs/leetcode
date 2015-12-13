// source: https://leetcode.com/problems/longest-palindromic-substring/

/**
 *
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 **/

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.length() == 1) return s;
		int begin = 0, longest_length = 0;
		int length = s.length();
		for (int i = 1; i < length;)
		{
			if (longest_length/2 >= length - i - 1) break;
			int j = i, k = i;
			while (k < length-1 && s[k+1] == s[k]) k++;
			i = k+1;
			while (k < length-1 && j > 0 && s[k+1] == s[j-1])
			{
				k++;j--;
			}
			if (k-j+1 > longest_length)
			{
				begin = j; longest_length = k-j+1;
			}
		}
		return s.substr(begin, longest_length);
	}
};
