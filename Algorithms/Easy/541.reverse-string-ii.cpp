/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (45.39%)
 * Likes:    240
 * Dislikes: 725
 * Total Accepted:    58.8K
 * Total Submissions: 129.5K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0, len = s.length(); i < len; i += k * 2) {
			int start = i;
			int end = min(start + k - 1, len - 1) + 1;
			if (start < end) {
				reverse(begin(s) + start, begin(s) + end);
			}
			else {
				break;
			}
		}
		return s;
	}
};

