/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * click to show spoilers.
 *
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 *
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 *
 */

#include <iostream>  
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x > 0 && x % 10 == 0)) return false;
		int n = 0;
		while(x > n)
		{
			n = n * 10 + x % 10;
			x = x/10;
		}
		return x == n || n/10 == x;
	}
};

int main(int argc, char *argv[]) {
	Solution* so = new Solution();
	int case1 = 12345;
	int cases[] = {-1, 0, 10, 1001, 123454321, 12321};
	int size = sizeof(cases)/sizeof(cases[0]);
	for (int i = 0; i < size; i++)
	{
		cout << "input: "<<cases[i]<<", output: "<< so->isPalindrome(cases[i]) << endl;
	}
}
