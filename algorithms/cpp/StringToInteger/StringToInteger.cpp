// source: https://leetcode.com/problems/string-to-integer-atoi/ 

/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 *
 * spoilers alert... click to show requirements for atoi.
 *
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 *
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int pos = str.find_first_not_of(" ");
        int indicator = 1;
        long result = 0;
        if (str[pos] == '+' || str[pos] == '-')
        {
            if (str[pos] == '-') indicator = -1;
            pos++;
        }
        while(str[pos] <= '9' && str[pos] >= '0')
        {
            result = result * 10 + (str[pos] - '0');
            if (result * indicator >= INT_MAX) return INT_MAX;
            if (result * indicator <= INT_MIN) return INT_MIN;
            pos++;
        }
        return result * indicator;
    }
};

int main()
{
	string cases[] = {"+123", "+b",  "-123", "0", "999999999999999", "21b3", "abdc", "  45", " 3 45", "  4  8a ", " 3  4  5  ", "-  41 4", "-2323232323232"};
	Solution* so = new Solution();
	for(int i = 0; i < 13; i++)
	{
		cout << "intput: " << cases[i] << ", output: " << so->myAtoi(cases[i]) << endl;
	}
}
