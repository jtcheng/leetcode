/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int ans = 0;
		int now = 0;
		for (int i = 0, len = nums.size(); i < len; ++i) {
			if (nums[i] == 1) {
				if (++now > ans) {
					ans = now;
				}
			}
			else {
				now = 0;
			}
		}
		return ans;
	}
};
