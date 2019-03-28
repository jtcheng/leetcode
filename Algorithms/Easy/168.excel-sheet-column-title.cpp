/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (28.44%)
 * Total Accepted:    163.7K
 * Total Submissions: 574K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 */

class Solution {
public:
	string convertToTitle(int n) {
		const string albet = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
		string ret;
		while (n > 0) {
			ret = albet[n % 26] + ret;
			n = (n - 1) / 26;
		}
		return ret;
	}
};
