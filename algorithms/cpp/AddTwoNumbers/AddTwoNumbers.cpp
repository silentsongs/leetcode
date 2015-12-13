// source: https://leetcode.com/problems/add-two-numbers/

/**
 *
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode res(0);
		ListNode* node = &res;
		int temp = 0;
		while(l1 != NULL || l2 != NULL)
		{
		 	int val1 = 0, val2 = 0;
			if (l1 != NULL)
			{
				val1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				val2 = l2->val;
				l2 = l2->next;
			}
			int val = val1 + val2 + temp;
			temp = val/10;
			node->next = new ListNode(val%10);
			node = node->next;
		}
		if (temp > 0)
		{
			node->next = new ListNode(temp);
		}
		return res.next;
	}
};

