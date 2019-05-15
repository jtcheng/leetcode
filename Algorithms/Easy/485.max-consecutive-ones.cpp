/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (54.97%)
 * Likes:    357
 * Dislikes: 306
 * Total Accepted:    135K
 * Total Submissions: 245.5K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 * 
 * Example 1:
 * 
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ⁠   The maximum number of consecutive 1s is 3.
 * 
 * 
 * 
 * Note:
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 * 
 * 
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

