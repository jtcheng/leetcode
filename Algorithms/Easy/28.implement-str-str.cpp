/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.10%)
 * Total Accepted:    375.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.length();
		int len2 = needle.length();
		if (len2 == 0) {
			return 0;
		}
		for (int i = 0; i < len1; ++i) {
			int k = i;
			bool breaked = false;
			if (k+len2 > len1) {
				return -1;
			}
			for (int j = 0; j < len2; ++j) {
				if (haystack[k++] != needle[j]) {
					breaked = true;
					break;
				}
			}
			if (!breaked) {
				return i;
			}
		}
		return -1;
	}
};
