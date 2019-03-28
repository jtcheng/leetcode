/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.54%)
 * Total Accepted:    357.2K
 * Total Submissions: 837.5K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
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
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		return isSymmetric(root->left, root->right);
	}
private:
	bool isSymmetric(TreeNode* p, TreeNode* q) {
		if (!p && !q) {
			return true;
		}
		if ((p && !q) || (!p && q)) {
			return false;
		}
		if (p->val != q->val) {
			return false;
		}
		if (!isSymmetric(p->left, q->right)) {
			return false;
		}
		return isSymmetric(p->right, q->left);
	}
};