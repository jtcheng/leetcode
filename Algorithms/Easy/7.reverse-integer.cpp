/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.08%)
 * Total Accepted:    597.7K
 * Total Submissions: 2.4M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */

class Solution {
public:
	int reverse(int x) {
		bool positive = true;
		if (x < 0) {
			if (x == INT_MIN) {
				return 0;
			}
			x = -x;
			positive = false;
		}
		int len = 0;
		while (x && (x % 10 == 0)) {
			x = x / 10;
			--len;
		}
		int ret = 0;
		while (x) {
			int num = x % 10;
			x = x / 10;
			if (++len == 10) {
				if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && num > 7)) {
					return 0;
				}
			}
			ret = ret * 10 + num;
		}
		return positive ? ret : -ret;
	}
};
