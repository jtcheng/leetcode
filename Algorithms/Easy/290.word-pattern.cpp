/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (34.53%)
 * Total Accepted:    131.2K
 * Total Submissions: 379.9K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 */

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int p[26] = {0};
		unordered_map<string, int> m;
		char* s = strdup(str.c_str());
		char* k = s;
		for (int i = 0, len = pattern.length(); i < len; ++i) {
			if (!s) {
				return false;
			}
			char* sep = NULL;
			if (sep = strchr(s, ' ')) {
				*(sep++) = '\0';
			}

			int idx = pattern[i] - 'a';
			if (m[s] != p[idx]) {
				return false;
			}
			else if (!p[idx]) {
				m[s] = i + 1;
				p[idx] = i + 1;
			}

			s = sep;
		}
		bool b = (s == NULL);
		free(k);
		return b;
	}
};
