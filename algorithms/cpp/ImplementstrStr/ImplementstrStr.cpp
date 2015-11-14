// source: https://leetcode.com/problems/implement-strstr/

/**
 *
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 **/

class Solution {
public:
	int strStr(string haystack, string needle) {
		int h_size = haystack.length();
		int n_size = needle.length();
		if (n_size == 0) return 0;
		for (int i = 0; i < h_size - n_size + 1; i++)
		{
			int j = 0;
			for (j; j < n_size; j++)
			{
				if (haystack[i+j] != needle[j]) break;
			}
			if (j == n_size) return i; 
		}
		return -1;

	}
};
