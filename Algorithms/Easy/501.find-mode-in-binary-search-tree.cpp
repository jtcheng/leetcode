/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (39.31%)
 * Likes:    544
 * Dislikes: 206
 * Total Accepted:    55.2K
 * Total Submissions: 140.5K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
	vector<int> findMode(TreeNode* root) {
		if (!root) {
			return modes;
		}
		int curNum = INT_MIN;
		int curCnt = 0;
		inOrder(root, curNum, curCnt);
		return modes;
	}

private:
	void inOrder(TreeNode* root, int& curNum, int& curCnt) {
		if (!root) {
			return;
		}
		inOrder(root->left, curNum, curCnt);

		if (root->val == curNum) {
			curCnt++;
		}
		else {
			curCnt = 1;
			curNum = root->val;
		}
		if (curCnt > maxCnt) {
			modes.clear();
			modes.push_back(curNum);
			maxCnt = curCnt;
		}
		else if (curCnt == maxCnt) {
			modes.push_back(curNum);
		}

		inOrder(root->right, curNum, curCnt);
	}

private:
	vector<int> modes{};
	int maxCnt = 1;
};

