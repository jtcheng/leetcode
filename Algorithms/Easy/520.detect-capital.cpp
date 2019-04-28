/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

class Solution {
public:
	bool detectCapitalUse(string word) {
		int length = word.length();
		if (length < 2) {
			return true;
		}
		bool start = isCapital(word[0]);
		bool always = isCapital(word[1]);
		if (!start && always) {
			return false;
		}
		for (int i = 2; i < length; i++) {
			if (start && always) {
				if (!isCapital(word[i])) {
					return false;
				}
			}
			else {
				if (isCapital(word[i])) {
					return false;
				}
			}
		}
		return true;
	}

private:
	inline bool isCapital(char c) {
		return c >= 'A' && c <= 'Z';
	}
};
