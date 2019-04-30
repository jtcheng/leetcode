/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
	TreeNode* convertBST(TreeNode* root) {
		int curSum = 0;
		return convertBST(root, curSum);
	}

private:
	TreeNode* convertBST(TreeNode* root, int& curSum) {
		if (root != NULL) {
			convertBST(root->right, curSum);
			curSum += root->val;
			root->val = curSum;
			convertBST(root->left, curSum);
		}
		return root;
	}
};
