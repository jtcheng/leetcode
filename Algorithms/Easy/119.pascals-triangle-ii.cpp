/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (41.74%)
 * Total Accepted:    185K
 * Total Submissions: 440.3K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret(rowIndex + 1, 1);
		for (int i = 2; i <= rowIndex; ++i) {
			for (int j = i - 1; j > 0; --j) {
				ret[j] = ret[j] + ret[j - 1];
			}
		}
		return ret;
	}
};
