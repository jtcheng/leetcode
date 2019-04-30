/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

class Solution {
public:
	string reverseWords(string s) {
		for (int i = 0, j = 0, len = s.length(); i < len; ) {
			j = i;
			while (j != len && s[++j] != ' ') {
				;
			}
			reverse(begin(s) + i, begin(s) + j);
			i = j + 1;
		}
		return s;
	}
};
