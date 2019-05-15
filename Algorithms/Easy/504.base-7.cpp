/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (44.85%)
 * Likes:    139
 * Dislikes: 112
 * Total Accepted:    40.8K
 * Total Submissions: 91K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */

class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) {
			return "0";
		}
		string ans;
		int n = abs(num);
		while (n) {
			div_t dv = div(n, 7);
			ans = to_string(dv.rem) + ans;
			n = dv.quot;
		}
		return num < 0 ? "-" + ans : ans;
	}
};

