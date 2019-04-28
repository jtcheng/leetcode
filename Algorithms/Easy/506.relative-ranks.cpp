/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		int len = nums.size();
		vector<int> idx(len);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&nums](int i, int j) {return nums[i] > nums[j]; });
		vector<string> ans(len);
		for (int i = 0; i < len; ++i) {
			string rank;
			if (i == 0) {
				rank = "Gold Medal";
			}
			else if (i == 1) {
				rank = "Silver Medal";
			}
			else if (i == 2) {
				rank = "Bronze Medal";
			}
			else {
				rank = to_string(i + 1);
			}
			ans[idx[i]] = rank;
		}
		return ans;
	}
};
