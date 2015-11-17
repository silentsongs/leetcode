// source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * 	    3
 * 	   / \
 * 	  9  20
 * 	 /  \
 * 	15   7
 * 	return its bottom-up level order traversal as:
 * 	[
 * 		[15,7],
 * 		[9,20],
 * 		[3]
 * 	]
 * 	confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		stack<queue<TreeNode*>> levels;
		vector<vector<int>> result;
		queue<TreeNode*> q;
		q.push(root);
		levels.push(q);
		while(!levels.empty())
		{
			queue<TreeNode*> this_level = levels.top();
			queue<TreeNode*> next_level;
			while(!this_level.empty())
			{
				TreeNode* node = this_level.front();
				this_level.pop();
				if (node == NULL) continue;
				next_level.push(node->left);
				next_level.push(node->right);
			}
			if (next_level.empty()) break;
			else levels.push(next_level);
		}
		while(!levels.empty())
		{
			queue<TreeNode*> que = levels.top();
			levels.pop();
			vector<int> level;
			while(!que.empty())
			{
				TreeNode* node = que.front();
				que.pop();
				if (node != NULL) level.push_back(node->val);
			}
			if (level.size() > 0) result.push_back(level);
		}
		return result;
	}
};
