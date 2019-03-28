/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (48.71%)
 * Total Accepted:    117.6K
 * Total Submissions: 241.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;
		if (root == NULL) {
			return sum;
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
					if (!node->left->left && !node->left->right) {
						sum += node->left->val;
					}
				}
				if (node->right) {
					tnodes.push_back(node->right);
				}
			}
			nodes = move(tnodes);
		}
		return sum;
	}
};
