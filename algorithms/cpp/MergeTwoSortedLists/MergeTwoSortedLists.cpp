// source: https://leetcode.com/problems/merge-two-sorted-lists/

/**
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 **/

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode min = ListNode(INT_MIN);
		ListNode* head = &min;
		while(l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				head->next = l1; 
				l1 = l1->next;
			}
			else
			{
				head->next = l2; 
				l2 = l2->next;
			}
			head = head->next;
		}

		head->next = l1 == NULL ? l2 : l1;
		return min.next;
		
	}
};
