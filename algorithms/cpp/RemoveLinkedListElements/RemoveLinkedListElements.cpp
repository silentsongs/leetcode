// source: https://leetcode.com/problems/remove-linked-list-elements/

/**
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* node = head;
		while(node != NULL)
		{
			if (node->val == val)
			{
				head = node->next;
				node = node->next;
				continue;
			}
			ListNode* next = node->next;
			while(next != NULL && next->val == val)
			{
				next = next->next;
			}
			node->next = next;
			node = node->next;
		}
		return head;
	}
}

