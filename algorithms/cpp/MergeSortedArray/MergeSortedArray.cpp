// source: https://leetcode.com/problems/merge-sorted-array/

/**
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 *
 **/

#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int length = m + n;
		int x = m - 1;
		int y = n - 1;
		for (int i = length - 1; i >= 0; i--)
		{
			if (x >=0 && y >= 0 )
			{
				nums1[i] = nums1[x] >= nums2[y] ? nums1[x--] : nums2[y--]; 
			}
			else if (x >= 0 && y < 0)
				nums1[i] = nums1[x--];
			else if (x < 0 && y >= 0)
				nums1[i] = nums2[y--];
		}
	}
};
