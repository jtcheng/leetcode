/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (37.22%)
 * Total Accepted:    147.4K
 * Total Submissions: 395.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */

class Solution {
public:
    int trailingZeroes(int n) {
    	int zeroes = 0;
    	while (n >= 5) {
    		int factors = n / 5;
    		zeroes += factors;
    		n = factors;
    	}
    	return zeroes;
    }
};
