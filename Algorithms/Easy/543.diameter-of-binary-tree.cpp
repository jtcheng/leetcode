/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (46.62%)
 * Likes:    1360
 * Dislikes: 83
 * Total Accepted:    127.8K
 * Total Submissions: 274.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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

