// source: https://leetcode.com/problems/compare-version-numbers/

/**
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 **/

 #include <iostream>

 using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int pos1 = 0, pos2 = 0;
		int length1 = version1.length();
		int length2 = version2.length();
		while(pos1 < length1 && pos2 < length2)
		{
			int point_pos1 = version1.find_first_of('.', pos1);
			int point_pos2 = version2.find_first_of('.', pos2);
			string ver1 = point_pos1 >= 0 ? version1.substr(pos1, point_pos1 - pos1) : version1.substr(pos1, length1 - pos1);
			string ver2 = point_pos2 >= 0 ? version2.substr(pos2, point_pos2 - pos2) : version2.substr(pos2, length2 - pos2);
			pos1 = point_pos1 >= 0 ? point_pos1 + 1 : length1;
			pos2 = point_pos2 >= 0 ? point_pos2 + 1 : length2;
			
			int num1 = convertStringToInt(ver1);
			int num2 = convertStringToInt(ver2);
			if (num1 > num2) return 1;
			if (num1 < num2) return -1;
		}
		while(pos1 < length1)
		{
			int point_pos1 = version1.find_first_of('.', pos1);
			string ver1 = point_pos1 >= 0 ? version1.substr(pos1, point_pos1 - pos1) : version1.substr(pos1, length1 - pos1);
			if (convertStringToInt(ver1) > 0) return 1;
			pos1 = point_pos1 >= 0 ? point_pos1 + 1 : length1;
		}
		while (pos2 < length2)
		{
			int point_pos2 = version2.find_first_of('.', pos2);
			string ver2 = point_pos2 >= 0 ? version2.substr(pos2, point_pos2 - pos2) : version2.substr(pos2, length2 - pos2);
			if (convertStringToInt(ver2) > 0) return -1;
			pos2 = point_pos2 >= 0 ? point_pos2 + 1 : length2;
		}
		return 0;
		
	}

	int convertStringToInt(string s)
	{
		if (s.length() == 0) return 0;
		int num = 0;
		for (int i = 0; i < s.length(); i++)
		{
			num = num * 10 + (s[i] - '0');
		}
		return num;
	}
};

int main()
{
	Solution* so = new Solution();
	string versions1[] = {"2",  "2.34", "2.3.13", "2.3", "1.0", "1.0.3"};
	string versions2[] = {"10", "13.0", "2.3",    "2.3", "1",   "1"};
	for (int i = 0; i < 6; i++)
		cout << "input: version1 = " << versions1[i] << ", version2 = " << versions2[i] << "; output: " << so->compareVersion(versions1[i], versions2[i]) << endl;
}
