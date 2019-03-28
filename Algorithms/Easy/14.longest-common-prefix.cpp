/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.90%)
 * Total Accepted:    401.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
 
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = strs.size();
		if (len == 0) {
			return "";
		}
		string common(strs[0]);
		for (int i = 1; i < len; ++i) {
			common = longestCommonPrefix(common, strs[i]);
		}
		return common;
	}
private:
	string longestCommonPrefix(string& lstr, string& rstr) {
		int minLen = min(lstr.length(), rstr.length());
		string common;
		common.reserve(minLen);
		for (int i = 0; i < minLen; ++i) {
			if (lstr[i] != rstr[i]) {
				break;
			}
			common += lstr[i];
		}
		return common;
	}
};
