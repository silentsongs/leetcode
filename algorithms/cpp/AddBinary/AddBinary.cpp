// source: https://leetcode.com/problems/add-binary/

/**
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 **/
#include<iostream>
using namespace std;

class Solution {
public:

	// addBinary2 is from Discuss
	string addBinary2(string a, string b)
	{
		int m = a.length() - 1;
		int n = b.length() - 1;
		int c = 0;
		string output = "";
		while(m >= 0 || n >= 0 || c > 0)
		{
			c += (m >= 0 ? (a[m--] - '0') : 0);
			c += (n >= 0 ? (b[n--] - '0') : 0);
			output = char(c % 2 + '0') + output;
			c = c/2;
		}
		return output;
	}

	string addBinary(string a, string b) {
		return addBinaryWithFlag(a, b, 0);
	}

	string addBinaryWithFlag(string a, string b, char c)
	{
		int m = a.length();
		int n = b.length();
		if (m == 0 && n == 0)
		{
			if (c == 0) return "";
			else return "1";
		}
		char x;
		string prefix;
		if (m > 0 && n > 0)
		{
			x = (((a[m-1] - '0') + (b[n-1] - '0') + c) % 2) + '0'; 
			c = ((a[m-1] - '0') + (b[n-1] - '0') + c) / 2;
			prefix = addBinaryWithFlag(a.substr(0, m-1), b.substr(0, n-1), c);
		}
		if (m > 0 && n == 0)
		{
			x = (((a[m-1] - '0') + c) % 2) + '0';
			c = ((a[m-1] - '0') + c) / 2;
			prefix = addBinaryWithFlag(a.substr(0, m-1), b, c);
		}
		if (n > 0 && m == 0)
		{
			x = (((b[n-1] - '0') + c) % 2) + '0';
			c = ((b[n-1] - '0') + c) / 2;
			prefix = addBinaryWithFlag(a, b.substr(0, n-1), c);
		}
		prefix = prefix + x;
		return prefix;
	}
};

int main()
{
	Solution* so = new Solution();
	cout << "input: 1 + 0, output: " << so->addBinary("1", "0") << endl;
	cout << "input: 11 + 10, output: " << so->addBinary("11", "10") << endl;
	cout << "input: 011 + 1, output: " << so->addBinary("011", "1") << endl;
	cout << "input: 111 + 111, output: " << so->addBinary("111", "111") << endl;
	cout << "input: 1000 + 01, output: " << so->addBinary("1000", "01") << endl;
}
