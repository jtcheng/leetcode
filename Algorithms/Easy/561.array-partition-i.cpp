/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 */

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int ans = 0;
		sort(begin(nums), end(nums));
		for (int i = 0, len = nums.size(); i < len; i += 2) {
			ans += nums[i];
		}
		return ans;
	}
};
