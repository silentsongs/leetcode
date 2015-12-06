// source: https://leetcode.com/problems/valid-anagram/

/**
 *
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> v(26, 0);
		int length = s.length();
		if (length != t.length()) return false;
		for (int i = 0; i < length; i++)
		{
			int pos = s[i] - 'a';
			v[pos]++;
		}
		for (int i = 0; i < length; i++)
		{
			int pos = t[i] - 'a';
			v[pos]--;
			if (v[pos] < 0) return false;
		}
		return true;
	}
};

int main()
{
	Solution* so = new Solution();
	cout << "input: s = \"anagram\" t = \"nagaram\", output = " << so->isAnagram("anagram", "nagaram") << endl;
	cout << "input: s = \"rat\" t = \"car\", output = " << so->isAnagram("rat", "car") << endl;
}
