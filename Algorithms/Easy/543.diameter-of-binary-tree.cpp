/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
	int diameterOfBinaryTree(TreeNode* root) {
		int maxDiameter = 0;
		maxDepth(root, maxDiameter);
		return maxDiameter;
	}

private:
	int maxDepth(TreeNode* node, int& maxDiameter) {
		if (node == NULL) {
			return 0;
		}
		int left = maxDepth(node->left, maxDiameter);
		int right = maxDepth(node->right, maxDiameter);
		maxDiameter = max(maxDiameter, left + right);
		return max(left, right) + 1;
	}
};
