// source: https://leetcode.com/problems/delete-node-in-a-linked-list/

/**
 *
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 *
 **

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node == NULL) return;
		ListNode** n = &node;
		while((*n)->next != NULL)
		{
			(*n)->val = (*n)->next->val;
			n = &(*n)->next;
		}
		*n = NULL;
		return;
	}

	// A much simpler solution from Discuss
	void deleteNode2(ListNode* node) {
		*node = *(node->next);
	}
};
