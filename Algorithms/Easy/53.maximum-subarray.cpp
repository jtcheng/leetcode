/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.60%)
 * Total Accepted:    456.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

 class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int smax = nums[0];
		pair<int, int> indexes;
		for (int i = 1, len = nums.size(); i < len; ++i) {
			if (nums[i] > sum + nums[i]) {
				sum = nums[i];
				indexes.first = i;
			}
			else {
				sum = sum + nums[i];
			}
			if (sum > smax) {
				smax = sum;
				indexes.second = i;
			}
		}
		return smax;
	}
};
