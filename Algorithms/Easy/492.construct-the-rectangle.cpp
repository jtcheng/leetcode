/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

class Solution {
public:
	vector<int> constructRectangle(int area) {
		int N = floor(sqrt(area));
		while (area % N != 0) {
			--N;
		}
		return { area / N, N };
	}
};
