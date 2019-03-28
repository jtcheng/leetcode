/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (36.72%)
 * Total Accepted:    188K
 * Total Submissions: 511.9K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int cs[128] = { 0 }, ct[128] = { 0 };
		for (int i = 0, len = s.length(); i < len; ++i) {
			if (cs[s[i]] != ct[t[i]]) {
				return false;
			}
			else if (!cs[s[i]]) {
				cs[s[i]] = i + 1;
				ct[t[i]] = i + 1;
			}
		}
		return true;
	}
};
