/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (47.44%)
 * Total Accepted:    89.9K
 * Total Submissions: 189.1K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */

class Solution {
public:
	int longestPalindrome(string s) {
		int ch[128] = { 0 };
		for (int i = 0, len = s.length(); i < len; ++i) {
			ch[s[i]]++;
		}
		int ans = 0;
		bool odd = false;
		for (int i = 0; i < 128; ++i) {
			div_t d = div(ch[i], 2);
			ans += d.quot * 2;
			if (d.rem) {
				odd = true;
			}
		}
		if (odd && !(ans % 2)) {
			return ans + 1;
		}
		return ans;
	}
};
