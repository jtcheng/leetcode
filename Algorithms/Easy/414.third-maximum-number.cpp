/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.65%)
 * Total Accepted:    85.4K
 * Total Submissions: 297.7K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long a[3] = { LONG_MIN, LONG_MIN, LONG_MIN };
		for (auto i : nums) {
			if (i > a[0]) {
				a[2] = a[1];
				a[1] = a[0];
				a[0] = i;
			}
			else if (i > a[1] && i < a[0]) {
				a[2] = a[1];
				a[1] = i;
			}
			else if (i > a[2] && i < a[1]) {
				a[2] = i;
			}
		}
		return a[2] == LONG_MIN ? int(a[0]) : int(a[2]);
	}
};
