// source: https://leetcode.com/problems/longest-substring-without-repeating-characters/

/**
 *
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 **/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> str_pos;
		queue<char> substr;
		int res = 0, temp = 0;
		for (int i = 0; i < s.length(); i++)
		{
			char x = s[i];
			map<char, int>::iterator it = str_pos.find(x);
			if (it != str_pos.end() && it->second > 0)
			{
				res = temp > res ? temp : res;
				while(substr.front() != x)
				{
					str_pos.find(substr.front())->second--;
					substr.pop();
					temp--;
				}
				substr.pop();
				substr.push(x);
			}
			else
			{
				str_pos[x] = 1; temp++;
				substr.push(x);
			}
		}
		res = temp > res ? temp : res;
		return res;
	}
};
