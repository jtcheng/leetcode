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
