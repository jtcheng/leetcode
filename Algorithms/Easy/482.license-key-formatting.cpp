/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int ls = S.length();
		string ret(ls + ls / K, '-');
		auto it = ret.end();
		for (int i = ls - 1, s = K; i >= 0; --i) {
			char c = S[i];
			if (c != '-') {
				*(--it) = toupper(c);
				if (--s == 0) {
					s = K;
					--it;
				}
			}
		}
		if (*it == '-') {
			++it;
		}
		ret.erase(ret.begin(), it);
		return ret;
	}
};
