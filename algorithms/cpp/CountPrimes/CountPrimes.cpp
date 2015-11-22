// source: https://leetcode.com/problems/count-primes/

/**
 *
 * Description:
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 *
 **/

// READ: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0; 
		int count = n - 2;
		vector<bool> isPrimes(n, true);

		for (int i = 2; i * i <= n; i++)
		{
			if (!isPrimes[i]) continue;
			for (int j = i * i; j < n; j+=i)
			{
				if (isPrimes[j]) 
				{	
					count--;
					isPrimes[j] = false;
				}
			}
		}
		return count;
	}

};

int main()
{

	Solution* so = new Solution();
	for (int i = 1; i < 21; i++)
	{
		cout << "input: " << i << ", output: " << so->countPrimes(i) << endl;
	}
	cout << "input: " << 499800 << ", output: " << so->countPrimes(499800) << endl;
}
