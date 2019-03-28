/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.66%)
 * Total Accepted:    52K
 * Total Submissions: 141.6K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */

class Solution {
public:
	int countSegments(string s) {
		int ans = 0;
		for (int i = 0, len = s.length(); i < len; ++i) {
			if ((i == 0 || s[i - 1] == ' ') && (s[i] != ' ')) {
				++ans;
			}
		}
		return ans;
	}
};
