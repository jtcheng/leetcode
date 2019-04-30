/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
	int findTilt(TreeNode* root) {
		int tilt = 0;
		postOrder(root, tilt);
		return tilt;
	}

private:
	int postOrder(TreeNode* root, int& curTilt) {
		if (root == NULL) {
			return 0;
		}
		int left = postOrder(root->left, curTilt);
		int right = postOrder(root->right, curTilt);
		curTilt += abs(left - right);
		return left + right + root->val;
	}
};
