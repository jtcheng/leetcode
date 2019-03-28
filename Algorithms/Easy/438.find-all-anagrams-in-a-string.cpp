/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (36.40%)
 * Total Accepted:    110.1K
 * Total Submissions: 300.6K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int len1 = s.length();
		int len2 = p.length();
		if (!len1 || !len2 || len1 < len2) {
			return ans;
		}
		int target[26] = { 0 };
		for (const char c : p) {
			++target[c - 'a'];
		}
		int window[26] = { 0 };
		int count = 0;
		int l = 0, r = 0;
		while (r < len1) {
			int idx = s[r] - 'a';
			++window[idx];
			++count;
			++r;
			while (window[idx] > target[idx]) {
				int idx = s[l] - 'a';
				--window[idx];
				--count;
				++l;
			}
			if (count == len2) {
				ans.push_back(l);
			}
		}
		return ans;
	}
};
