/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (48.22%)
 * Likes:    188
 * Dislikes: 359
 * Total Accepted:    42K
 * Total Submissions: 87K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		int len = nums.size();
		vector<int> idx(len);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&nums](int i, int j) {return nums[i] > nums[j]; });
		vector<string> ans(len);
		for (int i = 0; i < len; ++i) {
			string rank;
			if (i == 0) {
				rank = "Gold Medal";
			}
			else if (i == 1) {
				rank = "Silver Medal";
			}
			else if (i == 2) {
				rank = "Bronze Medal";
			}
			else {
				rank = to_string(i + 1);
			}
			ans[idx[i]] = rank;
		}
		return ans;
	}
};

