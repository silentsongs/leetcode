// source: https://leetcode.com/problems/remove-duplicate-letters/

/**
 *
 * Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
 *
 * Example:
 * Given "bcabc"
 * Return "abc"
 *
 * Given "cbacdcbc"
 * Return "acdb"
 *
 *
 **/

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> visited_times(26, 0);
		vector<int> is_visited(26, 0);
		for (int i = 0; i < s.length(); i++)
		{
			visited_times[s[i]-'a']++;
		}
		stack<char> stk;
		for (int i = 0; i < s.length(); i++)
		{
			char index = s[i] - 'a';
			if (is_visited[index] > 0)
			{
				visited_times[index]--;
				continue;
			}
			while(!stk.empty() && stk.top() > s[i] && visited_times[stk.top()-'a'] > 1)
			{
				visited_times[stk.top()-'a']--; is_visited[stk.top()-'a']--; stk.pop();
			}
			stk.push(s[i]); is_visited[index]++; 
		}
		string result;
		while(!stk.empty())
		{
			result.push_back(stk.top());
			stk.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
