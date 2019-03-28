/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (49.44%)
 * Total Accepted:    52K
 * Total Submissions: 105.1K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 */

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int ret = 0;
		unordered_map<long, int> mdist;
		for (int len = points.size(), i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) {
				long dist = pow((points[i].first - points[j].first), 2) + pow((points[i].second - points[j].second), 2);
				mdist[dist]++;
			}
			for (const auto &p : mdist) {
				ret += p.second * (p.second - 1);
			}
			mdist.clear();
		}
		return ret;
	}
};
