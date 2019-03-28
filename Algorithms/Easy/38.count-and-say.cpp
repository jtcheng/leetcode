/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.32%)
 * Total Accepted:    255.4K
 * Total Submissions: 649.2K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */

 class Solution {
public:
	string countAndSay(int n) {
		string ret("1");
		for (int i = 2; i <= n; ++i) {
			string tmp(move(ret));
			for (int j = 0, len = tmp.length(); j < len;) {
				int count = 0;
				char say = tmp[j];
				do {
					count++;
					j++;
				} while ((j < len) && (say == tmp[j]));
				ret += (to_string(count) + say);
			}
		}
		return ret;
	}
};
