// source: https://leetcode.com/problems/binary-tree-paths/

/**
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *       1
 *     /   \
 *    2     3
 *     \
 *      5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *
 **/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> paths;
		if (root == NULL) return paths;
		stringstream stream;
		stream<<root->val;  
		string s = stream.str();
		if (root->left == NULL && root->right == NULL) 
		{
			paths.push_back(s);
			return paths;
		}
		if (root->left != NULL)
		{
			vector<string> left_paths = binaryTreePaths(root->left);
			for (int i = 0; i < left_paths.size(); i++)
			{
				paths.push_back(s + "->" + left_paths[i]);
			}
		}
		if (root->right != NULL)
		{
			vector<string> right_paths = binaryTreePaths(root->right);
			for (int i = 0; i < right_paths.size(); i++)
			{
				paths.push_back(s + "->" + right_paths[i]);
			}
		}
		return paths;
	}
};
