/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
		vector<int> modes;
		if (!root) {
			return modes;
		}
		int curNum = root->val;
		int curCnt = 0;
		int maxCnt = 1;
		inOrder(root, curNum, curCnt, maxCnt, modes);
		return modes;
	}

private:
	void inOrder(TreeNode* root, int& curNum, int& curCnt, int& maxCnt, vector<int>& modes) {
		if (!root) {
			return;
		}
		inOrder(root->left, curNum, curCnt, maxCnt, modes);

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

		inOrder(root->right, curNum, curCnt, maxCnt, modes);
	}
};
