/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (37.71%)
 * Total Accepted:    272.7K
 * Total Submissions: 722.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */

class Solution {
public:
	string addBinary(string a, string b) {
		int len1 = a.length();
		int len2 = b.length();
		int maxlen = len1 >= len2 ? len1 : len2;
		string s(maxlen, '0');
		int carry = 0;
		for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; --i, --j) {
			int c1 = i >= 0 ? a[i] - '0' : 0;
			int c2 = j >= 0 ? b[j] - '0' : 0;
			int c = c1 + c2 + carry;
			char b = c % 2 ? '1' : '0';
			carry = c / 2;
			s[--maxlen] = b;
		}
		if (carry == 1) {
			s = "1" + s;
		}
		return s;
	}
};
