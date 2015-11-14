// source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *       After removing the second node from the end, the linked list becomes 1->2->3->5.
 *       Note:
 *       Given n will always be valid.
 *       Try to do this in one pass.
 *
 */
 
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode** l1 = &head;
		ListNode* l2 = head;
		for (int i = 1; i < n; i++)
		{
			if (l2 == NULL) return head;
			l2 = l2->next;
		}
		while(l2->next != NULL)
		{
			l1 = &((*l1)->next);
			l2 = l2->next;
		}
		*l1 = (*l1)->next; //TO UNDERSTAND IT MORE CAREFULLY!!!
		return head;
	}
};
