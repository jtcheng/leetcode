/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.96%)
 * Likes:    1388
 * Dislikes: 67
 * Total Accepted:    65.4K
 * Total Submissions: 218.1K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int l = 0;
        int r = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0, j = nums.size() - 1; j >= 0; ++i, --j) {
            maxi = max(maxi, nums[i]);
            if (maxi != nums[i]) {
                r = i;
            }
            mini = min(mini, nums[j]);
            if (mini != nums[j]) {
                l = j;
            }
        }
        return (r - l + 1);
    }
};
