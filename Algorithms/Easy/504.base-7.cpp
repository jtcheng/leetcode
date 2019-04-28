/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) {
			return "0";
		}
		string ans;
		int n = abs(num);
		while (n) {
			div_t dv = div(n, 7);
			ans = to_string(dv.rem) + ans;
			n = dv.quot;
		}
		return num < 0 ? "-" + ans : ans;
	}
};
