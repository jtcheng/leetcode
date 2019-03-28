/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (36.66%)
 * Total Accepted:    128.2K
 * Total Submissions: 349K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */

class NumArray {
public:
	NumArray(vector<int> nums) {
		int size = nums.size();
		up_ = make_unique<int[]>(size + 1);
		for (int i = 0; i < size; ++i) {
			up_[i + 1] = up_[i] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		return up_[j + 1] - up_[i];
	}
private:
	unique_ptr<int[]> up_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

