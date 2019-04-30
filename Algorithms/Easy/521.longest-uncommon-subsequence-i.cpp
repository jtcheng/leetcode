/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I 
 */

class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a == b) {
			return -1;
		}
		return max(a.length(), b.length());
	}
};
