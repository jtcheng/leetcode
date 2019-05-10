/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == NULL || t == NULL) {
			return false;
		}
		return equals(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}

private:
	bool equals(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL) {
			return true;
		}
		if (t1 == NULL || t2 == NULL) {
			return false;
		}
		return (t1->val == t2->val) && equals(t1->left, t2->left) && equals(t1->right, t2->right);
	}
};
