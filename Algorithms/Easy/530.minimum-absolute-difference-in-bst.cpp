/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (50.32%)
 * Likes:    510
 * Dislikes: 35
 * Total Accepted:    58.2K
 * Total Submissions: 115.7K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note: There are at least two nodes in this BST.
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

