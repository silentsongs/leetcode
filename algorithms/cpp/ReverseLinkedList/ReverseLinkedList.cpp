// source: https://leetcode.com/problems/reverse-linked-list/

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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* next = head->next;
		ListNode* new_head = reverseList(head->next);
		next->next = head;
		head->next = NULL;
		return new_head;
	}

	ListNode* reverseList2(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* node = head->next;
		ListNode* new_head = head;
		while(node != NULL)
		{
			ListNode* temp = node->next;
			node->next = new_head;
			new_head = node;
			node = temp;
		}
		head->next = NULL;
		return new_head;
	}
};
