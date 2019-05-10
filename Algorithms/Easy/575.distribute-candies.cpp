/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> uset(candies.begin(), candies.end());
		return min(uset.size(), candies.size() / 2);
	}
};
