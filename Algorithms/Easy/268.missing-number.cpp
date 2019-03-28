/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (47.55%)
 * Total Accepted:    248.9K
 * Total Submissions: 523.3K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		long sum1 = nums.size() * (nums.size() + 1) / 2;
		long sum2 = accumulate(nums.begin(), nums.end(), 0);
		return sum1 - sum2;
	}
};
