/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (52.88%)
 * Total Accepted:    141.2K
 * Total Submissions: 266.8K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ans;
		int N = nums.size();
		for (int i = 0; i < N; ++i) {
			nums[(nums[i] - 1) % N] += N;
		}
		for (int i = 0; i < N; ++i) {
			if (nums[i] <= N) {
				ans.push_back(i + 1);
			}
		}
		return ans;
	}
};
