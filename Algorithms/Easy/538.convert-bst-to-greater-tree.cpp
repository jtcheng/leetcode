/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (50.78%)
 * Likes:    1241
 * Dislikes: 82
 * Total Accepted:    76.9K
 * Total Submissions: 151.4K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 * 
 * 
 * Example:
 * 
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
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

