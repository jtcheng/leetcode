/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int ro = nums.size();
		int co = nums[0].size();
		if (ro == r || ro * co != r * c) {
			return nums;
		}
		int count = 0;
		vector<vector<int>> ans(r, vector<int>(c, 0));
		for (int i = 0; i < ro; ++i) {
			for (int j = 0; j < co; ++j) {
				div_t idx = div(count, c);
				ans[idx.quot][idx.rem] = nums[i][j];
				++count;
			}
		}
		return ans;
	}
};
