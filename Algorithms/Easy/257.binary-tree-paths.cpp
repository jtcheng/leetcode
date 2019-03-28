/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.01%)
 * Total Accepted:    211.2K
 * Total Submissions: 468.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (!root) {
			return res;
		}
		vector<pair<TreeNode*, string>> nodes;
		nodes.push_back(make_pair(root, to_string(root->val)));
		while (!nodes.empty()) {
			vector<pair<TreeNode*, string>> tnodes;
			for (const pair<TreeNode*, string>& p : nodes) {
				TreeNode* node = p.first;
				string str(move(p.second));
				if (node->left) {
					tnodes.push_back(make_pair(node->left, str + "->" + to_string(node->left->val)));
				}
				if (node->right) {
					tnodes.push_back(make_pair(node->right, str + "->" + to_string(node->right->val)));
				}
				if (!node->left && !node->right) {
					res.push_back(move(str));
				}
			}
			nodes = move(tnodes);
		}
		return res;
	}
};
