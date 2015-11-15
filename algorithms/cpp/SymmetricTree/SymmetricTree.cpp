// source: https://leetcode.com/problems/symmetric-tree/

/**
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *    1
 *   / \
 *  2   2
 *   \   \
 *    3    3
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;

		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);

		while(!q1.empty() && !q2.empty())
		{
			TreeNode* left = q1.front();
			q1.pop();
			TreeNode* right = q2.front();
			q2.pop();
			if (left == NULL && right == NULL)
				continue;
			if (left == NULL || right == NULL)
				return false;
			if (left->val != right->val) return false;
			q1.push(left->left);
			q2.push(right->right);
			q1.push(left->right);
			q2.push(right->left);
		}
		return true;

	}

	bool isSymmetric2(TreeNode* root) {
		if (root == NULL) return true;
		return isSymmetricHelper(root->left, root->right);
	}

	bool isSymmetricHelper(TreeNode* left, TreeNode* right)
	{
		if (left == NULL || right == NULL)
			return left == right;
		if (left->val != right->val) return false;
		return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
	}
};
