// source: https://leetcode.com/problems/palindrome-linked-list/

/**
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next != NULL && fast->next->next !=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* opp_head = slow->next;
		ListNode* node = slow->next->next;
		while(node != NULL)
		{
			ListNode* temp = node->next;
			node->next = opp_head;
			opp_head = node;
			node = temp;
		}
		slow->next->next = NULL;
		ListNode* node1 = opp_head;
		ListNode* node2 = head;
		while(node1 != NULL)
		{
			if (node1->val != node2->val) return false;
			node1 = node1->next;
			node2 = node2->next;
		}
		return true;
	}
};
