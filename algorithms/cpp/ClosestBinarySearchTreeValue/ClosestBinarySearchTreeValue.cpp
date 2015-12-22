// source: https://leetcode.com/problems/closest-binary-search-tree-value/

/**
 *
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 *
 * Note:
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest to the target.
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
	int closestValue(TreeNode* root, double target) {
		int closest = root->val;
		TreeNode* node = root;
		while(node != NULL)
		{
			node = target > node->val ? node->right : node->left;
			if (node != NULL)
			{
				closest = abs(closest - target) <= abs(node->val - target) ? closest : node->val;
			}
		}
		return closest;
	}
};
