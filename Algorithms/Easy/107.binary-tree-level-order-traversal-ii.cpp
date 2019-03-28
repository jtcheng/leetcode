/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.42%)
 * Total Accepted:    208.8K
 * Total Submissions: 458K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> values;
		if (root == NULL) {
			return values;
		}
		vector<vector<TreeNode*>> allNodes;
		vector<TreeNode*> nodes;
		nodes.push_back(root);
		int currLevel = 0;
		while (!nodes.empty()) {
			++currLevel;
			allNodes.push_back(move(nodes));
			for (TreeNode* node : allNodes[currLevel-1]) {
				if (node->left) {
					nodes.push_back(node->left);
				}
				if (node->right) {
					nodes.push_back(node->right);
				}
			}
		}

		values.resize(currLevel);
		for (int i = currLevel - 1, j = 0; i >= 0; --i, ++j) {
			for (TreeNode* node : allNodes[i]) {
				values[j].push_back(node->val);
			}
		}
		return values;
	}
};
