// source: https://leetcode.com/problems/count-and-say/

/**
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 *
 **/

 #include<iostream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0) return "10";
		if (n == 1) return "1";
		string last = countAndSay(n-1);
		string output = "";
		char temp = '0';
		int num = 0;
		for (int i = 0; i < last.length(); i++)
		{
			if (last[i] != temp) 
			{
				if (num > 0)
				{
					output += ('0' + num);
					output += temp;
				}
				temp = last[i];
				num = 1;
			}
			else
				num++;
		}
		if (num > 0)
		{
			output += ('0' + num); 
			output += temp;
		}
		return output;
	}
};

int main()
{
	Solution* so = new Solution();
	for (int i = 0; i < 10; i++)
	{
		cout << "input: " << i << ", output: " << so->countAndSay(i) << endl;
	}
}
