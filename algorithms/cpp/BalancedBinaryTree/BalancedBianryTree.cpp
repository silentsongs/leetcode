// source: https://leetcode.com/problems/balanced-binary-tree/

/**
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
	bool isBalanced(TreeNode* root) {
		if (root == NULL) return true;
		int left_hight = getDepth(root->left);
		int right_hight = getDepth(root->right);
		int diff = left_hight - right_hight;
		if (diff >= -1 && diff <= 1)
			return isBalanced(root->left) && isBalanced(root->right);
		return false;
	}
	
	int getDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int left_hight = getDepth(root->left);
		int right_hight = getDepth(root->right);
		return left_hight > right_hight ? (left_hight + 1) : (right_hight + 1);
	}
};
