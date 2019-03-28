/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (40.86%)
 * Total Accepted:    144.5K
 * Total Submissions: 353.1K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */

class Solution {
public:
	string reverseVowels(string s) {
		unordered_set<char> us{ 'a', 'e', 'i', 'o', 'u', 'A', 'E','I', 'O', 'U' };
		int start = 0;
		int end = s.length() - 1;
		while (start < end) {
			while (us.find(s[start]) == us.end()) {
				if (++start == end) {
					return s;
				}
			}
			while (us.find(s[end]) == us.end()) {
				if (start == --end) {
					return s;
				}
			}
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
};
