/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0, len = s.length(); i < len; i += k * 2) {
			int start = i;
			int end = min(start + k - 1, len - 1) + 1;
			if (start < end) {
				reverse(begin(s) + start, begin(s) + end);
			}
			else {
				break;
			}
		}
		return s;
	}
};
