//source : https://leetcode.com/problems/word-pattern/

/**
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 *
 **/

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		if (pattern.empty() && str.empty()) return true;
		map<char, string> str_map;
		set<string> show_strs;
		int str_length = str.length();
		int pos = 0;
		for (int i = 0; i < pattern.length(); i++)
		{
			if (pos >= str_length) return false;
			int pos2 = str.find_first_of(' ', pos);
			if (pos2 == string::npos)
				pos2 = str_length;
			string substr = str.substr(pos, pos2-pos);
			pos = pos2+1;
			map<char, string>::iterator it = str_map.find(pattern[i]);
			if (it == str_map.end())
			{
				if (show_strs.find(substr) != show_strs.end()) return false;
				str_map[pattern[i]] = substr;
				show_strs.insert(substr);
			}
			else
			{
				string str_val = it->second;
				if (str_val != substr) return false;
			}
		}
		if (pos <= str_length) return false;
		return true;
	}
};
