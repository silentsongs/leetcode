// source: https://leetcode.com/problems/strobogrammatic-number-ii/

/**
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * For example,
 * Given n = 2, return ["11","69","88","96"].
 *
 **/

class Solution {
public:
	vector<string> findStrobogrammatic(int n) {
		vector<string> result;
		if (n <= 0) return result;
		if (n == 1)
		{
			result.push_back("0");result.push_back("1");result.push_back("8");
			return result;
		}
		queue<string> strs;
		strs.push("1");strs.push("6");strs.push("8");strs.push("9");strs.push("");
		for (int i = 0; i < n/2-1; i++)
		{
			while(strs.front() != "")
			{
				string s = strs.front();
				strs.pop();
				strs.push(s + "0");strs.push(s + "1");strs.push(s + "6");strs.push(s + "8");strs.push(s + "9");
			}
			strs.pop();strs.push("");
		}
		while(strs.front() != "")
		{
			string str = strs.front();
			strs.pop();
			if (n % 2 == 0)
				result.push_back(str + generateStrobogrammaticHalf(str));
			else
			{
				result.push_back(str + "0" + generateStrobogrammaticHalf(str));
				result.push_back(str + "1" + generateStrobogrammaticHalf(str));
				result.push_back(str + "8" + generateStrobogrammaticHalf(str));
			}
		}
		return result;
	}

	string generateStrobogrammaticHalf(string str)
	{
		string res = "";
		for (int i = str.length()-1; i >=0; i--)
		{
			if (str[i] == '8' || str[i] == '0' || str[i] == '1') res.append(1, str[i]);
			else if (str[i] == '6') res += "9";
			else if (str[i] == '9') res += "6";
		}
		return res;
	}
};
