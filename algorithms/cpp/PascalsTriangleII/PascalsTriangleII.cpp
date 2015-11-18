// source: https://leetcode.com/problems/pascals-triangle-ii/

/**
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 **/

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row;
		if (rowIndex < 0) return row;
		row.push_back(1);
		if (rowIndex == 0) return row;
		for (int i = 1; i < rowIndex+1; i++)
		{
			int previous = row[0];
			for (int j = 1; j <= i; j++)
			{
				if (j == i) row.push_back(1);
				else 
				{	
					int val = previous + row[j];
					previous = row[j];
					row[j] = val;
				}
			}
		}
		return row;
	}
};

