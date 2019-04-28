/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num < 1) {
			return false;
		}
		vector<int> p{ 2, 3, 5, 7, 13 };
		for (int i : p) {
			if (pn(i) == num) {
				return true;
			}
		}
		return false;
	}

private:
	int pn(int p) {
		return (1 << (p - 1)) * ((1 << p) - 1);
	}
};
