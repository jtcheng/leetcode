/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
	int getMinimumDifference(TreeNode* root) {
		int curNum = INT_MIN;
		inOrder(root, curNum);
		return minDiff;
	}

private:
	void inOrder(TreeNode* root, int& curNum) {
		if (root == NULL) {
			return;
		}
		inOrder(root->left, curNum);
		if (curNum != INT_MIN) {
			minDiff = min(minDiff, root->val - curNum);
		}
		curNum = root->val;
		inOrder(root->right, curNum);
	}

private:
	int minDiff = INT_MAX;
};
