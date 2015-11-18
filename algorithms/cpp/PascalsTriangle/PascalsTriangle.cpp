// source: https://leetcode.com/problems/pascals-triangle/

/**
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *        [1],
 *       [1,1],
 *      [1,2,1],
 *     [1,3,3,1],
 *    [1,4,6,4,1]
 * ]
 *
 **/


class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows == 0) return result;
		vector<int> first_row;
		first_row.push_back(1);
		result.push_back(first_row);
		if (numRows == 1) return result;
		for (int i = 1; i < numRows; i++)
		{
			vector<int> row;
			for (int j = 0; j <= i; j++)
			{
				if (j == 0 || j == i) row.push_back(1);
				else
					row.push_back(result[i-1][j-1] + result[i-1][j]); 
			}
			result.push_back(row);
		}
		return result;
	}
};

