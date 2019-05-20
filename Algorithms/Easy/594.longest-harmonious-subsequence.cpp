/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (43.60%)
 * Likes:    404
 * Dislikes: 55
 * Total Accepted:    35.8K
 * Total Submissions: 82.1K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array is an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 * 
 * Example 1:
 * 
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * 
 * Note:
 * The length of the input array will not exceed 20,000.
 * 
 * 
 * 
 */

class Solution {
public:
    int findLHS(vector<int> &nums) {
        int len = 0;
        unordered_map<int, int> umap;
        for (auto n : nums) {
            umap[n]++;
        }
        for (auto n : nums) {
            if (umap.count(n + 1)) {
                len = max(len, umap[n] + umap[n + 1]);
            }
        }
        return len;
    }
};
