/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (49.18%)
 * Total Accepted:    235.5K
 * Total Submissions: 477.7K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */

class Solution {
public:
	int firstUniqChar(string s) {
		int arr[26] = { 0 };
		for_each(begin(s), end(s), [&](char c) {arr[c - 'a']++; });
		auto pos = find_if(begin(s), end(s), [&](char c) {return arr[c - 'a'] == 1; });
		if (pos != s.end()) {
			return distance(s.begin(), pos);
		}
		return -1;
	}
};
