/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) {
			return 0;
		}

		unordered_set<int> s1;
		unordered_set<int> s2;
		for (int n : nums) {
			auto ret = s1.insert(n);
			if (!ret.second) {
				s2.insert(n);
			}
		}

		if (k == 0) {
			return s2.size();
		}

		int ret = 0;
		for (int n : s1) {
			if (s1.find(n - k) != s1.end()) {
				++ret;
			}
		}
		return ret;
	}
};
