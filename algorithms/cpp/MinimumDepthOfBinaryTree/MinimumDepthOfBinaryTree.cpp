// source: https://leetcode.com/problems/minimum-depth-of-binary-tree/

/**
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> que;
		que.push(root);
		que.push(NULL);
		int depth = 1;
		while(!que.empty())
		{
			TreeNode* node = que.front();
			que.pop();
			if (node == NULL) 
			{	
				que.push(NULL);	
				depth++;
			}
			else
			{
				if (node->left == NULL && node->right == NULL) return depth;
				if (node->left != NULL) que.push(node->left);
				if (node->right != NULL) que.push(node->right);
			}
		}
	}
};
