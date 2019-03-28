/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (39.39%)
 * Total Accepted:    101.3K
 * Total Submissions: 257K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */

class Solution {
public:
	bool isPerfectSquare(int num) {
		long r = num / 2 + 1;
		while (r*r > num) {
			r = (r + num / r) / 2;
		}
		return r * r == num;
	}
};
