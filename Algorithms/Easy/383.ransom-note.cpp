/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (49.28%)
 * Total Accepted:    104.8K
 * Total Submissions: 212.3K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int len1 = ransomNote.length();
		int len2 = magazine.length();
		if (len1 > len2) {
			return false;
		}
		int m[26] = { 0 };
		for_each(begin(magazine), end(magazine), [&](char c) {m[c - 'a']++; });
		for_each(begin(ransomNote), end(ransomNote), [&](char c) {m[c - 'a']--; });
		return all_of(begin(m), end(m), [](int x) {return x >= 0; });
	}
};
