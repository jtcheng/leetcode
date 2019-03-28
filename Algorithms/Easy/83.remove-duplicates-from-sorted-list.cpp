/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (41.78%)
 * Total Accepted:    300.6K
 * Total Submissions: 718.3K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* curr = head;
		ListNode* next = curr ? curr->next : NULL;
		while (next) {
			if (curr->val == next->val) {
				curr->next = next->next;
				next = curr->next;
			}
			else {
				curr = next;
				next = curr->next;
			}
		}
		return head;
	}
};
