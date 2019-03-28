/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (43.03%)
 * Total Accepted:    85.7K
 * Total Submissions: 198.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

class Solution {
public:
	string addStrings(string num1, string num2) {
		int l1 = num1.length();
		int l2 = num2.length();
		int maxlen = l1 >= l2 ? l1 : l2;
		string s(maxlen, '0');
		int c = 0;
		for (int i = l1 - 1, j = l2 - 1; i >= 0 || j >= 0; --i, --j) {
			int c1 = i >= 0 ? num1[i] - '0' : 0;
			int c2 = j >= 0 ? num2[j] - '0' : 0;
			div_t d = div(c1 + c2 + c, 10);
			c = d.quot;
			s[--maxlen] = d.rem + '0';
		}
		if (c == 1) {
			s = "1" + s;
		}
		return s;
	}
};
