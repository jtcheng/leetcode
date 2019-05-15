/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (45.20%)
 * Likes:    142
 * Dislikes: 586
 * Total Accepted:    50.6K
 * Total Submissions: 112K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).    
 * 
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 * 
 * Example 1:
 * 
 * Input: "PPALLP"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "PPALLL"
 * Output: False
 * 
 * 
 * 
 * 
 * 
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

