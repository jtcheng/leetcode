/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (40.26%)
 * Total Accepted:    294K
 * Total Submissions: 728.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the depth of the two subtrees of every node never
 * differ by more than 1.
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * Return false.
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
	bool isBalanced(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		int lh = depth(root->left);
		int rh = depth(root->right);
		if (abs(lh - rh) <= 1) {
			return isBalanced(root->left) && isBalanced(root->right);
		}
		return false;
	}
private:
	int depth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		vector<TreeNode*> nodes;
		nodes.push_back(root);
		int currLevel = 0;
		while (!nodes.empty()) {
			++currLevel;
			vector<TreeNode*> tnodes;
			for (TreeNode* node : nodes) {
				if (node->left) {
					tnodes.push_back(node->left);
				}
				if (node->right) {
					tnodes.push_back(node->right);
				}
			}
			nodes = move(tnodes);
		}
		return currLevel;
	}
};
