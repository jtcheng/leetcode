/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (60.44%)
 * Total Accepted:    128.4K
 * Total Submissions: 211.8K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water.
 * 
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 * 
 * The island doesn't have "lakes" (water inside that isn't connected to the
 * water around the island). One cell is a square with side length 1. The grid
 * is rectangular, width and height don't exceed 100. Determine the perimeter
 * of the island.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * Output: 16
 * 
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 * 
 * 
 * 
 * 
 */

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int count = 0;
		int repeat = 0;
		int rs = grid.size();
		int cs = grid[0].size();
		for (int i = 0; i < rs; ++i) {
			for (int j = 0; j < cs; ++j) {
				if (grid[i][j] == 1) {
					++count;
					if (i != 0 && grid[i - 1][j] == 1) ++repeat;
					if (j != 0 && grid[i][j - 1] == 1) ++repeat;
				}
			}
		}
		return 4 * count - 2 * repeat;
	}
};
