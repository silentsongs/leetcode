// source: https://leetcode.com/problems/first-bad-version/

/**
 *
 * You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which will return whether version is bad. 
 * Implement a function to find the first bad version. You should minimize the number of calls to the API.
 *
 **/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	//TODO: should have a more clear solution
	int firstBadVersion(int n) {
		int begin = 1, end = n, middle = n/2;
		while(begin < middle && end > middle)
		{
			if (isBadVersion(middle))
				end = middle;
			else
				begin = middle;
			middle = begin/2+end/2;
		}
		for (int i = begin; i <= end; i++)
			if (isBadVersion(i)) return i;
		return 0;
	}	
}

