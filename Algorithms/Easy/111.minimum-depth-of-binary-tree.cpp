/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (34.77%)
 * Total Accepted:    273.6K
 * Total Submissions: 785.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
  int minDepth(TreeNode* root) {
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
				if (!node->left && !node->right) {
					return currLevel;
				}
			}
			nodes = move(tnodes);
		}
		return currLevel;
	}
};
