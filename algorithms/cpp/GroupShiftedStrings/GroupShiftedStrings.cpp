// source: https://leetcode.com/problems/group-shifted-strings/

/**
 *
 * Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
 *
 * "abc" -> "bcd" -> ... -> "xyz"
 * Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
 *
 * For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
 * Return:
 *
 * [
 *     ["abc","bcd","xyz"],
 *     ["az","ba"],
 *     ["acef"],
 *     ["a","z"]
 * ]
 * Note: For the return value, each inner list's elements must follow the lexicographic order.
 *
 **/

class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		unordered_map<string, multiset<int>> map;
		vector<vector<string>> result;
		for (int i = 0; i < strings.size(); i++)
		{
			int dis = strings[i][0] - 'a';
			string s = "";
			for (int j = 0; j < strings[i].length(); j++)
			{
				char x = strings[i][j] >= strings[i][0] ? strings[i][j] - dis : strings[i][j] + 26 - dis;
				s.append(1, x);
			}
			map[s].insert(dis);
		}
		for (unordered_map<string, multiset<int>>::iterator it = map.begin(); it != map.end(); it++)
		{
			vector<string> strs;
			string str = it->first;
			multiset<int> pos = it->second;
			for (multiset<int>::iterator s_it = pos.begin(); s_it != pos.end(); s_it++)
			{
				string new_str = "";
				for (int i = 0; i < str.length(); i++)
				{
					char x = str[i] + *s_it > 'z' ? str[i] + *s_it - 26 : str[i] + *s_it;
					new_str.append(1, x); 
				}
				strs.push_back(new_str);
			}
			result.push_back(strs);
		}
		return result;
	}
};
