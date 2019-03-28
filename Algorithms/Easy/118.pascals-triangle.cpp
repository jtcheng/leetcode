/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (44.24%)
 * Total Accepted:    228.1K
 * Total Submissions: 512.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		if (numRows == 0) {
			return ret;
		}
		ret.resize(numRows);
		ret[0].push_back(1);
		if (numRows == 1) {
			return ret;
		}
		for (int i = 1; i < numRows; ++i) {
			ret[i].resize(i + 1, 1);
			for (int j = 1; j < i; ++j) {
				ret[i][j] = ret[i - 1][j-1] + ret[i - 1][j];
			}
		}
		return ret;
	}
};
