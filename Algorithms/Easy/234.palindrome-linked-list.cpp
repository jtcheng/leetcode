/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.31%)
 * Total Accepted:    233.2K
 * Total Submissions: 660K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
	bool isPalindrome(ListNode* head) {
		stack<int> s;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			s.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast) {
			slow = slow->next;
		}
		for (; !s.empty(); s.pop()) {
			if (s.top() != slow->val) {
				return false;
			}
			slow = slow->next;
		}
		return true;
	}
};