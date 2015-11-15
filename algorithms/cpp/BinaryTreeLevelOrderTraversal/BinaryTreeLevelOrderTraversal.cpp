// source: https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * 
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *      3
 *     / \
 *    9  20
 *   /  \
 *  15   7
 *  return its level order traversal as:
 *  [
 *  	[3],
 *  	[9,20],
 *  	[15,7]
 *	]
 *	confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		queue<queue<TreeNode*>> queues;
		queue<TreeNode*> q;
		q.push(root);
		queues.push(q);
		while(!queues.empty())
		{
			queue<TreeNode*> que = queues.front();
			queues.pop();
			queue<TreeNode*> next_level;
			vector<int> ver;
			while(!que.empty())
			{
				TreeNode* node = que.front();
				que.pop();
				if (node != NULL) 
				{
					ver.push_back(node->val);
					next_level.push(node->left);
					next_level.push(node->right);
				}
			}
			if (!next_level.empty())
				queues.push(next_level);
			if (ver.size() > 0)
				result.push_back(ver);
		}
		return result;
	}
};
