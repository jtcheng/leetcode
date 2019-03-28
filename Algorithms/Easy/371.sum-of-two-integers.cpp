/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.22%)
 * Total Accepted:    126.2K
 * Total Submissions: 246.7K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

class Solution {
public:
	int getSum(int a, int b) {
		int res = 0, c = 0;
		for (int i = 0; i < 32; i++) {
			int cur = 0;
			int t1 = (a >> i) & 1;
			int t2 = (b >> i) & 1;
			cur = t1 ^ t2 ^ c;
			res = res | (cur << i);
			if ((t1&t2) || (t1&c) || (t2&c)) {
				c = 1;
			}
			else {
				c = 0;
			}
		}
		return res;
	}
};
