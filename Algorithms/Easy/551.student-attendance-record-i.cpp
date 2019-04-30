/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

class Solution {
public:
	bool checkRecord(string s) {
		int A = 0;
		int L = 0;
		for (char c : s) {
			if (c == 'L') {
				if (++L > 2) {
					return false;
				}
			}
			else {
				L = 0;
				if (c == 'A') {
					if (++A > 1) {
						return false;
					}
				}
			}
		}
		return true;
	}
};
