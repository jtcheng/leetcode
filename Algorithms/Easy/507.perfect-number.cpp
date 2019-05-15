/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (34.17%)
 * Likes:    150
 * Dislikes: 425
 * Total Accepted:    39.9K
 * Total Submissions: 116.7K
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself. 
 * 
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * 
 * 
 * Example:
 * 
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 * 
 */

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num < 1) {
			return false;
		}
		vector<int> p{ 2, 3, 5, 7, 13 };
		for (int i : p) {
			if (pn(i) == num) {
				return true;
			}
		}
		return false;
	}

private:
	int pn(int p) {
		return (1 << (p - 1)) * ((1 << p) - 1);
	}
};

