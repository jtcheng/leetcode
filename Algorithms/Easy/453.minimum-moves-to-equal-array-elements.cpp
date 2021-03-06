/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (49.06%)
 * Total Accepted:    55K
 * Total Submissions: 112.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int len = nums.size();
		long sum = nums[0];
		long min = nums[0];
		for (int i = 1; i < len; ++i) {
			sum += nums[i];
			if (nums[i] < min) {
				min = nums[i];
			}
		}
		return sum - len * min;
	}
};
