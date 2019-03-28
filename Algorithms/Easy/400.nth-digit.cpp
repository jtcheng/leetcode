/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.09%)
 * Total Accepted:    44.8K
 * Total Submissions: 148.9K
 * Testcase Example:  '3'
 *
 * Find the n^th digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 2^31).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */

class Solution {
public:
	int findNthDigit(int n) {
		long m = 0;
		int num = 0;
		int i = 1;
		for (long base = 9; ; ++i, base *= 10) {
			num += base;
			m += i * base;
			if (n < m) {
				break;
			}
		}
		ldiv_t d = ldiv(m-n, i);
		num = num - d.quot;
		for (int j = 0; j < d.rem; ++j) {
			num /= 10;
		}
		return num % 10;
	}
};
